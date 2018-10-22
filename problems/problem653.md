## Problem 653: Two Sum IV - Input is a BST

problem: [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)

### Solution

- [Python](../python/problem653.py)

- [C++](../cpp/problem653.cpp)

- [Swift](../swift/problem653.swift)

### Discussion

**Reference**: Thanks Ziyang for recommending the 'squeezing' method (see below).

The key feature of this problem is that the input sequence is a binary search tree (BST), which itself is a very efficient structure for searching problem. So we have the following conclusion:

- The [solution using a Hash-table](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/solution/) (either with BST or without) is un-acceptable, since it takes O(n) extra memory (note that the space cost by a hash table usually has a very large coefficient, so the extra memory consuming can be even larger than the BST itself).

- The solution should take advantage of the properties of the BST structure.

Considering these two conclusion, we have the following solutions. The first have LESS memory cost O(log(n)), but larger time cost O(n*log(n)), so it is most suitable for space-limited problem. The second have O(log(n)) space cost (same with the first method in O notation, but have a larger coefficient), but BEST time cost ( O(n) ), so it is nice for the time-controlled situation.

**Solution 1: using BST searching algorithm**

For each value to search, the BST gives response within O(log(n)) time (where n is the number of nodes in BST). When we want to find two nodes with value i, j that satisfy i+j = sum, we traverse the BST, and for each node with value x we determine whether sum - x is in the tree or not by BST search. This is stopped when sum-x is found in the tree, or the traversal is finished.

The algorithm shall like this:
```c++
bool findTarget(TreeNode* root, int k) {
    if( !root ) return false;
    stack<TreeNode *> stk; stk.push_back(root);
    TreeNode *temp = nullptr, *find = nullptr;
    while( !stk.empty() ){                              // <2> DFS traversal working with the stack 'stk'.
        temp = stk.top(); stk.pop();
        if( ( find = locateVal(k - temp->val, root) ) && find != temp ) return true;
        if( temp->left ) stk.push(temp->left);
        if( temp->right ) stk.push(temp->right);
    }
    return false;
}
TreeNode * locateVal(int val, TreeNode *p){             // <1> Search the value 'val' in BST rooted with 'p'.
    while(p){
        if( val < p->val ) p = p->left;
        else if( p->val < val ) p = p->right;
        else break;
    }
    return p;
}
```

Here the subroutine `<1>` implement the BST search algorithm. At `<2>` we perform DFS traversal with a stack.  The DFS takes O(log(n)) memory, and O(n) time. For each node visited, we apply the BST search with time cost O(log(n)) and space cost O(1). So the total time cost is O(n*log(n)) while the total space cost remains O(log(n)).

**Solution 2: Squeezing method**

This treat the BST as a sorted sequential list `L` with index ranging from `beg` to `end`. We first know that the result `i`, 'j' should locate in range [beg, end], then we iterate to narrow the range. At each step,

* if L[i] + L[j] < sum: the only sensible way is to increase i by 1, since if we decrease j, the summation must decrease.

* if L[i] + L[j] > sum: similar to above, but we need to decrease j by 1.

* if L[i] + L[j] == sum: we find the result.

The loop we stopped when we find the result, or the index j >= i so we know the result does not exist.

The only problem remains is that how we take the BST as a sequence. The key is to use in-order-DFS. An in-order-DFS for BST will give an increasing sequence, while the reversed in-order-DFS will give a decreasing one. So we maintain two stacks, one for normal DFS while the other for reversed one.

The implementation can be like the following:
```c++
class Solution2{
public:
    bool findTarget(TreeNode* root, int k) {
        init(root); rinit(root);
        TreeNode *l = next(), *r = rnext();
        while( l != r ) {                               // <5> squeezing algorithm.
            int sum = l->val + r->val;
            if( sum < k ){ l = next(); }
            else if( sum > k ){ r = rnext(); }
            else{ return true; }
        }
        return false;
    }
protected:
    void init(TreeNode *root){ _cur = root; }           // <1> init the DFS traversal.
    void rinit(TreeNode *root){ _rcur = root; }         // <2> init the reversed DFS traversal.
    TreeNode * next(  ){                                // <3> get next node in DFS order.
        if( _cur || !_stk.empty() ){
            TreeNode *p = _cur;
            while( p ){
                _stk.push( p ); p = p->left;
            }
            p = _stk.top(); _stk.pop();
            _cur = p->right;
            return p;
        }
        return nullptr;
    }
    TreeNode * rnext(  ){                               // <4> get next node in reversed DFS order.
        if( _rcur || !_rstk.empty() ){
            TreeNode *p = _rcur;
            while( p ){
                _rstk.push( p ); p = p->right;
            }
            p = _rstk.top(); _rstk.pop();
            _rcur = p->left;
            return p;
        }
        return nullptr;
    }
    TreeNode *_cur = nullptr, *_rcur = nullptr;
    stack<TreeNode *> _stk, _rstk;
};

```

At `<1>` the DFS is initialized, while calling of `<3>` always return the next node. `<2>` and `<4>` do the same thing, but for the reversed DFS. Here at `<5>` we narrow the range of sequential list by comparing the sum of two ends of the squential list with the target value. This solution doubles the memory cost, 2*log(n), compared with solution 1, since it maintains two stack structures, but the time consumption is much better, viz O(n).
