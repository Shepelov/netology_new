#include "threadPool.h"

ThreadPool::ThreadPool(int cores, int depth) {
	this->depth = depth;
	for (int i = 0; i < cores; ++i) {
		thread_vector.push_back(std::thread(&ThreadPool::work, this));
	}
}

ThreadPool::~ThreadPool() {
	for (auto& thread : thread_vector) {
		thread.join();
	}
}

void ThreadPool::submit(URL url) {
		safe_queue.push(url);
		std::this_thread::sleep_for(1s);	//временно!
	submit_flag = true;
}

void ThreadPool::work() {
	while (!submit_flag) {
		std::unique_lock<std::mutex> lockMutex(mtx);
		if (!safe_queue.empty()) {
			URL current = safe_queue.pop();
			HtmlParser parser(current.address);
			std::cout << parser.isRedirect() << std::endl;
			//for (int i = 0; i < parser.getUrlsList().size(); ++i) {
			//	std::cout << parser.getUrlsList()[i] << std::endl;
			//}
			std::vector<std::string> urls = parser.getUrlsList();
			if (parser.isRedirect()) {
				submit({urls[0], current.depth});
				//std::cout << "ADDR: " << urls[0] << std::endl << "DEP: " << current.depth << std::endl << std::endl;
			}
			else if (current.depth < depth) {
				for (std::string url : urls) {
					submit({ url, current.depth + 1 });
					//std::cout << "ADDR: " << url << std::endl << "DEP: " << current.depth + 1 << std::endl << std::endl;
				}
			}
			
			//передаем список слов в pqxx
		}
		else {
			std::this_thread::yield();
		}
		lockMutex.unlock();
	}
}