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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = head;
        ListNode* temp = head;

        while (head && head->next) {

            if (head->next->val == newHead->val) {
                head->next = head->next->next;
            } else {
                newHead = head->next;
                head = head->next;
            }
        }

        return temp;
    }
};