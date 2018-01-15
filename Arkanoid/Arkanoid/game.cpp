#include "game.h"

//collision checks
void Game::solvePaddleBallCollision(const Paddle& paddle, Ball& ball) noexcept
{
	if (!isColliding(paddle, ball)) return;

	ball.velocity.y = -Ball::defaultVelocity;
	ball.velocity.x = ball.x() < paddle.x() ? -Ball::defaultVelocity : Ball::defaultVelocity;
}

void Game::solveBrickBallCollision(Brick& brick, Ball& ball) noexcept
{
	if (!isColliding(brick, ball)) return;

	--brick.strength;
	if (brick.strength <= 0) brick.destroyed = true;

	float overlapLeft = std::abs(ball.right() - brick.left());
	float overlapRight = std::abs(brick.right() - ball.left());
	float overlapTop = std::abs(ball.bottom() - brick.top());
	float overlapBottom = std::abs(brick.bottom() - ball.top());


	float overlapX = std::min(overlapLeft, overlapRight);
	float overlapY = std::min(overlapTop, overlapBottom);

	if (overlapX < overlapY)
	{
		ball.velocity.x = overlapLeft < overlapRight ? -Ball::defaultVelocity : Ball::defaultVelocity;
	}
	else
	{
		ball.velocity.y = overlapTop < overlapBottom ? -Ball::defaultVelocity : Ball::defaultVelocity;
	}

}


Game::Game() 
{
	lives = 7;
	window.setFramerateLimit(60);

	font.loadFromFile(R"(C:\Windows\Fonts\Arial.ttf)");

	stateText.setFont(font);
	stateText.setPosition(10, 10);
	stateText.setCharacterSize(35.f);
	stateText.setFillColor(Color::White);
	stateText.setString("Paused");

	livesText.setFont(font);
	livesText.setPosition(10, 10);
	livesText.setCharacterSize(15.f);
	livesText.setFillColor(sf::Color::White);
};

void Game::restart()
{
	lives = 7;

	state = State::Paused;
	manager.clear();

	manager.create<Ball>(winWidth / 2.f, winHeight / 2.f);
	manager.create<Paddle>(winWidth / 2.f, winHeight - 50);

	for (int i{ 0 }; i < brickColumns; ++i)
	{
		for (int j{ 0 }; j < brickRows; ++j)
		{
			float x{ i * (Brick::defaultWidth + brickSpacing) };
			float y{ (j + 2) * (Brick::defaultHeight + brickSpacing) };
			auto& brick(manager.create<Brick>(brickMargin + x, y));
			brick.strength = 1 + ((i * j) % 3);

		}
	}

}

void Game::run()
{
	while (window.isOpen())
	{
		window.clear();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Space))
		{
			if (!pausedPressed)
			{
				if (state == State::Paused)	{ state = State::Running; }
				else if (state == State::Running) {	state = State::Paused; }
			}
			pausedPressed = true;
		}
		else { pausedPressed = false; }

		if (Keyboard::isKeyPressed(Keyboard::Key::R)) restart();

		if (state != State::Running)
		{
			if (state == State::Paused) stateText.setString("Paused");
			else if (state == State::Lost)	stateText.setString("You Lost :(");
			else if (state == State::Victory) stateText.setString("You Won!!!");
			window.draw(stateText);
		}
		else
		{
			if (manager.getAll<Ball>().empty())
			{
				manager.create<Ball>(winWidth / 2.f, winHeight / 2.f);
				--lives;
			}

			if (manager.getAll<Brick>().empty())
			{
				state = State::Victory;
			}

			if (lives <= 0)
			{
				state = State::Lost;
			}

			//update game entities
			manager.update();

			manager.forEach<Ball>([this](auto& ball)
			{
				manager.forEach<Paddle>([this, &ball](auto& paddle)
				{
					solvePaddleBallCollision(paddle, ball);
				});
				manager.forEach<Brick>([this, &ball](auto& brick)
				{
					solveBrickBallCollision(brick, ball);
				});
			});

			manager.refresh();
			livesText.setString("Lives Left: " + std::to_string(lives));
			window.draw(livesText);
		}



		//draw all game entities
		manager.draw(window);
		window.display();

	}
}
