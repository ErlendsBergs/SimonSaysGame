/// <summary>
/// Name: Erlends Bergs
/// Login: C00271073
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:
	// Initalize
	void initializeText();
	void initializeFont();

	// Functions
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void initializeButtons();

	void gameTexts();


	// Game objects
	sf::RectangleShape greenButton;
	sf::RectangleShape redButton;
	sf::RectangleShape yellowButton;
	sf::RectangleShape blueButton;

	// Text and Font
	sf::Text m_titleText;
	sf::Font m_font;


	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

