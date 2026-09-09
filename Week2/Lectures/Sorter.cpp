#include "Sorter.h"


//
// Part A-2
//
/*
procedure bubbleSort(A : list of sortable items)
	n := length(A)
	repeat
		swapped := false
		for i := 1 to n - 1 inclusive do
			if A[i - 1] > A[i] then
				swap(A, i - 1, i)
				swapped = true
			end if
		end for
		n := n - 1
	while swapped
end procedure
*/
void Sorter::bubbleSort(std::vector<Light>& A) const
{
	//	n := length(A)
	int n = A.size();
	//repeat
	
	bool swapped = false;
	do
	{
		//		swapped := false
		swapped = false;
		//		for i := 1 to n - 1 inclusive do
		for (int i = 1; i <= n - 1; i++)
		{
			//if A[i - 1] > A[i] then
			if (A[i - 1].red > A[i].red)
			{
				//swap(A, i - 1, i)
				//TODO: figure out how to swap????
				//NG:
				std::swap(A[i - 1], A[i]);

				//swapped = true
				swapped = true;
			}//end if
		}//end for
		//n := n - 1
		n--; //n = n-1 --n n-- n-=1
	} while (swapped);//while swapped
}//end procedure
