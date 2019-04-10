//time complexity O(n)
class Solution1 {
    func singleNonDuplicate(_ nums: [Int]) -> Int {
        return nums.reduce(0,^)
    }
}

//time complexity O(n)
class Solution2 {
    func singleNonDuplicate(_ nums: [Int]) -> Int {
        let length = nums.count
        for i in 0..<length {
            if (nums[i] != nums[i+1]) {
                if (i+2 == length || nums[i+1] != nums[i+2]) {
                    return nums[i+1]
                } else if (i == 0) {
                    return nums[0]
                }
            }
        }
        
        return -1
    }
}

//binary search
//time complexity o(log n)
class Solution3 {
    func singleNonDuplicate(_ nums: [Int]) -> Int {
        var head = 0; var mid = 0; var tail = nums.count-1
        
        while (head < tail) {
            mid = (head+tail)/2
            if (mid&1 == 0) {
                if (nums[mid] == nums[mid+1]) {
                    head = mid+2
                } else {
                    tail = mid-1
                }
            } else {
                if (nums[mid] == nums[mid+1]) {
                    tail = mid-1
                } else {
                    head = mid+1
                }
            }
        }
        
        return nums[head]
    }
}
