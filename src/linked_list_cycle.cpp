/*  Problem: Linked List Cycle
    Statement: Check if a linked list contains a cycle or not. If a cycle exists, return TRUE. Otherwise, return FALSE.
    Approach: Two pointers: fast and slow
                Slow pointer moves to next node in one step.
                Fast pointer moves to next of next node in one step (with the exception when current node is the last node of linear linked list).
                If cycle present, then fast pointer will meet the slow pointer.
    Complexity:
        - Time: O(n) where n is the number of nodes in the linked list.
        - Space: O(1) since the additional space used is only for storing the slow and fast pointer.
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

struct EduLinkedListNode {
    int data;
    EduLinkedListNode* next;
    EduLinkedListNode* arbitrary_pointer;
    EduLinkedListNode (int d){
        data = d;
        next = nullptr;
        arbitrary_pointer = nullptr;
    }
};

/*  Both the solutions use the fast and slow pointers.
    Difference being a) initialization of fast pointer  b) where the check for cycle detection/ reaching of end node is done.

    Solution #1 follows the solution as presented in Happy Number.
*/
bool DetectCycleSolution1(EduLinkedListNode* head){
    // Case: Empty linked list
    if (head == nullptr){
        return false;
    }

    EduLinkedListNode* slow = head;
    EduLinkedListNode* fast = head->next;

    // At each step, move slow one node and fast two nodes.
    // Continue looping till either
    //  a) fast reaches the end of the linked list (linear linked list without any cycle)
    //  b) fast catches up with slow (in case of cycle present in the linked list)
    while ((fast != nullptr) && (fast != slow))
    {
        slow = slow->next;
        fast = fast->next;

        if (fast != nullptr)
        {
            fast = fast->next;
        }
    }
    
    if (fast == slow)
    {
        return true;
    }

    return false;
}

// Solution #2: Inspired by the solution presented in the course.
bool DetectCycle(EduLinkedListNode* head){
    EduLinkedListNode* slow = head;
    EduLinkedListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    
    return false;
}

EduLinkedListNode* create_linked_list(vector<int> vec)
{
    EduLinkedListNode* head = nullptr;
    EduLinkedListNode* prevNode = nullptr;

    for (auto i=0; i != vec.size(); ++i)
    {
        EduLinkedListNode* curNode = new EduLinkedListNode(vec[i]);

        if (i == 0)
        {
            head = curNode;    
        }
        else
        {
            prevNode->next = curNode;
        }

        prevNode = curNode;
    }

    return head;
}

/*  Convert a linear linked list to a cyclic linked list by connecting an edge from the last node of the linear linked list
    to the node at tail_index.
*/
void add_cyclic_edge(EduLinkedListNode* head, unsigned int tail_index)
{
    EduLinkedListNode* fromNode = nullptr;
    EduLinkedListNode* toNode = nullptr;

    unsigned int i = 0;
    EduLinkedListNode* curNode = head;

    while (i < tail_index)
    {
        curNode = curNode->next;
        ++i;
    }
    
    toNode = curNode;

    // Now identify the last node of the acylic linked list
    while (curNode->next)
    {
        curNode = curNode->next;
    }
    
    fromNode = curNode;

    // Now add the edge which will convert the linked list from acyclic to cyclic.
    fromNode-> next = toNode;

    // return head;
}

lest::test tests[] = {
    CASE("Test Case T1"){
        vector<int> vec = {1,2,3,4,5,6};
        EduLinkedListNode* head = create_linked_list(vec);
        add_cyclic_edge(head, 3);
        EXPECT(DetectCycle(head) == true);
    },
    CASE("Test Case T2"){
        vector<int> vec = {1};
        EduLinkedListNode* head = create_linked_list(vec);
        add_cyclic_edge(head, 0);
        EXPECT(DetectCycle(head) == true);
    },
    CASE("Test Case T3"){
        vector<int> vec = {1,2};
        EduLinkedListNode* head = create_linked_list(vec);
        add_cyclic_edge(head, 0);
        EXPECT(DetectCycle(head) == true);
    },
    CASE("Test Case F1"){
        vector<int> vec = {1,2,3,4,5,6};
        EduLinkedListNode* head = create_linked_list(vec);
        EXPECT(DetectCycle(head) == false);
    },
    CASE("Test Case F2"){
        vector<int> vec = {1};
        EduLinkedListNode* head = create_linked_list(vec);
        EXPECT(DetectCycle(head) == false);
    },
    CASE("Test Case F3"){
        vector<int> vec = {1, 2};
        EduLinkedListNode* head = create_linked_list(vec);
        EXPECT(DetectCycle(head) == false);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
