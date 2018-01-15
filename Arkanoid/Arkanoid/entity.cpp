#include "entity.h"

//Rectange and Circle struct methods
float Rectangle::x() const noexcept { return rect.getPosition().x; }
float Rectangle::y() const noexcept { return rect.getPosition().y; };
float Rectangle::w() const noexcept { return rect.getSize().x; };
float Rectangle::h() const noexcept { return rect.getSize().y; };
float Rectangle::left() const noexcept { return x() - w() / 2.f; };
float Rectangle::right() const noexcept { return x() + w() / 2.f; };
float Rectangle::top() const noexcept { return y() - h() / 2.f; };
float Rectangle::bottom() const noexcept { return y() + h() / 2.f; };

float Circle::x() const noexcept { return circle.getPosition().x; };
float Circle::y() const noexcept { return circle.getPosition().y; };
float Circle::r() const noexcept { return circle.getRadius(); };
float Circle::left() const noexcept { return x() - r(); };
float Circle::right() const noexcept { return x() + r(); };
float Circle::top() const noexcept { return y() - r(); };
float Circle::bottom() const noexcept { return y() + r(); };

//Ball Class methods
Ball::Ball(float x, float y)
{
	circle.setPosition(x, y);
	circle.setFillColor(defaultColor);
	circle.setRadius(defaultRadius);
	circle.setOrigin(defaultRadius, defaultRadius);
};

void Ball::update()
{
	circle.move(velocity);
	solveCollisions();
}

void Ball::draw(RenderWindow& window)
{
	window.draw(circle);
}

void Ball::solveCollisions() noexcept
{
	if (left() < 0 || right() > winWidth) velocity.x = -velocity.x;
	if (top() < 0) velocity.y = -velocity.y;
	if(bottom() > winHeight) {	destroyed = true; }
}

//Paddle Class methods
Paddle::Paddle(float x, float y)
{
	rect.setPosition(x, y);
	rect.setFillColor(defaultColor);
	rect.setSize({ defaultWidth, defaultHeight });
	rect.setOrigin(defaultWidth / 2.f, defaultHeight / 2.f);
};

void Paddle::update()
{
	processInput();
	rect.move(velocity);
}

void Paddle::draw(RenderWindow& window)
{
	window.draw(rect);
}

void Paddle::processInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
	{
		velocity.x = -defaultVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < winWidth)
	{
		velocity.x = defaultVelocity;
	}
	else
	{
		velocity.x = 0;
	}
}

Brick::Brick(float x, float y)
{
	rect.setPosition(x, y);
	rect.setFillColor(colors[strength-1]);
	rect.setSize({ defaultWidth, defaultHeight });
	rect.setOrigin(defaultWidth / 2.f, defaultHeight / 2.f);
};

void Brick::draw(RenderWindow& window) { window.draw(rect); }

void Brick::update()
{
	rect.setFillColor(colors[strength - 1]);
}
