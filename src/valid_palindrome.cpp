/*  Problem: Valid Palindrome
    Date: Feb 2023

    Approach: Two pointers from left and right side of the string moving towards the mdiddle.
                And simulatenously checking whether the corresponding characters are same or not.
            
            Time Complexity: O(n) where n = length of string.
            Space Complexity: O(1) as no extra space is utilized.

    Alternative approach: Naive approach
            Create another string be reversing the original string. Iterate both string one character at a time
            and simultaneously check for the corresponding characters in both the strings.

            Time Complexity: O(n)
            Space Complexity: O(n) as a new string is created.

            Resource: https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/g7Yo5r75gyZ
                        - Solution page for the given problem.
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

bool IsPalindrome(string inputString)
{
    // Write your code here
    if (inputString.empty()){
        return true;
    }

    unsigned int left_ptr_pos = 0;
    unsigned int right_ptr_pos = inputString.size()-1;

    while (left_ptr_pos < right_ptr_pos)
    {
        if (inputString[left_ptr_pos] != inputString[right_ptr_pos]){
            return false;
        }
        ++left_ptr_pos;
        --right_ptr_pos;
    }
    
    return true;
}

const lest::test tests[] = {
    CASE("Test Case 1: Valid"){
        string inputString = "kayak";
        EXPECT(IsPalindrome(inputString) == true);
    },
    CASE("Test Case 2: Invalid"){
        string inputString = "hello";
        EXPECT(IsPalindrome(inputString) == false);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
