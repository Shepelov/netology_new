#pragma once
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

template<class T>
class Safe_queue {
public:
	void push(T func) {
		std::unique_lock<std::mutex> lock_mtx(mtx);
		safe_queue.push(func);
		notice.notify_one();
	};

	T pop() {
		std::unique_lock<std::mutex> lock_mtx(mtx);
		notice.wait(lock_mtx, [this]() { return !safe_queue.empty(); });
		T func = std::move(safe_queue.front());
		safe_queue.pop();
		return func;
	};

	bool empty() {
		std::unique_lock<std::mutex> lock_mtx(mtx);
		return safe_queue.empty();
	}

	void front() {
		std::unique_lock<std::mutex> lock_mtx(mtx);
		safe_queue.front()();
	};

private:
	std::queue<T> safe_queue;
	std::mutex mtx;
	std::condition_variable notice;
};