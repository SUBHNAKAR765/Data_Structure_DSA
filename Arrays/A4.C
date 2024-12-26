#include <stdio.h>

int main() 
{
    int TS[] = {85, 78, 92, 65, 89, 76, 94, 81, 87, 90, 72, 88, 95, 79, 83, 91, 70, 84, 86, 93};   
    //TS: TEST SCORE
    int size = sizeof(TS) / sizeof(TS[0]);

    int sum = 0;
    int highest_score = TS[0];
    for (int i = 0; i < size; i++) 
    {
        sum += TS[i];

        if (TS[i] > highest_score) 
        {
            highest_score = TS[i];
        }
    }
    double average_score = (double)sum / size;
    printf("A. Average score: %.2lf\n", average_score);
    printf("   Highest score : %d\n", highest_score);

    int PASS_MARK = 75;
    int pass_count = 0, fail_count = 0;
    for (int i = 0; i < size; i++) 
    {
        if (TS[i] >= PASS_MARK) 
        {
            pass_count++;
        } else {
            fail_count++;
        }
    }
    printf("B. Number of students passed: %d\n", pass_count);
    printf("   Number of students failed: %d\n", fail_count);

    // Task C: Determine the grade distribution
    int grade_counts[5] = {0}; // O, E, A, B, F
    for (int i = 0; i < size; i++) 
    {
        if (TS[i] >= 90) 
        {
            grade_counts[0]++; // O
        } else if (TS[i] >= 80)

        {
            grade_counts[1]++; // E
        } else if (TS[i] >= 70) 
        {
            grade_counts[2]++; // A
        } 
        else if (TS[i] >= 60) 
        {
            grade_counts[3]++; // B
        } 
        else 
        {
            grade_counts[4]++; // F
        }
    }
    printf(" Grade Distribution:\n");
    printf("   O: %d\n", grade_counts[0]);
    printf("   E: %d\n", grade_counts[1]);
    printf("   A: %d\n", grade_counts[2]);
    printf("   B: %d\n", grade_counts[3]);
    printf("   F: %d\n", grade_counts[4]);

    return 0;
}