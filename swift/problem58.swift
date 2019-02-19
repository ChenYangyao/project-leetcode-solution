class Solution {
    func lengthOfLastWord(_ s: String) -> Int {
        var startCount = false; var length = 0
        
        for char in s.reversed() {
            if (char == " ") {
                if !startCount {
                    continue
                } else {
                    return length
                }
            } else {
                startCount = true
                length += 1
            }
        }
        
        return length
    }
}
