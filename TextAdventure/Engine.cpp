#include "Engine.h"
#include "Terminal.h"
#include "World.h"

#include <thread>


#ifndef __DATE__
#define __DATE__ "UNDEFINED"
#endif


///////////////////////////////////////////////////////////////
/*#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

int testest() {
	std::atomic<bool> interrupted;
	int x;
	int i = 0;

	do {
		interrupted.store(false);

		// create a new thread that does stuff in the background
		std::thread th([&]() {
			while (!interrupted) {
				// do stuff. Just as an example:
				std::cout << i << std::flush;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		});

		std::cin >> x;

		// when input is complete, interrupt thread and wait for it to finish
		interrupted.store(true);
		th.join();

		// apply x, then loop to make new thread to do stuff
		i = x;
	} while (x != -1); // or some other exit condition
}
////////////////////////////////////////////////*/



using namespace TextAdventure;

std::map<std::string, std::shared_ptr<World>> Engine::s_Worlds;

void Engine::init(const std::function<void(void)> &aInitFunctionPtr)
{
	Terminal::init();

	//Terminal::write(std::string("Text Adventure Engine\nBuild date: ")+__DATE__+'\n',Terminal::Color::YELLOW);

	aInitFunctionPtr();

	

	//for (;;)
	//	update();

	//close();
	/*bool closeTheThread = false;

	std::thread testThread([&]
	{
		for (;;)
			if (Terminal::read() == "quit")
				break;

	});

	static int counter = 0;
	for (;;)
	{
		++counter;

		if (counter % 1000000000 == 0)
		{
			Terminal::write("a grue can be heard in the distance\n");
			counter = 1;

		}
	}
	close();*/

	//testest();
	//close();

}



void Engine::update()
{
	

	

	//Terminal::read();

}

std::weak_ptr<World> Engine::getWorld(const std::string &aString)
{
	std::shared_ptr<World> get;
	
	try 
	{
		get = s_Worlds.at(aString);
	
	}
	catch (const std::out_of_range& oor) 
	{
		Terminal::error("Out of Range error:", oor.what());
		return std::weak_ptr<World>();
	
	}

	return std::weak_ptr<World>(std::dynamic_pointer_cast<World>(get));
	
}

void Engine::close()
{
	Terminal::write("The Text Adventure is now closing\n", Terminal::Color::YELLOW);
	Terminal::anyKey();

}
