#include "threadPool.h"

ThreadPool::ThreadPool(int cores, int depth) {
	this->depth = depth;
	do {
		for (int i = 0; i < cores; ++i) {
			thread_vector.push_back(std::thread(&ThreadPool::work, this));
		}
	} while (!safe_queue.empty());
	
}

ThreadPool::~ThreadPool() {
	for (auto& thread : thread_vector) {
		thread.join();
	}
}

void ThreadPool::submit(URL url) {
		safe_queue.push(url);
		//std::this_thread::sleep_for(50ms);	//временно!
	submit_flag = true;
}

void ThreadPool::work() {
	int cnt{ 0 };
	while (!submit_flag) {
		std::unique_lock<std::mutex> lockMutex(mtx);
		if (!safe_queue.empty()) {
			URL current = safe_queue.pop();
			HtmlParser parser(current.address);
			std::vector<std::string> urls = parser.getUrlsList();
			if (parser.isRedirect()) {
				submit({urls[0], current.depth});
				cnt++;
				std::cout << cnt << " ADDR REDIR: " << urls[0] << std::endl << "DEP: " << current.depth << std::endl << std::endl;
			}
			else if (current.depth < this->depth) {
				for (std::string url : urls) {
					submit({ url, current.depth + 1 });
					cnt++;
					std::cout << cnt << "CURR: " << current.address << std::endl << " ADDR: " << url << std::endl << "DEP: " << current.depth + 1 << std::endl << std::endl;
				}
			}
			
			//передаем список слов в pqxx - доделать
		}
		else {
			std::this_thread::yield();
		}
		lockMutex.unlock();
	}
}