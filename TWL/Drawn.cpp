#include "Engine.h"
void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::White);
	if (!m_SplitScreen)
	{
		// Switch to background view
		m_Window.setView(m_BGMainView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite);
		// Switch to m_MainView
		m_Window.setView(m_MainView);
		// Draw the level
		m_Window.draw(m_VALevel, &m_textureTiles);
		// Drawn Thomas
		m_Window.draw(m_Thomas.getSprite());
		//Drawn Bob
		m_Window.draw(m_Bob.getSprite());
	}
	else
	{
		// Split-screen view is active
		// First drawn Thomas' side of the screen
		// Switch to background view
		m_Window.setView(m_BGLeftView);
		// Drawn the background
		m_Window.draw(m_BackgroundSprite);
		// Switch to m_LeftView
		m_Window.setView(m_LeftView);
		// Draw the level
		m_Window.draw(m_VALevel, &m_textureTiles);

		//Drawn Bob
		m_Window.draw(m_Bob.getSprite());
		// Drawn Thomas
		m_Window.draw(m_Thomas.getSprite());

		// Now draw Bob's side of the screen
		// Switch to background view
		m_Window.setView(m_BGRightView);
		// Drawn the background
		m_Window.draw(m_BackgroundSprite);
		// Switch to m_RightView
		m_Window.setView(m_RightView);
		// Draw the level
		m_Window.draw(m_VALevel, &m_textureTiles);

		// Drawn Thomas
		m_Window.draw(m_Thomas.getSprite());
		//Drawn Bob
		m_Window.draw(m_Bob.getSprite());
	}
	// Drawn the HUD
	// Switch to m_HudView
	m_Window.setView(m_HudView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_Playing)
	{
		m_Window.draw(m_Hud.getMessage());
	}

	// Show everything we have just drawn
	m_Window.display();
}