#include "threadPool.h"

ThreadPool::ThreadPool(int cores, int depth, URL startUrl, DB Database) {
	std::cout << "Spyder is started." << std::endl;
	this->Database = Database;
	this->depth = depth;
	submit(startUrl);
	for (int i = 0; i < cores; ++i) { //создаем пул потоков по количеству свободных ядер

		thread_vector.push_back(std::thread(&ThreadPool::work, this));
	}
}

ThreadPool::~ThreadPool() {
	for (auto& thread : thread_vector) {	//присоединяем дочерние потоки
		thread.join();
	}
}

void ThreadPool::submit(URL url) {
		safe_queue.push(url);
}

void ThreadPool::work() {
	while (true) {		//запскаем бесконечный цикл обработки
		std::unique_lock<std::mutex> lockMutex(mtx);
		if (!safe_queue.empty()) {			//если очередь не пуста - выполняем полезную работу
			URL current = safe_queue.pop();
			HtmlParser parser(current.address);
			std::vector<std::string> urls = parser.getUrlsList();
			if (parser.isRedirect()) { //если есть редирект - добавляем в очередь URL с той же глубиной
				submit({ urls[0], current.depth });
			}
			else if (current.depth < this->depth) {	//редиректа нет, глубина не превышает заданную - добавляем каждую ссылку
				for (std::string url : urls) {		//в очередь с глубиной +1
					submit({ url, current.depth + 1 });
				}
			}
			
			for (std::pair word : parser.getWordList()) {	//обходим массив слов
				Database.addEntry(current.address, word.first, word.second);
			}
			
			std::cout << "Spyder process: " << safe_queue.size() << " elements elapsed" << std::endl;
		}
		else {			//если очередь пуста - говорим, что паук завершил работу и выходим
			std::cout << "Spyder has done successfully!" << std::endl;
			return;
		}
		lockMutex.unlock();
	}
}