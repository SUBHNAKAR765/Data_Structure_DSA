#include <stdio.h>
int binary_search_first(int arr[], int n, int target) 
{
    int low = 0;
    int high = n - 1;
    int first_occurrence = -1;
    
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) 
        {
            first_occurrence = mid;
            high = mid - 1;
        } else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    } 
    return first_occurrence;
}
int binary_search_last(int arr[], int n, int target) 
{
    int low = 0;
    int high = n - 1;
    int last_occurrence = -1;
    
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) 
        {
            last_occurrence = mid;
            low = mid + 1;
        } else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    
    return last_occurrence;
}
int count_occurrences(int arr[], int n, int target) 
{
    int first = binary_search_first(arr, n, target);
    int last = binary_search_last(arr, n, target);
    
    if (first == -1) 
    {
        return -1;
    }
    
    return last - first + 1;
}
int main() 
{
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    
    printf("First occurrence: %d\n", binary_search_first(arr, n, target));
    printf("Last occurrence: %d\n", binary_search_last(arr, n, target));
    printf("Count of occurrences: %d\n", count_occurrences(arr, n, target));
    
    return 0;
}