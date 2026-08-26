#pragma once
#include "PG2Graphics.h"
#include <vector>
#include <string>

class GameObject
{
public:
	GameObject(PG2Texture* texture, PG2Graphics* engine, float scale = 1);
	GameObject(PG2Graphics* engine, const std::string& textureFile, float scale = 1, int xPos = 0, int yPos = 0);
	virtual ~GameObject() = default;

	static void SetMap(const std::vector<int>& map, int columns, int rows)
	{
		map_ = map;
		cols_ = columns;
		rows_ = rows;
	}

	int GetXPosition() const { return xPosition_; }
	int GetYPosition() const { return yPosition_; }

	int Size() const { return static_cast<int>(width_ * scale_); }

	virtual void Render() const;
protected:
	virtual void FreeResources();

	std::string textureFilename_;

	//The dimensions of the object
	int width_ = 20;
	int height_ = 20;

	static std::vector<int> map_;
	static int mapSize_;
	static int cols_, rows_;

	static int maxVelocity_;// = 10;

	float scale_;//destination scale

	int xPosition_, yPosition_;
	int xVelocity_, yVelocity_;

	PG2Graphics* engine_;
	PG2Texture* texture_ = nullptr;

};

