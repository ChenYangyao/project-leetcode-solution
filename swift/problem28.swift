//ref: KMP algorithm implemented by
//https://github.com/raywenderlich/swift-algorithm-club/tree/master/Knuth-Morris-Pratt
class Solution {
    func strStr(_ haystack: String, _ needle: String) -> Int {
        let text = Array(haystack)
        var pattern = Array(needle)
        
        let textLength = text.count
        let patternLength = pattern.count
        
        if (patternLength == 0) {
            return 0
        }
        
        if (textLength < patternLength) {
            return -1
        }
        
        var suffixPrefix = [Int](repeating: 0, count: patternLength)
        var textIndex = 0
        var patternIndex = 0
        /* Pre-processing stage: computing the table for the shifts (through Z-Algorithm) */
        let zeta = ZetaAlgorithm(&pattern)
        
        for patternIndex in (1 ..< patternLength).reversed() {
            textIndex = patternIndex + zeta[patternIndex] - 1
            suffixPrefix[textIndex] = zeta[patternIndex]
        }
        
        /* Search stage: scanning the text for pattern matching */
        textIndex = 0
        patternIndex = 0
        
        while (patternLength - patternIndex - 1 < textLength - textIndex) {
            while (patternIndex < patternLength && text[textIndex] == pattern[patternIndex]) {
                textIndex += 1; patternIndex += 1
            }
            
            if (patternIndex == patternLength) {
                return textIndex - patternIndex
            }
            
            if (patternIndex == 0) {
                textIndex += 1
            } else {
                patternIndex = suffixPrefix[patternIndex - 1]
            }
        }
        
        return -1
    }
    
    func ZetaAlgorithm(_ pattern: inout [Character]) -> [Int] {
        let patternLength = pattern.count
        var zeta = [Int](repeating: 0, count: patternLength)
        
        var left = 0
        var right = 0
        var k_1 = 0
        var betaLength = 0
        var textIndex = 0
        var patternIndex = 0
        
        for k in 1..<patternLength {
            if (k > right) {  // Outside a Z-box: compare the characters until mismatch
                patternIndex = 0
                
                while (k + patternIndex < patternLength  &&
                    pattern[k + patternIndex] == pattern[patternIndex]) {
                        patternIndex += 1
                }
                
                zeta[k] = patternIndex
                
                if (zeta[k] > 0) {
                    left = k; right = k + zeta[k] - 1
                }
            } else {  // Inside a Z-box
                k_1 = k - left + 1
                betaLength = right - k + 1
                
                if (zeta[k_1 - 1] < betaLength) { // Entirely inside a Z-box: we can use the values computed before
                    zeta[k] = zeta[k_1 - 1]
                } else if (zeta[k_1 - 1] >= betaLength) { // Not entirely inside a Z-box: we must proceed with comparisons too
                    textIndex = betaLength
                    patternIndex = right + 1
                    
                    while (patternIndex < patternLength && pattern[textIndex] == pattern[patternIndex]) {
                        textIndex += 1
                        patternIndex += 1
                    }
                    
                    zeta[k] = patternIndex - k
                    left = k
                    right = patternIndex - 1
                }
            }
        }
        return zeta
    }
}
