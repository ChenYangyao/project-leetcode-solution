//iterative method
class Solution1 {
    func mySqrt(_ x: Int) -> Int {
        if (x < 2) {
            return x
        }
        
        var ans = x/2; var prev = x
        
        while (prev-ans > 1) {
            prev = ans
            ans = (x/prev+prev)/2
        }
        return (ans*ans > x ? ans-1 : ans)
    }
}

//bisection method
//ref: https://en.wikipedia.org/wiki/Bisection_method
class Solution2 {
    func mySqrt(_ x: Int) -> Int {
        if (x < 2) {
            return x
        }
        
        var a = 1; var b = x
        
        while (b-a > 1) {
            let c = (a+b)/2
            if (c*c-x == 0) {
                return c
            } else if (c*c-x > 0) {
                b = c
            } else {
                a = c
            }
        }
        
        return a
    }
}
