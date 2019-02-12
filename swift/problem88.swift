class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var tail = m+n-1; var p1 = m-1; var p2 = n-1
        
        while (p1 >= 0 || p2 >= 0) {
            if (p1 >= 0 && p2 >= 0) {
                if (nums1[p1] >= nums2[p2]) {
                    nums1[tail] = nums1[p1]
                    p1 -= 1
                } else {
                    nums1[tail] = nums2[p2]
                    p2 -= 1
                }
                tail -= 1
            } else if (p2 >= 0) {
                while (p2 >= 0) {
                    nums1[tail] = nums2[p2]
                    p2 -= 1; tail -= 1
                }
                return
            } else {
                return
            }
            
        }
    }
}
