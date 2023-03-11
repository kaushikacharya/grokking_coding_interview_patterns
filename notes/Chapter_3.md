# Fast and Slow Pointers

1. Fast and Slow pointers: Introduction
2. [Happy Number](#happy-number)

- ## Happy Number
    - ### Statement:
    ```
        Write an algorithm to determine if a number n is happy.
        A happy number is a number defined by the following process:
            - Starting with any positive integer, replace the number by the sum of the squares of its digits.
            - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
            - Those numbers for which this process ends in 1 are happy.
        Return TRUE if n is a happy number, and FALSE if not.
    ```
    - ### Constraints:
        1 <= n <= $2^{31}$-1
    - ### Solutions:
        - Naive approach
            - Brute force approach: Repeatedly calculate the squared sum of digits of the input number and store the computed sum in a **hash set**.
            - For every calculation, we check if the sum is already present in the set.
            - If yes, we've detected a cycle and should return FALSE.
            - Otherwise, we add it to our hash set and continue further.
            - If our sum converges to 1, we've found a happy number.
            - ?? How is time complexity: O(log n)
        - Optimal approach using Fast and Slow pattern
            - The fast pointer would eventually reach the number whose squared digits sum would result in a 1, in which csse we will return TRUE.
            - Otherwise, it would meet the slow pointer, which would mean we are in an endless loop and we can return FALSE.