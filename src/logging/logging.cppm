export module logging;

export import <string_view>;
export import <source_location>;
export import <chrono>;

import <filesystem>;
import <memory>;
import <cstdio>;

export namespace logging
{	
	enum class level
	{
		debug,
		info,
		warn,
		error,
		fatal
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
		
		static void
		log(std::FILE*, level, std::string_view,
		    std::source_location loc = std::source_location::current(),
		    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now());
		
		void 
		log(level, std::string_view,
		    std::source_location loc = std::source_location::current(),
		    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now()) const;
	};
}