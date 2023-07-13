#include <iostream>
#include <ctime>
#include <climits>

int main() {
	srand(time(0));

	std::cout << "WELCOME TO THE MINI-GAME \"GUESS RANDOM NUMBER's (1-50)\" " << std::endl;
	std::cout << "RULES: NO RULES, BUT YOU SHOULD GUESS WHAT NUMBER I GUESSED FOR YOU. (CHOOSE THE NUMBER OF ATTEMPTS)" << std::endl;

	int playerNum;
	int genNum;
	int attempts = 0;
	int highscore = INT_MAX;
	int maxAttempts;
	bool playAgain = true;

	while (playAgain)
	{
		genNum = rand() % 51;

		std::cout << "Choose the number of attempts (3, 5, -1 for infinite attempts, -2 to leave this game): ";
		std::cin >> maxAttempts;
		
		if (maxAttempts == -2)
		{
			playAgain = false;
			break;
		}

		switch (maxAttempts)
		{
		case 3:
			std::cout << "You have 3 attempts to guess the number." << std::endl;
			break;
		case 5:
			std::cout << "You have 5 attempts to guess the number." << std::endl;
			break;
		case -1:
			std::cout << "You have infinite attempts to guess the number." << std::endl;
			break;
		default:
			std::cout << "Invalid number of attempts. Defaulting to infinite attempts." << std::endl;
			maxAttempts = -1;
			std::cout << "You have infinite attempts to guess the number." << std::endl;
			break;
		}

		while (true)
		{
			std::cout << "TRY TO GUESS THE NUMBER (-2 to leave the game): " << std::endl;
			std::cin >> playerNum;

			if (playerNum == -2)
			{
				playAgain = false;
				break;
			}

			if (playerNum < 0 || playerNum > 50)
			{
				std::cout << "THIS NUMBER IS OUT OF RANGE! TRY AGAIN..." << std::endl;
				continue;
			}

			attempts++;

			if (playerNum == genNum)
			{
				std::cout << "OMFG, YOU ARE A FU**ING GENIUS! WELL PLAYED!" << std::endl;

				if (attempts < highscore)
				{
					highscore = attempts;
					std::cout << "NEW HIGHSCORE! LOWEST NUMBER OF ATTEMPTS: " << highscore << std::endl;
				}
				else
				{
					std::cout << "CURRENT HIGHSCORE: " << highscore << " ATTEMPTS" << std::endl;
				}

				break;
			}
			else
			{
				if (playerNum > genNum + 20)
				{
					std::cout << "PROMPT: YOUR NUMBER IS BIGGER THAN THE GUESS BY MORE THAN 20" << std::endl;
				}
				else if (playerNum > genNum + 10)
				{
					std::cout << "PROMPT: YOUR NUMBER IS BIGGER THAN THE GUESS BY MORE THAN 10" << std::endl;
				}
				else if (genNum > playerNum + 20)
				{
					std::cout << "PROMPT: THE GUESS NUMBER IS BIGGER THAN YOUR NUMBER BY MORE THAN 20" << std::endl;
				}
				else if (genNum > playerNum + 10)
				{
					std::cout << "PROMPT: THE GUESS NUMBER IS BIGGER THAN YOUR NUMBER BY MORE THAN 10" << std::endl;
				}
				else
				{
					std::cout << "OOH WHOUU YOU ARE CLOSED XD!" << std::endl;
				}
			}

			if (maxAttempts != -1 && attempts >= maxAttempts)
			{
				std::cout << "YOU RAN OUT OF ATTEMPTS! THE CORRECT NUMBER WAS: " << genNum << std::endl;
				break;
			}
		}

		attempts = 0;
	}

	std::cout << "THE GAME HAS ENDED. THANK YOU FOR PLAYING!" << std::endl;

	return 0;
}