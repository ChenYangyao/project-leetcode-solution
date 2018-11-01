class Solution {
    func canConstruct(_ ransomNote: String, _ magazine: String) -> Bool {
        var dic = [Character:Int]()
        
        for char in magazine {
            dic[char, default: 0] += 1
        }
        
        for char in ransomNote {
            dic[char, default: 0] -= 1
            if (dic[char]! < 0) {
                return false
            }
        }
        
        return true
    }
}
