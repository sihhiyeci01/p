module application;

application::application(cli::args args)
: flags(args.parse())
{}

int application::exec()
{
	return 0;
}