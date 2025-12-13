#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>

#include "safeQueue.hpp"
#include "HtmlParser.h"

using namespace std::chrono_literals;

struct URL {
	std::string address;
	int depth;
};

class ThreadPool {
public:
	ThreadPool(int cores, int depth);
	~ThreadPool();
	void work();
	void submit(URL url);
private:
	std::mutex mtx;
	std::vector<std::thread> thread_vector;
	SafeQueue<URL> safe_queue;
	bool submit_flag = false;
	int depth;
};