#include "World.h"
#include "Room.h"

using namespace TextAdventure;

World::World(const std::string &aName) :
	m_Name(aName)
{}

void World::update()
{


}

std::ostream& TextAdventure::operator<<(std::ostream& stream, World& aWorld)
{
	int roomCount = aWorld.m_Rooms.size();

	stream.clear();
	
	stream << "World{" 
	<< "Count: " << roomCount << ", {";
	
	for (std::map<std::string, std::shared_ptr<Room>>::iterator it = aWorld.m_Rooms.begin();it != aWorld.m_Rooms.end();++it)
	{
		stream << it->first;

		if (it != --aWorld.m_Rooms.end())
			stream << ", ";

	}

	stream << "}}";

	return stream;

}