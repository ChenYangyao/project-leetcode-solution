class MyLinkedListNode{
    int val;
    MyLinkedListNode *prev, *next;
    MyLinkedListNode(int _val = 0, MyLinkedListNode *_prev = nullptr,
        MyLinkedList *_next = nullptr):val(_val), prev(_prev),next(_next){ }
};

class MyLinkedList {
public:
    typedef MyLinkedListNode node_type;
    typedef node_type *pointer_type;
    /** Initialize your data structure here. */
    MyLinkedList():head(new node_type()) {
        init_head(head);
    }
    ~MyLinkedList(){
        for( pointer_type t = head->next, n = t->next; t != head; t = n, n = n->next ){
            delete t;
        }
        delete head;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int id = 0;
        auto p = locateIndex(index, id);
        if( p == head ) return -1;
        return p->val;
    }
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        add(val, head, head->next);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        add(val, head->prev, head);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int id = 0;
        auto p = locateIndex(index, id);
        if( p == head ){
            if( id == index ){
                add(val, head->prev, head);
            }
        }else{
            add(val, p->prev, p);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int id = 0;
        auto p = locateIndex(index, id);
        if( p != head ) deleteAt(p);
    }
protected:
    pointer_type head;
    void init_head(pointer_type p){
        p->next = p;
        p->prev = p;
    }
    void deleteAt(pointer_type p){
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
    pointer_type locateIndex(int index, int &id){
        pointer_type t = head->next;
        for( ; t != head; t = t->next ){
            if( id++ = index ) break;
        }
        return t;
    }
    void add(int val, pointer_type p, pointer_type q){
        pointer_type newp = new pointer_type(val, p, q);
        p->next = newp;
        q->prev = newp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
