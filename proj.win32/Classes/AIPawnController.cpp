#include "AIPawnController.h"



AIPawnController::AIPawnController()
{
}


AIPawnController::~AIPawnController()
{
}

AIPawnController* AIPawnController::create()
{
	AIPawnController* pc = new (std::nothrow) AIPawnController();
	if (pc && pc->init())
	{
		pc->autorelease();
		return pc;
	}
	CC_SAFE_DELETE(pc);
	return nullptr;
}

void AIPawnController::OnPawnReachedTargetPoint()
{
}
