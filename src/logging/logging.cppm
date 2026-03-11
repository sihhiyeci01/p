export module logging.logger;

export import logging.log;


export namespace logging
{
	class file
	{
		std::FILE* handle;
		
	public:
		file() = default;
		file(const char* path, const char* mode);
	};
	
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
		};
		
	private:
		config config;
	};
}