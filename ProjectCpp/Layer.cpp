#include "Layer.h"

Layer::Layer()
{
}

Layer::Layer(LayerType type) :layerType(type), layerUseAutoTiling(false)
{
}

Layer::Layer(LayerType type, bool useAutoTiling): layerType(type),layerUseAutoTiling(useAutoTiling)
{
}

Layer::~Layer()
{
	buttonLayer->~Button();
	grid.~Grid();
}

void Layer::AddTile(Vector2 tilePos)
{
	if (visible)
	{
		grid.AddTileInGrid(tilePos);
	}
}

void Layer::RemoveTile(Vector2 tilePos)
{
	if (visible)
	{
		grid.RemoveTileInGrid(tilePos);
	}
}

void Layer::Update()
{
	if (visible)
	{
		grid.Update();
	}
}

void Layer::Draw()
{
	//Ca va dessiner une ref grille de la taille de la room, avec le cell width et cell height décidé
	if (visible)
	{
		grid.Draw();
	}
}

void Layer::CreateGrid(int width, int height)
{
	grid = Grid(width, height);
}

void Layer::AddButton(Vector2 pos)
{
	buttonLayer = new Button(pos, 100, 50);
}

Button* Layer::GetButton()
{
	if (buttonLayer != nullptr)
	{
		return buttonLayer;
	}
}

void Layer::RemoveButton()
{
	//delete[] buttonLayer;
	std::cout << "On remove le boutton " << std::endl;
	delete buttonLayer;
	buttonLayer->~Button();

}

