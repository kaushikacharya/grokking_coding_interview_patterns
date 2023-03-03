/*  Problem: Valid Palindrome II
    Statement: Write a function that takes a string as input and checks whether it can be a valid palindrome by removing at most one character from it.
    Date: March 03, 2023

    Approach: Iterate with two pointers: one from start of the string and another from end of the string.
                Keep checking for character match and moving towards the center.
                Allow for at max one character removal.
            
    Complexity:
        - Time: O(n)
                - Single iteration over the elements of the string.
        - Space: O(1)
                - No additional space.
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

bool validPalindrome(string arr)
{
    unsigned int i = 0; // left index
    unsigned int j = arr.size()-1; // right index
    unsigned int n_mismatch = 0;

    while ((i < j) && (n_mismatch <= 1))
    {
        if (arr[i] == arr[j])
        {
            // Case: Elements at left and right index matched
            // Shift left index one step ahead and right index one step backward
            ++i;
            --j;
        }
        else
        {
            // Case: Elements at current left and right index mismatched.            
            // Check if there's a match if we shift only one of the left or right indexes 
            if (arr[i+1] == arr[j])
            {
                i += 2;
                --j;
                ++n_mismatch;
            }
            else if (arr[i] == arr[j-1])
            {
                ++i;
                j -= 2;
                ++n_mismatch;
            }
            else
            {
                ++i;
                --j;
                n_mismatch += 2;
            }  
        }
    }

    return (n_mismatch <= 1) ? true : false;
}

lest::test tests[] = {
    CASE("Test Case 1"){
        string str = "madame";
        EXPECT(validPalindrome(str) == true);
    },
    CASE("Test Case 2"){
        string str = "dead";
        EXPECT(validPalindrome(str) == true);
    },
    CASE("Test Case 3"){
        string str = "abca";
        EXPECT(validPalindrome(str) == true);
    },
    CASE("Test Case 4"){
        string str = "tebbem";
        EXPECT(validPalindrome(str) == false);
    },
    CASE("Test Case 5"){
        string str = "eeccccbebaeeabebccceea";
        EXPECT(validPalindrome(str) == false);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
