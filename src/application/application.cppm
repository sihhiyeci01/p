export module application;

export import application.cli;

export class application
{
	const cli::args::flags flags;
	
  public:
	explicit application(cli::args args);
	
	int exec();
};