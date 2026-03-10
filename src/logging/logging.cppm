export module logging.logger;

export import logging.log;

export namespace logging
{
	class Logger
	{
	  public:
		enum class Sink
		{
			File,
			Console,
			Both
		};
		
		enum class Mode
		{
			Debug,
			Release
		};
		
		struct Config
		{
			Sink sink;
			Mode mode;
		};
		
		explicit Logger(Config);
		
	  private:
		Config config;
	};
}