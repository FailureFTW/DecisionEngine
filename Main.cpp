#include "Main.h"

int main ()
// int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdParam, int iCmdShow)
{
	InitRNG();
	HashInit();
	SquareType data[NUM_SQUARES];
	SquareType ranks[NUM_SQUARES][2];

	while(true)
	{
		FillRandom::FillArray(data, 0, 17);

		for (int i=0; i<NUM_SQUARES; i++)
			ranks[i][0] = i;
		
		for (int i=0; i<NUM_SQUARES; i++)
			ranks[i][1] = data[i];
		
		std::cout << "Board:" << std::endl;
		for (int i=0; i<NUM_SQUARES; i++)
			std::cout << "(" << int(ranks[i][0]) << "," << int(ranks[i][1]) << ") ";
		
		std::cout << std::endl;

		sorting.Quicksort(ranks, 1);
		
		std::cout << "Ranks:" << std::endl;
		for (int i=0; i<NUM_SQUARES; i++)
			std::cout << "(" << int(ranks[i][0]) << "," << int(ranks[i][1]) << ") ";
		
		std::cout << std::endl;

		std::cout << "Key:" << GenerateKey(data) << std::endl << std::endl;

		system("pause");
		std::cout << std::endl;
	}
}
