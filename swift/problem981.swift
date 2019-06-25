class TimeMap {
    private var dict: [String:([Int],[String])]
    
    init() {
        self.dict = [String:([Int],[String])]()
    }
    
    func set(_ key: String, _ value: String, _ timestamp: Int) {
        if (dict[key] == nil) {
            dict[key] = ([timestamp], [value])
        } else {
            dict[key]!.0.append(timestamp)
            dict[key]!.1.append(value)
        }
    }
    
    func get(_ key: String, _ timestamp: Int) -> String {
        guard let entry = dict[key] else { return "" }
        
        if entry.0[0] > timestamp {
            return ""
        }
        
        var head = 0
        var tail = entry.0.count - 1
        
        while (head <= tail) {
            let mid = (head+tail)/2
            if (entry.0[mid] == timestamp) {
                return entry.1[mid]
            } else if (entry.0[mid] < timestamp) {
                head = mid + 1
            } else {
                tail = mid - 1
            }
        }
        
        return entry.1[tail]
    }
}
