/*
Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        // tail is always one node behind l1 and l2
        // thats why when we on tail we can change
        // the next node address and not mess with l1 and l2 
        while (l1 || l2) {
            if (!l1 || (l2 && l1->val > l2->val)) {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            } else {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
        }
        return head->next;
          }
 
       };  
    /*
    ***first try***

    ListNode* head = new ListNode();
        ListNode* tail = new ListNode();
       while(l1!=NULL || l2!=NULL){
           if(l1->val<=l2->val &&
            l2->val<=(l1->next? l1->next->val:0)){
               if(tail==NULL){
                 tail=l2;  
               }else
                   tail->next=l2;
              
               
          }
           
           if(head==NULL){       
             head->val=l1->val;
               head->next=tail;  
           }
           l1=l1->next;
           l2=l2->next;
           
          
              
          }
        return head;
    */ 