//
// Created by alexander tavares miro on 3/8/22.
//

#ifndef LOG_POD_LOGCONFIG_H
#define LOG_POD_LOGCONFIG_H

#include <string>
#include <vector>
#include <filesystem>

namespace pod::common::log {

namespace def {

enum class LogLevel : uint8_t {
      kTrace = 0
    , kDebug           /* 1 */
    , kInfo            /* 2 */
    , kWarn            /* 3 */
    , kError           /* 4 */
    , kCritical        /* 5 */
    , kTurnedOff       /* 6 */
};

constexpr auto kLogHeaderDefaultPattern = "[%Y-%m-%d %T.%e] [%t] [%n] [%l] %v";

using LoggerName = std::string;

} // namespace def

// Holds the static information about how to initialize a log module
//
struct LogConfig {

    struct ThreadInfo {
        size_t maxItemsInQueue{8192U};
        size_t maxNumThreads{2U};
    };

    struct BacktraceInfo {
        bool isEnabled{false};
        size_t max{100U};                  // maximum number of lines
    };

    struct FileInfo {
#ifndef TESTING
        bool isRotating{true};
#else
        bool isRotating{false};
#endif
        std::filesystem::path filePath{"/tmp"};
        std::string filename;
        size_t maxNumFiles{3U};
        size_t maxFileSize{1048576U * 5U}; // 5 Mb
    };

    // A driver has the same concept as spdlog's sinks
    struct DriverInfo {
        enum class Type : uint8_t { kConsole = 0, kFile, kPubSub };

        std::string headerPattern{def::kLogHeaderDefaultPattern};
        Type type;
        bool isEnabled{false};
    };

    struct LoggerInfo {
        def::LoggerName name;
        def::LogLevel level{def::LogLevel::kTrace};
    };

    std::vector<DriverInfo> drivers{ {.type = DriverInfo::Type::kConsole, .isEnabled = true}
                                   , {.type = DriverInfo::Type::kFile} };
    ThreadInfo thread;
    BacktraceInfo backtrace;
    FileInfo file;
    LoggerInfo logger;
};

} // namespace pod::common::log

template <typename OStream>
OStream& operator<<(OStream& os, const pod::common::log::LogConfig& config) {
    os << std::endl
       << "\tThreadInfo.maxItemsInQueue = " << config.thread.maxItemsInQueue << std::endl
       << "\tThreadInfo.maxNumThreads   = " << config.thread.maxNumThreads << std::endl
       << "\tBacktrace.isEnabled        = " << config.backtrace.isEnabled << std::endl
       << "\tBacktrace.max              = " << config.backtrace.max << std::endl
       << "\tFileInfo.isRotating        = " << config.file.isRotating << std::endl
       << "\tFileInfo.filePath          = " << config.file.filePath.string() << std::endl
       << "\tFileInfo.filename          = " << config.file.filename << std::endl
       << "\tFileInfo.maxNumFiles       = " << config.file.maxNumFiles << std::endl
       << "\tFileInfo.maxFileSize       = " << config.file.maxFileSize << std::endl
       << "\tLoggerInfo.name            = " << config.logger.name;
    return os;
}

#endif //LOG_POD_LOGCONFIG_H
