#include <stdio.h>
int main()
{
    int m,n;
    printf("Enter row size: ");
    scanf("%d",&m);
    printf("Enter column size: ");
    scanf("%d",&n);
    int arr[m][n];
    int tarr[n][m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter element (%d,%d) :",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("The entered matrix :\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%3d\t",arr[i][j]);
            tarr[j][i]=arr[i][j];
        }
        printf("\n");
    }
    printf("\nThe transpose matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%3d\t",tarr[i][j]);
        }
        printf("\n");
    }
    return 0;
}