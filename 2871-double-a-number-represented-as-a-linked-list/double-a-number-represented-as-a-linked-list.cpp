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
        if(head==NULL or head->next==NULL){
            return head;
        }

       ListNode* newHead= reverseList(head->next);
       ListNode *headNext= head->next;
       headNext->next= head;
       head->next =NULL;
       return newHead;
    }
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* new_head = reverseList(head);
        ListNode* temp = new_head;
        int carry =0;
        
        while(temp!=NULL){
            int num= temp->val;
            
            
            num*=2;
            num+=carry;
            int stay = num%10;
            temp->val = stay;
            num/=10;
            carry = num%10;
            temp=temp->next;
        }
        if(carry!=0){
            ListNode* new_node = new ListNode(carry);
            ListNode *head_returns = reverseList(new_head);
            new_node->next = head_returns;
            return new_node;
        }
        else{
            ListNode *head_returns = reverseList(new_head);
            return head_returns;
        }
        
        
    }
};