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
 * Solution 1: by reversing one of the list, and counting
 * the nodes of lists before and after reversing, and then 
 * solving the linear equation set of three variables k1, 
 * k2 and k4 (see code for definition).
 * 
 * Author: Yangyao Chen, 2019/02/16
 */
#define REVERSE(h, f) {\
    ListNode *p = h->next, *q;\
        h->next = nullptr; f\
        while(p){\
            q = p->next; p->next = h;\
            h = p; p = q; f\
        }\
}
#define TRAVERSAL(h, f, t) {\
    ListNode *p = h; f\
    while( p->next ){\
        p = p->next;\
        f\
    }\
    t\
}
#define LOCATE(h, n) {\
    int i = 0;\
    while( i++ < n ) h = h->next;\
    return h;\
} 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if( !(headA && headB) ) return nullptr;
        int k1 = 0, k2 = 0, k4 = 0; 
        ListNode *a = headA, *b;
        REVERSE(headA, ++k1;)
        TRAVERSAL(headB, ++k2;, b=p;)
        REVERSE(headA, ;)
        if( a != b ) return nullptr;
        TRAVERSAL(headB, ++k4;, ;)
        int p = (k2-1+k4-k1)/2, n = (k2-1-k4+k1)/2;
        if( n < p ) LOCATE(headA, n) else LOCATE(headB, p)
    }
};

/** 
 * Solution 2: by first counting nodes of two lists, and then moving the head of 
 * the longer one to let them synchronized.
 * 
 * Author: Yangyao Chen, 2019/02/16
 */
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto *pa = headA, *pb = headB;
        if( !(pa && pb) ) return nullptr;
        int cnta = cntNodes(pa), cntb = cntNodes(pb);
        if( pa != pb ) return nullptr;
        forward( cnta>cntb?headA:headB, abs(cnta-cntb) );
        while( headA != headB ){ headA=headA->next; headB=headB->next; }
        return headA;
    }
    int cntNodes(ListNode *&p){
        int cnt = 1;
        while( p->next ){ p = p->next; ++cnt; }
        return cnt;
    }
    void forward(ListNode *&p, int n){
        for(int i=0; i<n; ++i) p = p->next;
    }
};

/** 
 * Solution 3: refer to Leetcode Official Solution Approach 3: Two Pointers
 */ 


int main(int argc, char const *argv[]){
    // test case in Leetcode Problem
    ListNode *a = new ListNode(4), *c = a;
    for(auto i: {1,8,4,5}){
        c->next = new ListNode(i);
        c = c->next;
    }
    ListNode *b = new ListNode(5); c = b;
    for(auto i: {0,1}){
        c->next = new ListNode(i);
        c = c->next;
    }
    c->next = a->next->next;

    Solution sol;
    cout << sol.getIntersectionNode( a,b )->val << endl;

    Solution2 sol2;
    cout << sol2.getIntersectionNode( a,b )->val << endl;

    return 0;
}