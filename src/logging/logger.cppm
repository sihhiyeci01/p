export module logging.logger;

export import logging.file;
export import logging.log;

export namespace logging
{	
	class logger
	{
	public:
		enum class sink
		{
			file,
			console
		};
	  
		enum class mode
		{
			debug,
			release
		};
	  
		struct config
		{
			sink sink;
			mode mode;
			file file;
		};
		
	private:
		config config;
	};
}