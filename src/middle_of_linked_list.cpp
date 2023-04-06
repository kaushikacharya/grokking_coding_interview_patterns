/*  Problem: Middle of the Linked List
    URL: https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/m20QRwBm3mp
    Date: April 06, 2023
    Approach: Two pointers: fast and slow
            Initialize both the pointers to head of the linked list.
            For each iteration, move slow pointer one step and fast pointer two steps forward.
            Iterate till the fast pointer can move two steps i.e.,
            Fast pointer has not reached either end of the list or the last node of the list.
            The slow pointer will be at the middle node of the linked list at that moment.
    
    Complexity:
            Time Complexity: O(n) (Since the pointers iterate once over the linked list.)
            Space Complexity: O(1) (Constant additional space required.)
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

struct EduLinkedListNode {
    int data;
    EduLinkedListNode* next;
    EduLinkedListNode* arbitrary_pointer;
    EduLinkedListNode(int d){
        data = d;
        next = nullptr;
        arbitrary_pointer = nullptr;
    }
};

// function for finding the middle node
EduLinkedListNode* GetMiddleNode(EduLinkedListNode* head){

    EduLinkedListNode* slow = head;
    EduLinkedListNode* fast = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

EduLinkedListNode* create_linked_list(vector<int> vec){
    EduLinkedListNode* head = nullptr;
    EduLinkedListNode* prev = nullptr;

    for (auto i=0; i != vec.size(); ++i){
        EduLinkedListNode* cur = new EduLinkedListNode(vec[i]);

        if (i == 0){
            head = cur;
        } 
        else {
            prev->next = cur;
        }

        // Assign prev to cur before moving into next iteration.
        prev = cur;
    }

    return head;
}

lest::test tests[] = {
    CASE("TEST CASE 1: Single Node"){
        vector<int> vec = {1};
        EduLinkedListNode* head = create_linked_list(vec);
        EXPECT(GetMiddleNode(head)->data == 1);
    },
    CASE("TEST CASE 2: Two nodes"){
        vector<int> vec = {1,2};
        EduLinkedListNode* head = create_linked_list(vec);
        EXPECT(GetMiddleNode(head)->data == 2);
    },
    CASE("TEST CASE 3: Odd nodes"){
        vector<int> vec = {1, 2, 3};
        EduLinkedListNode* head = create_linked_list(vec);
        EXPECT(GetMiddleNode(head)->data == 2);
    },
    CASE("TEST CASE 4: Even nodes"){
        vector<int> vec = {1, 2, 3, 4, 5, 6};
        EduLinkedListNode* head = create_linked_list(vec);
        EXPECT(GetMiddleNode(head)->data == 4);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
