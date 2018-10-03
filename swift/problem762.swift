class Solution {
    func countPrimeSetBits(_ L: Int, _ R: Int) -> Int {
        let prime_number = [0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1] //record the positions of prime numbers lesser than 20
        var count_prime = 0 //the number of set bits for every number in the range of L...R
        var count = 0 //counts for having prime number of set bits
        for var tmp in L...R {
            count_prime = 0
            while (tmp != 0) {
                count_prime += 1
                tmp = tmp & (tmp-1)
            }
            count += prime_number[count_prime] //determine whether count_prime is prime number
        }
        return count
    }
}

var test = Solution()
print(test.countPrimeSetBits(90,1000))
