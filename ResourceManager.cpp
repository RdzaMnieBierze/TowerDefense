#include "Headers.h"

ResourceManager& ResourceManager::get() {
    static ResourceManager instance;
    return instance;
}

void ResourceManager::loadFont(const std::string& filename) {
    sf::Font _font;
    if (!_font.loadFromFile(filename)) {
        throw std::runtime_error("Nie mo¿na za³adowaæ fontu: " + filename);
    }
    font = _font;
}

void ResourceManager::loadTexture_GameBackground(const std::string& filename) {
    sf::Texture _texture;
    if (!_texture.loadFromFile(filename)) {
        throw std::runtime_error("Nie mo¿na za³adowaæ texture: " + filename);
    }
    GameBackground = _texture;
}

void ResourceManager::loadTexture_MenuBackground(const std::string& filename) {
    sf::Texture _texture;
    if (!_texture.loadFromFile(filename)) {
        throw std::runtime_error("Nie mo¿na za³adowaæ texture: " + filename);
    }
    MenuBackground = _texture;
}

void ResourceManager::loadLaserSound(const std::string& filename) {
    if (!LaserBuffer.loadFromFile(filename)) {
        throw std::runtime_error("Nie mo¿na za³adowaæ dŸwieku: " + filename);
    }
    LaserSound.setBuffer(LaserBuffer);
    LaserSound.setVolume(5.f);
}