#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);

private:
	// TODO make global
	// Visible size of the OpenGL view in points.
	// Initialized in `init()`.
	cocos2d::Size m_OpenGLVisibleSize;

	// TODO make global
	// Visible origin coordinate of the OpenGL view in points.
	// Initialized in `init()`.
	cocos2d::Vec2 m_OpenGLOrigin;

	// Font used for all text in the game.
	const std::string m_FontFilePath = "fonts/GameCube.ttf";

	// Font size used for all text in the game.
	const int m_FontSize = 70;

};

#endif // __MAIN_MENU_SCENE_H__
