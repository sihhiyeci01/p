module exception;

import <stdexcept>;
import <cstdlib>;

constexpr const char* msg = "unknown type of exception";

namespace exception
{
	int handle(std::exception_ptr ptr)
	{
		try
		{
			std::rethrow_exception(ptr);
		}
		catch (const std::exception& ex)
		{
			logging::logger::log(stderr, logging::level::fatal, ex.what());
		}
		catch (...)
		{
			logging::logger::log(stderr, logging::level::fatal, msg);
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
			logger.log(logging::level::fatal, ex.what());
		}
		catch (...)
		{
			logger.log(logging::level::fatal, msg);
		}
		return EXIT_FAILURE;
	}
}