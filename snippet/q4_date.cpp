/* -*- mode: C++; c-file-style: "Linux" -*-
 *
 * Copyright (c) 2013 Luke Huang <lukehuang.ca@me.com>
 */

/**
 * @file q4_date.cpp
 * @author Luke Huang
 * @date 10 Feb 2014 19:12:08
 */

#include <cstdint>
#include <iostream>
#include <iomanip>

using namespace std;

class Pearls_Date {
public:
	int64_t	year;
	int    	month;
	int    	day;

	Pearls_Date() {};
	Pearls_Date(int64_t y, int m, int d);
	int64_t		operator-(Pearls_Date &date);
	bool		operator==(Pearls_Date &date);
	bool		operator!=(Pearls_Date &date);
	bool		operator<(Pearls_Date &date);
	bool 		operator<=(Pearls_Date &date);

	friend ostream& operator<<(ostream &os, Pearls_Date &date);
	friend istream& operator>>(istream &os, Pearls_Date &date);
};

static bool
is_leap(int64_t year)
{
	return (((year % 400) == 0) ||
		((year % 4) == 0 && ((year % 100) != 0)));
}

static int
past_days(Pearls_Date &date)
{
	int days = 0;
	int days_of_month[] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	
	if (is_leap(date.year)) {
		days_of_month[2] = 29;
	}

	for (int i = 1; i < date.month; i++)
		days += days_of_month[i];
	
	return days + date.day - 1;
}

Pearls_Date::Pearls_Date(int64_t y, int m, int d)
{
	this->year  = y;
	this->month = m;
	this->day   = d;
}

bool
Pearls_Date::operator<=(Pearls_Date &date)
{
	if (year != date.year)
		return (year <= date.year);
	else if (month != date.month)
		return (month <= date.month);
	return day <= date.day;
}

bool
Pearls_Date::operator==(Pearls_Date &date)
{
	return (year  == date.year 	&&
		month == date.month	&&
		day   == date.day);
}

bool
Pearls_Date::operator!=(Pearls_Date &date)
{
	return !(*this == date);
}

int64_t
Pearls_Date::operator-(Pearls_Date &date)
{
	int64_t days_between;
	int64_t years_day = 0;
	int	start_year, end_year;

	days_between = past_days(*this) - past_days(date);
	if (this->year <= date.year) {
		start_year = this->year;
		end_year   = date.year;
	} else {
		start_year = date.year;
		end_year   = this->year;
	}

	for (int64_t year = start_year; year < end_year; year++) 
		years_day += (is_leap(year) ? 366 : 365);
	if (this->year <= date.year)
		years_day = -years_day;

	return days_between + years_day;
}

ostream& 
operator<<(ostream &os, Pearls_Date &date)
{
	os << date.year << "-";
	
	os.fill('0');
	os << std::setw(2) << date.month << "-" << std::setw(2) << date.day;
	
	return os;
}

istream& 
operator>>(istream &is, Pearls_Date &date)
{
	is  >> date.year >> date.month >> dec >> date.day;

	return is;
}

int
main(int argc, char **argv)
{
	Pearls_Date 	date0;
	Pearls_Date 	date1;

	cin >> date0;
	cin >> date1;

	cout << date0 << " - " << date1 << " = " << (date0 - date1) << endl;
	cout << date1 << " - " << date0 << " = " << (date1 - date0) << endl;

	return 0;
}
