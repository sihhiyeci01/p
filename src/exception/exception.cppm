export module exception;

export import <exception>;

import logging;

import <stdexcept>;
import <iostream>;
import <cstdlib>;

constexpr const char* msg = "unknown type of exception";

export namespace exception
{	
	int handle(std::exception_ptr ptr)
	{
		try
		{
			std::rethrow_exception(ptr);
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what() << '\n';
		}
		catch (...)
		{
			std::cerr << msg << '\n';
		}
		
		return EXIT_FAILURE;
	}
	
	int handle(std::exception_ptr ptr, const logging::logger& logger)
	{
		try
		{
			std::rethrow_exception(ptr);
		}
		catch (const std::exception& ex)
		{
			logger.log(stderr, logging::level::fatal, ex.what());
		}
		catch (...)
		{
			logger.log(logging::level::fatal, msg);
		}
		
		return EXIT_FAILURE;
	}
};