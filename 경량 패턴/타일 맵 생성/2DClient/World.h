#pragma once
#include "stdafx.h"
#include"Terrain.h"
class World{
private:
	Terrain*			tiles_[WIDTH][HEIGHT];
	Terrain				groundTerrain_;
	Terrain				waterTerrain_;
	Terrain				ironTerrain_;
public:
	World() :
		groundTerrain_(1, false, g_groundTexture), waterTerrain_(1, true, g_waterTexture),
		ironTerrain_(1, false, g_ironTexture) {}

	void				GenerateTerrain();
	const Terrain&		GetTile(int x,int y)const;

};
