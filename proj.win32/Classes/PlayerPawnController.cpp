#include "PlayerPawnController.h"
#include "cocos2d.h"

USING_NS_CC;

PlayerPawnController* PlayerPawnController::create()
{
	PlayerPawnController* pc = new (std::nothrow) PlayerPawnController();
	if (pc && pc->init())
	{
		pc->autorelease();
		return pc;
	}
	CC_SAFE_DELETE(pc);
	return nullptr;
}

bool PlayerPawnController::init()
{
	return true;
}

void PlayerPawnController::OnPawnReachedTargetPoint()
{
	CCLOG("OnPawnReachedTargetPoint");
}
