#pragma once
#include <vector>
#include <thread>
#include <chrono>
#include "Safe_queue.h"

using namespace std::chrono_literals;

class Thread_pool {
public:
	Thread_pool(int cores);
	~Thread_pool();
	void work();
	void submit(std::vector<std::function<void()>> func_vector, int amount_of_submits);
private:
	std::mutex mtx;
	std::vector<std::thread> thread_vector;
	Safe_queue<std::function<void()>> safe_queue;
	bool submit_flag = false;
};