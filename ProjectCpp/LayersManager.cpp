#include "LayersManager.h"

#include "Maths.h"
#include <string>

int layerNumber = 0;

void LayersManager::AddLayer()
{
	LayersManager* This = &LayersManager::instance();

	layerNumber++;

	Layer newLayer = Layer(Layer::LayerType::Tiles, true);
	newLayer.CreateGrid(960, 540); //Il faudra créer une grille de la taille de la room
	newLayer.AddButton(Vector2{ 100, 20.0f + (layerNumber*10 ) + (50 * layerNumber) });


	This->actualLayer++;
	newLayer.GetButton()->functPrtInt = &LayersManager::SelectLayer;
	newLayer.GetButton()->value = This->actualLayer;

	This->layers.push_back(newLayer);
	This->GoToLayer(This->actualLayer);


}

void LayersManager::RemoveLayer()
{
	//layers[actualLayer - 1].RemoveButton();
	layers[actualLayer - 1].~Layer();
	actualLayer--;
	layerNumber--;
	GoToLayer(actualLayer);
}

void LayersManager::AddTileMapToActualLayer(string tileSet)
{
	string sprite = "../../Resources/" + tileSet; //Va chercher le tileSet
	layers[actualLayer-1].GetGrid().AddTilemap(LoadTexture(sprite.c_str()));
}

void LayersManager::SelectLayer(int layer)
{
	LayersManager* This = &LayersManager::instance();

	This->actualLayer = layer;
	This->GoToLayer(This->actualLayer);
}

void LayersManager::ProcessInputs()
{
	//Calcul la position de la souris
	Vector2 mouse = GetMousePosition();
	Vector2 mousePosInGrid = { 0 };
	if (!layers.empty())
	{
		mousePosInGrid = layers[actualLayer - 1].GetGrid().CalculatePositionInGrid(mouse);
	}
	

	//Check quand on clique
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (!layers.empty())
		{
			//Check si la position de la souris et dans la position du layer
			layers[actualLayer-1].AddTile(mousePosInGrid);

		}
	}
	if (IsKeyPressed(KEY_DELETE))
	{
		RemoveLayer();
	}
	DrawText(("Mouse: " + to_string(mouse.x) + " : " + to_string(mouse.y)).c_str(), 40, 40, 10, WHITE);
	DrawText(("MouseInGrid: " + to_string(mousePosInGrid.x) + " : " + to_string(mousePosInGrid.y)).c_str(), 40, 70, 10, WHITE);

}




void LayersManager::Update()
{
	for (Layer layer : layers)
	{
		
		if (layer.GetButton() != nullptr) //Check si le boutton existe
		{
			layer.GetButton()->Update();

		}

		layer.Update();
	}
}

void LayersManager::Draw()
{
	for (Layer layer : layers)
	{
		if (layer.GetButton() != nullptr) //Check si le boutton existe
		{
			layer.GetButton()->Draw();
		}

		layer.Draw();
	}

	string text = "Actual Layer: " + std::to_string(actualLayer);
	DrawText(text.c_str(), 10, 10, 10, WHITE);
}



void LayersManager::GoToLayer(int layer)
{

}
