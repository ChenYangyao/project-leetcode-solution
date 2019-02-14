class Solution {
    func hasGroupsSizeX(_ deck: [Int]) -> Bool {
        let counters = deck.reduce(into: [:]){$0[$1, default: 0] += 1}.values

        var minCount = Int.max
        
        for counter in counters {
            minCount = min(minCount,counter)
        }
        
        if (minCount == 1) {
            return false
        }
        
        let factors = fact(&minCount); var flag = true

        for factor in factors {
            for counter in counters {
                if (counter % factor != 0) {
                    flag = false
                    break
                }
            }
            if (flag) {
                return true
            }
            flag = true
        }
        
        return false
    }
    
    //Integer factorization
    private func fact(_ n: inout Int) -> Set<Int> {
        var ans = Set<Int>(); var i = 2
        while (i <= n) {
            while (n != i) {
                if (n%i != 0) {
                    break
                }
                ans.insert(i)
                n /= i
            }
            i += 1
        }
        ans.insert(n)
        return ans
    }
}
