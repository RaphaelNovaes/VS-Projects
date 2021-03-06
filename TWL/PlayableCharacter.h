#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class PlayableCharacter
{
protected:
	// Of course we will need a sprite
	Sprite m_Sprite;
	// How long does a jump last
	float m_JumpDuration;
	// Is character currently jumping or falling
	bool m_IsJumping;
	bool m_IsFalling;
	// Which directions is the character currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;
	// How long has this initiated a jump
	float m_TimeThisJump;
	// Has the player jus initiated a jump?
	bool m_JustJumped = false;
	// Private variables and functions come next

private:
	// What is the gravit
	float m_Gravity;
	// How fast is the character
	float m_Speed = 400;
	// Where is the player
	Vector2f m_Position;
	// Where are the character varius body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;
	// And a texture
	Texture m_Texture;
	// All our public function will come next

public:
	void spawn(Vector2f startPosition, float gravity);
	// This is a pure virtual abstract function
	bool virtual handleInput() = 0;
	// This class is now abstract and cannot be instantited
	// Where is the player
	FloatRect getPosition();
	// A rectangle representing the position of different parts of the sprite
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();
	// Send a copy of the sprite to main
	Sprite getSprite();
	// Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();
	// Where is the center of the character
	Vector2f getCenter();
	// We will call this function once every frame
	void update(float elapsedTime);


};// End of the class