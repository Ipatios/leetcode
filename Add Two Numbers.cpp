/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/ 
#include<iostream>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 
    // res is head node of the resultant list
    ListNode* res = NULL;
    ListNode *temp, *prev = NULL;
    int carry = 0, sum;
 
    // while both lists exist
    while (l1 != NULL
           || l2 != NULL) {
        // Calculate value of next
        // digit in resultant list.
        // The next digit is sum of
        // following things
        // (i) Carry
        // (ii) Next digit of l1
        // list (if there is a next digit)
        // (ii) Next digit of l2
        // list (if there is a next digit)
        sum = carry + (l1? l1->val:0) + 
        (l2? l2->val:0);
 
        // update carry for next calulation
        carry = (sum >= 10) ? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        temp = new ListNode(sum);
 
        // if this is the l1 node then
        // set it as head of the resultant list
        if (res == NULL)
            res = temp;
 
        // If this is not the l1
        // node then connect it to the rest.
        else
            prev->next = temp;
 
        // Set prev for next insertion
        prev = temp;
 
        // Move l1 and l2
        // pointers to next nodes
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
//  if last node's value sum is >=10 then 
// we have a reamainder we need to put last
    if (carry > 0)
        temp->next = new ListNode(carry);
 
    // return head of the resultant list
    return res;
        
    }
};
int main(){
    Solution* s;
    ListNode* head = new ListNode(2);
    ListNode *temp= new ListNode(4,head);
    ListNode *temp2= new ListNode(3,temp);

    ListNode* head2 = new ListNode(5);
    ListNode *temp3= new ListNode(6,head2);
    ListNode *temp4= new ListNode(4,temp3);
    s->addTwoNumbers(temp2,temp4);
}
