#include "Main.h"

int main ()
// int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdParam, int iCmdShow)
{
	InitRNG();
	unsigned int data[8][2];
	int size1 = sizeof(data)/sizeof(data[0]);
	int size2 = sizeof(data[0])/sizeof(data[0][0]);

	while(true)
	{
		for (int i=0; i<size2; i++)
			FillRandom::FillArray(data, 0, 10, i);
		
		for (int i=0; i<size1; i++)
			std::cout << "(" << data[i][0] << "," << data[i][1] << ") ";

		std::cout << std::endl;

		dataSort.Quicksort(data, 0);

		for (int i=0; i<size1; i++)
			std::cout << "(" << data[i][0] << "," << data[i][1] << ") ";

		std::cout << std::endl;
		system("pause");
		std::cout << std::endl;
	}
}
