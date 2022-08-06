
#include "AudioMixer.h"
#include "log.h"

using namespace pod::common::log;

auto LOG = Log("main", kIsDefaultLogger);

int main() {
    // The next call is only needed because I deliberately wanted to modify
    // one of the default settings of LogConfig.
    LOG.configFilename("output_file").init();

    LOG.trace("Starting the demo...");
    LOG.debug("The log configuration is: {}", LOG.getConfig());

    pod::audio::AudioMixer audioMixer;
    audioMixer.setCurrentAudio("baby_voice");

    int x = 10;
    LOG.info("value = {}", x);

    const std::string quote{R"(Power is of two kinds.
One is obtained by the fear of punishment and the other by acts of love.
Power based on love is a thousand times more effective and permanent then
the one derived from fear of punishment.)"};

    LOG.debug("Quote:\n{}\nIn binary: {}", quote, LOG.toHex(quote));

    LOG.trace("Time to go, bye!");
    return 0;
}
