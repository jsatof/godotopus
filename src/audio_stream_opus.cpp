#include "audio_stream_opus.h"

namespace godot {

int AudioStreamPlaybackOpus::_mix_internal(AudioFrame *p_buffer, int p_frames) {

	return 0;
}

void AudioStreamPlaybackOpus::_bind_methods() {

}

float AudioStreamPlaybackOpus::get_stream_sampling_rate() {
	return 0.f;
}

void AudioStreamPlaybackOpus::_ready() {

}

AudioStreamPlaybackOpus::AudioStreamPlaybackOpus() {}
AudioStreamPlaybackOpus::~AudioStreamPlaybackOpus() {}


// ------------ AudioStreamOpus -------------


void AudioStreamOpus::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_loop_offset", "seconds"), &AudioStreamOpus::set_loop_offset);
	ClassDB::bind_method(D_METHOD("get_loop_offset"), &AudioStreamOpus::get_loop_offset);

	ClassDB::bind_method(D_METHOD("set_loop", "enable"), &AudioStreamOpus::set_loop);
	ClassDB::bind_method(D_METHOD("has_loop"), &AudioStreamOpus::has_loop);

	ClassDB::bind_method(D_METHOD("set_bpm", "bpm"), &AudioStreamOpus::set_bpm);
	ClassDB::bind_method(D_METHOD("get_bpm"), &AudioStreamOpus::get_bpm);

	ClassDB::bind_method(D_METHOD("set_beat_count", "count"), &AudioStreamOpus::set_beat_count);
	ClassDB::bind_method(D_METHOD("get_beat_count"), &AudioStreamOpus::get_beat_count);

	ClassDB::bind_method(D_METHOD("set_bar_beats", "count"), &AudioStreamOpus::set_bar_beats);
	ClassDB::bind_method(D_METHOD("get_bar_beats"), &AudioStreamOpus::get_bar_beats);

	// missing: get_packet_sequence
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "bpm", PROPERTY_HINT_RANGE, "0,400,0.01,or_greater"), "set_bpm", "get_bpm");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "beat_count", PROPERTY_HINT_RANGE, "0,512,1,or_greater"), "set_beat_count", "get_beat_count");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "bar_beats", PROPERTY_HINT_RANGE, "2,32,1,or_greater"), "set_bar_beats", "get_bar_beats");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "loop"), "set_loop", "has_loop");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "loop_offset"), "set_loop_offset", "get_loop_offset");
}

void AudioStreamOpus::set_loop_offset(float p_seconds) {

}

float AudioStreamOpus::get_loop_offset() const {
	return 0.f;
}

void AudioStreamOpus::set_loop(bool p_enable) {

}

bool AudioStreamOpus::has_loop() const {
	return false;
}

void AudioStreamOpus::set_bpm(double p_bpm) {

}

bool AudioStreamOpus::get_bpm() const {
	return false;
}

void AudioStreamOpus::set_beat_count(int p_beat_count) {

}

int AudioStreamOpus::get_beat_count() const {
	return 0;
}

void AudioStreamOpus::set_bar_beats(int p_bar_beats) {

}

int AudioStreamOpus::get_bar_beats() const {
	return 0;
}

Ref<AudioStreamPlayback> AudioStreamOpus::instantiate_playback() {
	return nullptr;
}

String AudioStreamOpus::get_stream_name() const {
	return "test";
}

double AudioStreamOpus::get_length() const {
	return 0.0;
}

bool AudioStreamOpus::is_monophonic() const {
	return false;
}

AudioStreamOpus::AudioStreamOpus() {}
AudioStreamOpus::~AudioStreamOpus() {}

}
