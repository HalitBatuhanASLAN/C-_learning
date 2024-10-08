#include <iostream>
#define ROW_COLUMN_NUMS 4
#define SHIPS_NUM 4
#define TURN_NUM 6
using namespace std;

int main()
{
    bool positions[ROW_COLUMN_NUMS][ROW_COLUMN_NUMS] =
    {
        {1,0,0,0},
        {0,0,0,1},
        {0,1,0,1},
        {0,0,0,0}
    };
    int hit_num = 0,turn = 0;
    int row,column;
    while(turn<TURN_NUM && hit_num <SHIPS_NUM)
    {
        turn++;
        cout << "Enter the row number(between 0-3) : ";
        cin >> row;
        cout << "Enter the column number(between 0-3) : ";
        cin >> column;
        cout << endl;
        if(positions[row][column] == 1)
        {
            positions[row][column] = 0;
            hit_num++;
            if(hit_num == SHIPS_NUM)
                cout << "You have hitted all of them\n";
            else
                cout << "Yes you hit it. You have " << (SHIPS_NUM-hit_num) << " more ships\n";
        }
        else
        {
            if(turn != TURN_NUM)
                cout << "You have missed it. You have " << TURN_NUM-turn << " more turns\n";
            else
                cout << "Unfortunatelly you could not hit all of them\n";
        }
        cout << endl;
    }
    return 0;
}
