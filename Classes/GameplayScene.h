#ifndef __GAMEPLAY_SCENE_H__
#define __GAMEPLAY_SCENE_H__

#include "cocos2d.h"
#include "PacManScene.h"

class GameplayScene : public PacManScene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameplayScene);

	virtual void update(float delta) override;

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

	void SubscribeToInputEvents();

};

#endif // __GAMEPLAY_SCENE_H__
