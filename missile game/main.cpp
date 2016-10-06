#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>

int lives = 3;
int targetXCordinate;
int targetYCordinate;
int missileXCordinate;
int missileYCordinate = 100;
bool gameOn = true;
bool collision = false;
int r_Gen();
int r_Gen2();

int main()
{
	srand((unsigned)time(0));
	int targetXCordinate = r_Gen();
	int targetYCordinate = r_Gen2();

	while (gameOn == true)
	{
		std::cout << "Target's x is between 1 and 10 and its y co-ordinate is between 10 and 99. the missile is launched from the y co-ordinate 100 and is launched vertically \nPlease enter the x co-ordinate of where you want the missle to launch from \n";
		std::cin >> missileXCordinate;

		while (collision == false)
		{
			if (missileXCordinate == targetXCordinate)
			{
				collision = true;
				std::cout << "you win" << std::endl;
				system("pause");
				gameOn = false;

			}

			else if (missileYCordinate < targetYCordinate)
			{
				std::cout << "MISSED!! TRY AGAIN \n";
				lives--;
				std::cout << "lives remaining: " << lives << std::endl;
				break;
			}

			missileYCordinate -= 1;
		}

		if (lives == 0)
		{
			std::cout << "GAME OVER" << std::endl;
			system("PAUSE");
			std::exit(0);
		}
	}
}
int r_Gen()
{
	return (rand() % 10) + 1;
}
int r_Gen2()
{
	return(rand() % 99) + 1;
}




