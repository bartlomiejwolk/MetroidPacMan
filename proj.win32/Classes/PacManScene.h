#pragma once

#include "cocos2d.h"

class PacManScene : public cocos2d::Scene
{
protected:
	// TODO adjust name
	// Visible size of the OpenGL view in points.
	// Initialized in `init()`.
	cocos2d::Size m_OpenGLVisibleSize;

	// TODO adjust name
	// Visible origin coordinate of the OpenGL view in points.
	// Initialized in `init()`.
	cocos2d::Vec2 m_OpenGLOrigin;

	// TODO adjust name
	// Font used for all text in the game.
	const std::string m_FontFilePath = "fonts/GameCube.ttf";

	// All UI placed above the Maze is attached to this Node.
	// It allows to move all top UI elements by moving a single Node.
	// Anchor point and position is set to (0, 0) upon creation. Initialized in `init()`.
	cocos2d::Node m_UITop;

	cocos2d::Node m_UIBotton;

	// TODO adjust name
	// Font size used for all text in the game.
	const int m_FontSize = 50;

	virtual bool init() override;

	// Called in `init()`.
	void SubscribeToInputEvents();

	virtual void HandleInput(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);

	void Draw1UPLabel();

	// TODO adjust name
	void Draw2UPLabel();

	void DrawHighScoreLabel();

	void DrawHighScoreValueLabel(int highscore);

	void DrawPlayerScoreValueLabel(int score);

	// TODO rename to DrawCreditLabel
	void DrawCredits();

};

