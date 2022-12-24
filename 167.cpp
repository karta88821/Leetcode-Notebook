/*
#167. Two Sum II - Input Array Is Sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
*/

// Sol 1: Brute Force
// Time:  O(n^2)
// Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (numbers[i] + numbers[j] == target)
                    return {i+1, j+1};
            }
        }
        return {0, 0};
    }
};

// Sol 2: Two Pointers
// Time:  O(n)
// Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int lo = 0, hi = n-1;

        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target) {
                return {lo+1, hi+1};
            } else if (sum < target) {
                lo++;
            } else {
                hi--;
            }
        }
        
        return {0, 0};
    }
};