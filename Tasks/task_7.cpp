#include <iostream>

/* Въведете число в 7-ична бройна система като текст, съдържащ точно 3 знака, които са цифри (от интервала 0-6).
 * Изведете това число в 10-ична бройна система.
 */
int main()
{
	char *number_str = new char[4];
	int decimal_number = 0;

	std::cin >> number_str;

	for (int i = 2; i >= 0; i--)
	{
		char c = number_str[i];
		if (c < '0' || c > '6')
		{
			std::cerr << "Invalid number in septenary base." << std::endl;
			return -1;
		}
		long power_of_seven = 1;
		for (int j = 0; j < 2 - i; power_of_seven *= 7, j++);

		decimal_number += power_of_seven * (c - '0');
	}

	std::cout << decimal_number << std::endl;

	delete [] number_str;

	return 0;
}