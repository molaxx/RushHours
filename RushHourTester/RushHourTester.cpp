// RushHourTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "rushhours.hpp"
using namespace std;

int main()
{
	RushHours rushHours;
	if (rushHours.IsRushHour(5))
		cout << "No rush hours and isrushhour got true" << endl;

	rushHours.AddRushHour(1, 2);
	if (rushHours.IsRushHour(5))
		cout << "isrushhour got true for 5. where [1,2) interval exists" << endl;

	rushHours.AddRushHour(1, 2);
	if (rushHours.GetRushIntervals().size() != 2)
		cout << "adding the same interval twice increased the number of interval points" << endl;

	if (!rushHours.IsRushHour(1))
		cout << "isRushHour false for 1. where [1,2) interval exists" << endl;

	if (rushHours.IsRushHour(2))
		cout << "isRushHour true for 2. where only [1,2) interval exists" << endl;

	rushHours.AddRushHour(1.4, 2);
	if (rushHours.GetRushIntervals().size() != 2 ||
		*(rushHours.GetRushIntervals().begin()) != IntervalsContainer::value_type(1,OPEN) ||  
		*(++rushHours.GetRushIntervals().begin()) != IntervalsContainer::value_type(2, CLOSE))
		cout << "[1,2)<-[1.4,2) werent merged" << endl;

	rushHours.AddRushHour(1, 2.1);
	if (rushHours.GetRushIntervals().size() != 2 ||
		*(rushHours.GetRushIntervals().begin()) != IntervalsContainer::value_type(1, OPEN) ||
		*(++rushHours.GetRushIntervals().begin()) != IntervalsContainer::value_type(2.1, CLOSE))
		cout << "[1,2)<-[1,2.1) werent merged" << endl;

	rushHours.AddRushHour(3, 4);
	if (!rushHours.IsRushHour(2.01))
		cout << "isRushHour false for 2.01 where [1,2.1) interval exists" << endl;

	if (rushHours.IsRushHour(2.3))
		cout << "isRushHour true for 2.3 where only [1,2.1) and [3,4) interval exists" << endl;
	
	if (!rushHours.IsRushHour(3.1))
		cout << "isRushHour false for 3.1 where [1,2.1) and [3,4) exist" << endl;

	rushHours.AddRushHour(0.5, 4);
	if (rushHours.GetRushIntervals().size() != 2 ||
		*(rushHours.GetRushIntervals().begin()) != IntervalsContainer::value_type(0.5, OPEN) ||
		*(++rushHours.GetRushIntervals().begin()) != IntervalsContainer::value_type(4, CLOSE))
		cout << "[1,2),[3,4)<-[0.5,4) werent merged" << endl;

	if (!rushHours.IsRushHour(2.3))
		cout << "isRushHour false for 2.3 where [0.5,4) interval exists" << endl;

	rushHours.AddRushHour(5, 6);
	rushHours.AddRushHour(7, 8);
	if (!rushHours.IsRushHour(5.5))
		cout << "IsRushHour false for 5.5 with [0.5,4),[5,6),[7,8)" << endl;
	if (rushHours.IsRushHour(6.5))
		cout << "IsRushHour true for 6.5 with [0.5,4),[5,6),[7,8)" << endl;
	if (rushHours.IsRushHour(4.5))
		cout << "IsRushHour true for 4.5 with [0.5,4),[5,6),[7,8)" << endl;

    return 0;
}

