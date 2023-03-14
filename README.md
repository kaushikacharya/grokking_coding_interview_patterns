Grokking Coding Interview Patterns in C++
=========================================

### <u>Course Homepage</u>

- https://www.educative.io/courses/grokking-coding-interview-patterns-cpp

### <u>Unit Test Framework</u>

- [lest](https://github.com/martinmoene/lest)
    - Unit tests are written using lest test framework which is written in a [single-file header only](./include/lest.hpp).

#### <u>Space Complexity Definiiton</u>
- There's a difference of opinion on whether memory used by input should also be considered as part of space complexity.
    - [GeeksForGeeks](https://www.geeksforgeeks.org/g-fact-86/) considers space complexity as sum of a) auxiliary space and b) space used by input.
    - Educative course considers space complexity as only the additional space used by the algorithm.
- Convention followed in this repository:
    - Only the additional space used by the algorithm is considered for space complexity.
    - Space used by the input has been ignored.

### <u>Problem Solutions</u>

#### Chapter: [Two Pointers](./notes/README.md/#two-pointers)

| Problem | Solution | Unit Tests | Time Complexity | Space Complexity* |
|---------|----------|------------|-----------------|-----------|
|[Valid Palindrome](https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/R1NKJD3XxBq)|[C++](./src/valid_palindrome.cpp)|Y|O(n)|O(1)|
|[Sum of Three Values](https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/xl6yz4283Jz)|[C++](./src/sum_of_three_values.cpp)|Y|O($n^2$)|O(1)|
|[Reverse Words in a String](https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/qAVoZ7ByYxy)|[C++](./src/reverse_words_in_a_string.cpp)|Y|O(n)|O(1)|
|[Valid Palindrome II](https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/R1kZPG4B00K)|[C++](./src/valid_palindrome_ii.cpp)|Y|O(n)|O(1)|

#### Chapter: [Fast and Slow Pointers](./notes/README.md#fast-and-slow-pointers)

| Problem | Solution | Unit Tests | Time Complexity | Space Complexity* |
|---------|----------|------------|-----------------|-----------|
|[Happy Number](https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/qVW5Xjgrn4r)|[C++](./src/happy_number.cpp)|Y||O(1)|
|[Linked List Cycle](https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/m7GZAz1lnDr)|[C++](./src/linked_list_cycle.cpp)|Y|O(n)|O(1)|

#### <u>Related Repositories</u>
- [leetcode](https://github.com/kaushikacharya/leetcode)
