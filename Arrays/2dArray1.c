#include <stdio.h>
int main()
{
    int m,n;
    printf("Enter row size: ");
    scanf("%d",&m);
    printf("Enter column size: ");
    scanf("%d",&n);
    int arr[m][n];
    int s=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter element (%d,%d) :",i,j);
            scanf("%d",&arr[i][j]);
            s+=arr[i][j];
        }
    }
    printf("Sum of elements of array : %d",s);
    return 0;
}