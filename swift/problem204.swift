//fatest sample code
class Solution {
    func countPrimes(_ n: Int) -> Int {
        if (n < 3) {
            return 0
        }
        
	//Bool array consumes less memory than Set<Int>(minimumCapacity: n)
        var primes = Array(repeating: true, count: n)
        var count = n / 2
        
        var i = 3
        while (i*i < n) {
            if primes[i] {
                var j = i*i
                while (j < n) {
                    if primes[j] {
                        count -= 1
                        primes[j] = false
                    }
                    j += 2 * i
                }
            }
            i += 2
        }
        
        return count
    }
}
