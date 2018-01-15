#pragma once

#include "SFML\Graphics.hpp"
using namespace sf;
constexpr unsigned int winWidth{ 1000 }, winHeight{ 800 };


class Entity
{
public:
	bool destroyed{ false };

	virtual ~Entity() {}
	virtual void update() {}
	virtual void draw(RenderWindow& window) {}
};


struct Rectangle
{
	RectangleShape rect;

	float x() const noexcept;
	float y() const noexcept;  
	float w() const noexcept; 
	float h() const noexcept;  

	float left() const noexcept; 
	float right() const noexcept; 
	float top() const noexcept;
	float bottom() const noexcept;

};

struct Circle
{
	CircleShape circle;

	float x() const noexcept;
	float y() const noexcept;
	float r() const noexcept;
	float left() const noexcept;
	float right() const noexcept;
	float top() const noexcept;
	float bottom() const noexcept;
};

class Ball : public Circle, public Entity
{
public:
	const Color defaultColor{Color::Red};
	static constexpr float defaultRadius{ 10.f };
	static constexpr float defaultVelocity{ 8.f };

	Vector2f velocity{ -defaultVelocity, -defaultVelocity };

	Ball(float x, float y);
	void update();
	void draw(RenderWindow& window);

private:
	void solveCollisions() noexcept;
};

class Paddle : public Rectangle, public Entity
{
public:
	const Color defaultColor{Color::Green};
	static constexpr float defaultWidth{ 100.f };
	static constexpr float defaultHeight{ 20.f };
	static constexpr float defaultVelocity{ 10.f };

	Vector2f velocity;

	Paddle(float x, float y);
	void update();
	void draw(RenderWindow& window);
private:

	void processInput();
};

class Brick : public Rectangle, public Entity
{
public:
	int strength = 1;

	const Color color1{ 255, 255, 0, 80 };
	const Color color2{ 255, 255, 0, 170 };
	const Color color3{ 255, 255, 0, 255 };
	
	const std::vector<Color> colors{ color1, color2, color3 };

	static constexpr float defaultWidth{ 60.f };
	static constexpr float defaultHeight{ 20.f };
	static constexpr float defaultVelocity{ 5.f };

	Brick(float x, float y);

	void draw(RenderWindow& window);
	void update();

};