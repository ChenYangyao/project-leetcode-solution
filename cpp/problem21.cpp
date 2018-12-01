#include "mystd.h"
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *init_list(vector<int> v){
    ListNode head(0), *p = &head;
    for(auto i: v){
        p->next = new ListNode(i);
        p = p->next;
    }
    return head.next;
}

ostream & print_list(ostream &os, ListNode *p){
    while(p){
        os << p->val << ' ';
        p = p->next;
    }
    return os;
}

/**
 * solution by ordinary merge - that is, creating a new list
 *
 * Time cost: Theta(n), Space cost: Theta(n).
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode head(0), *p = &head;
        while( p1 && p2 ){
            if( p1->val < p2->val ){
                p->next = new ListNode(p1->val);
                p1 = p1->next;
            }else{
                p->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            p = p->next;
        }
        if( p2 ){ p1 = p2; }
        while( p1 ){
            p->next = new ListNode(p1->val);
            p1 = p1->next;
            p = p->next;
        }
        return head.next;
    }
};

/**
 * if input lists are not required unchanged, the optimized way
 * is to insert nodes of l2 into l1, without creating new nodes.
 *
 * Time cost: Theta(n), Space cost: constant.
 *
 * Note that in this case, the memory is possible leaked since we
 * do not know how leetcode free the allocated memory of nodes.
 */
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( !l1 ) return l2;
        if( !l2 ) return l1;

        // We require to insert l2 into l1, so l1 should begin
        // with the smallet value among all in two lists.
        if( l1->val > l2->val ) swap(l1, l2);
        ListNode *front = l1;
        ListNode *p1 = l1->next;
        while( l2 ){
            ListNode * p2 = l2->next;
            while( p1 && p1->val < l2->val  ){
                l1 = p1; p1 = p1->next;
            }
            l1->next = l2;
            l2->next = p1;
            l1 = l2;
            l2 = p2;
        }
        return front;
    }
};


int main(int argc, char const *argv[]){
    // a simple test
    // Note that for simplicity, memory is leaked.
    vector<int> v1 = {1,2,3,4,5}, v2 = {1,1,5,5,7};
    auto *p1 = init_list(v1), *p2 = init_list(v2);

    print_list(cout, p1) << endl;
    print_list(cout, p2) << endl;

    Solution sol;
    Solution2 sol2;

    auto *res1 = sol.mergeTwoLists(p1,p2);
    print_list( cout, res1 ) << endl;
    auto *res2 = sol2.mergeTwoLists(p1,p2);
    print_list( cout, res2 ) << endl;
    return 0;
}
