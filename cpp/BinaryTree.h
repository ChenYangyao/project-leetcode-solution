/**
 * Binary Tree (BT) Data Structure
 * This BT is designed for Leetcode solution test,
 * not safe, not optimized for performance, so not
 * for a general usage.
 * Author: Yangyao, 2018/1117
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_
#include "mystd.h"
namespace MYDS{
using namespace MYSTD;

namespace _binary_tree_helper {

/**
 * BinaryTreeNode - node type of binary tree
 * DataT can be specified as any type when needed.
 */
template<typename DataT>
class BinaryTreeNode{
public:
    typedef DataT value_type;
    typedef BinaryTreeNode * pointer_type;
    BinaryTreeNode(int _val = 0, pointer_type _left = nullptr,
        pointer_type _right = nullptr) :
        val(_val), left(_left), right(_right){ }
    ~BinaryTreeNode(){ }

    value_type val;
    pointer_type left, right;
};

template<typename DataT> class BinaryTree;
template<typename DataT> ostream & operator<<(ostream &os, const BinaryTree<DataT> &that);

/**
 * BinaryTree - binary tree, children representation.
 * DataT, which is the type assigned to each node,  can be
 * specified as any type when needed.
 * The binary tree holds an extra head node for code-clarity.
 */
template<typename DataT>
class BinaryTree{
public:
    typedef BinaryTreeNode<DataT> node_type;
    typedef typename node_type::value_type value_type;
    typedef typename node_type::pointer_type pointer_type;

    /**
     * memory controllers
     */
    BinaryTree() :head( new node_type ){ }
    BinaryTree( pointer_type p ) :BinaryTree(){ copy(p, root()); }
    BinaryTree( const vector<value_type> &v, value_type nullval );
    BinaryTree( const BinaryTree & that ) :BinaryTree(that.root()){ }
    BinaryTree( BinaryTree && that )noexcept :BinaryTree(){ swap( that.root(), root() ); }
    ~BinaryTree(){ destroy(); delete head; head = nullptr; }
    BinaryTree & operator=( const BinaryTree &that );
    BinaryTree & operator=( BinaryTree &&that )noexcept;
    /**
     * print the tree, in a sequential manner, into tream os
     * If p is specified, only the subtree rooted in p is printed.
     */
    friend ostream & operator<< <value_type>(ostream &os, const BinaryTree &that);
    ostream &print(ostream &os, pointer_type p)const;

    /**
     * get the root node
     */
    pointer_type & root(){ return head->right; }
    const pointer_type & root()const{ return head->right; }
    /**
     * destroy a tree rooted in p
     * If p is not specified, destroy the whole tree.
     */
    void destroy(){ destroy(root()); }
    void destroy( pointer_type &p );
    /**
     * copy a binary tree rooted in s to t
     * Note that original tree t is destroyed.
     */
    void copy( pointer_type s, pointer_type &t );
protected:
    pointer_type head;
};

template<typename DataT>
ostream & operator<<(ostream &os, const BinaryTree<DataT> &that){ return that.print( os, that.root() ); }

template<typename DataT>
BinaryTree<DataT>::BinaryTree( const vector<value_type> &v, value_type nullval ):BinaryTree(){
    if( v.empty() ) return;
    root() = new node_type( v[0] );
    std::queue<pointer_type> sq; sq.push( root() );
    int done = 1; int n = v.size();
    while( done < n ){
        auto p = sq.front(); sq.pop();
        if( v[done] != nullval ){
            p->left = new node_type(v[done]);
            sq.push(p->left);
        }
        done++;
        if( done >= n ) break;
        if( v[done] != nullval ){
            p->right = new node_type(v[done]);
            sq.push(p->right);
        }
        done++;
    }
}

template<typename DataT>
BinaryTree<DataT> & BinaryTree<DataT>::operator=( const BinaryTree &that )
    { destroy(); copy(that.root(), root()); return *this; }

template<typename DataT>
BinaryTree<DataT> & BinaryTree<DataT>::operator=( BinaryTree &&that )noexcept
    { swap(that.root(), root()); return *this; }

template<typename DataT>
ostream & BinaryTree<DataT>::print(ostream &os, pointer_type p)const{
    std::queue<pointer_type> sq; sq.push(p);
    while( !sq.empty() ){
        p = sq.front(); sq.pop();
        if( !p ) os << "NULL  ";
        else{
            os << p->val << "  ";
            sq.push(p->left); sq.push(p->right);
        }
    }
    os << endl;
    return os;
}

template<typename DataT>
void BinaryTree<DataT>::destroy( pointer_type &p ){
    if( !p ) return;
    destroy(p->left); destroy(p->right);
    delete p;
    p = nullptr;
}

template<typename DataT>
void BinaryTree<DataT>::copy( pointer_type s, pointer_type &t ){
    destroy(t);
    if( !s )return;
    t = new node_type(s->val);
    copy( s->left, t->left );
    copy( s->right, t->right );
}



} // _binary_tree_helper


using _binary_tree_helper::BinaryTreeNode;
using _binary_tree_helper::BinaryTree;


}
#endif
