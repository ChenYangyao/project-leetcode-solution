class Solution {
    func intersect(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var ans = [Int]()
        let length1 = nums1.count; let length2 = nums2.count
        
        if (length1 > length2) {
            var nums2 = nums2.reduce(into: [:]){$0[$1,default: 0] += 1}
            //another way to init the dictionary
            //var nums2 = Dictionary(nums2.map{($0,1)}, uniquingKeysWith: +)
            for number in nums1 {
                if let tmp = nums2[number], tmp != 0 {
                    ans.append(number)
                    nums2[number]! -= 1
                }
            }
        } else {
            var nums1 = nums1.reduce(into: [:]){$0[$1,default: 0] += 1}
            for number in nums2 {
                if let tmp = nums1[number], tmp != 0 {
                    ans.append(number)
                    nums1[number]! -= 1
                }
            }
        }
        
        return ans
    }
}
