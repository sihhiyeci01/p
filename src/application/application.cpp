module application;

import logging.logger;

application::application(cli::args args)
	: flags(args.parse())
{}

int application::exec()
{
	return 0;
}