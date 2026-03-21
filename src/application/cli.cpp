module application.cli;

import <string>;
import <string_view>;
import <stdexcept>;

cli::args::args(int argc, char* const* argv) noexcept
: argc(argc)
, argv(argv)
{}

cli::flags cli::args::parse() const
{
	cli::flags result{};
	for (int i = 1; i < argc; ++i)
	{
		std::string_view arg = argv[i];
		if (arg == "--help")
		{
			result.help = true;
		}
		else if (arg == "--debug")
		{
			result.debug = true;
		}
		else
		{
			throw std::invalid_argument{ std::string(arg) + ": unrecognized argument" };
		}
	}
	return result;
}