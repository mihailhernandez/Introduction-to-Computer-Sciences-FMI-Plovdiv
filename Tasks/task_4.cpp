#include <iostream>

/*
 * Направете програма за кодиране на шпионска информация:
 * Вход на инициалите на таен агент (напр. А.C.D.)
 * Изход на кодираната информация чрез кода на Цезар при n=2 (за примера: С.Е.F.)
 * Код на Цезар: Всяка буква се заменя с буквата отдалечена на разстояние n=2, напр. А->C, B->D, .... 
 * Последните две букви се прехвърлят в началото на азбуката (може да се пропусне за момента)
 */
int main()
{
	const unsigned int LETTER_COUNT = 3;
	const unsigned int CEASAR_OFFSET = 2;

	char letters[LETTER_COUNT];
	char current_letter;

	for (int i = 0; i < LETTER_COUNT; i++)
	{
		std::cout << "Enter letter " << i + 1 << ": ";	
		std::cin >> letters[i];
		if (letters[i] < 'A' || letters[i] > 'Z')
		{
			std::cout << "Please enter a letter A-Z. ";
			i--;
			continue;
		}
		letters[i] += CEASAR_OFFSET;
		if (letters[i] > 'Z')
		{
			letters[i] -= 'Z' - 'A' + 1;
		}
	}

	for (int i = 0; i < LETTER_COUNT; i++)
	{
		std::cout << letters[i] << " ";
	}

	return 0;
}