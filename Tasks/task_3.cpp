#include <iostream>

/*
 * Направете програма, улесняваща работата на инспектор в учебен отел на ПУ.
 * При въвеждане на факултетен номер на студент, извежда формата на обучение, която е записана чрез цифрата на хилядните : 1 - редовна, 2 - задочна.
 * Например: вх. XXXX2XXX -> изх. задочна форма
 */
int main()
{
	int faculty_number, value_at_thousand;

	std::cout << "Enter faculty number: " << std::endl;
	std::cin >> faculty_number;

	value_at_thousand = (faculty_number / 1000) % 10;

	switch (value_at_thousand)
	{
	case 1: std::cout << "Regular" << std::endl; break;
	case 2: std::cout << "Remote" << std::endl; break;
	default: std::cout << "Invalid" << std::endl; break;
	}

	return 0;
}