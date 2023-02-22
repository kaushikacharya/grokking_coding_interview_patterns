/*  Problem: Sum of Three Values
    Date: Feb 16, 2023

    Time complexity: O(n^2)
        - Explanation: Step 1 (sorting) uses O(n*logn)
        -               Step 2 (looping through the array): O(n^2)
    
    Space complexity: O(1)
        - No extra space utilized when sorting is done in-place (e.g. quicksort).
        - In case of mergesort, it would have been O(n).

        Reference: https://www.geeksforgeeks.org/quick-sort/
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

bool FindSumOfThree(vector<int> nums, int target)
{
    // Step 1: Sort the elements in ascending order
    sort(nums.begin(), nums.end());

    // Step 2: Loop through the array. Use two pointers: low and high to check if the current element of the array 
    //          and the elements of low and high pointers sum up to the target.
    for (unsigned int i=0; i != nums.size()-2; ++i)
    {
        unsigned int low = i+1;
        unsigned int high = nums.size()-1;

        while (low < high)
        {
            int sum_val = nums[i] + nums[low] + nums[high];

            if (sum_val == target)
            {
                return true;
            }
            else if (sum_val < target)
            {
                ++low;
            }
            else
            {
                --high;
            }
        }
        
    }

    // None of the 3 elements sums up to the target.
    return false;
}

const lest::test tests[] = {
    CASE("All +ve"){
        vector<int> nums = {3,7,1,2,8,4,5};
        int target = 10;
        EXPECT(FindSumOfThree(nums, target) == true);
    },
    CASE("3 Elements: false"){
        vector<int> nums = {1,-1,0};
        int target = -1;
        EXPECT(FindSumOfThree(nums, target) == false);
    },
    CASE("7 Elements: true"){
        vector<int> nums = {3,7,1,2,8,4,5};
        int target = 20;
        EXPECT(FindSumOfThree(nums, target) == true);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
