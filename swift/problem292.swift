import Dispatch

// recursive
class Solution {
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

//test time consuming for different methods
var test1 = Solution()
var test2 = Solution2()
var test3 = Solution3()

//recursive method is extremely slow
var time_start = DispatchTime.now().uptimeNanoseconds
for i in 1...40 {
    _ = test1.canWinNim(i)
}
var time_end = DispatchTime.now().uptimeNanoseconds
print("recursive",(time_end-time_start)/1000000,"ms")

time_start = DispatchTime.now().uptimeNanoseconds
for i in 1...32768 {
    _ = test2.canWinNim(i)
}
time_end = DispatchTime.now().uptimeNanoseconds
print("iteration",(time_end-time_start)/1000000,"ms")

time_start = DispatchTime.now().uptimeNanoseconds
for i in 1...32768 {
    _ = test3.canWinNim(i)
}
time_end = DispatchTime.now().uptimeNanoseconds
print("math",(time_end-time_start)/1000000,"ms")
