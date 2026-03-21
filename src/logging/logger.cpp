module logging;

import <cstdio>;
import <format>;
import <string>;
import <system_error>;
import <cerrno>;

namespace
{
	constexpr const char* to_str(logging::level val)
	{
		switch (val)
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
		return std::format("{:%FT%T}Z", std::chrono::floor<std::chrono::milliseconds>(tp));
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

void logging::logger::log(const logging::entry& data) const
{
	std::fprintf(
		sink.get(), "%s [%s] [%s:%u] %s: %s\n",
		to_iso8601(data.time).c_str(),
		to_str(data.lvl),
		data.loc.file_name(),
		data.loc.line(),
		data.loc.function_name().c_str(),
		data.content.c_str()
	);
}