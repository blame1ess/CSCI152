#include <iostream>
#include "date.h"

bool date::isleapyear( unsigned int y )
{
}

// This is called 'anonymous namespace'. It prevents that
// the names are passed to the linker.
// All the tables start with an unused element, because we don't
// use 0 for counting months.

namespace
{
    // Tables start with an unused 0, because we start counting months at 1.

    const unsigned int normalyear[] =
            { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    const unsigned int leapyear[] =
            { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Table starts with an empty string, because we start counting months at 1.

    const char* const monthnames[] =
            { "", "january", "february", "march", "april",
              "may", "june", "july", "august", "september",
              "october", "november", "december" };
}

bool date::ispossible( unsigned int year, unsigned int month, unsigned int day )
{
    int numberOfDays;

    if ( month > 0 && month < 13 ) {
        if ( date::isleapyear(year) ) {
            numberOfDays = leapyear[month];
        } else {
            numberOfDays = normalyear[month];
        }

        if (day > 0 && day < numberOfDays) {
            return 1;
        } else {
            return  0;
        }
    } else {
        return 0;
    }
}

void date::print_usa( std::ostream& out ) const
{
    out << monthnames[month] << ' ' << day << ' ' << year;
}

void date::print_euro( std::ostream& out ) const
{
    out << day << ' ' << monthnames[month] << ' ' << year;
}

bool date::operator == ( date other ) const
{
    return year == other.year && month == other.month && day == other.day;
}

bool date::operator <= ( date other ) const
{
    if (year < other.year) {
        return 1;
    } else if (year > other.year) {
        return 0;
    }

    if (month <  other.month) {
        return 1;
    } else if (month > other.month) {
        return 0;
    }

    return day <= other.day;
}

unsigned int date::daysinyear( unsigned int y )
{
    if (isleapyear(y)) {
        return 366;
    } else {
        return 365;
    }
}

unsigned int date::daysinmonth( unsigned int y, unsigned int m )
{
    if (isleapyear(y)) {
        return leapyear[m];
    } else {
        return normalyear[m];
    }
}

unsigned int date::days1jan( ) const
{
    int numberOfDays = 0;
    numberOfDays += day;

    for (int i = month - 1; i > 0; i--) {
        numberOfDays += daysinmonth(year, month);
    }
    return numberOfDays;
}

void date::setdays1jan( unsigned int nrdays )
{
    int leftDays = nrdays - daysinmonth(year, month);
}

date& date::operator += ( int diff )
{

}

int date::operator - ( const date& other ) const
{
}

namespace
{
    const char *weekdays[] =
            { "sunday", "monday", "tuesday", "wednesday",
              "thursday", "friday", "saturday" };
}

const char* date::getweekday( ) const
{
}

