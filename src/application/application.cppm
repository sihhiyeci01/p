export module application;

export import application.cli;

export class application
{
	cli::args::flags flags;
	
  public:
	explicit application(cli::args);
	int exec();
};