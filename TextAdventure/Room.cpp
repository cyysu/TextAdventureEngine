#include "Room.h"

using namespace TextAdventure;

std::string Room::getName()
{
	return m_Name;

}

//
//
//
Room::Room(const std::string &aName) : 
m_Name(aName)
{}