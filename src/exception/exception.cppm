export module exception;

export import <exception>;

import logging;

import <stdexcept>;
import <iostream>;
import <cstdlib>;

using namespace logging;

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
	
	int handle(std::exception_ptr ptr, const logger& logger)
	{
		try
		{
			std::rethrow_exception(ptr);
		}
		catch (const std::exception& ex)
		{
			logger.log(entry{ ex.what(), level::fatal });
		}
		catch (...)
		{
			logger.log(entry{ msg, level::fatal });
		}
		
		return EXIT_FAILURE;
	}
};