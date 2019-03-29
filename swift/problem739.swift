//ref: sample solution
//no extra space needed compared to Sln2
class Solution1 {
    func dailyTemperatures(_ T: [Int]) -> [Int] {
        var waitDays = [Int](repeating: 0, count: T.count)
        //it's OK even if T.count-2<0 by using stride inside of range
        for i in stride(from: T.count - 2, through: 0, by: -1) {
            var j = i + 1
            while (waitDays[j] != 0 && T[i] >= T[j]) {
                j += waitDays[j]
            }
            if (T[i] < T[j]) {
                waitDays[i] = j - i
            }
        }
        return waitDays
    }
}

//ref: https://leetcode.com/problems/daily-temperatures/solution/
//Approach 2
class Solution2 {
    func dailyTemperatures(_ T: [Int]) -> [Int] {
        var idx = T.count - 1
        var ans = [Int](repeating: 0, count: idx + 1)
        var stack = [Int]()
        
        while (idx >= 0) {
            while (!stack.isEmpty && T[idx] >= T[stack.last!]) {
                stack.removeLast(1)
            }
            ans[idx] = stack.isEmpty ? 0 : stack.last! - idx
            stack.append(idx)
            idx -= 1
        }
        
        return ans
    }
}
