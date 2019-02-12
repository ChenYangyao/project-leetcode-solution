#include <mystd.h>
using namespace MYSTD;
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * solution by reversing the link pointer of the second half of nodes
 *
 * There is a subtle memory leak. In principle we must repair the changed 
 * poitners in practical case, but we ignore this problem in this question 
 * for clarity.
 * 
 * Author: Yangyao, 2019/02/12
 */ 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if( !head || !head->next ) return true;
        // find the middle point of the linked list
        ListNode *fast = head->next, *slow = head;
        while( fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse the second half links
        auto *q = reverseLink( slow->next ), *p = head;
        // compare the first half and the second half
        while( q ){
            if( q->val != p->val ) return false;
            q = q->next;
            p = p->next;
        }
        return true;
    }
    ListNode *reverseLink(ListNode *head){
        ListNode *p = head->next, *q;
        head->next = nullptr;
        while(p){
            q = p->next;
            p->next = head;
            head = p;
            p = q;            
        }
        return head;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;

    // test cases in Leetcode Problem
    {
        ListNode *head = new ListNode(1), *p = head;
        p->next = new ListNode(2); p = p->next;
        cout << sol.isPalindrome( head ) << endl;
    }
    {
        ListNode *head = new ListNode(1), *p = head;
        p->next = new ListNode(2); p = p->next;
        p->next = new ListNode(2); p = p->next;
        p->next = new ListNode(1); p = p->next;
        cout << sol.isPalindrome( head ) << endl;
    }
    return 0;
}
