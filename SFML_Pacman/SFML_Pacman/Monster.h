#pragma once

#include <random>
#include "Entity.h"

class Monster : public Entity {

private:
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 6);

	void monsterAI();
};

void Monster::monsterAI() {
	
}