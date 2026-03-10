module logging.logger;

import <utility>;

logging::Logger::Logger(Config config) : config(std::move(config))
{}