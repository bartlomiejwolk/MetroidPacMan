#pragma once

#include "PawnController.h"

// This class is used for all ghosts. There's no further specialization.
// Each ghost type accepts different pathfinding algorithm in the constructor.
class AIPawnController : public PawnController
{
public:
	// TODO accept pathfinding algorithm interface
	AIPawnController();
	~AIPawnController();

	static AIPawnController* create();

	void OnPawnReachedTargetPoint() override;

};

