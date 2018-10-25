// Class: Solution by 'moving' rather than 'deleting'
// Description:
//  - This is an amazing question...
// Creat: Yangyao, 2018/10/18
// References: Leetcode discussion.
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

// Class: After the first solution, I realize that we could move only one element rather than all of them.
// Creat: Yangyao CHen, 2018/10/26
class Solution2 {
public:
    void deleteNode(ListNode* node) {
        ListNode *post = node->next;
        node->val = post->val;
        node->next = post->next;
        delete post;
    }
};
