#pragma once
struct Target
{
	int col, row;
	int red, green, blue;

	bool Equals(int x, int y) const
	{
		return col == x && row == y;
	}
};

