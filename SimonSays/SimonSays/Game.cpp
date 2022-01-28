/// <summary>
/// @author Peter Lowe
/// @date May 2019
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	initializeFont();
	initializeText();
	initializeButtons();

	gameTexts();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 30 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 30.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 30 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 30 fps
			update(timePerFrame); //30 fps
		}
		render(); // as many as possible
	}
}

void Game::initializeText()
{
	m_titleText.setFont(m_font);
	m_titleText.setCharacterSize(48);
	m_titleText.setFillColor(sf::Color::Black);
	m_titleText.setOutlineColor(sf::Color::White);
	m_titleText.setOutlineThickness(3.0f);

	m_greenText.setFont(m_font);
	m_greenText.setCharacterSize(24);
	m_greenText.setFillColor(sf::Color::Green);

	m_yellowText.setFont(m_font);
	m_yellowText.setCharacterSize(24);
	m_yellowText.setFillColor(sf::Color::Yellow);

	m_redText.setFont(m_font);
	m_redText.setCharacterSize(24);
	m_redText.setFillColor(sf::Color::Red);

	m_blueText.setFont(m_font);
	m_blueText.setCharacterSize(24);
	m_blueText.setFillColor(sf::Color::Blue);
}

void Game::initializeFont()
{
	if (!m_font.loadFromFile("ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "ERROR: Failed to load font." << std::endl;
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear();

	// Draw on window
	m_window.draw(greenButton);
	m_window.draw(redButton);
	m_window.draw(yellowButton);
	m_window.draw(blueButton);

	m_window.draw(m_titleText);
	m_window.draw(m_greenText);
	m_window.draw(m_yellowText);
	m_window.draw(m_redText);
	m_window.draw(m_blueText);

	m_window.display();
}

void Game::initializeButtons()
{
	greenButton.setSize(sf::Vector2f(200.0f, 200.0f));
	greenButton.setPosition(300.0f, 50.0f);
	greenButton.setFillColor(sf::Color::Green);

	redButton.setSize(sf::Vector2f(200.0f, 200.0f));
	redButton.setPosition(515.0f, 50.0f);
	redButton.setFillColor(sf::Color::Red);

	yellowButton.setSize(sf::Vector2f(200.0f, 200.0f));
	yellowButton.setPosition(300.0f, 265.0f);
	yellowButton.setFillColor(sf::Color::Yellow);

	blueButton.setSize(sf::Vector2f(200.0f, 200.0f));
	blueButton.setPosition(515.0f, 265.0f);
	blueButton.setFillColor(sf::Color::Blue);
}

void Game::gameTexts()
{
	m_titleText.setString("S I M O N");
	m_titleText.setPosition(20.0f, 25.0f);

	m_greenText.setString("Press green for \n Easy Mode");
	m_greenText.setPosition(20.0f, 100.0f);

	m_yellowText.setString("Press yellow for \n Normal Mode");
	m_yellowText.setPosition(20.0f, 200.0f);

	m_redText.setString("Press red for \n Hard Mode");
	m_redText.setPosition(20.0f, 300.0f);

	m_blueText.setString("Press blue to \n Exit Game");
	m_blueText.setPosition(20.0f, 400.0f);
}

