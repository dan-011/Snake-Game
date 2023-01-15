#ifndef __SGVISUALCOMPONENT_H
#define __SGVISUALCOMPONENT_H

#include <vector>
#include "allegro5/allegro.h"

class SGVisualComponent { // maybe subclass, may use sprite sheet or individual sprites
public:
	SGVisualComponent(int xPos, int yPos, double waitTime);
	virtual ~SGVisualComponent();
	virtual void Draw() = 0;
	double GetWaitingTime() const;
	int GetXPos() const;
	void SetXPos(int x);
	int GetYPos() const;
	void SetYPos(int y);
	double GetTime() const;
	void SetTime(double updatedTime);
	// maybe keep track of the coords?

protected:
	int xpos;
	int ypos;
	double waitingTime;
	double time;
};

class SGIndivSpriteComponent : public SGVisualComponent {
public:
	SGIndivSpriteComponent(int xPos, int yPos, double waitTime);
	virtual ~SGIndivSpriteComponent();
	virtual void Draw() override;
	void AddFrame(ALLEGRO_BITMAP* frame);

private:
	int index;
	std::vector<ALLEGRO_BITMAP*> frames;
};


/*class SGSheetComponent {

};*/
#endif // !__SGVISUALCOMPONENT_H
