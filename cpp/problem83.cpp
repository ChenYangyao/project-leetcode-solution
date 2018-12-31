#include <mystd.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
  * this is easy
  * but some leetcode user-solution has obvious memory leak.
  */ 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if( !head ) return nullptr;
  		auto *cur = head, *p = head->next;
  		while( p ){
  			if( cur->val != p->val ){
  				cur = p; p = p->next;
  			}else{
  				auto pp = p->next;
  				delete p;
  				p = cur->next = pp;
  			}
  		}
  		return head;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	
	{
		ListNode *head = new ListNode(1);
		ListNode *cur = head;
		for(auto i: {1,2,3,3}){
			cur->next = new ListNode( i );
			cur = cur->next;
		}

		head = sol.deleteDuplicates( head );

		cur = head;
		while(cur){
			cout << cur->val << ' ';
			cur = cur->next;
		}
		cout << endl;
	}

	{
		ListNode *head = new ListNode(1);
		ListNode *cur = head;
		for(auto i: {1,2}){
			cur->next = new ListNode( i );
			cur = cur->next;
		}

		head = sol.deleteDuplicates( head );

		cur = head;
		while(cur){
			cout << cur->val << ' ';
			cur = cur->next;
		}
		cout << endl;
	}

	return 0;
}