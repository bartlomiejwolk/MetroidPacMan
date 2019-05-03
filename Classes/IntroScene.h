#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"
#include "PacManScene.h"

class IntroScene : public PacManScene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(IntroScene);

private:
	
	// Called in `init()`.
	void SubscribeToInputEvents();

	void DrawCharacterNicknames();

	void DrawPointsInfo();

	void DrawCompanyName();

	void RunPacManAnimation();

};

#endif // __INTRO_SCENE_H__
