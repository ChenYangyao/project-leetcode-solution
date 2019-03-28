//put numbers into correct positions
//time complexity: o(n). But swap is a three step operation!
class Solution1 {
    func findDuplicates(_ nums: [Int]) -> [Int] {
        var nums = nums
        var ans = [Int]()
        var idx = 0; let length = nums.count
        
        while (idx < length) {
            while (nums[idx]-1 != idx) {
                let tmp = nums[idx]-1
                if (tmp < 0) {
                    break
                }
                if (tmp+1 == nums[tmp]) {
                    ans.append(tmp+1)
                    nums[tmp] = -tmp-1
                    break
                }
                nums.swapAt(idx,tmp)
            }
            idx += 1
        }
        
        return ans
    }
}

//record visited number by nums[number] *= -1
//time complexity: o(n)
//ref: sample 424 ms submission
class Solution2 {
    func findDuplicates(_ nums: [Int]) -> [Int] {
        var nums = nums
        var ans = [Int]()
        
        for i in 0..<nums.count {
            let tmp = abs(nums[i])
            if (nums[tmp-1] < 0) {
                ans.append(tmp)
            }
            nums[tmp-1] *= -1
        }
        
        return ans
    }
}
