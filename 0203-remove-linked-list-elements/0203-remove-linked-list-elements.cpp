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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(head){
            if(head && head->val==val){
                if(prev==NULL){
                    temp=head->next;
                }
                else{
                   prev->next=(head->next)?(head->next):(NULL); 
                }
                head=head->next;
            }
            else{
                prev=head;
                head=(head->next)?(head->next):(NULL);
            }
        }
        return temp;
    }
};