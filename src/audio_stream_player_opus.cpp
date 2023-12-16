#include "audio_stream_player_opus.h"

namespace godot {

int AudioStreamPlayerOpus::_mix_internal(AudioFrame *p_buffer, int p_frames) {
	if (!active) {
		return 0;
	}

	int todo = p_frames;
	int frames_mixed_this_step = p_frames;

	int beat_length_frames = -1;

}

void AudioStreamPlayerOpus::_bind_methods() {

}

void AudioStreamPlayerOpus::_ready() {

}

AudioStreamPlayerOpus::AudioStreamPlayerOpus() {}
AudioStreamPlayerOpus::~AudioStreamPlayerOpus() {}


// ----------------------------------------


AudioStreamOpus::AudioStreamOpus() {}
AudioStreamOpus::~AudioStreamOpus() {}

}
