#ifndef ELI_RUSHHOURS_H_
#define ELI_RUSHHOURS_H_
#include <map>
using namespace std;

class RushHours 
{
    public:
		enum IntervalSide { OPEN, CLOSE };
		typedef map<double, RushHours::IntervalSide> IntervalsContainer;

        void AddRushHour(double open, double close);
        bool IsRushHour(double t);

		const IntervalsContainer& GetIntervals() {
			return _rushIntervals;
		}
    private:
		IntervalsContainer _rushIntervals;
};
#endif

