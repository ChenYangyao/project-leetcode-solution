class Solution {
    func countSegments(_ s: String) -> Int {
        var ans = 0; var prev = Character(" ")
        let space = Character(" ")
        for char in s {
            if (char != space && prev == space) {
                ans += 1
            }
            prev = char
        }
        return ans
    }
}
