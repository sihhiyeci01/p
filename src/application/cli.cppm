export module application.cli;

export namespace cli
{
	struct args
	{
		struct flags
		{
			bool help = false;
			bool debug = false;
		};
		
		args(int argc, char* const* argv) noexcept;
		flags parse() const;
		
	  private:
		int argc;
		char* const* argv;
	};
}