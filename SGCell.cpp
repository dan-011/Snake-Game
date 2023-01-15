#include "SGCell.h"
#include <allegro5/allegro_primitives.h>

SGAbstractCell::SGAbstractCell(int x, int y) : SGVisualComponent(x, y, .12) {}
SGAbstractCell::~SGAbstractCell() {}
int SGAbstractCell::GetRadius() const {
	return 30;
}
void SGAbstractCell::SetColors(int r, int g, int b) {}

SGAppleCell::SGAppleCell(int x, int y) : SGAbstractCell(x, y) {}
SGAppleCell::~SGAppleCell() {}
void SGAppleCell::Draw() {
	int rad = GetRadius() / 2;
	int cx = GetXPos() + rad;
	int cy = GetYPos() + rad;
	al_draw_filled_circle(cx, cy, rad, al_map_rgb(255, 0, 0));
	al_draw_circle(cx, cy, rad, al_map_rgb(0, 0, 0), 2);
}
int SGAppleCell::Denomination() {
	return 1;
}

SGEmptyCell::SGEmptyCell(int x, int y) : SGAbstractCell(x, y) {}
SGEmptyCell::~SGEmptyCell() {}
void SGEmptyCell::Draw() {
	int xS = GetXPos();
	int yS = GetYPos();
	int xE = xS + GetRadius();
	int yE = yS + GetRadius();
	al_draw_filled_rectangle(xS, yS, xE, yE, al_map_rgb(0, 0, 255));
	al_draw_rectangle(xS, yS, xE, yE, al_map_rgb(0, 0, 0), 2);
}
int SGEmptyCell::Denomination() {
	return 0;
}

SGSnakeCell::SGSnakeCell(int x, int y, SGDirection dir) : SGAbstractCell(x, y), direction(dir), red(0), green(255), blue(0) {}
SGSnakeCell::~SGSnakeCell() {}
void SGSnakeCell::Draw() {
	int xS = GetXPos();
	int yS = GetYPos();
	int xE = xS + GetRadius();
	int yE = yS + GetRadius();
	al_draw_filled_rectangle(xS, yS, xE, yE, al_map_rgb(red, green, blue));
}
int SGSnakeCell::Denomination(){
	return 0;
}
SGDirection SGSnakeCell::GetDirection() const {
	return direction;
}
void SGSnakeCell::SetDirection(SGDirection dir) {
	direction = dir;
}
void SGSnakeCell::SetColors(int r, int g, int b) {
	red = r;
	green = g;
	blue = b;
}