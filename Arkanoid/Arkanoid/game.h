#pragma once
#include "manager.h"

class Game
{
private:

	Font font;
	Text stateText;

	int lives;
	Text livesText;

	enum class State { Lost, Paused, Running, Victory };

	static constexpr int brickColumns{ 15 }, brickRows{ 5 };
	static constexpr float brickSpacing{ 3 }, brickMargin{ 60.f };

	State state{ State::Running };
	bool pausedPressed{ false };

	Manager manager;
	RenderWindow window{ { winWidth, winHeight }, "Arkanoid Clone" };

	template <typename S1, typename S2>
	bool isColliding(const S1& a, const S2& b) noexcept
	{
		return a.right() >= b.left() && a.left() <= b.right() && a.bottom() >= b.top() && a.top() <= b.bottom();
	}

	void solvePaddleBallCollision(const Paddle& paddle, Ball& ball) noexcept;

	void solveBrickBallCollision(Brick& brick, Ball& ball) noexcept;

public:
	Game();
	void restart();
	void run();
};
