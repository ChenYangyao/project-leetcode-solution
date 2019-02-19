class Solution {
    func largestTimeFromDigits(_ A: [Int]) -> String {
        let A = A.sorted(by: >)
        
        var upper1 = 2
        
        if (A[1] > 5 && A[2] == 2) {
            if (A[3] == 2) {
                return ""
            } else {
                upper1 = 1
            }
        }
        
        var ans = ""
        var visited = [Bool](repeating: false, count: 4)
        
        hour1: for i in (0...upper1).reversed() {
            for j in 0..<4 where !visited[j] {
                if (A[j] == i) {
                    visited[j] = true; ans.append(String(i))
                    break hour1
                }
            }
        }
        
        if (ans.count != 1) {
            return ""
        }
        
        let upper2 = (ans != "2" ? 9 : 3)
        
        hour2: for i in (0...upper2).reversed() {
            for j in 0..<4 where !visited[j] {
                if (A[j] == i) {
                    visited[j] = true; ans.append(String(i))
                    break hour2
                }
            }
        }
        
        if (ans.count != 2) {
            return ""
        }
        
        ans.append(":")
        
        minite1: for j in 0..<4 where !visited[j] {
            if (A[j] < 6) {
                visited[j] = true; ans.append(String(A[j]))
                break minite1
            }
        }
        
        if (ans.count != 4) {
            return ""
        }
        
        for j in 0..<4 where !visited[j] {
            ans.append(String(A[j]))
        }
        
        return ans
    }
}
