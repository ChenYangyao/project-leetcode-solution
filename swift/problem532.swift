//trivial searching using two sets to avoid duplicates
class Solution1 {
    func findPairs(_ nums: [Int], _ k: Int) -> Int {
        if (k < 0) {
            return 0
        }
        
        var visited = Set<Int>()
        var ans = 0
        
        for i in 0..<nums.count where !visited.contains(nums[i]) {
            var calc = Set<Int>()
            for j in 0..<nums.count where (i != j) {
                if (nums[j] - nums[i] == k && !calc.contains(nums[j])) {
                    ans += 1
                    calc.insert(nums[j])
                }
            }
            visited.insert(nums[i])
        }
        
        return ans
    }
}

//generally the same idea as Sln1
//instead of using two sets to avoid duplicates, we first convert nums into set.
class Solution2 {
    func findPairs(_ nums: [Int], _ k: Int) -> Int {
        if (k < 0) {
            return 0
        } else if (k == 0) {
            return nums.reduce(into: [:]){$0[$1, default: 0] += 1}.reduce(0,{$1.value > 1 ? $0 + 1 : $0})
        }
        let tmp = Set(nums)
        return tmp.reduce(0,{tmp.contains($1 + k) ? $0 + 1 : $0})
    }
}
