#ifndef TEXTADVENTURE_ENTITY_H
#define TEXTADVENTURE_ENTITY_H

#include "World.h"

namespace TextAdventure
{
	class Entity
	{
	public:
		virtual void print() = 0;
		void update();
		
	};

}

#endif