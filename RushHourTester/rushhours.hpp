#ifndef ELI_RUSHHOURS_H_
#define ELI_RUSHHOURS_H_
#include <map>
using namespace std;

enum IntervalSide { OPEN, CLOSE };
typedef map<double, IntervalSide> IntervalsContainer;

class RushHours 
{
    public:
        void AddRushHour(double open, double close);
        bool IsRushHour(double t);

		// for testing 
		const IntervalsContainer& GetRushIntervals() { return _rushIntervals; }
    private:
		IntervalsContainer _rushIntervals;
};
#endif

