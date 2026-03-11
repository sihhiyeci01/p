module application.cli;

import <string>;
import <string_view>;
import <stdexcept>;

cli::args::args(int argc, char* const* argv) noexcept
	: argc(argc)
	, argv(argv)
{}

cli::args::flags cli::args::parse() const
{
	flags f{  };
	for (int i{ 1 }; i < argc; ++i)
	{
		std::string_view arg{ argv[i] };
		if (arg == "--help")
		{
			f.help = true;
		}
		else if (arg == "--debug")
		{
			f.debug = true;
		}
		else
		{
			throw std::invalid_argument{ std::string{ arg } + ": command not recognized" };
		}
	}
	return f;
}