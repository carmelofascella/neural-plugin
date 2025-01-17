# Neural Plugin - RTNeural

This audio plugin processes the incoming audio signal through a neural network. I created it to use it as a neural plugin template. <br>
This project is built with [CMake](https://cmake.org/), and it uses [CPM](https://github.com/cpm-cmake/CPM.cmake) as a dependancy manager to add and configure the external dependencies JUCE and RTNeural.<br>

[JUCE](https://github.com/juce-framework/JUCE) is an open-source cross-platform C++ framework to create mainly audio plug-ins. <br>
[RTNeural](https://github.com/jatinchowdhury18/RTNeural) is a library written in C++ able to load a pre-trained neural network and run inferences, designed specifically for real-time audio processing. <br>

### Building with CMake.

Run the following commands on terminal:

```
cmake -S . -B build

cmake --build build --config Debug
```

Then you will find the plugin in format AU, VST3 and Standalone in `build/src/plugin/neural-plugin_artefacts/Debug/`

### Load neural network weights

RTNeural can load neural network weights saved in a `.json` file.<br>
The absolute path of the file is saved into `jsonPath` in the file `PluginProcesser.cpp`.

The network architecture in this project has 1 input, one LSTM layer with 1 input and 32 internal units, one dense later and 1 output.

### References

The main reference for this project is the book "Build AI-Enhanced Audio Plugins with C++" by Matthew John Yee-King.

Book: http://www.yeeking.net/book/

Code: https://github.com/yeeking/ai-enhanced-audio-book
