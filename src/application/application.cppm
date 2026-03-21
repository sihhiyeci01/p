export module application;

export import application.cli;

export class application
{
	cli::flags flags{};
	
public:
	explicit application(cli::args);
	
	int exec();
};