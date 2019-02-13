//totally the same as problem205
class Solution {
    func wordPattern(_ pattern: String, _ str: String) -> Bool {
        let pattern = pattern.unicodeScalars
        let str = str.split(separator: " ")
        
        if (pattern.count != str.count) {
            return false
        }
        
        var mapping = [String.SubSequence:Unicode.Scalar]()
        var index = 0
        
        for char in pattern {
            let word = str[index]
            if (mapping[word] != nil) {
                if (char != mapping[word]!) {
                    return false
                }
            } else if mapping.values.contains(char) {
                return false
            } else {
                mapping[word] = char
            }
            index += 1
        }
        
        return true
    }
}
