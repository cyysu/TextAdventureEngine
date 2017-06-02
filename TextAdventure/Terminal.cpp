#include "Terminal.h"

//rutil inc
#include "./Dependencies/rlutil/rlutil.h"
//PDCurses inc
#include "Dependencies\PDCurses\curses.h"
//std inc
#include <iostream>

using namespace TextAdventure;

std::ostream* Terminal::s_StandardStream = &std::cout; //TODO: Consider paramaterizing these?
std::ostream* Terminal::s_ErrorStream    = &std::cerr;

int Terminal::Color::BLACK        = rlutil::BLACK;
int Terminal::Color::BLUE         = rlutil::BLUE;
int Terminal::Color::GREEN        = rlutil::GREEN;
int Terminal::Color::CYAN         = rlutil::CYAN;
int Terminal::Color::RED          = rlutil::RED;
int Terminal::Color::MAGENTA      = rlutil::MAGENTA;
int Terminal::Color::BROWN        = rlutil::BROWN;
int Terminal::Color::GREY         = rlutil::GREY;
int Terminal::Color::DARKGREY     = rlutil::DARKGREY;
int Terminal::Color::LIGHTBLUE    = rlutil::LIGHTBLUE;
int Terminal::Color::LIGHTGREEN   = rlutil::LIGHTGREEN;
int Terminal::Color::LIGHTCYAN    = rlutil::LIGHTCYAN;
int Terminal::Color::LIGHTRED     = rlutil::LIGHTRED;
int Terminal::Color::LIGHTMAGENTA = rlutil::LIGHTMAGENTA;
int Terminal::Color::YELLOW       = rlutil::YELLOW;
int Terminal::Color::WHITE        = rlutil::WHITE;

//tseting stuff
WINDOW* createWindow(const int &aWidth, const int &aHeight, const int &aX, const int &aY)
{
	//OutputDebugString(std::to_string(x).append(", ").append(std::to_string(y)).c_str());
	WINDOW* newWindow = newwin(aHeight, aWidth, aX, aY);

	if (newWindow == NULL)
	{
		endwin();
		throw (std::exception("Terminal could not create a new window"));

	}

	return newWindow;

}

void deleteWindow(WINDOW*& aWindow)
{
	delwin(aWindow);

}

///

void Terminal::resize(const int &aWidth, const int &aHeight)
{
	savetty();
	resize_term(aHeight, aWidth);
	clear();
	refresh();

}



void Terminal::init()
{
	initscr();
	start_color();
	resize(100, 50);

	/*WINDOW* win = 0;//createWindow(LINES, COLS, 0, 0);
	{
		win = newwin(30, 30, 5, 65);

		if (win == NULL)
		{
			endwin();

		}

	}*/

	WINDOW* win = createWindow(30, 30, 5, 20);

	{
		mvwaddstr(win, 0, 0, "Press any key to continue");
		wrefresh(win);
		raw();
		wgetch(win);
		wrefresh(win);
	}

	resize(50, 20);

	wgetch(win);
	
}


void Terminal::setTextColor(const int &aColor)
{
	rlutil::setColor(aColor);

}

void Terminal::setPosition(const int &aX, const int &aY)
{
	rlutil::locate(aX, aY);

}

void Terminal::anyKey()
{
	write("Press any key...");
	rlutil::anykey();

}

std::string Terminal::read()
{
	std::string rValue;
	std::cin >> rValue;

	return rValue;

}

void Terminal::write(const std::string &aText, const int &aColor, const int &aX, const int &aY)
{
	int x = 1 + aX, y = 1 + aY;

	//setTextColor(aColor);
	setPosition(x, y);

	write(aText, aColor);

}

void Terminal::write(const std::string &aText, const int &aColor)
{
	setTextColor(aColor);
	write(aText);
	setTextColor(Color::WHITE);

}

void Terminal::write(const std::string &aText, const int &aX, const int &aY)
{
	write(aText, Color::WHITE, aX, aY);

}

void Terminal::write(const std::string &aText)
{
	*s_StandardStream << aText;

}