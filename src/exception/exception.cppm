export module exception;

export import <exception>;

import <stdexcept>;
import <iostream>;

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
			std::cerr << "app.exe: error: " << ex.what() << '\n';
		}
		catch (...)
		{
			std::cerr << "app.exe: error: unknown exception" << '\n';
		}
		
		return EXIT_FAILURE;
	}
}