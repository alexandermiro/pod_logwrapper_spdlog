#include "AudioMixer.h"
#include "Voice.h"
#include "log.h"


namespace pod::audio {

// auto LOG = Log();   /* uses the default logger name */
auto LOG = Log("audio_mixer");

void AudioMixer::setCurrentAudio(std::string_view name) {
    LOG.info("configuring current audio for [{}]", std::string{name.begin(), name.end()});
    Voice voice{name};
    voice.play();
    LOG.debug(HERE("macro to show function and line. {}"), "OKAY");
}

} // namespace pod::audio
