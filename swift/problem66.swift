//the same as problem415
class Solution {
    func plusOne(_ digits: [Int]) -> [Int] {
        var carry = 1; var ans = [Int]()
        
        for i in (0..<digits.count).reversed() {
            let sum = digits[i] + carry
            ans = [sum%10] + ans
            carry = sum/10
        }
        
        if (carry != 0) {
            ans = [carry] + ans
        }
        
        return ans
    }
}
