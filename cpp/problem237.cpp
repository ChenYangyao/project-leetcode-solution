// Class: Solution by 'moving' rather than 'deleting'
// Description:
//  - This is an amazing question...
// Creat: Yangyao, 2018/10/18
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *post = node->next;
        while( post->next ){
            node->val = post->val;
            node = post; post = post->next;
        }
        node->val = post->val;
        node->next = nullptr;
        delete post;
    }
};
