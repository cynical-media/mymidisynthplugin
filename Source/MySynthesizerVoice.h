#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "MySynthesizerSound.h"
#include "Oscillator.h"

class MySynthesizerVoice : public SynthesiserVoice {
public:
	MySynthesizerVoice();
	~MySynthesizerVoice();

	bool canPlaySound(SynthesiserSound*) override;

	void startNote(int midiNoteNumber,
		float velocity,
		SynthesiserSound* sound,
		int currentPitchWheelPosition) override;

	void stopNote(float velocity, bool allowTailOff) override;

	void renderNextBlock(AudioBuffer<double>& outputBuffer,
		int startSample,
		int numSamples) override;

	//void renderNextBlock(AudioBuffer<float>& outputBuffer,
	//	int startSample,
	//	int numSamples) override;
	Oscillator osc1;
	Oscillator osc2;
	double oscVolumesMix;
	ADSR arEnv;
	void pitchWheelMoved(int newPitchWheelValue) override;
	void controllerMoved(int controllerNumber, int newControllerValue) override;

	//bool isVoiceActive() const;
	//void aftertouchChanged(int newAftertouchValue);
	//void channelPressureChanged(int newChannelPressureValue) override;
	//bool isPlayingChannel(int midiChannel) const;
private:
};
