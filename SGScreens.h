#ifndef __SGSCREENS_H
#define __SGSCREENS_H

#include "SGVisualComponent.h"
#include "SGTextComponent.h"

class SGClassicGameOverScreen : public SGVisualComponent {
public:
	SGClassicGameOverScreen();
	virtual ~SGClassicGameOverScreen();
	virtual void Draw() override;
	void AddScore(int score);

private:
	void GetHighScores();

	int yOffset;
	SGIndivSpriteComponent* sadSnake;
	SGTextComponent* gameOverText;
	SGTextComponent* restartText;
	SGTextComponent* exitText;
	SGTextComponent* highScoresText;
	SGTextComponent* highScoresOneText;
	SGTextComponent* highScoresTwoText;
	SGTextComponent* highScoresThreeText;
};

#endif