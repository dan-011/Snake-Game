#ifndef __SGTEXTCOMPONENT_H
#define __SGTEXTCOMPONENT_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "SGVisualComponent.h"
#include <string>

class SGTextComponent : public SGVisualComponent {
public:
	SGTextComponent(int x, int y, int sz, const char* fontDir, ALLEGRO_COLOR clr, const char* txt);
	virtual ~SGTextComponent();
	virtual void Draw() override;
	std::string GetText() const;

	template <class T>
	void SetText(const T txt);
	int GetSize() const;
	void SetSize(int sz);
	void SetColor(ALLEGRO_COLOR clr);
	void SetFont(char* fontDir);

private:
	ALLEGRO_FONT* font;
	ALLEGRO_COLOR color;
	int size;
	char text[128];

};

#endif