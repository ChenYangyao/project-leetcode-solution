class Solution {
    func checkRecord(_ s: String) -> Bool {
        var flag_A = false
        var flag_L = false
        var flag_LL = false
        
        for char in s {
            if (char == "A") {
                if flag_A {
                    return false
                } else {
                    flag_A = true
                }
                flag_L = false
                flag_LL = false
            } else if (char == "L") {
                if flag_LL {
                    return false
                } else if flag_L {
                    flag_LL = true
                } else {
                    flag_L = true
                }
            } else {
                flag_L = false
                flag_LL = false
            }
        }
        
        return true
    }
}
