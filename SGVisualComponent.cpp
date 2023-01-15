#include "SGVisualComponent.h"


SGVisualComponent::SGVisualComponent(int xPos, int yPos, double waitTime) : xpos(xPos), ypos(yPos), waitingTime(waitTime), time(0) {}
SGVisualComponent::~SGVisualComponent() {}
double SGVisualComponent::GetWaitingTime() const {
	return waitingTime;
}
int SGVisualComponent::GetXPos() const {
	return xpos;
}
void SGVisualComponent::SetXPos(int x) {
	xpos = x;
}
int SGVisualComponent::GetYPos() const {
	return ypos;
}
void SGVisualComponent::SetYPos(int y) {
	ypos = y;
}
double SGVisualComponent::GetTime() const {
	return time;
}
void SGVisualComponent::SetTime(double updatedTime) {
	time = updatedTime;
}

SGIndivSpriteComponent::SGIndivSpriteComponent(int xPos, int yPos, double waitTime) : SGVisualComponent(xPos, yPos, waitTime), index(0) {}
SGIndivSpriteComponent::~SGIndivSpriteComponent() {
	for (int i = 0; i < frames.size(); i++) {
		al_destroy_bitmap(frames.at(i));
	}
}
#include <iostream>

void SGIndivSpriteComponent::Draw() {
	if (al_get_time() - GetTime() > GetWaitingTime()) {
		//std::cout << al_get_time() << " : " << GetTime() << " : " << al_get_time() - GetTime() << " : ";
		index++;
		if (index >= frames.size()) {
			index = 0;
		}
		SetTime(al_get_time());
		//std::cout << GetTime() << std::endl;
	}
	ALLEGRO_BITMAP* frame = frames.at(index);
	if (frame != NULL) {
		al_draw_bitmap(frame, GetXPos(), GetYPos(), 0);
	}
}
void SGIndivSpriteComponent::AddFrame(ALLEGRO_BITMAP* frame) {
	frames.push_back(frame);
}