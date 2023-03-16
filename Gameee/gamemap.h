#pragma once
#include "Base.h"

#define MAX_TILES 20

class TileMat : public Base
{
public:
	TileMat() { ; }
	~TileMat() { ; }
};

class GameMap
{
public:
	GameMap();
	~GameMap();
	void LoadMap(const char* name);
	void DrawMap(SDL_Renderer* des);
	void LoadMapTiles(SDL_Renderer* screen);
	void MapMove();

	Map GetMap() const { return game_map_; }
	void SetMap(const Map& gMap) { game_map_ = gMap; }
public:
	Map game_map_;
	TileMat tile_mat_[MAX_TILES];
	Input input_type_;
};

