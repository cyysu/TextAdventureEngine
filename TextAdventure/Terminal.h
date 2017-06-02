#ifndef TEXTADVENTURE_GRAPHICS_H
#define TEXTADVENTURE_GRAPHICS_H

#include <iostream>
#include <string>

namespace TextAdventure
{
	class Terminal
	{ 
	private: //Friend rules
		friend class Engine;

	private: //Construction & Destruction rules
		Terminal() = delete;
		Terminal(const Terminal&) = delete;
		Terminal& operator=(const Terminal&) = delete;
		~Terminal() = delete;

	private: //Data members
		static std::ostream* s_StandardStream;
		static std::ostream* s_ErrorStream;

	private: //Implementation
		static void setTextColor(const int &aColor);
		static void setPosition(const int &aX, const int &aY);

	private: //Engine interface
		static void init();

	public://Game programmer interface
		static void resize(const int &aWidth, const int &aHeight);

		static void anyKey();

		static std::string read();

		static void write(const std::string &aText, const int &aColor, const int &aX, const int &aY);
		static void write(const std::string &aText, const int &aColor);
		static void write(const std::string &aText, const int &aX, const int &aY);
		static void write(const std::string &aText);

		static void log() {}
		template<typename First, typename ...Rest>
		static void log(First && first, Rest && ...rest)
		{
			*s_StandardStream << std::forward<First>(first) << '\n';
			log(std::forward<Rest>(rest)...);

		}

		static void error() {}
		template<typename First, typename ...Rest>
		static void error(First && first, Rest && ...rest)
		{
			setTextColor(Color::LIGHTRED);

			*s_ErrorStream << std::forward<First>(first);
			error(std::forward<Rest>(rest)...);
			
			if (sizeof...(Rest) == 0) //if is last variarg
			{
				*s_ErrorStream << '\n';
				setTextColor(Color::WHITE);

			}

		}

		//Inner classes
	private:
		class Window final
		{
		private: //friends
			friend class Terminal;

		private: //Construction rules
			Window(const int& aWidth, const int& aHeight, const int& aX, const int& aY);
			Window() = delete;
			Window(const Window&) = delete;
			Window& operator=(const Window&) = delete;
			~Window() = delete;

		private: //terminal interface


		public: //public interface
			

		};

		class Color final
		{
		private: //Construction & Destruction rules
			Color() = delete;
			Color(const Color&) = delete;
			Color& operator=(const Color&) = delete;
			~Color() = delete;

		public:
			static int BLACK;
			static int BLUE;
			static int GREEN;
			static int CYAN;
			static int RED;
			static int MAGENTA;
			static int BROWN;
			static int GREY;
			static int DARKGREY;
			static int LIGHTBLUE;
			static int LIGHTGREEN;
			static int LIGHTCYAN;
			static int LIGHTRED;
			static int LIGHTMAGENTA;
			static int YELLOW;
			static int WHITE;

		};

	};

}

#endif
