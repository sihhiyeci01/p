import application;
import application.cli;
import exception;

int main(int argc, char* const* argv)
{
	try
	{
		return application{ cli::args(argc, argv) }.exec();
	}
	catch (...)
	{
		return exception::handle(std::current_exception());
	}
}