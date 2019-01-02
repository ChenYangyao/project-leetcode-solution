import Dispatch

class Solution1 {
    private func binomial(_ n: Int, _ k: Int) -> Int {
        var ans = 1
        
        for i in 0..<k {
            ans *= (n - i)
            ans /= (i + 1)
        }
        
        return ans
    }
    
    func getRow(_ rowIndex: Int) -> [Int] {
        if (rowIndex == 0) {
            return [1]
        }
        
        var ans = [Int](repeating: 0, count: rowIndex + 1)
        
        for i in 0...(rowIndex/2) {
            ans[i] = binomial(rowIndex,i)
        }
        
        for i in ((rowIndex/2)+1)...rowIndex {
            ans[i] = ans[rowIndex-i]
        }
        
        return ans
    }
}

//ref: sample 8 ms submission
class Solution2 {
    func getRow(_ rowIndex: Int) -> [Int] {
        
        if (rowIndex == 0) {
            return [1]
        }
        
        var result = [Int](repeating: 0, count: rowIndex + 1)
        
        result[0] = 1
        
        for row in 1 ... rowIndex {
            for index in (1 ... row).reversed() {
                result[index] += result[index - 1]
            }
        }
        
        return result
    }
}

protocol sol {
    func getRow(_ rowIndex: Int) -> [Int]
}
extension Solution1: sol{}
extension Solution2: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.getRow(61)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

time_consuming(Solution1(),"direct calculation", 10_000)
time_consuming(Solution2(),"two loops", 10_000)

/*
test results
 with optimisation:
 direct calculation 8636 ms for 1000000 times
 two loops 9280 ms for 1000000 times
 
 without opt.:
 direct calculation 137 ms for 10000 times
 two loops 7742 ms for 10000 times
*/
