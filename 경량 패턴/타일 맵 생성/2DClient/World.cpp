#include "stdafx.h"
#include "World.h"


void World::GenerateTerrain() {

	for (int x = 0; x < WIDTH; ++x) {
		for (int y = 0; y < HEIGHT; ++y) {
			tiles_[x][y] = &groundTerrain_;
		}
	}

	for (int x = 5; x < 10; ++x) {
		for (int y = 5; y < 10; ++y) {
			tiles_[x][y] = &waterTerrain_;
		}
	}

	for (int x = 15; x < WIDTH; ++x) {
		for (int y = 15; y < HEIGHT; ++y) {
			tiles_[x][y] = &ironTerrain_;
		}
	}

}

const Terrain& World::GetTile(int x, int y)const {
	return *tiles_[x][y];
}

