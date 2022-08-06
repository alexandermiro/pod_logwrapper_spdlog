//
// Created by alexander tavares miro on 3/8/22.
//

#ifndef LOG_POD_AUDIOMIXER_H
#define LOG_POD_AUDIOMIXER_H

#include <string_view>

namespace pod::audio {
class AudioMixer {
public:
    enum class Action { kStart = 0, kPause, kResume, kStop};
    void setCurrentAudio(std::string_view name);
};
} // namespace pod::audio
#endif //LOG_POD_AUDIOMIXER_H
