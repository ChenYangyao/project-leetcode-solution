//same as problem 205 and problem 290
class Solution {
    func findAndReplacePattern(_ words: [String], _ pattern: String) -> [String] {
        var pattern = pattern.map{$0}; let length = pattern.count
        var ans = [String]()
        
        for var word in words where (word.count == length && bijection(&word, &pattern)) {
            ans.append(word)
        }
        return ans
    }
    
    private func bijection(_ word: inout String, _ pattern: inout [Character]) -> Bool {
        var mapping = [Character:Character]()
        
        var index = 0
        for char in word {
            let p = pattern[index]
            if (mapping[p] != nil) {
                if (char != mapping[p]!) {
                    return false
                }
            } else if mapping.values.contains(char) {
                return false
            } else {
                mapping[p] = char
            }
            index += 1
        }
        
        return true
    }
}
