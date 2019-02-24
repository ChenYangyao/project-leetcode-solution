//swift implementation of cpp version
class Solution {
    func robotSim(_ commands: [Int], _ obstacles: [[Int]]) -> Int {
        //using one set to store both x and y coordinates of obstacles
        let obstacles = obstacles.reduce(into: Set<Int>()){$0.insert($1[0]*100_000+$1[1])}
        
        var x = 0; var y = 0
        var dx = 0; var dy = 1
        var maxDist = 0
        
        for command in commands {
            switch command {
            case -2:
                swap(&dx,&dy); dx = -dx; break
            case -1:
                swap(&dx,&dy); dy = -dy; break
            default:
                maxDist = max(maxDist,x*x+y*y)
                for _ in 0..<command {
                    if !obstacles.contains((x+dx)*100_000+y+dy) {
                        x += dx; y += dy
                    } else {
                        break
                    }
                }
            }
        }
        
        maxDist = max(maxDist,x*x+y*y)
        return maxDist
    }
}
