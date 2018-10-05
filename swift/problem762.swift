import Dispatch

//use array to determine prime numbers
class Solution1 {
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

//hash table
class Solution2 {
    func countPrimeSetBits(_ L: Int, _ R: Int) -> Int {
        let prime_number: Set = [2,3,5,7,11,13,17,19] //prime numbers lesser than 20
        var count_prime = 0 //the number of set bits for every number in the range of L...R
        var count = 0 //counts for having prime number of set bits
        for var tmp in L...R {
            count_prime = 0
            while (tmp != 0) {
                count_prime += 1
                tmp = tmp & (tmp-1)
            }
            count += prime_number.contains(count_prime) ? 1 : 0 //determine whether count_prime is prime number
        }
        return count
    }
}

//test time consuming for different methods
var test1 = Solution1()
var test2 = Solution2()

var time_start = DispatchTime.now().uptimeNanoseconds
for _ in 1...100 {
    _ = test1.countPrimeSetBits(1,1000000)
}
var time_end = DispatchTime.now().uptimeNanoseconds
print("array",(time_end-time_start)/1000000,"ms")

time_start = DispatchTime.now().uptimeNanoseconds
for _ in 1...100 {
    _ = test2.countPrimeSetBits(1,1000000)
}
time_end = DispatchTime.now().uptimeNanoseconds
print("hash table",(time_end-time_start)/1000000,"ms")
