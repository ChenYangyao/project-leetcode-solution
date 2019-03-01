//if x is in range of (Int32.min)...(Int32.max)
class Solution {
    func reverse(_ x: Int) -> Int {
        var x = x; var ans = 0
        let overflow = x > 0 ? {$0 > 214748364} : {$0 < -214748364}
        while (x != 0) {
            let tmp = x%10
            if overflow(ans) {
                return 0
            }
            ans *= 10; ans += tmp
            x /= 10
        }
        return ans
    }
}

//for 64-bit Int
class Solution2 {
    func reverse(_ x: Int) -> Int {
        var x = x; var ans = 0
        //must -$1, otherwise the first test case will overflow
        let overflow = x > 0 ? {$0 > (Int.max-$1)/10} : {$0 < (Int.min-$1)/10}
        //also cannot write >= otherwise like following
        //let overflow = x > 0 ? {$0 >= Int.max/10} : {$0 <= Int.min/10}
        //otherwise the second test case will give wrong answer 0
        while (x != 0) {
            let tmp = x%10
            if overflow(ans,tmp) {
                return 0
            }
            ans *= 10; ans += tmp
            x /= 10
        }
        return ans
    }
}

print(Solution2().reverse(8085774586302733229))
print(Solution2().reverse(6085774586302733229))
