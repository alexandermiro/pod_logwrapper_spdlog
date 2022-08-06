
#include "AudioMixer.h"
#include "log.h"

#include <iostream>


using namespace pod::common::log;

auto LOG = Log("main", kIsDefaultLogger);

int main() {
    // These calls are only needed if you want to modify the default LogConfig settings.
    //
    LOG.configFilename("output_file").init();

    LOG.trace("Starting the demo...");
    LOG.debug("The log configuration is: {}", LOG.getConfig());

    pod::audio::AudioMixer audioMixer;
    audioMixer.setCurrentAudio("baby_voice");

    int x = 10;
    LOG.info("value = {}", x);

    const std::string txt{R"(Power is of two kinds.
    One is obtained by the fear of punishment and the other by acts of love.
    Power based on love is a thousand times more effective and permanent then
    the one derived from fear of punishment.)"};

    LOG.debug("text {}", LOG.toHex(txt));

    LOG.trace("Time to go, bye!");
    return 0;
}
