#pragma once
#include "raylib.h"
#include <vector>
#include <map>
#include <string>

using std::map;
using std::vector;
using std::string;


namespace TileAround {
	enum Value {
		UPLEFT = 1 << 0,	//1
		UP = 1 <<1,			//2
		UPRIGHT= 1 <<2,		//4
		LEFT = 1 <<3,		//8
		RIGHT = 1 << 4,		//16
		DOWNLEFT = 1<<5,	//32
		DOWN = 1 <<6,		//64
		DOWNRIGHT = 1 <<7,	//128


	};
};

class Grid
{
public:
	Grid();
	Grid(int width, int height);
	~Grid();


	//Tilemaps dans la grille
	void AddTilemap(Texture2D sprite);
	void SetupSpritesOfGrid(string sprite);
	void SetupSpritesOfGrid(Texture2D upperLeft,Texture2D upper);

	//Li� � la souris
	void SetMousePos(Vector2* mousePosP) { mousePos = mousePosP; }

	Vector2 CalculatePositionInGrid(const Vector2& pos);

	//Draw and update
	void Draw();
	void Update();

	//Sizer
	void SetCellSize(Vector2 size);
	void ResizeGrid(Vector2 gridSize);
	void ChangeCellWithAndHeight(Vector2 newSize);

	//
	void AddTileInGrid(Vector2 pos);
	void RemoveTileInGrid(Vector2 pos);

	//Li� � l'auto Tiling
	void ChangeSpriteOfTile(Vector2 tilePos);


	void SetCellWidthHeight(int cellWidth, int cellHeight) {};



private:

	//Contiens l'ensemble des tiles(refs)
	vector<vector<class Tile*>> grid;


	//Posision de la souris(ref)
	Vector2* mousePos;


	//Li� � l'autoTiling
	std::uint8_t CheckTilesAround(Vector2 tilePos);

	int Conversion(int arg);

	void CheckAndReplaceAllTiles();
	void CheckAndReplaceAroundTile(Vector2 tilePos);


	//Li� � la grille
	int gridWidth;
	int gridHeight;

	int cellWidth; ///Longeur de cellules de la grille
	int cellHeight;

	int nbOfTilesWidth;
	int nbOfTilesHeight;


	//Stoquage des tilemaps(textures)
	vector<Texture2D> tileMaps;


	Vector2 startPos;



	
};


