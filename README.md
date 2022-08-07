# pod_logwrapper_spdlog
This is a wrapper for the spdlog log library that I've created just for fun.

I tried to use a modern approach instead of MACROS (however, as you can see, some information like function name and line number is only possible with macros).


## Output from the current main.cpp 
```
[2022-08-07 11:45:09.828] [38803] [main] [trace] Starting the demo...
[2022-08-07 11:45:09.828] [38803] [main] [debug] The log configuration is: 
	ThreadInfo.maxItemsInQueue = 8192
	ThreadInfo.maxNumThreads   = 2
	Backtrace.isEnabled        = 0
	Backtrace.max              = 100
	FileInfo.isRotating        = 1
	FileInfo.filePath          = /tmp
	FileInfo.filename          = output_file.log
	FileInfo.maxNumFiles       = 3
	FileInfo.maxFileSize       = 5242880
	LoggerInfo.name            = main
[2022-08-07 11:45:09.828] [38803] [audio_mixer] [info] configuring current audio for [baby_voice]
[2022-08-07 11:45:09.828] [38803] [Voice] [info] [Voice.h:15] Loading voice baby_voice
[2022-08-07 11:45:09.828] [38803] [Voice] [info] play
[2022-08-07 11:45:09.828] [38803] [audio_mixer] [debug] [AudioMixer.cpp:15] macro to show function and line. OKAY
[2022-08-07 11:45:09.828] [38803] [Voice] [info] Unloading voice baby_voice
[2022-08-07 11:45:09.828] [38803] [main] [info] value = 10
[2022-08-07 11:45:09.828] [38803] [main] [debug] Quote:
Power is of two kinds.
One is obtained by the fear of punishment and the other by acts of love.
Power based on love is a thousand times more effective and permanent then
the one derived from fear of punishment.
In binary: 
0000: 50 6f 77 65 72 20 69 73 20 6f 66 20 74 77 6f 20 6b 69 6e 64 73 2e 0a 4f 6e 65 20 69 73 20 6f 62
0020: 74 61 69 6e 65 64 20 62 79 20 74 68 65 20 66 65 61 72 20 6f 66 20 70 75 6e 69 73 68 6d 65 6e 74
0040: 20 61 6e 64 20 74 68 65 20 6f 74 68 65 72 20 62 79 20 61 63 74 73 20 6f 66 20 6c 6f 76 65 2e 0a
0060: 50 6f 77 65 72 20 62 61 73 65 64 20 6f 6e 20 6c 6f 76 65 20 69 73 20 61 20 74 68 6f 75 73 61 6e
0080: 64 20 74 69 6d 65 73 20 6d 6f 72 65 20 65 66 66 65 63 74 69 76 65 20 61 6e 64 20 70 65 72 6d 61
00A0: 6e 65 6e 74 20 74 68 65 6e 0a 74 68 65 20 6f 6e 65 20 64 65 72 69 76 65 64 20 66 72 6f 6d 20 66
00C0: 65 61 72 20 6f 66 20 70 75 6e 69 73 68 6d 65 6e 74 2e
[2022-08-07 11:45:09.828] [38803] [main] [trace] Time to go, bye!
```
