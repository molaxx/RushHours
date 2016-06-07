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

	if (!rushHours.IsRushHour(1))
		cout << "isRushHour false for 1. where [1,2) interval exists" << endl;

	if (rushHours.IsRushHour(2))
		cout << "isRushHour true for 2. where only [1,2) interval exists" << endl;

	rushHours.AddRushHour(1.4, 2);
	rushHours.AddRushHour(1, 2.1);
	rushHours.AddRushHour(3, 4);
	if (!rushHours.IsRushHour(2.01))
		cout << "isRushHour false for 2.01 where [1,2.1) interval exists" << endl;

	if (rushHours.IsRushHour(2.3))
		cout << "isRushHour true for 2.3 where only [1,2.1) and [3,4) interval exists" << endl;
	
	rushHours.AddRushHour(1, 4);
	if (!rushHours.IsRushHour(2.3))
		cout << "isRushHour false for 2.3 where [1,4) interval exists" << endl;
    return 0;
}

