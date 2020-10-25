#include <iostream>
#include "Source.h"

/*
 * Напишете програма, която при въвеждане на дадена дата, намира следващата дата.
 */

 // CONSTS
const unsigned int MONTHS = 12;
unsigned int DAYS_IN_MONTHS[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool is_leap_year(const unsigned int year)
{
    if (year % 400 == 0)
    {
        return true;
    }

    if (year % 100 == 0)
    {
        return false;
    }

    if (year % 4 == 0)
    {
        return true;
    }

    return false;
}

bool is_date_valid(const unsigned int day, const unsigned int month, const unsigned int year)
{
    if (is_leap_year(year))
    {
        DAYS_IN_MONTHS[1]++;
    }
    const bool result = !(year < 0 || month < 1 || month > MONTHS || day < 1 || day > DAYS_IN_MONTHS[month - 1]);
    if (is_leap_year(year))
    {
        DAYS_IN_MONTHS[1]--;
    }
    return result;
}

void enter_date(unsigned int& day, unsigned int& month, unsigned int& year)
{
    std::cout << "Enter day, month, year: ";
    std::cin >> day >> month >> year;
}

void increment_date(unsigned int& day, unsigned int& month, unsigned int& year)
{
    if (is_leap_year(year))
    {
        DAYS_IN_MONTHS[1]++;
    }
    if (++day > DAYS_IN_MONTHS[month - 1])
    {
        day = 1;
        if (++month > 12)
        {
            year++;
            month = 1;
        }
    }
    if (is_leap_year(year))
    {
        DAYS_IN_MONTHS[1]--;
    }
}

int main()
{
    unsigned int day, month, year;

    do
    {
        enter_date(day, month, year);
    } while (!is_date_valid(day, month, year));

    increment_date(day, month, year);

    std::cout << "Incremented date: " << day << "/" << month << "/" << year << " (dd/mm/yyyy)" << std::endl;

    return 0;
}