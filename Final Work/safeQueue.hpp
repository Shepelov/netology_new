#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

template<class T>
class SafeQueue {
public:
	void push(T entry) {
		std::unique_lock<std::mutex> lock_mtx(mtx);
		safe_queue.push(entry);
		notice.notify_one();
	};

	T pop() {
		std::unique_lock<std::mutex> lock_mtx(mtx);
		notice.wait(lock_mtx, [this]() { return !safe_queue.empty(); });
		T url = std::move(safe_queue.front());
		safe_queue.pop();
		return url;
	};

	bool empty() {
		std::unique_lock<std::mutex> lock_mtx(mtx);
		return safe_queue.empty();
	}

	int size() {
		return safe_queue.size();
	}

private:
	std::queue<T> safe_queue;
	std::mutex mtx;
	std::condition_variable notice;
};