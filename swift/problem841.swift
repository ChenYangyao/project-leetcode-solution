//recursive
class Solution1 {
    private var rooms = [[Int]]()
    private var visited = Set<Int>()
    
    func canVisitAllRooms(_ rooms: [[Int]]) -> Bool {
        self.rooms = rooms; self.visited = Set([0])
        visit(0)
        return visited.count == rooms.count
    }
    
    func visit(_ idx: Int) {
        for key in rooms[idx] where !visited.contains(key){
            visited.insert(key)
            visit(key)
        }
    }
}

//iterative
class Solution2 {   
    func canVisitAllRooms(_ rooms: [[Int]]) -> Bool {
        var visited = Set([0])
        var toVisit = [0]
        
        while !toVisit.isEmpty {
            let idx = toVisit.removeLast()
            for key in rooms[idx] where !visited.contains(key) {
                visited.insert(key)
                toVisit.append(key)
            }
        }
        
        return visited.count == rooms.count
    }
}
