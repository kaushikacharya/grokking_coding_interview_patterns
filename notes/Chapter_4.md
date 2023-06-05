# Sliding Window
1. [Sliding Window: Introduction](#sliding-window-introduction)
2. [Repeated DNA Sequences](#repeated-dna-sequences)

## Sliding Window: Introduction
- ### Overview
    - **Sliding window** pattern:
        - Computational method aimed at reducing the use of nested loops in an algorithm.
        - Variation of two pointer pattern:
            - Where pointers can be used to set window bounds.
        - Allows to process the data in segments instead of the entire list.
    - Window:
        - A sublist formed over a part of an iterable data structure.
        - Can be used to slide over the data in chunks corresponding to the window size.
    - Why is this method more efficient?
        - Naive:
            - For each window, iterate over all the elements of the window.
            - Time complexity: $O(k\,n)$
            - Non-efficient
        - Optimal usage:
            - Focus on the element entering the window and the one leaving it.
        - Example mentioned:
            - To find three consecutive integers with the largest sum in an array.
    
- ### Examples
    - Sliding window median
    - Maximum subarray sum

- ### Does my problem match this pattern?
    - Both these conditions needs to fulfilled:
        - The problem requires repeated computations on a contiguous set of data elements (a subarray or a substring), such that the window moves across the input array from one end to the other.
            - The size of the window may be fixed or variable, depending on the requirements of the problem.
        - The computations performed every time the window moves take $O(1)$ time or a slow growing function such as log(k), where $k << n$.

- ### Real-world problems

- ### Strategy time!
    - Match the problems that can be solved using the Sliding Window pattern.

## Repeated DNA Sequences
- ### Statement
    - Given a string ```s``` that represents a DNA sequence, and a number ```k```, return all the contiguous sequences (substrings) of length ```k``` that occur more than once in the string.
    - Constraints:
        - $1 <= s.length <= 10^4$
        - ```s[i]``` is either A, C, G or T.
- ### Examples
- ### Understand the problem
- ### Figure it out!
- ### Try it yourself
    - Additional info (KA):
        - [String hashing using Polynomial rolling hash function](https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/)
        - ```substr``` function time complexity: $O(n)$
            - Sources: 
                - [HackerEarth](https://www.hackerearth.com/practice/notes/standard-template-library/)
                - [CodingNinjas](https://www.codingninjas.com/codestudio/library/substring-in-cpp)
                - [Algorithms for Competitive Programming](https://cp-algorithms.com/string/string-hashing.html)
                    - Detailed article which describes various algorithms which uses string hashing.
            - Returns a copy of the substring.
    - Solution:
        - [Kaushik](../src/repeated_dna_sequences.cpp)
            - Code review:
                - Use indices to extract substrings instead of ```substr``` function.
                    - This would reduce time complexity from $O(k)$ to $O(1)$.
                        - ?? How to do that?
                - Error handling: Don't assume that input string $s$ has at least $k$ characters. [Update: Handled]
                - **Time complexity**:
                    - Comuting hash value for a substring of length $k$ using polynomial rolling hash function takes $O(k)$.
                    - Code review mentions that it takes $O(N k)$ for computing hash values for all the substrings.
                        - IMHO, we take $O(k)$ time only for a single substring. But for rest of the substrings, we use sliding window to compute in $O(1)$ for each of the substrings.
                - **Space complexity**:
                    - $O(N k)$ where N = input string length, k = substring length
                    - 3 components:
                        - *We are storing the hash value of each substring in an unordered_map*: $O(N k)$
                        - Another unordered_map stores count of each substring. Complexity: $O(N k)$
                        - Set of repeated substrings returned by the function. In worst case, all substrings are repeated. Complexity: $O(N k)$
        - [Official solution](../src/repeated_dna_sequences_official_solution.cpp)
            - My observation:
                - Ignores the possibility of hash collision. This could lead to incorrect solution.
                - IMHO time and space complexity mentioned is incorrect.
            - The complexity computation ignores [substr](https://www.geeksforgeeks.org/substring-in-cpp/)
                - Complexity of ```substr```:
                    - Time: $O(N)$
                    - Space: $O(N)$
