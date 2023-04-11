#include<stdio.h>
#include<limits.h>

// Function to calculate minimum cost of merging files using greedy approach
int optimalMerge(int files[], int n)
{
    int minCost = 0;

    // Sort the files in ascending order
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (files[j] < files[i])
            {
                int temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    // Merge the files in pairs of two, and keep track of the merge cost
    for (int i = 0; i < n-1; i++)
    {
        int mergeCost = files[i] + files[i+1];
        minCost += mergeCost;

        // Merge the two files and update the array
        files[i+1] = mergeCost;

        // Sort the array again to maintain the ascending order
        for (int j = i+1; j < n-1; j++)
        {
            if (files[j+1] < files[j])
            {
                int temp = files[j];
                files[j] = files[j+1];
                files[j+1] = temp;
            }
            else
            {
                break;
            }
        }
    }

    return minCost;
}
// Driver code to test the program
void main()
{
    int files[] = {10,15,5,20};
    int n = sizeof(files)/sizeof(files[0]);
    int minCost = optimalMerge(files, n);
    printf("Minimum cost of merging files is: %d", minCost);
}
