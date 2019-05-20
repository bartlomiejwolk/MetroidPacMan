#pragma once

#include "cocos2d.h"

class PlayerPawnController : public cocos2d::Node
{
public:
	static PlayerPawnController* create();

	virtual bool init() override;

	void OnPawnReachedTargetPoint();
};

