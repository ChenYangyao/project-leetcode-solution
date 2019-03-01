public class linkedList {
    public var val: Int
    public var next: linkedList?
    init(_ val: Int) {
        self.val = val
    }
}

class MyLinkedList {
    private var length: Int
    private var head: linkedList?
    
    init() {
        length = 0
    }

    func get(_ index: Int) -> Int {
        if (index >= length) {
            return -1
        }
        var cur = head!
        for _ in 0..<index {
            cur = cur.next!
        }
        return cur.val
    }

    func addAtHead(_ val: Int) {
        let tmp = linkedList(val)
        tmp.next = head
        head = tmp
        length += 1
    }
    
    func addAtTail(_ val: Int) {
        if (head == nil) {
            head = linkedList(val)
        } else {
            var tmp = head!
            while (tmp.next != nil) {
                tmp = tmp.next!
            }
            tmp.next = linkedList(val)
        }
        length += 1
    }
    
    func addAtIndex(_ index: Int, _ val: Int) {
        if (index <= length) {
            if (index == length) {
                addAtTail(val)
            } else if (index == 0) {
                addAtHead(val)
            } else {
                var cur = head!
                for _ in 0..<(index-1) {
                    cur = cur.next!
                }
                let tmp = linkedList(val)
                tmp.next = cur.next
                cur.next = tmp
                length += 1
            }
        }
    }
    
    func deleteAtIndex(_ index: Int) {
        if (index < length) {
            if (index == 0) {
                head = head!.next
            } else {
                var cur = head!
                for _ in 0..<(index-1) {
                    cur = cur.next!
                }
                cur.next = cur.next!.next
            }
            length -= 1
        }
    }
}
