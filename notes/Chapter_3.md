# Fast and Slow Pointers

1. Fast and Slow pointers: Introduction
2. [Happy Number](#happy-number)
3. [Linked List Cycle](#linked-list-cycle)
4. [Middle of the Linked List](#middle-of-the-linked-list)
5. Circular Array Loop
6. Find the Duplicate Number
7. [Palindrome Linked List](#palindrome-linked-list)

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
        $1 <= n <= 2^{31}-1$
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

- ## Linked List Cycle
    - ### Statement:
        ```
        Check if a linked list contains a cycle or not. If a cycle exists, return TRUE. Otherwise, return FALSE.
        ```
    - ### [Solution](../src/linked_list_cycle.cpp):
        - Naive approach:
            - Traverse the linked list and store the current node in a set.
                At each iteration, we check if the current node is already present in the set.
        - Optimized approach using fast and slow pointers:
            - We initialize two pointers, ```fast``` and ```slow```, which point to the head of the linked list.

            - We traverse the linked list through these two pointers. They move in the following way:
                - The slow pointer moves only one node forward on each iteration.
                - The fast pointer moves two nodes forward on each iteration; that is, it skips a node.
            
            - If the fast pointer becomes NULL, we have reached the end of the linked list. No cycle exists, so we return FALSE.

            - If both slow and fast pointers become equal to each other, a cycle exists in the linked list, so we return TRUE.

        - Solution summary:
            - The solution can be divided into three parts:
                - Initialize both pointers as head
                - Move both pointers at different rates
                - Check the equality of pointers

- ## Middle of the Linked List
    - ### Statement:
        ```
        Given  a singly linked list, return the middle node of the linked list. If the number of nodes in the linked list is even, return the second middle node.
        ```

    - ### Constraints:
        - 1 $<=$ Number of nodes in the list $<=$ 100

    - ### [Solution](../src/middle_of_linked_list.cpp):
        - Naive approach:
            - Count the number of nodes in the linked list first, and then find the middle node in the next iteration.
        - Optimized approach using fast and slow pointers:
            - Initialize two pointers names slow and fast at the head of the linked list.
            - While traversing, move the slow pointer one step forward and the fast pointer two steps forward.
            - When the fast pointer reaches the last node or NULL, then the slow pointer will point to the middle node of the linked list.

- ## Palindrome Linked List
    - ### Statement:
        ```
        Given the head of a linked list, your task is to check whether the linked list is a palindrome or not. Return TRUE if the linked list is a palindrome; otherwise, return FALSE.
        ```
    
    - ### Constraints:
        - Let $n$ be the number of nodes in a linked list.
            - $1 <= n <= 500$
    
    - ### [Solution](../src/palindrome_linked_list.cpp):
        - Using fast and slow pointers
            - First, find the middle node of the linked list.
                - Slow pointer: One step forward.
                - Fast pointer: Two step forward.
                - When fast pointer reaches either
                    - End of the list or
                    - Null node, 
                - slow pointer points to the middle node of the list.
            - Next, reverse the 2nd half of the linked list, starting from the node after the middle node.
                - Additional info (KA):
                    - IMHO, the official solution reverses the 2nd half from the middle node onwards, unlike the above statement.
            - Finally, compare every element of the first half of the linked list with the corresponding element in the second half of the reversed linked list.
