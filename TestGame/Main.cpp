//Game inc
#include "Game.h"
//TextAdventure inc
#include <Engine.h>

int main()
{
	TextAdventure::Engine::init(TestGame::init);
	return 0;

}
