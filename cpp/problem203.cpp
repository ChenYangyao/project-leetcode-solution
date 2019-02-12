#include <mystd.h>
using namespace MYSTD;
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * just follow the requirement of the question
 * We delete each node with certain val, and let its pre-node point to
 * its post-node.
 */ 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // add a extra head node for clarity
        ListNode *_head = new ListNode(-1);
        _head->next = head;

        ListNode *p = _head, *q = head;
        while( q ){
            if( q->val == val ){
                p->next = q->next;
                delete q;
                q = p->next;
            }else{
                p = p->next; q = q->next;
            }
        }
        
        head = _head->next;
        delete _head;
        return head;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;

    ListNode *head = new ListNode(1), *p = head;
    for(int i=0; i<5; ++i){
        p->next = new ListNode(p->val + 1);
        p = p->next;
    }

    head = sol.removeElements( head, 6 );
    p = head;
    while(p){
        cout << p->val << ' ';
        p = p->next;
    }

    return 0;
}
