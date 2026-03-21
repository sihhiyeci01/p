export module logging.source_location;

export import <source_location>;

import <string>;
import <string_view>;
import <cstdint>;

export namespace logging
{
	class source_location
	{
		std::source_location src;
		
	public:
		source_location() = default;
	
		source_location(std::source_location loc) noexcept
		: src(loc)
		{}
		
		std::string function_name() const
		{
			std::string_view sv = src.function_name();
			
			auto paren = sv.find('(');
			if (paren != std::string_view::npos)
			{
				sv = sv.substr(0, paren);
			}
			
			auto space = sv.rfind(' ');
			if (space != std::string_view::npos)
			{
				sv = sv.substr(space + 1);	
			}
			
			return std::string(sv);
		}
		
		const char* file_name() const noexcept
		{
			return src.file_name();
		}
		
		std::uint_least32_t line() const noexcept
		{
			return src.line();
		}
		
		std::uint_least32_t column() const noexcept
		{
			return src.column();
		}
	};
}