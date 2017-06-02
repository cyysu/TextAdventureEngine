#ifndef TEXTADVENTURE_ROOM_H
#define TEXTADVENTURE_ROOM_H

#include <string>

namespace TextAdventure
{
	class Room
	{
		//
		// friend rules
		//
		friend class World;

		//
		//Construction & Destruction rules
		//
	private:
		Room(const std::string &aName);
		Room() = delete;
		Room(const Room&) = delete;
		Room& operator=(const Room&) = delete;
	public:
		virtual ~Room() = default;

		//
		// Data members
		//
	private:
		std::string m_Name;
		std::string m_Description;

		//
		// Accessors
		//
	public:
		std::string getName();

	};

}

#endif