//linear search
class Solution1 {
    func isPerfectSquare(_ num: Int) -> Bool {
        var root = 1
        
        while (root*root < num) {
            root += 1
        }
        
        return root*root == num
    }
}

//Newton's method
//refer to cpp solution
class Solution2 {
    func isPerfectSquare(_ num: Int) -> Bool {
        var x0 = 0; var x1 = num/2 + 1
        
        repeat {
            x0 = x1
            x1 = (num+x0*x0)/(2*x0)
            if (x1*x1 == num) {
                return true
            }
        } while (abs(x1-x0) > 1)
        
        return false
    }
}
