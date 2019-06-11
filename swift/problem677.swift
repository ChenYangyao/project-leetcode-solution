public class trieNode {
    public let char: Character
    public var value: Int
    public var children: [Character:trieNode]
    
    init(_ char: Character, _ value: Int) {
        self.char = char
        self.value = value
        self.children = [Character:trieNode]()
    }
    
    public func find(_ word: String) -> Int {
        var node = self
        
        for char in word {
            guard let next = node.children[char] else {
                return 0
            }
            node = next
        }
        
        return node.value
    }
    
    public func construct(_ word: String, _ value: Int) {
        var node = self
        
        for char in word {
            if (node.children[char] == nil) {
                node.children[char] = trieNode(char, value)
            } else {
                node.children[char]!.value += value
            }
            node = node.children[char]!
        }
    }
}

class MapSum {
    private let root: trieNode
    private var records: [String:Int]
    
    init() {
        self.root = trieNode(Character(" "), 0)
        self.records = [String:Int]()
    }
    
    func insert(_ key: String, _ val: Int) {
        let delta = val - self.records[key, default: 0]
        self.records[key] = val
        self.root.construct(key, delta)
    }
    
    func sum(_ prefix: String) -> Int {
        return root.find(prefix)
    }
}
