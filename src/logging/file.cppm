export module logging.file;

import <filesystem>;
import <cstdio>;

export namespace logging
{
	class file
	{
		std::FILE* handle;
		
	public:
		file(std::filesystem::path);
		
		~file();
		
		file(const file&) = delete;
		file& operator=(const file&) = delete;
		
		file(file&&) = delete;
		file& operator=(file&&) = delete;
		
		int print(const char*) const noexcept;
	};
}