#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <RTNeural/RTNeural.h>

// the loaded model process floats, has 1 input and 1 output. 
// The network has one LSTM layer with 1 input and 32 lstm internal units and 1 dense layer.
using RTLSTMModel32 = RTNeural::ModelT<float, 
                                       1, 
                                       1, 
                                       RTNeural::LSTMLayerT<float, 1, 32>, 
                                       RTNeural::DenseT<float, 32, 1>>;


//==============================================================================
class AudioPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    AudioPluginAudioProcessor();
    ~AudioPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    using AudioProcessor::processBlock;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    RTLSTMModel32 lstmModel; 
    void setupModel(RTLSTMModel32& model, std::string jsonFile);

    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessor)
};
