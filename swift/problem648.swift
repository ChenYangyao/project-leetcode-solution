public class trieNode {
    public let val: Character
    public var children: [Character:trieNode]
    public var isLeaf = false
    
    init(_ val: Character) {
        self.val = val
        self.children = [Character:trieNode]()
    }
    
    public func find(_ word: String) -> String {
        var ans = ""
        var node = self
        
        for char in word {
            if node.isLeaf {
                break
            }
            guard let next = node.children[char] else {
                return word
            }
            ans.append(char)
            node = next
        }
        
        return ans
    }
    
    public func construct(_ word: String) {
        var node = self
        
        for char in word {
            if (node.children[char] == nil) {
                node.children[char] = trieNode(char)
            }
            node = node.children[char]!
        }
        
        node.isLeaf = true
    }
}

class Solution {
    func replaceWords(_ dict: [String], _ sentence: String) -> String {
        let root = trieNode(Character(" "))
        var ans = ""
        
        for word in dict {
            root.construct(word)
        }
        
        for word in sentence.split(separator: " ") {
            ans += (root.find(String(word)) + " ")
        }
        
        ans.removeLast(1)
        
        return ans
    }
}
