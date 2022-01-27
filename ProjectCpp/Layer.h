#pragma once
#include "raylib.h"
#include "Grid.h"
#include "Button.h"

//Layer: Types(objet, tile, collisions
//boutton AutoTiling?

//Cr�er une tile dans la grille(quel tilemap)
//Enl�ve une tile de la grille

class Layer
{
public:
	enum class LayerType{Tiles,Objects,Collisions};

	Layer();
	Layer(LayerType type);
	Layer(LayerType type, bool useAutoTiling);
	~Layer();

	void AddTile(Vector2 tilePos);
	void RemoveTile(Vector2 tilePos);

	void Update();
	void Draw();

	void SetMousePos(Vector2* mousePosP) { mousePos = mousePosP; }

	Grid GetGrid() { return grid; };

	void CreateGrid(int width, int height);

	void AddButton(Vector2 pos);
	Button& GetButton();

	void RemoveButton();

private:
	LayerType layerType;
	bool layerUseAutoTiling;

	Grid grid;

	vector<Texture2D> TileMaps;

	Vector2* mousePos;

	Button* buttonLayer;

	bool visible = true;

	

};

//Draw de RefGrid � la taille de cellule de la grille (dans le layerManger?)
//Faire en sorte de pouvoir voir ou pas le layer