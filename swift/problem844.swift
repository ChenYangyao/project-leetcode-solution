//space complexity O(N)
class Solution1 {
    func backspaceCompare(_ S: String, _ T: String) -> Bool {
        return textEditor(S) == textEditor(T)
    }
    
    func textEditor(_ S: String) -> String {
        var ans = String()
        for char in S {
            if (char != "#") {
                ans += String(char)
            } else {
                _ = ans.popLast()
            }
        }
        return ans
    }
}

//space complexity O(1). Since swift will make an copy of input parameters, this solution is indeed not an O(1) one either.
class Solution2 {
    func backspaceCompare(_ S: String, _ T: String) -> Bool {
        let S = Array(S); let T = Array(T)
        var index_S = S.count - 1; var index_T = T.count - 1
        var start_S = 0; var start_T = 0 //the index of first non-hashtag char
        var counter_S = 0; var counter_T = 0 //record how many char(s) should be skipped
        var flag_S = false; var flag_T = false //should the tmp char be compared or not
        var tmp_S = Character(" "); var tmp_T = Character(" ")
        
        for char in S {
            if (char != "#") {
                break
            }
            start_S += 1
        }
        
        for char in T {
            if (char != "#") {
                break
            }
            start_T += 1
        }
        
        while (index_S >= start_S || index_T >= start_T) { //iterate backwards through both S and T
            if (index_S >= start_S) { //ensure that we only read chars after start_S
                if !flag_S { //flag_S == true means tmp_S (from last iteration) is waiting to be compared, so no new char should be read
                    tmp_S = S[index_S]
                    index_S -= 1
                }
                if (tmp_S == "#") {
                    counter_S += 1
                    flag_S = false
                } else if (counter_S != 0){
                    counter_S -= 1
                    flag_S = false
                } else {
                    flag_S = true
                }
            }
            
            if (index_T >= start_T) {
                if !flag_T {
                    tmp_T = T[index_T]
                    index_T -= 1
                }
                if (tmp_T == "#") {
                    counter_T += 1
                    flag_T = false
                } else if (counter_T != 0) {
                    counter_T -= 1
                    flag_T = false
                } else {
                    flag_T = true
                }
            }
            
            //we have four cases for flag_S and flag_T:
            //both true, both false, S true whilst T false and S false whilst T true
            //for both true case, we compare tmp_S and tmp_T as following.
            //for other three cases, we just read the next tmp_char from S/T corresponding to false flag.
            if (flag_S && flag_T) {
                if (tmp_S != tmp_T) {
                    return false
                }
                //if two chars are the same, we move to next chars for both S and T
                flag_S = false; flag_T = false
            }
            
            if (index_S < start_S || index_T < start_T) {
                //at this stage, two flags only have three cases: both false, or one true one false
                if (flag_S != flag_T) {
                    //move to the char whose flag is true to compare with the char whose flag is already true
                    if (index_S < start_S && flag_S && index_T >= start_T) || (index_T < start_T && flag_T && index_S >= start_S) {
                        continue
                    }
                    //if nothing left can be compared with the char whose flag is already true, then we return false
                    return false
                }
                //for both false case, we just continue the while loop.
            }
        }
        
        return true
    }
}
