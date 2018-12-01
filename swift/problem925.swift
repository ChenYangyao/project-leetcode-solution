class Solution {
    func isLongPressedName(_ name: String, _ typed: String) -> Bool {
        var prev = Character(" ")
        var ind = 0
        let typed = Array(typed)
        let lt = typed.count
        
        for c in name {
            if (ind == lt) {
                return false
            } //"name" still has element(s) whilst "typed" not
            while (typed[ind] != c) {
                if (typed[ind] != prev) {
                    return false
                }
                while (typed[ind] == prev) {
                    ind += 1
                    if (ind == lt) {
                        return false
                    } //"typed" is always repeating the prev char
                }
            } //when it exits this loop, typed[ind] == c
            ind += 1 //so here ind should add 1
            prev = c
        }
        
        if (ind != lt) { //"typed" repeats the last char of "name"
            for i in ind..<lt {
                if typed[i] != prev {
                    return false
                }
            }
        }
        
        return true
    }
}
