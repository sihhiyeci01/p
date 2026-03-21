export module application.cli;

export namespace cli
{
	struct flags
	{
		bool help = false;
		bool debug = false;
	};
	
	struct args
	{
		args(int, char* const*) noexcept;
		
		flags parse() const;
		
	private:
		int argc;
		char* const* argv;
	};
}