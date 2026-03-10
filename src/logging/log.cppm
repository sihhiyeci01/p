export module logging.log;

export import <source_location>;
export import <string_view>;
export import <chrono>;

export namespace logging
{
	struct log
	{
		enum level
		{
			info,
			warn,
			debug,
			error,
			fatal
		};

		level lvl;
		std::string_view msg;
		std::source_location src;
		std::chrono::system_clock::time_point time;
	  
		log(level lvl, std::string_view msg, std::source_location src = std::source_location::current(), std::chrono::system_clock::time_point time = std::chrono::system_clock::now())
		: lvl(lvl)
		, msg(msg)
		, src(src)
		, time(time)
		{}
	};
}