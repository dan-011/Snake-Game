#include "SGController.h"

SGAbstractCtrl::~SGAbstractCtrl() {}
void SGAbstractCtrl::Tick() {}
void SGAbstractCtrl::Up() {}
void SGAbstractCtrl::Down() {}
void SGAbstractCtrl::Left() {}
void SGAbstractCtrl::Right() {}

SGStartupCtrl::SGStartupCtrl() : model(new SGStartupModel), view(new SGStaticView(*model)) {}
SGStartupCtrl::~SGStartupCtrl() {
	delete view;
	delete model;
}
void SGStartupCtrl::StartMode() {
	view->Show();
}
#include <iostream>
void SGStartupCtrl::EndMode() {
	view->SetIsActive(false);
	// have the view send a status to indicate when it is done
	//while(view->GetStatus()){
	//	std::cout << view->GetStatus() << std::endl;
		// wait for the view to finish
	//}
}
SGAbstractModel* SGStartupCtrl::GetModel() {
	return model;
}
SGAbstractView* SGStartupCtrl::GetView() {
	return view;
}

// MAY BE ABLE TO REFACTOR OUT AND MAKE GENERIC CONTROLLER
SGFirstGameCtrl::SGFirstGameCtrl() : model(new SGFirstGameModel), view(new SGStaticView(*model)), addingCells(0) {}
SGFirstGameCtrl::~SGFirstGameCtrl() {
	delete view;
	delete model;
}
void SGFirstGameCtrl::StartMode() {
	view->Show();
}
void SGFirstGameCtrl::EndMode() {
	view->SetIsActive(false);
}
SGAbstractModel* SGFirstGameCtrl::GetModel() {
	return model;
}
SGAbstractView* SGFirstGameCtrl::GetView() {
	return view;
}
void SGFirstGameCtrl::Tick() { // refactor
	if (!model->GetGameStart()) return;
	SGDirection lastDirection = model->GetSnakeHead()->GetDirection();
	for (int i = 0; i < model->GetSnake().size(); i++) {
		std::pair<int, int> coords = model->GetSnake().at(i).second;
		std::pair<int, int> beforeCoords(coords);
		SGDirection tempDir = model->GetSnake().at(i).first->GetDirection();
		switch (tempDir) {
			case NORTH:
				coords.second--;
				break;
			case SOUTH:
				coords.second++;
				break;
			case EAST:
				coords.first++;
				break;
			case WEST:
				coords.first--;
				break;
		}
		if (coords.first > model->GetNRows() || coords.first == 0 || coords.second > model->GetNCols() || coords.second == 0) {
			return;
		}
		SGAbstractCell* target = model->GetCells().at(coords.first).at(coords.second);
		if (dynamic_cast<SGSnakeCell*>(target) != NULL) {
			return;
		}
		else if (i == 0 && target != NULL) {
			addingCells = target->Denomination();
			model->MoveConsumableAt(coords.first, coords.second);
		}
		model->GetSnake().at(i).first->SetDirection(lastDirection);
		model->MoveSnakeCell(i, coords.first, coords.second);
		lastDirection = tempDir;
	}
	if (addingCells > 0) {
		std::pair<SGSnakeCell*, std::pair<int, int>> lastSnakeCell = model->GetSnake().back();
		std::pair<int, int> lastSnakeCellCoords(lastSnakeCell.second);
		switch (lastDirection)
		{
			case NORTH:
				lastSnakeCellCoords.second++;
				break;
			case SOUTH:
				lastSnakeCellCoords.second--;
				break;
			case EAST:
				lastSnakeCellCoords.first--;
				break;
			case WEST:
				lastSnakeCellCoords.first++;
				break;
		}
		model->AddSnakePart(lastDirection, lastSnakeCellCoords.first, lastSnakeCellCoords.second);
		addingCells--;
	}
}
void SGFirstGameCtrl::Up() {
	model->SetGameStart(true); // refactor this out
	if (model->GetSnakeHead()->GetDirection() != SOUTH) {
		model->GetSnakeHead()->SetDirection(NORTH);
	}
}
void SGFirstGameCtrl::Down() {
	model->SetGameStart(true); // refactor this out
	if (model->GetSnakeHead()->GetDirection() != NORTH) {
		model->GetSnakeHead()->SetDirection(SOUTH);
	}
}
void SGFirstGameCtrl::Left() {
	model->SetGameStart(true); // refactor this out
	if (model->GetSnakeHead()->GetDirection() != EAST) {
		model->GetSnakeHead()->SetDirection(WEST);
	}
}
void SGFirstGameCtrl::Right() {
	model->SetGameStart(true); // refactor this out
	if (model->GetSnakeHead()->GetDirection() != WEST) {
		model->GetSnakeHead()->SetDirection(EAST);
	}
}