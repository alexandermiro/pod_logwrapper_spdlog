#ifndef LOG_POD_VOICE_H
#define LOG_POD_VOICE_H

#include "log.h"

#include <string_view>

class Voice {

public:
    explicit Voice(std::string_view voiceName) : name_{voiceName} {

        // Not necessary to call Log::init() beforehand because the very
        // first call to a post function will try to create a logger for this instance.
        LOG.info(HERE("Loading voice {}"), name_);
    }

    ~Voice() {
        LOG.info("Unloading voice {}", name_);
    }

    void play() {
        LOG.info("play");
    }

    inline static auto LOG = Log("Voice");
    const std::string name_;
};


#endif //log_pod_voice_h
