#include <stdio.h>
void findMissingElements(int arr1[], int n1, int arr2[], int n2) 
{
    int found;
    printf("Missing elements in the second array:\n");
    
    for (int i = 0; i < n2; i++) 
    {
        found = 0; 
        for (int j = 0; j < n1; j++) 
        {
            if (arr2[i] == arr1[j]) 
            {
                found = 1; 
                break;
            }
        }
        if (!found) {
            printf("%d ", arr2[i]);
        }
    }
    printf("\n");
}
int main() 
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    findMissingElements(arr1, n1, arr2, n2);
    
    return 0;
}