#include "manager.h"

void Manager::refresh()
{

	for (auto& pair : groupedEntities)
	{

		auto& group(pair.second);

		group.erase(std::remove_if(group.begin(), group.end(),
			[](auto& ptr) { return ptr->destroyed; }),
			group.end());
	}

	entities.erase(std::remove_if(entities.begin(), entities.end(),
		[](const auto& uniquePtr) { return uniquePtr->destroyed; }),
		entities.end());

}

void Manager::clear()
{
	groupedEntities.clear();
	entities.clear();
}

void Manager::update()
{
	for (auto& entity : entities) entity->update();
}

void Manager::draw(RenderWindow& window)
{
	for (auto& entity : entities) entity->draw(window);
}
