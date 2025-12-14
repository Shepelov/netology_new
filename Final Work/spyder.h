#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <string>

#include "safeQueue.hpp"
#include "threadPool.h"

class Spyder
{
private:

public:
	Spyder(std::string startPage, int depth);
	~Spyder();
};

