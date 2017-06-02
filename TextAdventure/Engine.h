#ifndef TEXTADVENTURE_ENGINE_H
#define TEXTADVENTURE_ENGINE_H

#include <functional>
#include <map>
#include <memory>

namespace TextAdventure
{
	class World;

	class Engine
	{
		//
		// Data members
		//
	private:
		static std::map<std::string, std::shared_ptr<World>> s_Worlds;

		//
		// Buisness
		//
	private:
		static void close();
		static void update();

		//
		// Public interface
		//
	public:
		static void init(const std::function<void(void)> &aInitFunctionPtr);

		template<class WorldType = World>
		static std::weak_ptr<World> createWorld(const std::string &aName)
		{
			static_assert(std::is_base_of<World, WorldType>::value == true, "WorldType must derive from TextAdventure::World");

			std::shared_ptr<World> newWorld = std::shared_ptr<World>(new WorldType(aName));

			if (s_Worlds.insert(std::pair<std::string, std::shared_ptr<World>>(aName, newWorld)).second == false)
			{
				Terminal::error("World creation failed: ", aName, " already exists.");
				return std::weak_ptr<World>();

			}

			return std::weak_ptr<World>(std::dynamic_pointer_cast<World>(newWorld));

		}

		static std::weak_ptr<World> getWorld(const std::string &aString);

	};

}

#endif