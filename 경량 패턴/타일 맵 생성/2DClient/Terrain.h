#pragma once
#include "stdafx.h"

class Terrain{
private:
	int						movementCost_;
	bool					isWater_;
	Texture*				texture_;
public:
	Terrain(int movementCost, bool isWater, Texture& texture) :
		movementCost_(movementCost), isWater_(isWater), texture_(&texture) {}

	int						GetMovementCost()const;
	bool					IsWater()const;
	const Texture&			GetTexture()const;
};

