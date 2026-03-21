module application;

import logging;
import exception;

application::application(cli::args args)
: flags(args.parse())
{}

int application::exec()
{
	logging::logger logger("pilot.log");
	logger.log(logging::entry("test"));
	
	try
	{
		throw "what happened?";
	}
	catch (...)
	{
		exception::handle(std::current_exception(), logger);
	}
	
	return 0;
}