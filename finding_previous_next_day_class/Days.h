#ifndef DAYS_CLASS
#define DAYS_CLASS

class Day
{
    public:
        int day;
        int month;
        int year;

        Day(int d = 0,int m = 0,int y = 0)
        {
            day = d;
            month = m;
            year = y;
        }

        void printing_day();
        Day next_day(Day &tomorrow);
        Day previous_day(Day &yesterday);
};

#endif // DAYS_CLASS
