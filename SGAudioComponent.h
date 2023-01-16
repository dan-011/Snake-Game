#ifndef SGAUDIOCOMPONENT_H
#define SGAUDIOCOMPONENT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

class SGAbstractAudioComponent {
public:
	virtual ~SGAbstractAudioComponent();
	virtual void Play();
	virtual void Stop();
	virtual void SetSongInstance(ALLEGRO_SAMPLE_INSTANCE* instance);

private:
	ALLEGRO_SAMPLE_INSTANCE* audioInstance;
};

class SGLoopedAudioComponent : public SGAbstractAudioComponent {
public:
	SGLoopedAudioComponent(const char* audioDir);
	virtual ~SGLoopedAudioComponent();

private:
	ALLEGRO_SAMPLE* sample; // might be able to delete these
};

class SGSinglePlayAudioComponent : public SGAbstractAudioComponent {
public:
	SGSinglePlayAudioComponent(const char* audioDir);
	virtual ~SGSinglePlayAudioComponent();

private:
	ALLEGRO_SAMPLE* sample;
};

#endif