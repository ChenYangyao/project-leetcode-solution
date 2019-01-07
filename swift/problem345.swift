class Solution {
    private let vowels = Set<Unicode.Scalar>("aeiouAEIOU".unicodeScalars)
    
    func reverseVowels(_ s: String) -> String {
        var s = s.unicodeScalars.map{$0}
        
        var front = 0; var tail = s.count - 1
        
        while (front < tail) {
            let containFront = vowels.contains(s[front])
            let containTail = vowels.contains(s[tail])
            if (containFront && containTail) {
                s.swapAt(front,tail)
                front += 1; tail -= 1
            } else if (containFront) {
                tail -= 1
            } else if (containTail) {
                front += 1
            } else {
                front += 1; tail -= 1
            }
        }
        
        return String(s.map{Character($0)})
    }
}
