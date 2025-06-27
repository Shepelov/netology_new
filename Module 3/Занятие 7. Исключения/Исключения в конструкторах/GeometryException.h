#ifndef GEOMETRYEXCEPTION_H
#define GEOMETRYEXCEPTION_H

#include <exception>
#include <string>

class GeometryException : public std::exception{
public:
	std::string message;

	GeometryException(std::string message) : message(message) {};
	const char* what() const override {
		return message.c_str();
	}
};

#endif