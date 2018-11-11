class Solution {
    func findShortestSubArray(_ nums: [Int]) -> Int {
        typealias PosCount = (deb: Int, fin: Int, decom: Int)
        var dic = [Int:PosCount]() //use only one dictionary to reduce memory consuming
        var index = 0
        var ans = 50_001
        
        for number in nums {
            if (dic[number] == nil) {
                dic[number] = (index, index, 1)
            } else {
                dic[number]!.fin = index
                dic[number]!.decom += 1
            }
            index += 1
        }
        
        index = 0 //reuse "index" to store the maximun repeat count
        
        for dc in dic.values where (dc.decom >= index){
            index = dc.decom
        }
        
        for ps in dic.values where (ps.decom == index){
            ans = min(ans,ps.fin - ps.deb)
        }
        
        return (ans + 1)
    }
}
