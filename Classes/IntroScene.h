#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"

class IntroScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(IntroScene);

private:
	// Visible size of the OpenGL view in points.
	// Initialized in `init()`.
	cocos2d::Size m_OpenGLVisibleSize;

	// Visible origin coordinate of the OpenGL view in points.
	// Initialized in `init()`.
	cocos2d::Vec2 m_OpenGLOrigin;

	// Font used for all text in the game.
	const std::string m_FontFilePath = "fonts/GameCube.ttf";

	// Font size used for all text in the game.
	const int m_FontSize = 70;
	
	// Called in `init()`.
	void SubscribeToInputEvents();

	void Draw1UPLabel();

	void Draw2UPLabel();

	void DrawHighScoreLabel();

	void DrawCharacterNicknames();

	void DrawPointsInfo();

	void DrawCompanyName();

	void DrawCredits();

	void RunPacManAnimation();

};

#endif // __INTRO_SCENE_H__
