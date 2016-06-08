#include "stdafx.h"
#include "rushhours.hpp"

bool RushHours::IsRushHour(double t) 
{
    map<double,IntervalSide>::iterator upperBoundIt;
	// _rushIntervals maintains a set of non overlapping intervals
	// thus if the closest point from the left is closing an interval
	// the point is contained in it
    upperBoundIt = _rushIntervals.upper_bound(t);
    if (upperBoundIt != _rushIntervals.end() && upperBoundIt->second == IntervalSide::CLOSE)
        return true;
        
    return false;
}

void RushHours::AddRushHour(double open, double close)
{
    // We're maintining only non overlapping intervals!
    map<double,IntervalSide>::iterator lowerBoundIt;
    map<double,IntervalSide>::iterator upperBoundIt;
    
    // Check if contained from left
    lowerBoundIt = _rushIntervals.lower_bound(open);
	if (lowerBoundIt != _rushIntervals.end())
		lowerBoundIt--;

    if (lowerBoundIt == _rushIntervals.end() || lowerBoundIt->second == IntervalSide::CLOSE)
    {
        // if not then add the new openning point
        lowerBoundIt = _rushIntervals.insert(std::pair<double,IntervalSide>(open, IntervalSide::OPEN)).first;
    }
    
    // check if countained for right
    upperBoundIt = _rushIntervals.upper_bound(close);
    if (upperBoundIt == _rushIntervals.end() || upperBoundIt->second == IntervalSide::OPEN)
    {
        // if not then add the new closing point
        upperBoundIt = _rushIntervals.insert(std::pair<double,IntervalSide>(close, IntervalSide::CLOSE)).first;
    }
    
    // Union all intervals in the middle
    lowerBoundIt++;
    // remove any points inside the new interval
    if (lowerBoundIt != upperBoundIt)
    {
        _rushIntervals.erase(lowerBoundIt, upperBoundIt);
    }
}