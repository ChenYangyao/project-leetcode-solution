import Foundation

class Solution1 {
    func checkPerfectNumber(_ num: Int) -> Bool {
        if num <= 0 {
            return false
        }
        
        var i = 1
        var sum = 0
        while i * i <= num {
            if num % i == 0, i != num {
                let n = num / i
                sum += i
                if n != num, n != i {
                    sum += n
                }
            }
            i += 1
        }
        return sum == num
    }
}

//first facterise num, then form all divisors from factors
//generally much slower than Sln1 since init() and defer{} take times
//but for num with factors possessing large multi, it seems like Sln2 is better
class Solution2 {
    typealias factorisation = (base: Int, multi: UInt8)
    private var n = 0
    private var divisors = [Int]()
    private var factors = [factorisation]()
    private var length = 0
    
    func checkPerfectNumber(_ num: Int) -> Bool {
        if (num < 6) {
            return false
        }
        
        n = num
        fact(); length = factors.count
        comb(1,0)
        defer {
            //if Sln2 instance is called more than once,
            //these two arrays should be emptied
            divisors = [Int](); factors = [factorisation]()
        }
        return divisors.reduce(0,+) + 1 == num + num
    }
    
    private func fact() {
        var i = 2
        
        while (i*i <= n) {
            var multi = UInt8(0)
            if (n%i == 0) {
                while (n%i == 0) {
                    multi += 1
                    n /= i
                }
                factors.append((i,multi))
            }
            i += 1
        }
        
        if (n != 1) {
            factors.append((n,1))
        }
    }
    
    private func comb(_ multiplicand: Int, _ idx: Int) {
        for j in idx..<length {
            var x = factors[j].base*multiplicand
            for _ in 0..<factors[j].multi {
                divisors.append(x)
                comb(x,j+1)
                x *= factors[j].base
            }
        }
    }
}

//see https://leetcode.com/problems/perfect-number/solution/
//approach 4: Euclid-Euler Theorem
//constant time regardless of num
class Solution3 {
    private let perfect: Set<Int> = [6,28,496,8128,33550336,8589869056,137438691328,2305843008139952128]
    
    func checkPerfectNumber(_ num: Int) -> Bool {
        return perfect.contains(num)
    }
}

protocol sol {
    func checkPerfectNumber(_ num: Int) -> Bool
}
extension Solution1: sol{}
extension Solution2: sol{}
extension Solution3: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        for j in 1...45 {
            _ = solution_class.checkPerfectNumber(1 << j)
        }
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

time_consuming(Solution1(),"1",100)
time_consuming(Solution2(),"2",10000)
time_consuming(Solution3(),"3",10000)

/** test results
 1 770 ms for 100 times
 2 1035 ms for 10000 times
 3 10 ms for 10000 times
**/
