#include "SGAudioComponent.h"

SGAbstractAudioComponent::~SGAbstractAudioComponent() {
	al_destroy_sample_instance(audioInstance);
}
void SGAbstractAudioComponent::Play() {
	al_play_sample_instance(audioInstance);
}
void SGAbstractAudioComponent::Stop() {
	al_stop_sample_instance(audioInstance);
}
void SGAbstractAudioComponent::SetSongInstance(ALLEGRO_SAMPLE_INSTANCE* instance) {
	audioInstance = instance;
}

SGLoopedAudioComponent::SGLoopedAudioComponent(const char* audioDir) {
	sample = al_load_sample(audioDir);
	ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(sample);
	al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
}
SGLoopedAudioComponent::~SGLoopedAudioComponent() {
	al_destroy_sample(sample);
}

SGSinglePlayAudioComponent::SGSinglePlayAudioComponent(const char* audioDir) {
	sample = al_load_sample(audioDir);
	ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(sample);
	al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
}
SGSinglePlayAudioComponent::~SGSinglePlayAudioComponent() {
	al_destroy_sample(sample);
}