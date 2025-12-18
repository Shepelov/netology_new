#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>

#include "safeQueue.hpp"
#include "HtmlParser.h"
#include "DB.h"

using namespace std::chrono_literals;

struct URL {
	std::string address;
	int depth;
};

class ThreadPool {
public:
	ThreadPool(int cores, int depth, URL startUrl, DB Database);
	~ThreadPool();
	void work();
	void submit(URL url);
private:
	std::mutex mtx;
	std::vector<std::thread> thread_vector;
	SafeQueue<URL> safe_queue;
	int depth;
	DB& Database;
};