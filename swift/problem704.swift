class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var head = 0; var mid = 0; var tail = nums.count - 1
        
        while (head <= tail) {
            mid = (head+tail)/2
            if (nums[mid] == target) {
                return mid
            } else if (nums[mid] < target) {
                head = mid + 1
            } else {
                tail = mid - 1
            }
        }
        
        return -1
    }
}
