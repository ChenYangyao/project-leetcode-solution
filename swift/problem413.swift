class Solution {
    func numberOfArithmeticSlices(_ A: [Int]) -> Int {
        let length = A.count
        
        if (length < 3) {
            return 0
        }
        
        var head = 0; var tail = 2; var stride = 0
        let counter = {sublength in (sublength-1)*(sublength-2)/2}
        var ans = 0
        
        while (head < length - 2) {
            stride = A[head+1] - A[head]
            while (A[tail] - A[tail-1] == stride) {
                tail += 1
                if (tail == length) {
                    break
                }
            }
            let sublength = tail - head
            if (sublength > 2) {
                ans += counter(sublength)
            }
            head = tail - 1
            tail += 1
        }
        
        return ans
    }
}
