#include "Player.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <SDL_mixer.h>
#include <Console.h>

int Player::maxVelocity_ = 10;
Mix_Chunk* gStep = NULL;
std::vector<Mix_Chunk*> gSteps;
Mix_Music* gMusic = NULL;

Player::Player(PG2Texture* texture, PG2Graphics* engine, float scale) :
	engine_(engine)
	, texture_(texture)
	, scale_(scale)
	, xPosition_(0)
	, yPosition_(0)
	, xVelocity_(0)
	, yVelocity_(0)
	, width_(texture->Width())
	, height_(texture->Height())
	, mapSize_(10)
	, canAddAction_(true)
{
	maxVelocity_ = 1;// (width_ * scale);
	LoadInventory();
}

Player::Player(PG2Graphics* engine, float scale, int xPos, int yPos) :
	engine_(engine)
	, scale_(scale)
	, xPosition_(0)
	, yPosition_(0)
	, xVelocity_(0)
	, yVelocity_(0)
	, mapSize_(10)
	, canAddAction_(true)
{

	//PG2Texture dotTexture(engine->Renderer());
	texture_ = new PG2Texture(engine->Renderer());

	if (!texture_->LoadFromFile("steve.png"))
	{
		FreeResources();
	}
	else
	{
		width_ = texture_->Width();
		height_ = texture_->Height();
	}


	//Load sound effects
	gStep = Mix_LoadWAV("Grass_hit1.ogg");
	gSteps.push_back(gStep);
	gSteps.push_back(Mix_LoadWAV("Grass_hit2.ogg"));
	gSteps.push_back(Mix_LoadWAV("Grass_hit3.ogg"));
	gSteps.push_back(Mix_LoadWAV("Grass_hit4.ogg"));
	gSteps.push_back(Mix_LoadWAV("Grass_hit5.ogg"));
	gSteps.push_back(Mix_LoadWAV("Grass_hit6.ogg"));
	if (gStep == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}

	//Load music
	gMusic = Mix_LoadMUS("jocofullinterview41.ogg");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		//success = false;
	}

	maxVelocity_ = 1;// (width_ * scale);//75
	xPosition_ = xPos;// initialXOffset* maxVelocity_;
	yPosition_ = yPos;// initialYOffset* maxVelocity_;
	LoadInventory();
}

Player::~Player()
{
	FreeResources();
}

void Player::FreeResources()
{
	if (texture_ != nullptr)
		delete texture_;
	texture_ = nullptr;

	Mix_FreeChunk(gStep);
	gStep = nullptr;

	for (auto& chunk : gSteps)
	{
		Mix_FreeChunk(chunk);
	}
	gSteps.clear();

	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = nullptr;
}

bool Player::HandleEvent(SDL_Event& e, const std::vector<int>& map, int mapSize)
{
	bool quit = false;
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_ESCAPE: quit = true; break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		bool move = false;
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			MoveUp();
			move = true;
			break;
		case SDLK_DOWN:
			MoveDown();
			move = true;
			break;
		case SDLK_LEFT:
			MoveLeft();
			move = true;
			break;
		case SDLK_RIGHT:
			MoveRight();
			move = true;
			break;
		case SDLK_SPACE:
			Interact(map, mapSize);
			break;
		}
		if (move) Move(map, cols_, rows_);
	}
	return quit;
}

void Player::MoveUp()
{
	yVelocity_ -= maxVelocity_;
	Move(map_, cols_, rows_);
	AddUndo("MoveUp");
}

void Player::MoveDown()
{
	yVelocity_ += maxVelocity_;
	Move(map_, cols_, rows_);
	AddUndo("MoveDown");
}

void Player::MoveLeft()
{
	xVelocity_ -= maxVelocity_;
	Move(map_, cols_, rows_);
	AddUndo("MoveLeft");
}

void Player::MoveRight()
{
	xVelocity_ += maxVelocity_;
	Move(map_, cols_, rows_);
	AddUndo("MoveRight");
}

bool Player::CanMove(Direction direction)
{
	bool canMove = false;
	switch (direction)
	{
	case Up:
		canMove = CanMove(xPosition_, yPosition_ - maxVelocity_);
		break;
	case Down:
		canMove = CanMove(xPosition_, yPosition_ + maxVelocity_);
		break;
	case Left:
		canMove = CanMove(xPosition_ - maxVelocity_, yPosition_);
		break;
	case Right:
		canMove = CanMove(xPosition_ + maxVelocity_, yPosition_);
		break;
	default:
		break;
	}
	return canMove;
}

void Player::Interact()
{
	Interact(map_, cols_);
	AddUndo("Interact");
}

void Player::Interact(const std::vector<int>& map, int mapSize)
{
	//check player's position w/ map to see if interact does anything
	int index = yPosition_ * mapSize + xPosition_;
	if (map[index] == 2)
	{
		//interact causes action...
		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			Mix_PlayMusic(gMusic, -1);
		}
		//If music is being played
		else
		{
			//If the music is paused
			if (Mix_PausedMusic() == 1)
			{
				//Resume the music
				Mix_ResumeMusic();
			}
			//If the music is playing
			else
			{
				//Pause the music
				Mix_PauseMusic();
			}
		}
	}
}

void Player::LoadInventory()
{
	for (size_t i = 0; i < 20; i++)
	{
		inventory_.push_back((Item)(rand() % (Shield + 1)));
	}
}

