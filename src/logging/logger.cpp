module logging;

import <cstdio>;
import <format>;
import <string>;
import <system_error>;
import <cerrno>;

namespace
{
	constexpr const char* to_str(logging::level value)
	{
		switch (value)
		{
			case logging::level::info: return "INFO";
			case logging::level::debug: return "DEBUG";
			case logging::level::warn: return "WARN";
			case logging::level::error: return "ERROR";
			case logging::level::fatal: return "FATAL";
		}
		
		return nullptr;
	}

	std::string to_iso8601(std::chrono::system_clock::time_point tp)
	{
		return std::format(
			"{:%FT%T}Z", std::chrono::floor<std::chrono::milliseconds>(tp)
		);
	}
	
	std::string extract_function_name(std::string_view signature)
	{
		std::string_view::size_type paren = signature.find('(');
		if (paren != std::string_view::npos)
		{
			signature = signature.substr(0, paren);
		}
		
		std::string_view::size_type space = signature.rfind(' ');
		if (space != std::string_view::npos)
		{
			signature = signature.substr(space + 1);	
		}
		
		return std::string(signature);
	}
}

logging::logger::logger(std::filesystem::path path)
: sink(std::fopen(path.string().c_str(), "a"), std::fclose)
{
	if (sink == nullptr)
	{
		throw std::system_error(errno, std::generic_category(), path.string());
	}
}

logging::logger::~logger()
{
	std::fputs("\n", sink.get());
}

void
logging::logger::log(std::FILE* sink, logging::level lvl, std::string_view msg,
                     std::source_location loc,
                     std::chrono::system_clock::time_point tp)
{
	std::fprintf(
		sink, "%s [%s] [%s:%u] %s: %.*s\n",
		to_iso8601(tp).c_str(),
		to_str(lvl),
		loc.file_name(),
		loc.line(),
		extract_function_name(loc.function_name()).c_str(),
		static_cast<int>(msg.size()), msg.data()
	);
}

void
logging::logger::log(logging::level lvl, std::string_view msg,
                     std::source_location loc,
                     std::chrono::system_clock::time_point tp) const
{
	logging::logger::log(sink.get(), lvl, msg, loc, tp);
}