class Solution {
    func compress(_ chars: inout [Character]) -> Int {
        let length = chars.count

        var outputLength = 0
        
        var i = 0; var j = 0
 
        while (i < length) {
            while (j < length && chars[i] == chars[j]) {
                j += 1
            }
            chars[outputLength] = chars[i]
            outputLength += 1
            if (j - i > 1) {
                for digits in String(j-i) {
                    chars[outputLength] = digits
                    outputLength += 1
                }
            }
            i = j
        }
        
        return outputLength
    }
}
