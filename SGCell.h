#ifndef __SGCELL_H
#define __SGCELL_H

#include "SGVisualComponent.h"
#include "SGSupport.h"

class SGAbstractCell : public SGVisualComponent {
public:
	SGAbstractCell(int x, int y);
	virtual ~SGAbstractCell();
	/*int GetXPos() const;
	void SetXPos(int x);
	int GetYPos() const;
	void SetYPos(int y);*/
	virtual int Denomination() = 0;
	int GetRadius() const;
	virtual void SetColors(int r, int g, int b);
};

class SGEmptyCell : public SGAbstractCell {
public:
	SGEmptyCell(int x, int y);
	virtual ~SGEmptyCell();
	virtual void Draw() override;
	virtual int Denomination() override;
};

class SGAppleCell : public SGAbstractCell {
public:
	SGAppleCell(int x, int y);
	virtual ~SGAppleCell();
	virtual void Draw() override;
	virtual int Denomination() override; // make a subclass of cells that cause change which will be those that contain denomination
};

class SGSnakeCell : public SGAbstractCell {
public:
	SGSnakeCell(int x, int y, SGDirection dir = EAST);
	virtual ~SGSnakeCell();
	virtual void Draw() override;
	virtual int Denomination() override;
	SGDirection GetDirection() const;
	void SetDirection(SGDirection dir);
	virtual void SetColors(int r, int g, int b) override;

private:
	SGDirection direction; // default is east
	int red;
	int green;
	int blue;
};

#endif // !__SGCELL_H
