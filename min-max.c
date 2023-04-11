#include <stdio.h>
#include <conio.h>
int max = -1;
int min = 9999;
void minmax(int arr[], int i, int j)
{
    if (i == j)
    {
        min = max = arr[j];
    }
    else if (i == j - 1)
    {
        if (arr[i] > arr[j])
        {
            max = arr[i];
            min = arr[j];
        }
        else
        {
            min = arr[i];
            max = arr[j];
        }
    }
    else
    {
        int mid = i + (j - i) / 2;
        minmax(arr, i, mid);
        int max1 = max;
        int min1 = min;
        minmax(arr, mid + 1, j);
        int max2 = max;
        int min2 = min;
        if (max1 > max2)
        {
            max = max1;
        }
        if (min1 < min2)
        {
            min = min1;
        }
    }
}
void main()
{
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);
    printf("Enter elements in array:");
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    minmax(arr, 0, size - 1);
    printf("Maximum Element is:%d\n", max);
    printf("Minmum Element is:%d", min);
}