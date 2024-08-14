/*To rotate an array to the right by k steps in C, one effective approach is to use array reversal. The idea is to reverse different parts of the array and then reverse the entire array to achieve the desired rotation.

Steps:
1. Reverse the entire array.
2. Reverse the first k elements.
3. Reverse the remaining n - k elements.
*/

#include <stdio.h>

// Function to reverse a portion of the array
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate the array to the right by k steps
void rotate(int* nums, int numsSize, int k) {
    // If k is greater than the array size, reduce it to within bounds
    k = k % numsSize;

    // Step 1: Reverse the entire array
    reverse(nums, 0, numsSize - 1);

    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse the remaining n - k elements
    reverse(nums, k, numsSize - 1);
}

// Function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    // Example 1
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    rotate(nums1, size1, k1);
    printArray(nums1, size1); // Output: [5, 6, 7, 1, 2, 3, 4]

    // Example 2
    int nums2[] = {-1, -100, 3, 99};
    int k2 = 2;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    rotate(nums2, size2, k2);
    printArray(nums2, size2); // Output: [3, 99, -1, -100]

    return 0;
}
