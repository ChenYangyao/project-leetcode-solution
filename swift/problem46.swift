class Solution {
    private var ans = [[Int]]()
    
    func permute(_ nums: [Int]) -> [[Int]] {
        ans = [[Int]]()
        return permutation(nums)
    }
    
    private func permutation(_ nums: [Int]) -> [[Int]] {
        if (nums.count == 1) {
            return [nums]
        }
        
        var cache = [[Int]]()
        for idx in 0..<nums.count {
            var tmp = nums
            let head = [tmp.remove(at: idx)]
            for res in permutation(tmp) {
                cache.append(head + res)
            }
        }
        ans += cache
        
        return cache
    }
}
