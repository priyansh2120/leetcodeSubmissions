/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
    }


    void reorderList(ListNode* head) {
        // step 1 find the middle of the linked list
        ListNode* fast = head;
        ListNode* slow = head;
        if(head->next==NULL){
            return;
        }
        while( fast!=NULL and fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* upper = head;
        while(upper->next != slow){
            upper = upper -> next;
        }
        upper->next = NULL;
        // step 2 reverse the lower part of linked list

        slow = reverseList(slow);
        upper = head;
        while(slow!=NULL and upper!=NULL){
            ListNode* upperNext = upper->next;
            upper->next = slow;
            upper= upper->next;
            slow = upperNext;
        }
        
    }
};