#include <stdio.h>
#include <limits.h>

// Function to find the maximum subarray sum
long long maxSubarraySum(int arr[], int n) {
    int maxSum = INT_MIN;
    int currSum = 0;
    
    for(int i = 0; i < n; i++) {
        // Step 1
        currSum += arr[i];
        
        // Step 2
        if(currSum > maxSum) {
            maxSum = currSum;
        }
        
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    int n;
    scanf("%d", &n); // Input size of array
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]); // Inputting elements of array
            
    // Creating Solution object
    long long result = maxSubarraySum(a, n);
    
    printf("%lld\n", result); // Printing the result
    
    return 0;
}
