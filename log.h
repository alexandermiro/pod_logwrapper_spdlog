//
// Created by alexander tavares miro on 3/8/22.
//

#ifndef LOG_POD_LOG_H
#define LOG_POD_LOG_H

#include "LogConfig.h"
#include "LogManager.h"

using namespace pod::common::log;


class Log {
public:
    explicit Log(const std::string& moduleName = "", bool isDefault = !kIsDefaultLogger)
        : name_{moduleName}
        , isDefault_{isDefault} {
    }

    LogConfig& getConfig() {
        return LogManager::getConfig();
    }
    /**
     * Changes the output file name. This function must be called before
     * @param filename
     */
    Log& configFilename(const std::string& filename) {
        auto& config = LogManager::getConfig();
        config.file.filename = filename;
        return *this;
    }

    Log& configBacktrace(size_t max = 0U) {
        auto& config = LogManager::getConfig();
        config.backtrace.isEnabled = true;
        if (max > 0) {
            config.backtrace.max = max;
        }
        return *this;
    }

    Log& configThreadPool(size_t maxQueue = 0U, size_t maxThreads = 0U) {
        auto& config = LogManager::getConfig();
        config.thread.maxItemsInQueue = maxQueue > 0U ? maxQueue :  config.thread.maxItemsInQueue;
        config.thread.maxNumThreads = maxThreads > 0U ? maxThreads : config.thread.maxNumThreads;
        return *this;
    }

    void init() { LogManager::init(name_, isDefault_); }

    template <typename... Args>
    void trace(Args... args) { LogManager::getLogger(name_).trace(std::forward<Args>(args)...); }

    template <typename... Args>
    void info(Args... args) { LogManager::getLogger(name_).info(std::forward<Args>(args)...); }

    template <typename... Args>
    void debug(Args... args) { LogManager::getLogger(name_).debug(std::forward<Args>(args)...); }

    template <typename... Args>
    void warn(Args... args) { LogManager::getLogger(name_).warn(std::forward<Args>(args)...); }

    template <typename... Args>
    void error(Args... args) { LogManager::getLogger(name_).error(std::forward<Args>(args)...); }

    template <typename... Args>
    void fatal(Args... args) { LogManager::getLogger(name_).fatal(std::forward<Args>(args)...); }

    template <typename T>
    auto toHex(const T& buf) {
        return LogManager::getLogger(name_).hex(buf);
    }

private:
    const std::string name_;
    const bool isDefault_;
};

#define HERE(MessagePattern) "[{}:{}] " MessagePattern, __FILE_NAME__, __LINE__


#endif //LOG_POD_LOG_H
