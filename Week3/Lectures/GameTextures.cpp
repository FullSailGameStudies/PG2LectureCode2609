#include "GameTextures.h"

TTF_Font* GameTextures::font_ = NULL;
std::vector<Number> GameTextures::scoreTextures_;
PG2Texture* GameTextures::cardsSpriteSheet_;
SDL_Renderer* GameTextures::renderer_;
int GameTextures::markedIndex_ = 9;
int GameTextures::start = 1, GameTextures::cardWidth = 72, GameTextures::cardHeight = 96;
std::map<std::string, pos> GameTextures::suitStarts;


void GameTextures::Initialize(SDL_Renderer* renderer)
{
	if (font_ == NULL)
	{
		font_ = TTF_OpenFont("consola.ttf", 28);
		if (font_ == NULL)
		{
			printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		}
	}
	renderer_ = renderer;
	loadRenderedText();
	loadImageTextures();

	suitStarts["Clubs"] = { 1,1 };
	suitStarts["Spades"] = { 1,99 };
	suitStarts["Hearts"] = { 1,197 };
	suitStarts["Diamonds"] = { 1,295 };
}

void GameTextures::loadImageTextures()
{
	cardsSpriteSheet_ = new PG2Texture(renderer_);
	if (cardsSpriteSheet_->LoadFromFile("cards_02.png"))
		cardsSpriteSheet_->BlendMode(SDL_BLENDMODE_NONE);

}

void GameTextures::Cleanup()
{
	free();
}

void GameTextures::free()
{
	//Free textures if they exists
	for (auto& number : scoreTextures_)
	{
		number.free();
	}

	delete cardsSpriteSheet_;
	cardsSpriteSheet_ = nullptr;

	if (font_ != NULL)
	{
		TTF_CloseFont(font_);
		font_ = NULL;
	}
}

bool GameTextures::loadRenderedText()//, SDL_Color textColor)
{
	if (font_ == NULL) return false;
	SDL_Color textColor = { 255, 255, 255 };
	SDL_Color player1TextColor = { 0xD9, 0xD6, 0x02 };
	SDL_Color player2TextColor = { 0xD9, 0x00, 0x00 };

	std::vector<std::string> text{ "0","1","2","3","4","5","6","7","8","9","10","AAA","NPC"," : ","!! WINNER !! ", "TIE :-("};

	int width = 0, height = 0;
	for (int i = 0; i < text.size(); i++)
	{
		//Render text surface
		SDL_Surface* textSurface = TTF_RenderText_Solid(font_, text[i].c_str(), (i==ScoreTexture::Player1) ? player1TextColor : ((i == ScoreTexture::Player2) ? player2TextColor : textColor));
		if (textSurface == NULL)
		{
			printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		}
		else
		{
			//Create texture from surface pixels
			SDL_Texture* mTexture = SDL_CreateTextureFromSurface(renderer_, textSurface);
			if (mTexture == NULL)
			{
				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get image dimensions
				width = textSurface->w;
				height = textSurface->h;
			}

			//Get rid of old surface
			SDL_FreeSurface(textSurface);

			scoreTextures_.push_back(Number(mTexture, width, height));
		}
	}

	return scoreTextures_.size() > 0;
}

void GameTextures::RenderNumber(int number, int x, int y, int cellSize, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	if (number <= scoreTextures_.size())
	{
		Number& numberTexture = scoreTextures_[number];
		int w = numberTexture.Width(), h = numberTexture.Height();

		//Set rendering space and render to screen
		SDL_Rect renderQuad = { x, y, w, h };

		//Set clip rendering dimensions
		if (clip != NULL)
		{
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		//Render to screen
		SDL_RenderCopyEx(renderer_, numberTexture.Texture(), clip, &renderQuad, angle, center, flip);
	}
}
void GameTextures::ScoreItemSize(int number, int& width, int& height)
{
	if (number <= scoreTextures_.size())
	{
		Number& numberTexture = scoreTextures_[number];
		width = numberTexture.Width();
		height = numberTexture.Height();
	}
}
void GameTextures::RenderImage(std::string face, std::string suit, int x, int y, float scale, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//if (imageTextures_.size() == MatchingCard::LASTCARD)
	//{
	//	PG2Texture* texture = imageTextures_[number];
		//float scale = scale = cellSize / (float)texture->Width();
		//texture->Render(x, y, scale);//scale to cellSize?
	//}

	pos start = suitStarts[suit];
	int offset = 0;
	if (face == "A")
		offset = 0;
	else if (face == "J")
		offset = 10;
	else if (face == "Q")
		offset = 11;
	else if (face == "K")
		offset = 12;
	else
		offset = std::stoi(face)-1;

	//SDL_Rect srcRect{ start.x + (offset * (cardWidth+1)) - 1, start.y - 1, cardWidth + 2, cardHeight + 2};
	SDL_Rect srcRect{ start.x + (offset * (cardWidth+1)), start.y, cardWidth, cardHeight};
	SDL_Rect dstRect{ x, y, static_cast<int>(cardWidth * scale), static_cast<int>(cardHeight * scale) };
	//float scale = scale = cellSize / (float)cardsSpriteSheet_->Width();
	cardsSpriteSheet_->Render(&srcRect, &dstRect);
}

pos GameTextures::CardSize(float scale)
{
	return { (int)(cardWidth * scale), (int)(cardHeight * scale) };
}

void Number::free()
{
	if (texture_ != NULL)
	{
		SDL_DestroyTexture(texture_);
		texture_ = NULL;
	}
}
