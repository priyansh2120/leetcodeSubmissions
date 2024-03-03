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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp= head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        if(cnt==1){
            return NULL;
        }
        if(cnt==n){
            return head->next;
        }
        temp=head;
        for(int i=0; i<cnt-n-1; i++){
            temp=temp->next;
        }
        if(temp->next->next) temp->next=temp->next->next;
        else temp->next=NULL;
        
        return head;
    }
};