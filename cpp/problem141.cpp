#include <mystd.h>
using namespace std;
using namespace MYSTD;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * solution by recording visited nodes
 * 
 * If a node is visited twice, it is obvious there is a cycle.
 * Time: O(n), space O(n).
 * Author: Yangyao, 2019/02/04
 */ 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        auto *p = head;
        while( p ){
            auto it = visited.find( p );
            if( it != visited.end() ) return true;
            visited.emplace(p);
            p = p->next;
        }
        return false;
    }
};

/**
 * solution with two walkers, one fast and one slow
 * 
 * If there is a cycle, two walkers must encounter at some
 * time.
 * Reference: Leetcode Discussion
 */ 
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if( !head ) return false;
        auto *fast = head, *slow = head;
        while( fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow ) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;
    
    // case with no cycle
    ListNode *head = new ListNode(1), *p = head;
    p->next = new ListNode(2); p = p->next;
    p->next = new ListNode(3); p = p->next;
    p->next = new ListNode(4); p = p->next;
    cout << sol.hasCycle( head ) << endl;
    cout << sol2.hasCycle( head ) << endl;

    // case with cycle
    p->next = head->next;
    cout << sol.hasCycle( head ) << endl;
    cout << sol2.hasCycle( head ) << endl;
    
    return 0;
}
