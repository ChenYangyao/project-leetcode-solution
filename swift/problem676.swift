public class trieNode {
    public let val: Character
    public var children: [Character:trieNode]
    
    init(_ val: Character) {
        self.val = val
        self.children = [Character:trieNode]()
    }
    
    public func find(_ word: String.SubSequence) -> Bool {
        var node = self
        
        for char in word {
            guard let next = node.children[char] else {
                return false
            }
            node = next
        }
        
        return true
    }
    
    public func construct(_ word: String) {
        var node = self
        
        for char in word {
            if (node.children[char] == nil) {
                node.children[char] = trieNode(char)
            }
            node = node.children[char]!
        }
    }
}

class MagicDictionary {
    private var rootDict: [Int:trieNode]
    
    init() {
        self.rootDict = [Int:trieNode]()
    }
    
    func buildDict(_ dict: [String]) {
        for word in dict {
            if (rootDict[word.count] == nil) {
                rootDict[word.count] = trieNode(Character(" "))
            }
            rootDict[word.count]!.construct(word)
        }
    }
    
    func search(_ word: String) -> Bool {
        guard var node = rootDict[word.count] else { return false }
        var rest = word.dropFirst()
        var noMatching = true
        
        for char in word {
            for (childChar, childNode) in node.children {
                if (childChar == char) {
                    node = childNode
                    noMatching = false
                } else if childNode.find(rest) {
                    return true
                }
            }
            
            if noMatching {
                break
            } else {
                noMatching = true
            }
            
            rest = rest.dropFirst()
        }
        
        return false
    }
}
