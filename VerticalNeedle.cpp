#include "VerticalNeedle.h"
#include "Image.h"

void VerticalNeedle::Update()
{
	y = y + vy;
	if (y > Screen::Height - 64 || y < 32)
	{
		vy = -vy;
	}
}

void VerticalNeedle::Draw()
{
	Camera::DrawGraph(x, y, Image::mapchip[1], TRUE);
}
