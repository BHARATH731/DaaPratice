#include <stdio.h>
#include <stdlib.h>
int set[20], subset[20];
int n, sum;
// Function to print the current subset
void printSubset(int len) {
    int i;
    printf("{");
    for (i = 0; i < len; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Function to find all subsets of the given set with sum equal to the given sum
void findSubsets(int pos, int len, int curSum) {
    if (curSum == sum) {
        printSubset(len);
        return;
    }
    if (pos == n || curSum > sum) {
        return;
    }
    // Do not include the current element in the subset
    findSubsets(pos+1, len, curSum);
    // Include the current element in the subset
    subset[len] = set[pos];
    findSubsets(pos+1, len+1, curSum+set[pos]);
}

void main() {
    int i;
    printf("Enter the size of the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d", &sum);
    findSubsets(0, 0, 0);
}