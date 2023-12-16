#ifndef AUDIO_STREAM_PLAYER_OPUS_H
#define AUDIO_STREAM_PLAYER_OPUS_H

#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/audio_frame.hpp>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>

#include <memory>
#include <mutex>
#include <opus/opus.h>

namespace godot {

class AudioStreamOpus;

class AudioStreamPlayerOpus : public AudioStreamPlayer {
	GDCLASS(AudioStreamPlayerOpus, AudioStreamPlayer);

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
	virtual float get_stream_sampling_rate() override;
	virtual int _mix_internal(AudioFrame *p_buffer, int p_frames) override;

public:
	void _ready();

	AudioStreamPlayerOpus();
	~AudioStreamPlayerOpus();
};


class AudioStreamOpus : public AudioStream {
	GDCLASS(AudioStreamOpus, AudioStream);
	OBJ_SAVE_TYPE(AudioStream);
	RES_BASE_EXTENSION("opusstr");

	friend class AudioStreamPlayerOpus;

	PackedByteArry data;
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
	void set_loop(bool p_enable);
	virtual bool has_loop() const override;

	void set_bpm(double p_bpm);
	virtual bool get_bpm() const override;

	void set_beat_count(int p_beat_count);
	virtual int get_beat_count() const override;

	void set_bar_beats(int p_bar_beats);
	virtual int get_bar_beats() const override;

	virtual Ref<AudioStreamPlayback> instantiate_playback() override;
	virtual String get_stream_name() const override;

	void set_data(const Vector<uint8_t> &p_data);
	Vector<uint8_t> get_data() const;

	virtual double get_length() const override;
	virtual bool is_monophonic() const override;

	AudioStreamOpus();
	virtual ~AudioStreamOpus();
};

}
#endif
