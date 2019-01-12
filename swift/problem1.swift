class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic_ind = [Int:Int]()
        var sub = 0
        for index in 0..<nums.count {
            sub = target - nums[index]
            if (dic_ind[sub] == nil) {
                dic_ind[nums[index]] = index
            } else {
                return [dic_ind[sub]!, index]
            }
        }
        return [0,0]
    }
}
