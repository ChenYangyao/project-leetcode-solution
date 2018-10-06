import Dispatch

// recursive
class Solution1 {
    func canWinNim(_ n: Int) -> Bool {
        if (n>3) {
            if (canWinNim(n-1) && canWinNim(n-2) && canWinNim(n-3)) {
                return false
            } else {
                return true
            }
        } else {
            return true
        }
    }
}

//iteration
class Solution2 {
    func canWinNim(_ n: Int) -> Bool {
        if (n<4) {
            return true
        } else {
            var history = [true,true,true]
            var index_i = 2
            for _ in 4...n {
                index_i = (index_i+1)%3
                history[index_i] = !(history[0] && history[1] && history[2])
            }
            return history[index_i]
        }
    }
}

//math
class Solution3 {
    func canWinNim(_ n : Int) -> Bool {
        return (n%4 != 0)
    }
}

//time testing function
//swift is more strict than cpp when passing class to generic functions
//so protocol and extension are needed
protocol sol {
    func canWinNim(_ n: Int) -> Bool
}
extension Solution1: sol{}
extension Solution2: sol{}
extension Solution3: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for i in 1...r {
        _ = solution_class.canWinNim(i)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

//test time consuming for different methods
let test1 = Solution1()
let test2 = Solution2()
let test3 = Solution3()

time_consuming(test1,"recursive",40)
time_consuming(test2,"iteration",32768)
time_consuming(test3,"math",32768)

