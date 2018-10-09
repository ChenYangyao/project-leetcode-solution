import Dispatch

class Solution1 {
    func surfaceArea(_ grid: [[Int]]) -> Int {
        var output = 0
        for i in 0 ..< grid.count {
            for j in 0 ..< grid[0].count {
                if grid[i][j] != 0 {
                    output += grid[i][j] * 4 + 2
                    if i > 0 {
                        output -= 2 * min(grid[i][j], grid[i - 1][j])
                    }
                    if j > 0 {
                        output -= 2 * min(grid[i][j], grid[i][j - 1])
                    }
                }
            }
        }
        return output
    }
}

//convert 3D problem to 2D using function from problem 463
class Solution2 {
    func surfaceArea(_ grid: [[Int]]) -> Int {
        let tmp = grid.flatMap{$0}.filter{$0>0}
        let top_and_bottom = tmp.count*2
        if (top_and_bottom == 0) {
            return 0
        }
        let lowest = tmp.min()!
        let highest = tmp.max()!
        var output = top_and_bottom
        var grid_tier = grid
        output += tier_surface(grid)*(lowest-1) //surface area below lowest = tmp.min
        for tier in lowest...highest {
            grid_tier = grid
            output += tier_surface(grid_tier.map{$0.map{if ($0<tier) {return 0} else {return $0}}})
        }
        return output
    }
    
    func tier_surface(_ grid: [[Int]]) -> Int {
        var surface = 0
        let row = grid.count-1
        let col = grid[0].count-1
        
        if (row == 0 || col == 0) {
            return (2*grid.flatMap{$0}.filter{$0 != 0}.count + 2)
        }
        
        for i in 0...row {
            for j in 0...col {
                if (grid[i][j] != 0) {
                    surface += 4
                    if (i > 0 && grid[i-1][j] != 0) {
                        surface -= 2
                    }
                    if (j > 0 && grid[i][j-1] != 0) {
                        surface -= 2
                    }
                }
            }
        }
        return surface
    }
}

protocol sol {
    func surfaceArea(_ grid: [[Int]]) -> Int
}
extension Solution1: sol{}
extension Solution2: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.surfaceArea([[1,2,3,4],[1,5,2,3],[1,0,3,4]])
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

let test1 = Solution1()
let test2 = Solution2()

time_consuming(test1,"Solution1",1000000)
time_consuming(test2,"Solution2",1000000)
