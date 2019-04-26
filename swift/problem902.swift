//similar to problem788
class Solution {
    func atMostNGivenDigitSet(_ D: [String], _ N: Int) -> Int {
        let D = D.map{Int($0)!}
        let Dcount = D.count
        
        var N = N
        var digits = [Int]()
        
        while (N > 0) {
            digits.append(N%10)
            N /= 10
        }
        
        let Ncount = digits.count
        var ans = [Int](repeating: Dcount, count: Ncount+1)
        ans[0] = 1
        
        for power in 1..<Ncount {
            ans[power+1] = ans[power]*Dcount
        }
        
        for idx in (0..<Ncount).reversed() {
            guard let large = (D.firstIndex{$0 > digits[idx]}) else {
                if (D[Dcount-1] == digits[idx]) {
                    continue
                } else {
                    break
                }
            }
            ans[Ncount] -= (Dcount-large)*ans[idx]
            if (large == 0 || D[large-1] < digits[idx]) {
                break
            }
        }
        
        return ans.reduce(-1,+)
    }
}
