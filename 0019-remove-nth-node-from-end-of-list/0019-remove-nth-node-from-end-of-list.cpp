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
        if(!head->next && n==1){
            return NULL;
        }

        int count=0;
        
        ListNode* temp=head;

        while(temp){
            count++;
            temp=temp->next;
        }

        // If head needs to be deleted
        if (count == n) {
            temp = head->next;
            delete head;
            return temp;
        }


        int cnt=count-n;


        temp=head;
        ListNode* prev=NULL;
        while(temp && cnt--){
            prev=temp;
            temp=temp->next;
        }
        ListNode* nxt=temp->next;
        if(nxt){
            prev->next=nxt;
        }
        else{
            prev->next=NULL;
        }
        delete(temp);
        return head;


        
    }
};