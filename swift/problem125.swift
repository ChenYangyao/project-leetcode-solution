class Solution {
    private let valid = Set("abcdefghijklmnopqrstuvwxyz0123456789")
    
    func isPalindrome(_ s: String) -> Bool {
        let s = s.lowercased().map{$0}
        var head = 0; var tail = s.count - 1
        
        while (head < tail) {
            let tmpHead = s[head]; let tmpTail = s[tail]
            if (valid.contains(tmpHead)) {
                if (valid.contains(tmpTail)) {
                    if (tmpHead == tmpTail) {
                        head += 1; tail -= 1
                    } else {
                        return false
                    }
                } else {
                    tail -= 1
                }
            } else {
                head += 1
            }
        }
        
        return true
    }
}
