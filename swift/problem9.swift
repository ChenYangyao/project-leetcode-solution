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
        }
        if (x == 0) {
            return true
        }
        
        var x = x; var revX = x
        let length = lg(revX)
        var power = pow(length)
        
        for _ in 0..<(length/2) {
            if (x%10 != revX/power) {
                return false
            }
            x /= 10
            revX %= power
            power /= 10
        }
        
        return true
    }
    
    func lg(_ x: Int) -> Int {
        var ans = 0; var x = x
        while (x != 0) {
            x /= 10
            ans += 1
        }
        return ans
    }
    
    func pow(_ power: Int) -> Int {
        var ans = 1
        for _ in 1..<power {
            ans *= 10
        }
        return ans
    }
}
