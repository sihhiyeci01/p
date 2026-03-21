module logging.file;

import <system_error>;
import <cerrno>;

logging::file::file(std::filesystem::path path)
: handle(std::fopen(path.string().c_str(), "a"))
{
	if (handle == nullptr)
	{
		throw std::system_error(errno, std::generic_category(), path.string());
	}
}

logging::file::~file()
{
	if (handle != nullptr)
	{
		std::fclose(handle);
	}
}

int logging::file::print(const char* str) const noexcept
{
	return std::fputs(str, handle);
}