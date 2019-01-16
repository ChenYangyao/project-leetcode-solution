#include <mystd.h>
using namespace std;
using namespace MYSTD;


/**
 * definition for a QuadTree node.
 */
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


/**
 * Quad Tree - full implementation of intersect(), with some
 * helping ultilities for construting, destroying and debugging.
 */
class QuadTree{
public:
    /**
     * inializing of Quad Tree
     * If you use a value 'val' to initialize it, this generate a new tree.
     * If use a root node 'tr', the class takes over the tree, and is responsible
     * for the memory management.
     */
    QuadTree( bool val ):_root(copyLeaf(val)){ }
    QuadTree( Node *tr ):_root(tr){}
    ~QuadTree(){ delSubTree(_root); }
    /**
     * solution to the question intersect()
     */
    static Node * intersect(Node* tr1, Node* tr2) {
        if( tr1->isLeaf ){
            if( tr2->isLeaf ) return intersectLeafLeaf( tr1, tr2 );
            else return intersectBranchLeaf( tr2, tr1 );
        }else{
            if( tr2->isLeaf ) return intersectBranchLeaf( tr1, tr2 );
            else return intersectBranchBranch( tr1, tr2 );
        }
    }
    /**
     * print the tree nodes
     */
    ostream & print( ostream &os = cout ){
        return print( _root, os, 0 );
    }
    /**
     * return root node of the tree
     */
    Node * root(){
        return _root;
    }
    /**
     * extend a leaf node to a subtree
     */
    static void extend(Node *leaf, int val1, int val2, int val3, int val4){
        leaf->isLeaf = false;
        leaf->topLeft = copyLeaf( val1 );
        leaf->topRight = copyLeaf( val2 );
        leaf->bottomLeft = copyLeaf( val3 );
        leaf->bottomRight = copyLeaf( val4 );
    }
protected:
    Node *_root;

    static Node * copySubTree(Node *tr) {
        if( !tr ) return nullptr;
        return new Node( tr->val, tr->isLeaf, 
            copySubTree( tr->topLeft ), copySubTree( tr->topRight ), 
            copySubTree( tr->bottomLeft ), copySubTree( tr->bottomRight ) );
    }
    static Node * copyLeaf( bool val ){
        return new Node( val, true, nullptr, nullptr, nullptr, nullptr );
    }
    static void delSubTree(Node *&tr) {
        if( !tr ) return;
        delSubTree(tr->topLeft); delSubTree(tr->topRight);
        delSubTree(tr->bottomLeft); delSubTree(tr->bottomRight);
        delete tr;
        tr = nullptr;
    }
    static Node * intersectLeafLeaf(Node *tr1, Node *tr2){
        return copyLeaf( tr1->val || tr2->val );
    }
    static Node * intersectBranchLeaf(Node *tr1, Node *tr2){
        return tr2->val ? copyLeaf(true) : copySubTree(tr1);
    }
    static Node * intersectBranchBranch(Node *tr1, Node *tr2){
        auto *tr = new Node(false, false, 
            intersect( tr1->topLeft, tr2->topLeft ),
            intersect( tr1->topRight, tr2->topRight ),
            intersect( tr1->bottomLeft, tr2->bottomLeft ),
            intersect( tr1->bottomRight, tr2->bottomRight ) );
        bool val = tr->topLeft->val;
        if( tr->topLeft->isLeaf && tr->topRight->isLeaf && 
            tr->bottomLeft->isLeaf && tr->bottomRight->isLeaf && 
            tr->topRight->val == val && tr->bottomLeft->val == val &&
            tr->bottomRight->val == val ){
            delSubTree( tr->topLeft);
            delSubTree( tr->topRight);
            delSubTree( tr->bottomLeft);
            delSubTree( tr->bottomRight );
            tr->val = val;
            tr->isLeaf = true;
        }
        return tr;
    }
    static ostream & print( Node *tr, ostream &os = cout, int indent = 0 ){
        if( !tr ) return os;
        if( tr->isLeaf ){
            os << tr->val << endl;
        }else{
            os << endl;
            os << string(indent, ' ') << "topLeft: "; print( tr->topLeft, os, indent+4 );
            os << string(indent, ' ') << "topRight: "; print( tr->topRight, os, indent+4 );
            os << string(indent, ' ') << "bottomLeft: "; print( tr->bottomLeft, os, indent+4 );
            os << string(indent, ' ') << "bottomRight: "; print( tr->bottomRight, os, indent+4 );
        }
        return os;
    }
};



/**
 * solution with recursive merging, copy, and delete
 * Time cost O(n), Space cost O(n), where is number of nodes.
 *
 * Note that some C++ implementations in Leetcode discussion and solution
 * has severe logic problem (they mix the deep copy and shallow copy without
 * safe memory release).
 *
 * Author: Yangyao, 2019/01/16
 */
class Solution {
public:
    Node * intersect(Node* quadTree1, Node* quadTree2) {
        return QuadTree::intersect(quadTree1, quadTree2);
    }
};

int main(int argc, char const *argv[]){
    QuadTree tr1(true);
    auto *p1 = tr1.root();
    tr1.extend(p1, 1, 1, 0, 0);
    
    QuadTree tr2(true);
    auto *p2 = tr2.root();
    tr2.extend(p2, 1, 1, 1, 0);
    tr2.extend(p2->topRight, 0, 0, 1, 1);

    tr1.print();
    tr2.print();

    Solution sol;
    QuadTree tr12( sol.intersect( p1, p2 ) );
    tr12.print();

    return 0;
}