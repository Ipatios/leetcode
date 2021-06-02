/*
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/ 

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        int position = 1;
        ListNode *curr = head;
        ListNode *result = new ListNode(0);
        if (head->next == nullptr)
        {
            return head;
        }

        while (curr)
        {
            // only for the first two nodes
            if(position==2){
             ListNode* temp=head->next;
                head->next=curr;
                curr->next=temp;
                curr=curr->next;
                result=head;
                position++;
                continue;   
            }
            // for the rest nodes
            if (position % 2 == 0 && curr->next!=nullptr)
            {
                ListNode* temp=curr->next;
                head->next=temp;
                curr->next=temp->next;
                temp->next=curr;
                curr=curr->next; 
            }
// for when the number of list's nodes are odd 
            if(curr==NULL||curr->next==nullptr)break;
            head=head->next;
            
            position++;
        }
        return result;
    }
};
