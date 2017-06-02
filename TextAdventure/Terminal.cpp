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

std::map<std::string, std::shared_ptr<Terminal::Window>> Terminal::s_Windows;

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

void Terminal::setTitle(const std::string &aName)
{
#ifdef __PDCURSES__
	PDC_set_title(aName.c_str());
#endif

}

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
	raw();

	setTitle("TextAdventure");
	resize(100, 50);

	std::shared_ptr<Window> defaultWindow = std::shared_ptr<Window> (new Window(30, 30, 5, 20));
	s_Windows.insert(std::pair<std::string, std::shared_ptr<Window>>("SuperTestWindow", defaultWindow));

	defaultWindow._Get()->write("Write a string: ",0,0);
	std::string userInput = defaultWindow._Get()->read();

	defaultWindow._Get()->write(userInput+"\n");

	defaultWindow._Get()->write("A");
	defaultWindow._Get()->write("B");
	defaultWindow._Get()->write("C");

	//defaultWindow._Get()->write("\nPress any key to continue");
	//wgetch(defaultWindow._Get()->getHandle());

	//defaultWindow._Get()->draw();

	wgetch(defaultWindow._Get()->getHandle());
	resize(50, 20);
	wgetch(defaultWindow._Get()->getHandle());

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

////////////////////////////////////////
// WINDOW
/////////////////////////////////////////
Terminal::Window::Window(const int& aWidth, const int& aHeight, const int& aX, const int& aY) : 
	m_Handle(newwin(aHeight, aWidth, aX, aY))
{
	if (m_Handle == NULL)
	{
		endwin();
		throw (std::exception("Terminal could not create a new window"));

	}

}

Terminal::Window::~Window()
{
	_win* ptr = m_Handle;
	delwin(ptr);

}

/*void Terminal::Window::write(const char &aChar)
{
	//waddstr(m_Handle, &aChar);
	//wrefresh(m_Handle);
	
}*/

void Terminal::Window::write(const std::string &aString)
{
	waddstr(m_Handle, aString.c_str());
	//wrefresh(m_Handle);

}

void Terminal::Window::write(const std::string &aString, const int &aX, const int &aY)
{
	mvwaddstr(m_Handle, aY, aX, aString.c_str());
	//wrefresh(m_Handle);

}

void Terminal::Window::refresh()
{
	wrefresh(m_Handle);

}

std::string Terminal::Window::read(const int& aInputBufferLength)
{
	char* buffer = new char[aInputBufferLength+1];//+1 for the null terminator
	wgetnstr(m_Handle, buffer, aInputBufferLength);
	
	std::string rValue(buffer);
	delete[] buffer;

	return rValue;

}