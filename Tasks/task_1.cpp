#include <iostream>

/*
*  Направете програма, подпомагаща един бояджия колко кутии боя трябва да купи за една стая (нека стаите са само с 4 стени).
*  1 кутия е достатъчна за боядисването на 3 кв. м. площ. Изходът от програмата трябва да бъде цяло число, показващо необходимия брой кутии.
*/
int main()
{
	const int PAINT_CAN_COVERAGE = 3;
	
	int room_dim_h, room_dim_w, room_dim_l, result;

	std::cout << "Enter the room's height, width, length: ";
	std::cin >> room_dim_h >> room_dim_w >> room_dim_l;

	if (room_dim_h <= 0)
	{
		std::cout << "The room's height cannot be negative or zero." << std::endl;
		return -1;
	}

	if (room_dim_w <= 0)
	{
		std::cout << "The room's width cannot be negative or zero." << std::endl;
		return -1;
	}

	if (room_dim_l <= 0)
	{
		std::cout << "The room's length cannot be negative or zero." << std::endl;
		return -1;
	}

	result = 2 * room_dim_h * (room_dim_w + room_dim_l);

	if (result % PAINT_CAN_COVERAGE > 0) 
	{
		result += PAINT_CAN_COVERAGE;
	}

	result /= PAINT_CAN_COVERAGE;

	std::cout << result << " paint cans are needed to paint the room." << std::endl;

	return 0;
}