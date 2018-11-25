//naive solution
class MyHashSet1 {
    private var hashset = [Bool]()

    init() {
        hashset = Array(repeating: false, count: 1_000_001)
    }
    
    func add(_ key: Int) {
        hashset[key] = true
    }
    
    func remove(_ key: Int) {
        hashset[key] = false
    }
    
    func contains(_ key: Int) -> Bool {
        return hashset[key]
    }
}

//chaining method
//ref: Java std
//https://www.geeksforgeeks.org/implementing-our-own-hash-table-with-separate-chaining-in-java/
class MyHashSet2 {
    private var bucket: [hashNode?]
    private var capacity: Int
    private var occupied: Int
    
    init() {
        capacity = 10
        occupied = 0
        bucket = [hashNode?](repeating: nil, count: capacity)
    }
    
    func add(_ key: Int) {
        let bucketIndex = getIndex(key)
        var head = bucket[bucketIndex]
        
        while (head != nil) {
            if (head!.key == key) {
                return
            }
            head = head!.next
        }
        
        occupied += 1
        head = bucket[bucketIndex]
        let newNode = hashNode(key)
        newNode.next = head
        bucket[bucketIndex] = newNode
        
        if (Double(occupied)/Double(capacity) >= 0.7) {
            let tmp = bucket
            capacity *= 2
            occupied = 0
            bucket = [hashNode?](repeating: nil, count: capacity)
            for var headnode in tmp {
                while (headnode != nil) {
                    add(headnode!.key)
                    headnode = headnode!.next
                }
            }
        }
    }
    
    func remove(_ key: Int) {
        let bucketIndex = getIndex(key)
        var head = bucket[bucketIndex]
        var prev: hashNode? = nil
        
        while (head != nil) {
            if (head!.key == key) {
                break
            }
            prev = head
            head = head!.next
        }
        
        if (head == nil) {
            return
        }
        
        occupied -= 1
        
        if (prev != nil) {
            prev!.next = head!.next
        } else {
            bucket[bucketIndex] = head!.next
        }
    }
    
    func contains(_ key: Int) -> Bool {
        let bucketIndex = getIndex(key)
        var head = bucket[bucketIndex]
        
        while (head != nil) {
            if (head!.key == key) {
                return true
            }
            head = head!.next
        }
        
        return false
    }
    
    private func getIndex(_ key: Int) -> Int {
        return hashCode(key) % capacity
    }
    
    //32-bit hash function
    //ref: http://web.archive.org/web/20071223173210/http://www.concentric.net/~Ttwang/tech/inthash.htm
    private func hashCode(_ key: Int) -> Int {
        var a = key
        a = (a+0x7ed55d16) + (a<<12)
        a = (a^0xc761c23c) ^ (a>>19)
        a = (a+0x165667b1) + (a<<5)
        a = (a+0xd3a2646c) ^ (a<<9)
        a = (a+0xfd7046c5) + (a<<3)
        a = (a^0xb55a4f09) ^ (a>>16)
        return a
    }
    
    private class hashNode {
        public var key: Int
        public var next: hashNode?
        public init(_ key: Int) {
            self.key = key
        }
    }
}
