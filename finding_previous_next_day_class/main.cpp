#include <iostream>
#include "Days.h"

int main()
{
    Day today(1 , 1 , 2024);
    today.printing_day();

    Day tomorrow = today.next_day(tomorrow);
    tomorrow.printing_day();

    Day yesterday = today.previous_day(yesterday);
    yesterday.printing_day();

    return 0;
}
