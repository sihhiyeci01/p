export module logging;

export import logging.source_location;

export import <string>;
export import <chrono>;

import <filesystem>;
import <memory>;
import <cstdio>;

export namespace logging
{	
	enum class level
	{
		info,
		debug,
		warn,
		error,
		fatal
	};
	
	struct entry
	{
		std::string content;
		level lvl;
		source_location loc;
		std::chrono::system_clock::time_point time;
		
		entry(std::string str,
		      level lvl = level::info,
		      source_location loc = std::source_location::current(),
		      std::chrono::system_clock::time_point tp = std::chrono::system_clock::now())
		: content(std::move(str))
		, lvl(lvl)
		, loc(loc)
		, time(tp)
		{}
	};
	
	class logger
	{
		std::unique_ptr<std::FILE, decltype(&std::fclose)> sink;
		
	public:
		logger(std::filesystem::path);
		
		~logger();
		
		logger(const logger&) = delete;
		logger& operator=(const logger&) = delete;
		
		logger(logger&&) = delete;
		logger& operator=(logger&&) = delete;
		
		void log(const entry&) const;
	};
}