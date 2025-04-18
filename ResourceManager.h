#pragma once
#include "Headers.h"
class ResourceManager
{
public:
    ResourceManager() = default;
    static ResourceManager& get();

    sf::Font font;
    sf::Texture GameBackground;
    sf::Texture MenuBackground;
    sf::SoundBuffer LaserBuffer;
    sf::Sound LaserSound;

    void loadFont(const std::string& filename);
    void loadTexture_GameBackground(const std::string& filename);
    void loadTexture_MenuBackground(const std::string& filename);
    void loadLaserSound(const std::string& filename);
};

