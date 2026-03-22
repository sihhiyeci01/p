module application;

import logging;
import exception;

application::application(cli::args args)
: flags(args.parse())
{}

int application::exec()
{
	logging::logger logger("logs/pilot.log");
	
	try
	{
		// incomplete
	}
	catch (...)
	{
		exception::handle(std::current_exception(), logger);
	}
	
	return 0;
}