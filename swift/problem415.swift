class Solution {
    func addStrings(_ num1: String, _ num2: String) -> String {
        if (num1.count == 0 || num2.count == 0) {
            return (num1+num2)
        }
        
        var num1 = num1.map{Int(String($0))!}
        var num2 = num2.map{Int(String($0))!}
        if (num1.count < num2.count) {
            swap(&num1,&num2)
        }
        
        let longer = num1.count; let shorter = num2.count
        var carry = 0; var ans = String()
        
        for i in 1...shorter {
            let sum = num1[longer-i]+num2[shorter-i]+carry
            ans = String(sum%10) + ans
            carry = sum/10
        }
        
        for i in (0..<(longer-shorter)).reversed() {
            let sum = num1[i] + carry
            ans = String(sum%10) + ans
            carry = sum/10
        }
        
        if (carry != 0) {
            ans = String(carry) + ans
        }
        
        return ans
    }
}
