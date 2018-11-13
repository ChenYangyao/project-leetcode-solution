//judge whether to output Medals or numbers manually to avoid unnecessary comparison
class Solution {
    func findRelativeRanks(_ nums: [Int]) -> [String] {
        let length = nums.count
        
        if (length < 3) {
            if (length == 1) {
                return ["Gold Medal"]
            } else {
                if (nums[0] > nums[1]) {
                    return ["Gold Medal","Silver Medal"]
                } else {
                    return ["Silver Medal","Gold Medal"]
                }
            }
        }
        
        var dic_id = [Int:Int]()
        var index = 0
        for number in nums {
            dic_id[number] = index
            index += 1
        }
        
        var nums = nums.sorted(by: >)
        var ans = Array(repeating: "",count: length)
        
        ans[dic_id[nums[0]]!] = "Gold Medal"
        ans[dic_id[nums[1]]!] = "Silver Medal"
        ans[dic_id[nums[2]]!] = "Bronze Medal"
        
        index = 4
        for number in nums[3...] {
            ans[dic_id[number]!] = String(index)
            index += 1
        }
        
        return ans
    }
}
