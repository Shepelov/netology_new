#include "threadPool.h"

ThreadPool::ThreadPool(int cores, int depth, URL startUrl, DB* database) : database(database),  depth(depth) {
	std::cout << "Spyder is started." << std::endl;
	submit(startUrl);
	for (int i = 0; i < cores; ++i) { //создаем пул потоков по количеству свободных ядер
		thread_vector.push_back(std::thread(&ThreadPool::work, this));
	}
}

ThreadPool::~ThreadPool() {
	for (auto& thread : thread_vector) {	//присоединяем дочерние потоки
		thread.join();
	}
	std::cout << "--------------------" << std::endl << "Spyder has done successfully!" << std::endl;
}

void ThreadPool::submit(URL url) {
		safe_queue.push(url);
}

void ThreadPool::work() {
	while (true) {		//запускаем бесконечный цикл обработки			
			if (!safe_queue.empty()) {			//если очередь не пуста - выполняем полезную работу
				std::unique_lock<std::mutex> lockMutex(mtx);
				URL current = safe_queue.pop();
				try {
					if (!database->isUrlExists(current.address)) {	//если URL еще нет в БД запускаем для него парсер
						HtmlParser parser(current.address);
						std::vector<std::string> urls = parser.getUrlsList();
						if (parser.isRedirect()) { //если есть редирект - добавляем его в очередь URL с той же глубиной
							if (urls[0] != current.address) {	//исключаем зацикливание редиректа "на себя"
								submit({ urls[0], current.depth });
							}
						}
						else if (current.depth < this->depth) {	//редиректа нет, глубина не превышает заданную - добавляем каждую ссылку
							for (std::string url : urls) {		//в очередь с глубиной +1
								submit({ url, current.depth + 1 });
							}
						}

						for (std::pair word : parser.getWordList()) {	//обходим массив слов
							database->addEntry(current.address, word.first, word.second);
						}
					}
				}
				catch (std::exception e) {
					continue;
				}

				//вывод прогресса работы паука
				if (current.depth != depth) {
					system("cls");
					std::cout << "Spider is prepairing links: " << safe_queue.size() << std::endl;
				}
				else {
					if (max_links == 0) {
						max_links = safe_queue.size();
					}
					system("cls");
					std::cout << "Spider in process..." << std::endl;
					double progress = 100.0 - (static_cast<double>(safe_queue.size()) / max_links * 100.0);
					progress = round(progress * 10000) / 10000;
					std::cout << "[";
					int segments = 60;
					for (int i = 0; i < segments; ++i) {
						if (progress > static_cast<double>(100.0 / segments * i)) {
							std::cout << "=";
						}
						else {
							std::cout << " ";
						}
					}
					std::cout << "]" << std::endl;
					std::cout << "Progress: " << progress << "%" << std::endl;
				}

				lockMutex.unlock();
			}
			else {			//если очередь пуста - говорим, что паук завершил работу и выходим
				return;
			}
	}
}