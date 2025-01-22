#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    isOnButtonAttachment = std::make_unique<ButtonAttachment>(p.apvts, "isON", isOnButton);
    
    isOnButton.setButtonText("ON");
    isOnButton.setClickingTogglesState(true);
    
    isOnButton.setColour(juce::TextButton::buttonColourId, juce::Colour(15, 30, 45));
    isOnButton.setColour(juce::TextButton::buttonOnColourId, juce::Colours::green);

    addAndMakeVisible(isOnButton);
    setSize (400, 300);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
    
}



//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.drawFittedText (titleString, getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    juce::Rectangle r(getWidth(), getHeight());
    
    isOnButton.setSize(100, 100);
    isOnButton.setCentrePosition(r.getCentre());
}
