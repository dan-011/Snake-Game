#ifndef __SGMODEL_H
#define __SGMODEL_H

#include "SGVisualComponent.h"
#include "SGCell.h"
#include <vector>

class SGAbstractModel {
public:
	virtual ~SGAbstractModel();
	SGVisualComponent* GetVisualComponentAt(int index);
	void AddVisualComponent(SGVisualComponent* component);
	int GetNumComponents() const;
	virtual double GetTickTime() const;
	virtual void SetTickTime(double time);

private:
	std::vector<SGVisualComponent*> visualComponents;
};

class SGStartupModel : public SGAbstractModel {
public:
	SGStartupModel();
	virtual ~SGStartupModel();

};

class SGFirstGameModel : public SGAbstractModel {
public:
	SGFirstGameModel();
	virtual ~SGFirstGameModel();
	void EvaluateCoords(int& i, int& j);
	SGSnakeCell* GetSnakeHead();
	void GetSnakeHeadCoords(int& x, int& y);
	void SetSnakeHeadCoords(int x, int y);
	int GetNRows() const;
	int GetNCols() const;
	std::vector<std::pair<SGSnakeCell*, std::pair<int, int>>>& GetSnake();
	void MoveSnakeCell(int index, int i, int j);
	virtual double GetTickTime() const override;
	virtual void SetTickTime(double time) override;
	std::vector<std::vector<SGAbstractCell*>>& GetCells();
	void AddSnakePart(SGDirection dir, int i, int j);
	void MoveConsumableAt(int i, int j);
	bool GetGameStart() const;
	void SetGameStart(bool status);

private:
	std::vector<std::pair<SGSnakeCell*, std::pair<int, int>>> snake;
	std::vector<std::vector<SGAbstractCell*>> cells;
	SGAbstractCell* apple;
	int xOffset;
	int yOffset;
	double tickTime;
	bool gameStart;
};

/*class SGTransition : public SGAbstractModel {
public:
	SGTransition();
	virtual ~SGTransition();
	void Play();
};*/

#endif // !__SGMODEL_H
