class MyHashMap {
    private var values: [Int]
    /** Initialize your data structure here. */
    init() {
        values = Array(repeating: -1, count: 1_000_001)
    }
    
    /** value will always be non-negative. */
    func put(_ key: Int, _ value: Int) {
        values[key] = value
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    func get(_ key: Int) -> Int {
        return values[key]
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    func remove(_ key: Int) {
        values[key] = -1
    }
}
