#ifndef TEXTADVENTURE_WORLD_H
#define TEXTADVENTURE_WORLD_H

//std inc
#include <map>
#include <iostream>
#include <memory>

namespace TextAdventure
{
	class Room;
	class Entity;

	class World
	{
		//
		// friend rules
		//
		friend class Engine;
		friend std::ostream& operator<<(std::ostream& stream, World& aWorld);

		//
		//Construction & Destruction rules
		//
	private:
		World(const std::string &aName);
		World() = delete;
		World(const World&) = delete;
		World& operator=(const World&) = delete;
	public:
		virtual ~World() = default;

		//
		// Data members
		//
	private:
		const std::string m_Name;
		std::map<std::string,std::shared_ptr<Room>> m_Rooms;
		
		//
		// Engine interface
		//
	private:
		void update();

		//
		// Public interface
		//
	public:
		template<class RoomType = Room>
		void createRoom(const std::string &aName)
		{
			static_assert(std::is_base_of<Room, RoomType>::value == true, "RoomType must derive from TextAdventure::Room");

			std::shared_ptr<Room> newRoom = std::shared_ptr<Room>(new RoomType(aName));

			m_Rooms.insert(std::pair<std::string, std::shared_ptr<Room>>(aName, newRoom));

			//addRooms(std::forward<Rest>(rest)...);

		}

		/*void addRooms() {}
		template<class RoomType = Room,typename ...Rest>
		void addRooms(const std::shared_ptr<Room> &first, Rest && ...rest)
		{
			m_Rooms.insert(std::pair<std::string, std::shared_ptr<Room>>(first._Get()->getName(),first));

			addRooms(std::forward<Rest>(rest)...);

		}*/

	};

	std::ostream& operator<<(std::ostream& stream, const World& aWorld);
	
}

#endif