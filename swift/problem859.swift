class Solution {
    func buddyStrings(_ A: String, _ B: String) -> Bool {
        if (A.count != B.count) {
            return false
        }
        
        let A = A.map{$0}; let B = B.map{$0}
        
        if (A == B) {
            var counter = [Character:Int]()
            for char in A {
                counter[char, default: 0] += 1
                if (counter[char] == 2) {
                    return true
                }
            }
            return false
        }
        
        var diffCount = 0; var tmpA = Character(" "); var tmpB = Character(" ")
        
        for i in 0..<A.count {
            if (A[i] != B[i]) {
                diffCount += 1
                switch diffCount {
                case 1:
                    tmpA = A[i]; tmpB = B[i]
                case 2:
                    if (tmpA != B[i] || tmpB != A[i]) {return false}
                default:
                    return false
                }
            }
        }
        
        return diffCount == 2
    }
}
