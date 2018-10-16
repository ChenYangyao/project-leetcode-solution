/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = nullptr, *q = head, *r = nullptr;
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};
