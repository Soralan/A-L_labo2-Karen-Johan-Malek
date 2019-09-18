#include "Video.h"
#include <iostream>
#include <string>

bool main(void)
{

	Video* video = new Video;
	int choice;
	std::string nomVideo;

	std::cout << "Qu'elle est le nom de la video : ";
	std::cin >> nomVideo;

	if (SUCCEEDED(video->open(nomVideo))) {

		do {

			std::cout << "1. play-pause, " << std::endl;
			std::cout << "2. accelerer" << std::endl;
			std::cout << "3. retour en arriere" << std::endl;
			std::cout << "4. Quitter" << std::endl;
			std::cin >> choice;

			switch (choice) {
			case 1:
				video->playPause();
				break;
			case 2:
				video->avanceRapide();
				break;
			case 3:
				video->retourDepart();
				break;
			case 4:
				video->Arret();
				break;
			}

		} while (choice != 4);
	}
	else
		std::cout << "Failed to open video" << std::endl;

	return 1;
}