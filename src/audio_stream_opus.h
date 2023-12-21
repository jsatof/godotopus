#ifndef AUDIO_STREAM_OPUS_H
#define AUDIO_STREAM_OPUS_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/audio_frame.hpp>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/classes/audio_stream_playback_resampled.hpp>


#include <opus/opus.h>

namespace godot {

class AudioStreamOpus;

class AudioStreamPlaybackOpus : public AudioStreamPlaybackResampled {
	GDCLASS(AudioStreamPlaybackOpus, AudioStreamPlaybackResampled);

	friend class AudioStreamOpus;

	enum {
		FADE_SIZE = 256,
	};
	AudioFrame loop_fade[FADE_SIZE];
	int loop_fade_remaining = FADE_SIZE;

	int opus_error;
	int opus_size;
	OpusDecoder *decoder;

	Ref<AudioStreamOpus> opus_stream;
	
protected:
	int _mix_internal(AudioFrame *p_buffer, int p_frames);
	float get_stream_sampling_rate();
	static void _bind_methods();

public:
	void _ready();

	AudioStreamPlaybackOpus();
	~AudioStreamPlaybackOpus();
};


class AudioStreamOpus : public AudioStream {
	GDCLASS(AudioStreamOpus, AudioStream);

	friend class AudioStreamPlaybackOpus;

	PackedByteArray data;
	uint32_t data_length = 0;

	float sample_rate = 1.f;
	int channels = 2;
	float length = 0.f;
	bool loop = false;
	float loop_offset = 0.f;

	double bpm = 0.0;
	int beat_count = 0;
	int bar_beats = 4;

protected:
	static void _bind_methods();

public:
	void set_loop_offset(float p_seconds);
	float get_loop_offset() const;

	void set_loop(bool p_enable);
	bool has_loop() const;

	void set_bpm(double p_bpm);
	bool get_bpm() const;

	void set_beat_count(int p_beat_count);
	int get_beat_count() const;

	void set_bar_beats(int p_bar_beats);
	int get_bar_beats() const;

	Ref<AudioStreamPlayback> instantiate_playback();
	String get_stream_name() const;

	double get_length() const;
	bool is_monophonic() const;

	AudioStreamOpus();
	~AudioStreamOpus();
};

}

#endif
