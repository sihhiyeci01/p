export module logging.file;

export import <cstdio>;

export namespace logging
{
	class file
	{
		std::FILE* handle = nullptr;
		
	public:
		file(const char* path, const char* mode);
		
		~file() noexcept;
		
		file(const file&) = delete;
		file& operator=(const file&) = delete;
		
		file(file&& other) noexcept; 
		file& operator=(file&& other) noexcept;
		
		explicit operator bool() const noexcept
		{
			return handle;
		}
	};
}