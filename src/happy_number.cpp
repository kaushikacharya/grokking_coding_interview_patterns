/*  Problem: Happy Number
    Statement: Write an algorithm to determine if a number n is happy.
                A happy number is a number defined by the following process:
                    - Starting with any positive integer, replace the number by the sum of the squares of its digits.
                    - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
                    - Those numbers for which this process ends in 1 are happy.
                Return TRUE if n is a happy number, and FALSE if not.
    
    Solution #1:
        Space Complexity: O(n)

    Solution #2:
        Space Complexity: O(1)
        N.B. Solution provided in the course is more elegant.
                Comparing fast pointer after 2 step jump with slow pointer is enough.
                No need to compare fast pointer twice after each step jump.

*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

// Computes sum of the squares of the digits
int SumDigits(int number)
{
    int sum = 0;

    // Extract unit digit one by one
    while (number > 0)
    {
        // cout << "number: " << number << endl;
        int unit_digit = number % 10;
        sum += unit_digit * unit_digit;
        // Remove the unit digit so that next digit can be extracted in the next iteration
        number /= 10;
    }
    
    return sum;
}

/*  Solution #1: Using unordered_set
    Drawback: Stores each of the sum of square of digits for the numbers generated.
*/ 
bool IsHappyNumberSolution1(int n){
    int cur_num = n;
    unordered_set<int> sum_digit_square_set;

    // Your code will replace this placeholder return statement
    while (true)
    {
        // cout << "cur_num (Before sum of square of digits): " << cur_num << endl;
        cur_num = SumDigits(cur_num);
        // cout << "cur_num (Post sum of square of digits): " << cur_num << endl;

        if (cur_num == 1)
        {
            // Satisfies condition for Happy Number
            return true;
        }
        if (sum_digit_square_set.find(cur_num) == sum_digit_square_set.end())
        {
            sum_digit_square_set.insert(cur_num);
        }
        else
        {
            // Current sum of digits square repeats which confirms presence of cycle.
            return false;
        }
    }
}

/*  Solution #2: Using slow and fast pointers
    Memory complexity: O(1)
*/ 
bool IsHappyNumber(int n){
    int slow = n;
    int fast = n;

    while (true)
    {
        // Increment fast by two steps. Check whether a) it reached 1 b) catches up with slow.
        for (int i=0; i != 2; ++i)
        {
            fast = SumDigits(fast);

            if (fast == 1)
            {
                // Satisfies condition for Happy Number
                return true;
            }
            if (fast == slow)
            {
                // Fast catches up with slow. Hence cycle detected.
                return false;
            }
        }
        
        // Increment slow by single step
        slow = SumDigits(slow);
    }
}

lest::test tests[] = {
    CASE("Test Case 1"){
        int n = 4;
        EXPECT(IsHappyNumber(n) == false);
    },
    CASE("Test Case 2"){
        int n = 58;
        EXPECT(IsHappyNumber(n) == false);
    },
    CASE("Test Case 3"){
        int n = 68;
        EXPECT(IsHappyNumber(n) == true);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
