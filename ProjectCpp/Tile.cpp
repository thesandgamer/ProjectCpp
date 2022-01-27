#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(Vector2 posP, Vector2 sizeP, Texture2D* spriteP): pos(posP),size(sizeP),sprite(spriteP)
{
	valueForTest = 0;
}

Tile::Tile(Vector2 posP, Vector2 sizeP): pos(posP), size(sizeP)
{
}

Tile::~Tile()
{
}

void Tile::Update()
{
}

void Tile::Draw()
{
	if (sprite != nullptr)
	{
		DrawRectangle(gridAnchorStartPos.x + (pos.x * size.x), gridAnchorStartPos.y+(pos.y * size.y), 
			size.x, size.y,PURPLE);
		DrawText(std::to_string(valueForTest).c_str(), gridAnchorStartPos.x+pos.x * size.x, gridAnchorStartPos.y+ pos.y * size.y, 15, WHITE);
	}


	//DrawTextureRec(*sprite, spriteEmplacement, pos, WHITE); //Dessine un carr� de taille spriteEmplacement du sprite � la position pos
}

void Tile::ChangeSprite(int value)
{
	//Va retourner une valeur, en fonction de la valeur on va d�placer le carr� de lecture
	spriteEmplacement = { (float)value * size.x,0,(float)size.x,(float)size.y };
	valueForTest = value;
}
