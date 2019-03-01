//fatest sample code
class Solution {
    func countPrimes(_ n: Int) -> Int {
        if (n < 3) {
            return 0
        }
        
        //Bool array consumes less memory than Set<Int>(minimumCapacity: n)
        //swift doesn't provide fixed-size array, otherwise we only need to use
        //Array(repeating: true, count: n/2) instead of n
        var primes = Array(repeating: true, count: n)
        //skip all even numbers
        //1 is odd but not prime, 2 is even but prime
        //so we can write down count = n/2 without problem
        var count = n/2
        
        var i = 3
        while (i*i < n) {
            //if primes.count == n/2, revise all following primes[x] to primes[x/2]
            if primes[i] {
                var j = i*i
                while (j < n) {
                    if primes[j] {
                        count -= 1
                        primes[j] = false
                    }
                    //only consider odd times of i
                    j += 2 * i
                }
            }
            //only consider odd numbers
            i += 2
        }
        
        return count
    }
}
