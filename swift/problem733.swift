class Solution {
    private var row = 0
    private var col = 0
    private var _old = 0
    private var _new = 0
    func floodFill(_ image: [[Int]], _ sr: Int, _ sc: Int, _ newColor: Int) -> [[Int]] {
        var image = image
        row = image.count - 1
        col = image[0].count - 1
        _old = image[sr][sc]
        _new = newColor
        if _old == _new {
            return image
        } else {
            fill(&image, sr, sc)
        }
        return image
    }
    
    private func fill(_ image: inout [[Int]], _ sr: Int, _ sc: Int) {
        image[sr][sc] = _new
        if (sr < row && image[sr + 1][sc] == _old) {
            fill(&image, sr + 1, sc)
        }
        if (sr > 0 && image[sr - 1][sc] == _old) {
            fill(&image, sr - 1, sc)
        }
        if (sc < col && image[sr][sc + 1] == _old) {
            fill(&image, sr, sc + 1)
        }
        if (sc > 0 && image[sr][sc - 1] == _old) {
            fill(&image, sr, sc - 1)
        }
    }
}
