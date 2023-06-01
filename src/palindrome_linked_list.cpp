/*  Problem: Palindrome Linked List
    Date: 01 June 2023

    Approach: 
        - Split linked list into two halves using Fast and slow pointers.
        - Reverse the 2nd half.
        - Iterate and compare elements of first half with the reversed second half.
    
    Complexity:
        - Time: O(n), where n is the number of nodes in the linked list.
        - Space: O(1)
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

struct EduLinkedListNode {
	int data;
	EduLinkedListNode * next;
	EduLinkedListNode * arbitrary_pointer;
	EduLinkedListNode(int d) {
		data = d;
		next = nullptr;
		arbitrary_pointer = nullptr;
	}
};

EduLinkedListNode* GetMiddleNode (EduLinkedListNode* head){
    EduLinkedListNode* slowPtr = head;
    EduLinkedListNode* fastPtr = head;

    while (fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr;
}

EduLinkedListNode* ReverseList(EduLinkedListNode* head){
    EduLinkedListNode* prevNode = nullptr;
    EduLinkedListNode* curNode = head;
    EduLinkedListNode* nextNode = curNode->next;
    curNode->next = prevNode;

    while (nextNode)
    {
        prevNode = curNode;
        curNode = nextNode;
        nextNode = nextNode->next;
        curNode->next = prevNode;
    }
    
    return curNode;
}

bool CompareList(EduLinkedListNode* head1stHalf, EduLinkedListNode* head2ndHalfReversed){
    bool isPalindrome = true;

    EduLinkedListNode* curNode1stHalf = head1stHalf;
    EduLinkedListNode* curNode2ndHalfReversed = head2ndHalfReversed;

    while (curNode2ndHalfReversed)
    {
        if (curNode1stHalf->data != curNode2ndHalfReversed->data)
        {
            isPalindrome = false;
            break;
        }

        curNode1stHalf = curNode1stHalf->next;
        curNode2ndHalfReversed = curNode2ndHalfReversed->next;
    }
    
    return isPalindrome;
}

// Check palindrome in linkedList  
bool Palindrome(EduLinkedListNode* head){
    // Extract head node of the 2nd half of the list
    EduLinkedListNode* head2ndHalf = GetMiddleNode(head);

    // Reverse 2nd half of the list
    EduLinkedListNode* head2ndHalfReversed = ReverseList(head2ndHalf);

    // Compare the two halves of the list element by element
    bool isPalindrome = CompareList(head, head2ndHalfReversed);

    /* Restore the linked list (It is a good practice).
        Reversing back the reversed 2nd half would restore the original linked list
        since the next pointer of the last node of 1st half has remained intact in the entire process.
    */ 
    head2ndHalf = ReverseList(head2ndHalfReversed);

    return isPalindrome;
}

EduLinkedListNode* CreateLinkedList(vector<int> vec){
    EduLinkedListNode* head = new EduLinkedListNode(vec[0]);
    EduLinkedListNode* prevNode = head;

    for (auto it=vec.begin()+1; it != vec.end(); ++it){
        EduLinkedListNode* curNode = new EduLinkedListNode((*it));
        prevNode->next = curNode;
        prevNode = curNode;
    }

    return head;
}

lest::test tests[]={
    CASE("Test case #1"){
        vector<int> vec = {1};
        EduLinkedListNode* head = CreateLinkedList(vec);
        EXPECT(Palindrome(head) == true);
    },
    CASE("Test case #2"){
        vector<int> vec = {1,2,1};
        EduLinkedListNode* head = CreateLinkedList(vec);
        EXPECT(Palindrome(head) == true);
    },
    CASE("Test case #3"){
        vector<int> vec = {1,2,3,2,1};
        EduLinkedListNode* head = CreateLinkedList(vec);
        EXPECT(Palindrome(head) == true);
    },
    CASE("Test case #4"){
        vector<int> vec = {1,2,3,3,2,1};
        EduLinkedListNode* head = CreateLinkedList(vec);
        EXPECT(Palindrome(head) == true);
    },
    CASE("Test case #1"){
        vector<int> vec = {1,2,2};
        EduLinkedListNode* head = CreateLinkedList(vec);
        EXPECT(Palindrome(head) == false);
    },
    CASE("Test case #1"){
        vector<int> vec = {1,2,3,2,3,1};
        EduLinkedListNode* head = CreateLinkedList(vec);
        EXPECT(Palindrome(head) == false);
    },
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}