#include "Thread_pool.h"

Thread_pool::Thread_pool(int cores) {
	for (int i = 0; i < cores; ++i) {
		thread_vector.push_back(std::thread(&Thread_pool::work, this));
	}
}

Thread_pool::~Thread_pool() {
	for (auto& thread : thread_vector) {
		thread.join();
	}
}

void Thread_pool::submit(std::vector<std::function<void()>> func_vector, int amount_of_submits) {
	for (int i = 0; i < amount_of_submits; ++i) {
		for (size_t j = 0; j < func_vector.size(); ++j) {
			safe_queue.push(func_vector.at(j));
		}
		std::this_thread::sleep_for(1s);
	}
	submit_flag = true;
}

void Thread_pool::work() {
	while (!submit_flag) {
		std::unique_lock<std::mutex> lockMutex(mtx);
		if (!safe_queue.empty()) {
			std::cout << "Thread id: " << std::this_thread::get_id() << "\t";
			safe_queue.front();
			safe_queue.pop();
		}
		else {
			std::this_thread::yield();
		}
		lockMutex.unlock();
	}
}