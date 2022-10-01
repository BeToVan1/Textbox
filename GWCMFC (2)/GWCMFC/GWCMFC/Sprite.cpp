#include "Sprite.h"

void Sprite::Draw( CPaintDC tContext, double tInterpolation )
{
	// Just look at our object and draw something to the DC
}

Sprite::Sprite( GameObject* tObjectToDraw )
{
	mMyObject = tObjectToDraw;
}


Sprite::~Sprite()
{
}
