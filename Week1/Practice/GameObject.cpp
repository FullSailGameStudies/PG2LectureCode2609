#include "GameObject.h"

int GameObject::mapSize_ = 10;
int GameObject::maxVelocity_ = 10;
int GameObject::cols_ = 10;
int GameObject::rows_ = 10;
std::vector<int> GameObject::map_;


GameObject::GameObject(PG2Texture* texture, PG2Graphics* engine, float scale) :
	engine_(engine)
	, texture_(texture)
	, scale_(scale)
	, xPosition_(0)
	, yPosition_(0)
	, xVelocity_(0)
	, yVelocity_(0)
	, width_(texture->Width())
	, height_(texture->Height())
{
	maxVelocity_ = 1;// (width_ * scale);
}

GameObject::GameObject(PG2Graphics* engine, const std::string& textureFile, float scale, int xPos, int yPos) :
	engine_(engine)
	, scale_(scale)
	, xPosition_(0)
	, yPosition_(0)
	, xVelocity_(0)
	, yVelocity_(0)
	, textureFilename_(textureFile)
{
	texture_ = new PG2Texture(engine->Renderer());
	if (!texture_->LoadFromFile(textureFilename_))
	{
		FreeResources();
	}
	else
	{
		width_ = texture_->Width();
		height_ = texture_->Height();
	}

	maxVelocity_ = 1;// (width_ * scale);//75
	xPosition_ = xPos;// initialXOffset* maxVelocity_;
	yPosition_ = yPos;// initialYOffset* maxVelocity_;
}

void GameObject::FreeResources()
{
	if (texture_ != nullptr)
		delete texture_;
	texture_ = nullptr;
}

void GameObject::Render() const
{
	texture_->Render(static_cast<int>(xPosition_ * width_ * scale_), static_cast<int>(yPosition_ * width_ * scale_), scale_);
}