//brute force
//time limit exceeded
class Solution1 {
    func containsNearbyDuplicate(_ nums: [Int], _ k: Int) -> Bool {
        if (k <= 0) {
            return false
        }
        
        let length = nums.count
        
        for i in 0..<length {
            let lower = max(0,i-k); let upper = min(i+k,length-1)
            for j in lower...upper where (j != i) {
                if (nums[i] == nums[j]) {
                    return true
                }
            }
        }
        
        return false
    }
}

//use dictionary
class Solution2 {
    func containsNearbyDuplicate(_ nums: [Int], _ k: Int) -> Bool {
        if (k <= 0) {
            return false
        }
        
        var prevIndex = [Int:Int]()
        
        for i in 0..<nums.count {
            let number = nums[i]
            if (prevIndex[number] != nil && (i - prevIndex[number]! <= k)) {
                return true
            }
            prevIndex[number] = i
        }
        
        return false
    }
}
