#include "SGTextComponent.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

SGTextComponent::SGTextComponent(int x, int y, int sz, const char* fontDir, ALLEGRO_COLOR clr, const char* txt) : SGVisualComponent(x, y, .12), size(sz), color(clr) {
	font = al_load_ttf_font(fontDir, size, 0);
	SetText(txt);
}
SGTextComponent::~SGTextComponent() {
	al_destroy_font(font);
}
void SGTextComponent::Draw() {
	al_draw_text(font, color, GetXPos(), GetYPos(), 0, text);
}
std::string SGTextComponent::GetText() const {
	return text;
}

template <class T>
void SGTextComponent::SetText(const T txt) {
	int index = 0;
	while (txt[index] != '\0') {
		text[index] = txt[index];
		index++;
	}
	text[index] = '\0';
}

int SGTextComponent::GetSize() const {
	return size;
}
void SGTextComponent::SetSize(int sz) {
	size = sz;
	// al_destroy_font(font);
	// font = al_load_ttf_font(fileDir, size, 0);
}
void SGTextComponent::SetColor(ALLEGRO_COLOR clr) {
	color = clr;
}
void SGTextComponent::SetFont(char* fontDir) {
	al_destroy_font(font);
	font = al_load_ttf_font(fontDir, size, 0);
}