#pragma once
#include "PG2Graphics.h"
#include <vector>
#include <string>

enum Direction
{
	Up, Down, Left, Right
};

enum Item
{
	Pickaxe, Shovel, Hoe, Bow, Crossbow, Sword, Shield
};

class Player
{
public:
	Player(PG2Texture* texture, PG2Graphics* engine, float scale = 1);
	Player(PG2Graphics* engine, float scale = 1, int xPos = 0, int yPos = 0);
	~Player();

	void SetMap(const std::vector<int>& map, int columns, int rows)
	{
		map_ = map;
		cols_ = columns;
		rows_ = rows;
	}

	bool HandleEvent(SDL_Event& e, const std::vector<int>& map, int mapSize = 10);

	void Move(const std::vector<int>& map, int mapSize = 10);
	void Move(const std::vector<int>& map, int columns = 10, int rows = 10);
	void Render();

	void Undo();
	void Redo();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	bool CanMove(Direction direction);

	int GetXPosition() { return xPosition_; }
	int GetYPosition() { return yPosition_; }

	int Size() { return static_cast<int>(width_ * scale_); }

	void AddUndo(const std::string& action);
	void AddRedo(const std::string& action);

	void Interact(const std::vector<int>& map, int mapSize = 10);
	void Interact();

	bool IsValid() { return texture_ != nullptr; }

	void LoadInventory();
	void ShowInventory();
	void StoreItems(Item itemsToStore, std::vector<Item>& chest);

private:

	bool CanMove(int xPos, int yPos);
	bool canAddAction_;

	//The dimensions of the player
	int width_ = 20;
	int height_ = 20;

	std::vector<int> map_;
	int mapSize_;
	int cols_, rows_;

	std::vector<std::string> undo_, redo_;
	std::vector<Item> inventory_;

	static int maxVelocity_;// = 10;

	float scale_;//destination scale

	int xPosition_, yPosition_;
	int xVelocity_, yVelocity_;

	PG2Graphics* engine_;
	PG2Texture* texture_ = nullptr;

	void FreeResources();
};

