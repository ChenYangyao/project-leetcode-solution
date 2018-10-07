import Foundation //to use components() function which split string into string array

class Solution {
    func toGoatLatin(_ S: String) -> String {
        let vowels = Set<Character>(["a","e","i","o","u","A","E","I","O","U"])
        let words = S.components(separatedBy: " ")
        var goat_latin = String() //create output string
        var index = 1
        
        for var word in words {
            if (!vowels.contains(word.first!)) { //word begin with consonant
                let first_consonant = word.removeFirst()
                word.append(first_consonant)
            }
            word.append("ma"+String(repeating: "a", count: index)+" ") //append " " after each word
            index += 1
            goat_latin.append(word)
        }
        
        goat_latin.removeLast(1) //remove redundant " "
        return goat_latin
    }
}

print("I speak goat Latin")
print(Solution().toGoatLatin("I speak goat Latin"))
