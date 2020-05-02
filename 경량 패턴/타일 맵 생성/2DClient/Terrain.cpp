#include "stdafx.h"
#include "Terrain.h"



int Terrain::GetMovementCost()const {
	return movementCost_;
}

bool Terrain::IsWater()const {
	return isWater_;
}

const Texture& Terrain::GetTexture()const {
	return *texture_;
}
