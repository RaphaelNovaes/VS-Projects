#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
	public:
		Player();
		void spawn(IntRect arena, Vector2f resolution, int tileSize);
		// Call this at the end of every game
		void resetPlayerStats();
		// Handle the player getting hit by a zombie
		bool hit(Time timeHit);
		// How long ago was the player las hit
		Time getLastHitTime();
		// Where is the player
		FloatRect getPosition();
		// Where is the center of the player
		Vector2f getCenter();
		// What angle is the player facing
		float getRotation();
		// Send a cop of the sprite to the main function
		Sprite getSprite();
		// The next four functions move the player
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		// Stop the player moving in a specific direction
		void stopLeft();
		void stopRight();
		void stopUp();
		void stopDown();
		// We will call this function once every frame
		void update(float elapsedTime, Vector2i mousePosition);
		// Give the player a speed boost
		void upgradeSpeed();
		// Give the player some health
		void upgradeHealth();
		// Increase the maximun amount of health the player can have
		void increaseHealthLevel(int amount);
		// How much health has the player currently got
		int getHealth();

	private:
		const float START_SPEED = 200;
		const float START_HEALT = 100;
		// Where is the player
		Vector2f m_Position;
		// Of couse, we will need a sprite
		Sprite m_Sprite;
		// Add a texture
		// !!Whatch this space - Interesting changes here soon!!
		Texture m_Texture;
		// What is the screen solution
		Vector2f m_Resolution;
		// What size is the current arena
		IntRect m_Arena;
		// How big is each tile of the arena
		int m_TileSize;
		// Which direction(s) is the player currenctly moveing in
		bool m_UpPressed;
		bool m_DownPressed;
		bool m_LeftPressed;
		bool m_RightPressed;
		// How much health has the player got
		int m_Health;
		// What is the maximun health the player can have
		int m_MaxHealth;
		// When was the player last hit
		Time m_LastHit;
		// Speed in pixelsper second
		float m_Speed;
		// All our plublic functions will  come next
};