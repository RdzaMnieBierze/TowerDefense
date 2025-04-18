#include "Headers.h"

int main() {
	sf::RenderWindow Game(sf::VideoMode(static_cast<unsigned int>(GAME_WIDTH), static_cast<unsigned int>(GAME_HEIGHT), 32), "Tower Defense", sf::Style::Titlebar | sf::Style::Close);
	Game.setVerticalSyncEnabled(true);



	Scene CurrentScene = Scene::Menu;
	float CurrentBaseHealth = BASE_HEALTH;
	sf::Clock _timer;
	float Timer = 0.f;
	int Level = 1;
	bool DrawRange = false;
	Levels LevelMaker;

	ResourceManager::get().loadFont(resourcesDir() + "tuffy.ttf");
	ResourceManager::get().loadTexture_GameBackground(resourcesDir() + "Background.png");
	ResourceManager::get().loadTexture_MenuBackground(resourcesDir() + "gradient.png");
	ResourceManager::get().loadLaserSound(resourcesDir() + "Laser_sound.mp3");


	std::vector<std::unique_ptr<Enemy>> Enemies;
	std::vector<Tower> Towers;

#pragma region GameView

	sf::Sprite GameBackground;
	sf::Texture BackgroundTexture = ResourceManager::get().GameBackground;
	GameBackground.setTexture(BackgroundTexture);
	GameBackground.setOrigin(BackgroundTexture.getSize().x / 2.f, BackgroundTexture.getSize().y / 2.f);
	GameBackground.setPosition(GAME_WIDTH / 2.f, GAME_HEIGHT / 2.f);

	sf::Text BaseHealth;
	BaseHealth.setCharacterSize(32);
	BaseHealth.setFont(ResourceManager::get().font);
	BaseHealth.setString("HP: " + std::to_string(CurrentBaseHealth));
	BaseHealth.setFillColor(sf::Color::Black);
	sf::FloatRect textRect = BaseHealth.getLocalBounds();
	BaseHealth.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	BaseHealth.setPosition(555.f, 646.f);

	sf::Text MoneyText;
	MoneyText.setCharacterSize(32);
	MoneyText.setFont(ResourceManager::get().font);
	MoneyText.setString("Money: " + std::to_string(LevelMaker.Money));
	MoneyText.setFillColor(sf::Color::Black);
	textRect = MoneyText.getLocalBounds();
	MoneyText.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	MoneyText.setPosition(188.f, 646.f);


	sf::Text LevelText;
	LevelText.setCharacterSize(32);
	LevelText.setFont(ResourceManager::get().font);
	LevelText.setString("Level: " + std::to_string(LevelMaker.Level));
	LevelText.setFillColor(sf::Color::Black);
	textRect = LevelText.getLocalBounds();
	LevelText.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	LevelText.setPosition(834.f, 646.f);
#pragma endregion

#pragma region MenuView
	sf::Sprite MenuBackground;
	sf::Texture MenuBackgroundTexture = ResourceManager::get().MenuBackground;
	MenuBackground.setTexture(MenuBackgroundTexture);
	MenuBackground.setOrigin(MenuBackgroundTexture.getSize().x / 2.f, MenuBackgroundTexture.getSize().y / 2.f);
	MenuBackground.setPosition(GAME_WIDTH / 2.f, GAME_HEIGHT / 2.f);

	sf::Text Title;
	Title.setCharacterSize(52);
	Title.setFont(ResourceManager::get().font);
	Title.setStyle(sf::Text::Bold);
	Title.setString("Tower Defense");
	Title.setFillColor(sf::Color::Black);
	textRect = Title.getLocalBounds();
	Title.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	Title.setPosition(GAME_WIDTH / 2.f, 150.f);

	sf::Text StartText;
	StartText.setCharacterSize(40);
	StartText.setFont(ResourceManager::get().font);
	StartText.setString("Start");
	StartText.setFillColor(sf::Color::Black);
	textRect = StartText.getLocalBounds();
	StartText.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	StartText.setPosition(GAME_WIDTH / 2.f, 325.f);



	sf::Text InstructionText;
	InstructionText.setCharacterSize(40);
	InstructionText.setFont(ResourceManager::get().font);
	InstructionText.setString("Instruction");
	InstructionText.setFillColor(sf::Color::Black);
	textRect = InstructionText.getLocalBounds();
	InstructionText.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	InstructionText.setPosition(GAME_WIDTH / 2.f, 400.f);

#pragma endregion

#pragma region WinView
	sf::Text VictoryText;
	VictoryText.setCharacterSize(52);
	VictoryText.setFont(ResourceManager::get().font);
	VictoryText.setStyle(sf::Text::Bold);
	VictoryText.setString("YOU WON!");
	VictoryText.setFillColor(sf::Color::Black);
	textRect = Title.getLocalBounds();
	VictoryText.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	VictoryText.setPosition(GAME_WIDTH / 2.f, 250.f);

	sf::Text ScoreText;
	ScoreText.setCharacterSize(52);
	ScoreText.setFont(ResourceManager::get().font);
	ScoreText.setStyle(sf::Text::Bold);
	ScoreText.setString("Money: " + std::to_string(LevelMaker.Money));
	ScoreText.setFillColor(sf::Color::Black);
	textRect = Title.getLocalBounds();
	ScoreText.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	ScoreText.setPosition(GAME_WIDTH / 2.f, 350.f);

#pragma endregion




	while (Game.isOpen()) {
		sf::Event event;
		while (Game.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
				Game.close();
				break;
			}

			if (event.type == sf::Event::Resized)
			{
				sf::View view;
				view.setSize(GAME_WIDTH, GAME_HEIGHT);
				view.setCenter(GAME_WIDTH / 2.f, GAME_HEIGHT / 2.f);
				Game.setView(view);
			}


		}

		Timer = _timer.restart().asSeconds();
		if (CurrentScene == Scene::Game) {
			for (auto& enemy : Enemies) {
				enemy->Update(Timer, CurrentBaseHealth);
			}

			for (auto& enemy : Enemies) {
				if (!enemy->alive) {
					LevelMaker.Money += enemy->ValueForKill;
				}
			}

			Enemies.erase(std::remove_if(Enemies.begin(), Enemies.end(),
				[](const std::unique_ptr<Enemy>& e) { return !e->alive; }), Enemies.end());

			for (auto& tower : Towers) {
				tower.Update(Timer, Enemies, Game);
			}


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2f mousePos = Game.mapPixelToCoords(sf::Mouse::getPosition(Game));
				std::pair<bool, sf::Vector2f> check = validBuildZone(mousePos, Towers);
				if (check.first && LevelMaker.Money >= TOWER_PRICE) {
					Towers.emplace_back(Tower{ check.second });
					LevelMaker.Money -= TOWER_PRICE;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				sf::Vector2f mousePos = Game.mapPixelToCoords(sf::Mouse::getPosition(Game));
				std::pair<bool, sf::Vector2f> check = validBuildZone(mousePos, Towers);
				if (!check.first && check.second != sf::Vector2f(0.f, 0.f) && LevelMaker.Money >= TOWER_UPGRADE) {
					for (auto& tower : Towers) {
						if (check.second == tower.Position && !tower.isUpgraded && tower.Name == "Tower") {
							LevelMaker.Money -= TOWER_UPGRADE;
							tower.Upgrade();
						}
					}
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				sf::Vector2f mousePos = Game.mapPixelToCoords(sf::Mouse::getPosition(Game));
				std::pair<bool, sf::Vector2f> check = validBuildZone(mousePos, Towers);
				if (check.first && LevelMaker.Money >= TOWER_SLOWANDSTRONG_PRICE) {
					Towers.emplace_back(Tower_SlowAndStrong{ check.second });
					LevelMaker.Money -= TOWER_SLOWANDSTRONG_PRICE;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				sf::Vector2f mousePos = Game.mapPixelToCoords(sf::Mouse::getPosition(Game));
				std::pair<bool, sf::Vector2f> check = validBuildZone(mousePos, Towers);
				if (!check.first && check.second != sf::Vector2f(0.f, 0.f) && LevelMaker.Money >= TOWER_SLOWANDSTRONG_UPGRADE) {
					for (auto& tower : Towers) {
						if (check.second == tower.Position && !tower.isUpgraded && tower.Name == "Tower_Slow") {
							LevelMaker.Money -= TOWER_SLOWANDSTRONG_UPGRADE;
							tower.Upgrade();
						}
					}
				}
			}


			if (LevelMaker.GameStarted) {
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !LevelMaker.isStarted) {
					LevelMaker.Ready = true;
					std::cout << "Ready" << std::endl;
				}
				if (LevelMaker.Ready) {
					switch (LevelMaker.Level)
					{
					case 1:
						LevelMaker.Level_1(Enemies, Timer);	
						break;
					case 2:
						LevelMaker.Level_2(Enemies, Timer);
						break;
					case 3:
						LevelMaker.Level_3(Enemies, Timer);
						break;
					}
				}

				if (LevelMaker.Level == 4) {
					CurrentScene = Scene::Win;
					LevelMaker.GameStarted = false;
				}

				if (CurrentBaseHealth <= 0.f) {
					CurrentScene = Scene::Loss;
					LevelMaker.GameStarted = false;
					LevelMaker.isStarted = false;
					LevelMaker.Ready = false;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				DrawRange = true;
			}
			else {
				DrawRange = false;
			}
			
		}

		if (CurrentScene == Scene::Menu) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2f mousePos = Game.mapPixelToCoords(sf::Mouse::getPosition(Game));

				if (mousePos.x >= StartText.getPosition().x - 60.f && mousePos.x <= StartText.getPosition().x + 60.f
					&& mousePos.y >= StartText.getPosition().y - 20.f && mousePos.y <= StartText.getPosition().y + 20.f) {
					CurrentScene = Scene::Game;
					LevelMaker.GameStarted = true;
					LevelMaker.Level = 1;
				}

				if (mousePos.x >= InstructionText.getPosition().x - 90.f && mousePos.x <= InstructionText.getPosition().x + 90.f
					&& mousePos.y >= InstructionText.getPosition().y - 20.f && mousePos.y <= InstructionText.getPosition().y + 20.f) {
					CurrentScene = Scene::Instruction;
					break;
				}
			}
		}


		switch (CurrentScene)
		{
		case Scene::Menu:
			Game.clear();
			Game.draw(MenuBackground);
			Game.draw(Title);
			Game.draw(StartText);
			Game.draw(InstructionText);

			Game.display();
			break;
		case Scene::Game:
			Game.clear();
			Game.draw(GameBackground);
			for (auto& enemy : Enemies) {
				Game.draw(enemy->shape);
				Game.draw(enemy->HPtext);
			}

			for (auto& tower : Towers) {
				Game.draw(tower.shape);
				if(DrawRange) Game.draw(tower.RangeCircle);
				tower.DrawLaser(Game);
				Game.draw(tower.TextLevel);
			}
			Game.draw(MoneyText);
			MoneyText.setString("Money: " + std::to_string(LevelMaker.Money));
			Game.draw(LevelText);
			LevelText.setString("Level: " + std::to_string(LevelMaker.Level));	

			Game.draw(BaseHealth);
			BaseHealth.setString("HP: " + std::to_string((int)CurrentBaseHealth));
			Game.display();
			break;
		case Scene::Win:
			Game.clear();
			Game.draw(MenuBackground);
			ScoreText.setString("Money: " + std::to_string(LevelMaker.Money));
			Game.draw(VictoryText);
			Game.draw(ScoreText);

			Game.display();
			break;
		case Scene::Loss:
			Game.clear();
			Game.draw(MenuBackground);
			break;

		case Scene::Instruction:
			break;
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}