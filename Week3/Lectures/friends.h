#pragma once

class Box;//forward declaration
class GraphicsEngine
{
public:
	void Draw(Box& box);
};

void GraphicsEngine::Draw(Box& box)
{
	//accessing the private fields of box
	if (box.width > 0 && box.height > 0)
	{
	}
}

class Box
{
private:
	int width, height;
public:
	//grant GraphicsEngine::Draw function  
	//access to my private members
	friend void GraphicsEngine::Draw(Box& box);
};
