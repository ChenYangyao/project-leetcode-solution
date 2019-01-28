class Solution {
    func addBinary(_ a: String, _ b: String) -> String {
        var a = a; var b = b; var carry = false
        var ans = String()
        
        if (a.count < b.count) {
            swap(&a,&b)
        }
        
        while !a.isEmpty {
            let digit1 = b.popLast() == "1"
            let digit2 = a.popLast() == "1"
            ans =  ((digit1 != digit2) != carry ? "1" : "0") + ans
            carry = (digit1&&digit2)||(digit1&&carry)||(digit2&&carry)
            
        }
        
        if carry {
            ans = "1" + ans
        }
        return ans
    }
}
