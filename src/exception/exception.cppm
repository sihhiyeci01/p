export module exception;

export import <exception>;

import logging;

export namespace exception
{
	int handle(std::exception_ptr);
	int handle(std::exception_ptr, const logging::logger&);
}