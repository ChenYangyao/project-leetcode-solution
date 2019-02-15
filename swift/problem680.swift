class Solution {
    func validPalindrome(_ s: String) -> Bool {
        var s = s.map{$0}; var head = 0; var tail = s.count - 1
        
        while (head < tail) {
            if (s[head] == s[tail]) {
                head += 1; tail -= 1
            } else {
                if (s[head+1] != s[tail] && s[head] != s[tail-1]) {
                    return false
                } else {
                    //either delete s[head] or s[tail]
                    return validSlice(&s,head+1,tail) || validSlice(&s,head,tail-1)
                }
            }
        }
        return true
    }
    
    private func validSlice(_ s: inout [Character], _ start: Int, _ end: Int) -> Bool {
        var head = start; var tail = end
        while (head < tail) {
            if (s[head] == s[tail]) {
                head += 1; tail -= 1
            } else {
                return false
            }
        }
        return true
    }
}
