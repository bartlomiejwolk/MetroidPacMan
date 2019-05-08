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

	// TODO adjust name
	// Font size used for all text in the game.
	const int m_FontSize = 70;

	virtual bool init() override;

	void Draw1UPLabel();

	// TODO adjust name
	void Draw2UPLabel();

	void DrawHighScoreLabel();

	// TODO rename to DrawCreditLabel
	void DrawCredits();

};

