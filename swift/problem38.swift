class Solution {
    func countAndSay(_ n: Int) -> String {
        if (n == 1) {
            return "1"
        }
        
	//"n" can be replaced with any other character instead of digit.
	//"n" is used for the sake of last digit in the following loop
	//for digits in prevAns {}
        let prevAns = countAndSay(n-1) + "n"
        var ans = String(); var prevDigit = prevAns.first!
        var counter = 0
        
        for digits in prevAns {
            if (digits == prevDigit) {
                counter += 1
            } else {
                ans += String(counter) + String(prevDigit)
                counter = 1
                prevDigit = digits
            }
        }
        
        return ans
    }
}
