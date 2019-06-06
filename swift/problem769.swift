class Solution {
    func maxChunksToSorted(_ arr: [Int]) -> Int {
        var prevMax = 0
        var ans = 0
        
        for idx in 0..<arr.count {
            prevMax = max(prevMax, arr[idx])
            if (prevMax == idx) {
                ans += 1
            }
        }
        
        return ans
    }
}
