import Dispatch

//recursive DFS
class Solution1 {
    private var row = 0
    private var col = 0
    
    private func area(_ r: Int, _ c: Int, _ grid: inout [[Int]]) -> Int{
        if (r<0 || r>row || c<0 || c>col || grid[r][c] == 0) {
            return 0
        }
        grid[r][c] = 0
        return (1+area(r+1,c,&grid)+area(r,c+1,&grid)+area(r,c-1,&grid)+area(r-1,c,&grid))
    }
    
    func maxAreaOfIsland(_ grid: [[Int]]) -> Int {
        var grid = grid
        row = grid.count-1
        col = grid[0].count-1
        var output = 0
        
        for r in 0...row {
            for c in 0...col {
                if (grid[r][c] == 1) {
                    output = max(output,area(r,c,&grid))
                }
            }
        }
        
        return output
    }
}

//implement of UFS (ref to cpp version) without using pointer
class Solution2 {
    private var row = 0
    private var col = 0
    private var _grid = [[Int]]()
    
    func maxAreaOfIsland(_ grid: [[Int]]) -> Int {
        _grid = grid
        row = _grid.count
        col = _grid[0].count
        var temp_x = 0
        var temp_y = 0
        
        for r in 0..<row {
            for c in 0..<col {
                if (_grid[r][c] == 0) {
                    continue
                }
                let up = (r != 0) ? findroot(r-1,c) : 0
                let left = (c != 0) ? findroot(r,c-1) : 0
                if (up != 0) {
                    _grid[r][c] = up
                    index2coord(up,&temp_x,&temp_y)
                    _grid[temp_x][temp_y] += 1
                    if (left != 0 && left != up) {
                        merge(left,up)
                    }
                } else if (left != 0) {
                    _grid[r][c] = left
                    index2coord(left,&temp_x,&temp_y)
                    _grid[temp_x][temp_y] += 1
                }
            }
        }
        
        var max_area = 0
        for r in 0..<row {
            for c in 0..<col {
                max_area = max(max_area,_grid[r][c])
            }
        }
        return max_area
    }
    
    private func index2coord(_ index: Int, _ x: inout Int, _ y: inout Int) {
        x = -(index+1)/col
        y = -(index+1)%col
    }
    
    private func coord2index(_ x: Int, _ y: Int) -> Int {
        return -(x*col + y + 1)
    }
    
    private func findroot(_ x: Int, _ y: Int) -> Int {
        var x = x
        var y = y
        if (_grid[x][y] == 0) {
            return 0
        }
        
        var x0 = x
        var y0 = y
        
        while (_grid[x][y] < 0) {
            index2coord(_grid[x][y],&x,&y)
        }
        
        let root = coord2index(x,y)
        
        while (_grid[x0][y0] < 0) {
            _grid[x0][y0] = root
            index2coord(_grid[x0][y0],&x0,&y0)
        }
        return root
    }
    
    private func merge(_ root1: Int, _ root2: Int) {
        var temp_x1 = 0
        var temp_y1 = 0
        var temp_x2 = 0
        var temp_y2 = 0
        index2coord(root1, &temp_x1, &temp_y1)
        index2coord(root2, &temp_x2, &temp_y2)
        
        if (_grid[temp_x1][temp_y1] > _grid[temp_x2][temp_y2]) {
            _grid[temp_x1][temp_y1] += _grid[temp_x2][temp_y2]
            _grid[temp_x2][temp_y2] = root1
        } else {
            _grid[temp_x2][temp_y2] += _grid[temp_x1][temp_y1]
            _grid[temp_x1][temp_y1] = root2
        }
    }
}

//DFS using pointer. Try to avoid using pointer in swift!
class Solution3 {
    private var row = 0
    private var col = 0
    private var _grid = [[Int]]()
    
    func maxAreaOfIsland(_ grid: [[Int]]) -> Int {
        _grid = grid
        row = _grid.count
        col = _grid[0].count
        
        for r in 0..<row {
            for c in 0..<col {
                if (_grid[r][c] == 0) {
                    continue
                }
                let up = (r != 0) ? findroot(r-1,c) : 0
                let left = (c != 0) ? findroot(r,c-1) : 0
                if (up != 0) {
                    _grid[r][c] = up
                    getvalue(up).pointee += 1
                    if (left != 0 && left != up) {
                        merge(left,up)
                    }
                } else if (left != 0) {
                    _grid[r][c] = left
                    getvalue(left).pointee += 1
                }
            }
        }
        
        var max_area = 0
        for r in 0..<row {
            for c in 0..<col {
                max_area = max(max_area,_grid[r][c])
            }
        }
        return max_area
    }
    
    private func index2coord(_ index: Int, _ x: inout Int, _ y: inout Int) {
        x = -(index+1)/col
        y = -(index+1)%col
    }
    
    private func coord2index(_ x: Int, _ y: Int) -> Int {
        return -(x*col + y + 1)
    }
    
    private func getvalue(_ index: Int) -> UnsafeMutablePointer<Int> {
        var x = 0
        var y = 0
        index2coord(index, &x, &y)
        return UnsafeMutablePointer(&_grid[x][y])
    }
    
    private func findroot(_ x: Int, _ y: Int) -> Int {
        var x = x
        var y = y
        var temp = _grid[x][y]
        if (temp == 0) {
            return 0
        }
        
        var x0 = x
        var y0 = y
        
        while (temp < 0) {
            index2coord(temp, &x, &y)
            temp = _grid[x][y]
        }
        
        let root = coord2index(x,y)
        
        temp = _grid[x0][y0]
        while (temp < 0) {
            _grid[x0][y0] = root
            index2coord(temp, &x0, &y0)
            temp = _grid[x0][y0]
        }
        return root
    }
    
    private func merge(_ root1: Int, _ root2: Int) {
        let v1 = getvalue(root1)
        let v2 = getvalue(root2)
        
        if(v1.pointee > v2.pointee) {
            v1.pointee += v2.pointee
            v2.pointee = root1
        } else {
            v2.pointee += v1.pointee
            v1.pointee = root2
        }
    }
}

protocol sol {
    func maxAreaOfIsland(_ grid: [[Int]]) -> Int
}
extension Solution1: sol{}
extension Solution2: sol{}
extension Solution3: sol{}

func random_grid(_ row: Int, _ col: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: col), count: row)
    for r in 0..<row {
        for c in 0..<col {
            grid[r][c] = Int.random(in: 0...1)
        }
    }
    return grid
}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int, _ grid: [[Int]]) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.maxAreaOfIsland(grid)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

let small_grid = random_grid(10,10)
let large_grid = random_grid(10000,10000)

print("small grid 10*10")
time_consuming(Solution1(),"DFS - recursively",1000000,small_grid)
time_consuming(Solution2(),"UFS - w/o pointer",1000000,small_grid)
time_consuming(Solution3(),"UFS - w/ pointer",1000000,small_grid)

print("large grid 10 000*10 000")
time_consuming(Solution1(),"DFS - recursively",5,large_grid)
time_consuming(Solution2(),"UFS - w/o pointer",5,large_grid)
time_consuming(Solution3(),"UFS - w/ pointer",5,large_grid)
