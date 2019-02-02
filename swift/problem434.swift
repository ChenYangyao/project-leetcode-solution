class Solution {
    func countSegments(_ s: String) -> Int {
        var ans = 0; var prev = true
        let space = Character(" ")
        for char in s {
            if (char != space) {
                if prev {
                    ans += 1
                }
                prev = false
            } else {
                prev = true
            }
        }
        return ans
    }
}
