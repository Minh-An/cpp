#pragma once
#include <memory>
#include <typeinfo>
#include <map>
#include "entity.h"

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;
	std::map<std::size_t, std::vector<Entity*>> groupedEntities;
public:
	template <typename T, typename... TArgs>
	T& create(TArgs&&... args)
	{
		static_assert(std::is_base_of<Entity, T>::value, "T must be child of Entity");

		auto uniquePtr(std::make_unique<T>(std::forward<TArgs>(args)...));
		auto ptr(uniquePtr.get());

		groupedEntities[typeid(T).hash_code()].emplace_back(ptr);

		entities.emplace_back(std::move(uniquePtr));

		return *ptr;
	}

	void refresh();
	void clear();
	

	template<typename T>
	auto& getAll()
	{
		return groupedEntities[typeid(T).hash_code()];
	}

	template<typename T, typename TFunction>
	void forEach(const TFunction& func)
	{
		auto& vector(getAll<T>());
		for (auto ptr : vector) func(*reinterpret_cast<T*>(ptr));
	}

	void update();
	void draw(RenderWindow& window);
	
};

