//recursive, time limit exceeded
class Solution1 {
    private var cost_cp = [Int]()
    
    func minCostClimbingStairs(_ cost: [Int]) -> Int {
        cost_cp = cost
        let last = cost.count - 1
        return min(minCost(last),minCost(last-1))
    }
    
    func minCost(_ index: Int) -> Int {
        if (index == 1) {
            return cost_cp[1]
        } else if (index == 0) {
            return cost_cp[0]
        }
        return cost_cp[index] + min(minCost(index-1),minCost(index-2))
    }
}

//iterative. from bottom to top
class Solution2 {
    func minCostClimbingStairs(_ cost: [Int]) -> Int {
        var later_1 = 0; var later_2 = 0; var cur = 0
        
        for i in cost {
            cur = i + min(later_1,later_2)
            later_2 = later_1
            later_1 = cur
        }
        
        return min(later_1,later_2)
    }
}
