import Foundation

class Solution1 {
    func isPalindrome(_ x: Int) -> Bool {
        if (x < 0) {
            return false
        }
        
        var x = x; var digits = [Int]()
        
        while (x > 0) {
            digits.append(x%10)
            x /= 10
        }
        
        let length = digits.count
        for i in 0..<(length/2) {
            if (digits[i] != digits[length-i-1]) {
                return false
            }
        }
        
        return true
    }
}

class Solution2 {
     func isPalindrome(_ x: Int) ->  Bool {
        if (x < 0) {
            return false
        } else if (x == 0) {
            return true
        }
        
        var x = x; var revX = x
        let length = Int(log10(Double(x)))
        var power = lround(pow(10,Double(length)))
        
        for i in 0..<((length+1)/2) {
            if (x%10 != revX/power) {
                return false
            }
            x /= 10
            revX %= power
            power /= 10
        }
        
        return true
    }
}
