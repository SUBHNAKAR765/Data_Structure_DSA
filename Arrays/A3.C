#include <stdio.h>
int main() 
{
    int TEMP_DATA[] = {25, 28, 27, 30, 31, 29, 26};    //TEMP_DATA:- TEMPERATURE DATA 
    int size = sizeof(TEMP_DATA) / sizeof(TEMP_DATA[0]);

    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += TEMP_DATA[i];
    }
    double average = (double)sum / size;
    printf("Average temperature for the week: %.2lf\n", average);

    int X = 0, Y = 0;     
    // X= HOTEST DAY
    // Y=  COLDEST DAY
                           
    for (int i = 1; i < size; i++) 
    {
        if (TEMP_DATA[i] > TEMP_DATA[X]) 
        {
            X = i;
        }
        if (TEMP_DATA[i] < TEMP_DATA[Y]) 
        {
            Y = i;
        }
    }
    printf(" Hottest day: Day %d : %d\n", X + 1, TEMP_DATA[X]);
    printf(" Coldest day: Day %d : %d\n", Y + 1, TEMP_DATA[Y]);
   
    int TEMP_RANGE = TEMP_DATA[X] - TEMP_DATA[Y];
    printf("Temperature range: %d\n", TEMP_RANGE);

    return 0;
}
   