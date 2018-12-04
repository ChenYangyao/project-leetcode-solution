class Solution {
    func poorPigs(_ buckets: Int, _ minutesToDie: Int, _ minutesToTest: Int) -> Int {
        let base = minutesToTest/minutesToDie+1
        var power = 0; var buckets = buckets - 1
        
        while (buckets != 0) {
            buckets /= base
            power += 1
        }
        
        return power
    }
}
