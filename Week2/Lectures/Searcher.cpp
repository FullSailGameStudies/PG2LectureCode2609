#include "Searcher.h"

//
// Part B-1
//

int Searcher::LinearSearch(const std::vector<Light>& lights, int green) const
{
    int foundIndex = NOT_FOUND;
	for (int i = 0; i < lights.size(); i++)
	{
		if (green == lights[i].green)
		{
			foundIndex = i;
			break;
		}
	}
    return foundIndex;
}
