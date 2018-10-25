#include <vector>
using namespace std;

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
    ListNode* middleNode(ListNode* head) {
        auto * temp = head;
        while( temp->next ){
            head = head->next;
            temp = temp->next;
            if( temp->next ){ temp = temp->next; }
        }
        return head;
    }
};