void Player::ShowInventory()
{
	Console::WriteLine("\nInventory", ConsoleColor::Yellow);
	for (Item& item : inventory_)
	{
		switch (item)
		{
		case Pickaxe:
			Console::WriteLine("Pickaxe", ConsoleColor::Cyan);
			break;
		case Shovel:
			Console::WriteLine("Shovel", ConsoleColor::Cyan);
			break;
		case Hoe:
			Console::WriteLine("Hoe", ConsoleColor::Cyan);
			break;
		case Bow:
			Console::WriteLine("Bow", ConsoleColor::Cyan);
			break;
		case Crossbow:
			Console::WriteLine("Crossbow", ConsoleColor::Cyan);
			break;
		case Sword:
			Console::WriteLine("Sword", ConsoleColor::Cyan);
			break;
		case Shield:
			Console::WriteLine("Shield", ConsoleColor::Cyan);
			break;
		default:
			break;
		}
	}
}

void Player::StoreItems(Item itemToStore, std::vector<Item>& chest)
{
	for (size_t i = 0; i < inventory_.size(); i++)
	{
		if (inventory_[i] == itemToStore)
		{
			chest.push_back(inventory_[i]);
			inventory_.erase(inventory_.begin() + i);
			i--;//make sure to not skip items
		}
	}
}

bool Player::CanMove(int xPos, int yPos)
{
	if (xPos < 0 || yPos < 0 || xPos > cols_ - 1 || yPos > rows_ - 1)
		return false;

	int index = yPos * cols_ + xPos;
	if (map_[index] != 1)
		return true;

	return false;
}

void Player::Move(const std::vector<int>& map, int mapSize)
{
	//Move the player's x position
	int newXPosition = xPosition_ + xVelocity_;

	//if the new x position is outside of the bounds...
	if (newXPosition < 0)
		newXPosition = 0;
	else if (newXPosition > mapSize - 1)
		newXPosition = mapSize - 1;
	//else if ((xPosition_ + (width_ * scale_) > engine_->Width()))
	//	xPosition_ = engine_->Width() - (width_ * scale_);



	//Move the player's y position
	int newYPosition = yPosition_ + yVelocity_;

	//if the new y position is outside of the bounds...
	if (newYPosition < 0)
		newYPosition = 0;
	else if (newYPosition > mapSize - 1)
		newYPosition = mapSize - 1;
	//else if (yPosition_ + (height_ * scale_) > engine_->Height())
	//	yPosition_ = engine_->Height() - (height_ * scale_);

	int index = newYPosition * mapSize + newXPosition;
	if (map[index] != 1)
	{
		xPosition_ = newXPosition;
		yPosition_ = newYPosition;

		Mix_PlayChannel(-1, gSteps[rand() % gSteps.size()], 0);
	}

	xVelocity_ = 0;
	yVelocity_ = 0;
	//std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
void Player::Move(const std::vector<int>& map, int columns, int rows)
{
	//Move the player's x position
	int newXPosition = xPosition_ + xVelocity_;

	//if the new x position is outside of the bounds...
	if (newXPosition < 0)
		newXPosition = 0;
	else if (newXPosition > columns - 1)
		newXPosition = columns - 1;
	//else if ((xPosition_ + (width_ * scale_) > engine_->Width()))
	//	xPosition_ = engine_->Width() - (width_ * scale_);



	//Move the player's y position
	int newYPosition = yPosition_ + yVelocity_;

	//if the new y position is outside of the bounds...
	if (newYPosition < 0)
		newYPosition = 0;
	else if (newYPosition > rows - 1)
		newYPosition = rows - 1;
	//else if (yPosition_ + (height_ * scale_) > engine_->Height())
	//	yPosition_ = engine_->Height() - (height_ * scale_);

	int index = newYPosition * columns + newXPosition;
	if (map[index] != 1)
	{
		xPosition_ = newXPosition;
		yPosition_ = newYPosition;

		Mix_PlayChannel(-1, gSteps[rand() % gSteps.size()], 0);
	}

	xVelocity_ = 0;
	yVelocity_ = 0;
	//std::this_thread::sleep_for(std::chrono::milliseconds(500));
}


void Player::Render()
{
	texture_->Render(static_cast<int>(xPosition_ * width_ * scale_), static_cast<int>(yPosition_ * width_ * scale_), scale_);
}

void Player::Undo()
{
	if (undo_.empty()) return;

	//remove last item from the undo_ vector
	std::string action = undo_.back();

	//make the students do this?
	undo_.erase(undo_.end() - 1);

	//insert the item to the front of the redo_ vector
	AddRedo(action);

	canAddAction_ = false;
	//undo the action
	if (action == "MoveUp")
	{
		MoveDown();
	}
	else if (action == "MoveDown")
	{
		MoveUp();
	}
	else if (action == "MoveLeft")
	{
		MoveRight();
	}
	else if (action == "MoveRight")
	{
		MoveLeft();
	}
	else if (action == "Interact")
	{
		Interact();
	}
	canAddAction_ = true;
}

void Player::Redo()
{
	if (redo_.empty()) return;

	//remove the first item from the redo_ vector
	std::string action = redo_.front();

	//make the students do this?
	redo_.erase(redo_.begin());

	//push back the item to the undo_ vector
	AddUndo(action);

	canAddAction_ = false;
	//redo the action
	if (action == "MoveUp")
	{
		MoveUp();
	}
	else if (action == "MoveDown")
	{
		MoveDown();
	}
	else if (action == "MoveLeft")
	{
		MoveLeft();
	}
	else if (action == "MoveRight")
	{
		MoveRight();
	}
	else if (action == "Interact")
	{
		Interact();
	}
	canAddAction_ = true;
}

void Player::AddUndo(const std::string& action)
{
	if (canAddAction_)
	{
		//push back the item to the undo_ vector
		undo_.push_back(action);
	}
}

void Player::AddRedo(const std::string& action)
{
	//insert the item to the front of the redo_ vector
	redo_.insert(redo_.begin(), action);
}
