class Solution {
    func powerfulIntegers(_ x: Int, _ y: Int, _ bound: Int) -> [Int] {
        let xpower = power(x,bound); let ypower = power(y,bound)
        var ans = Set<Int>()
        for xp in xpower {
            for yp in ypower {
                if (xp + yp <= bound) {
                    ans.insert(xp + yp)
                } else {
                    break
                }
            }
        }
        
        return Array(ans)
    }
    
    private func power(_ base: Int, _ bound: Int) -> [Int] {
        if (base == 1) {
            return [1]
        } else if (base == 0) {
            return [0]
        }
        var tmp = base; var ans = [1]
        
        while (tmp < bound) {
            ans.append(tmp)
            tmp *= base
        }
        
        return ans
    }
}
