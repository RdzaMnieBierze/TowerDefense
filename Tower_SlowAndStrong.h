#pragma once
#include "Headers.h"
class Tower_SlowAndStrong : public Tower
{
public:
    Tower_SlowAndStrong(sf::Vector2f&);
    float maxLaserTimer = 1.f;
    std::string Name = "Tower_Slow";
};

