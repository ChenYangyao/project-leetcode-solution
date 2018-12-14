#include "mystd.h"
using namespace std;

/**
 * Perhaps the best but still most efficient way is linear searching, 
 * since maximally we can only have 26 characters in letters, and linear
 * search needs no multiplication and division, saving the time.
 */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    	size_t i = 0;
    	while( i < letters.size() && letters[i] <= target) {
    	    ++i;
    	}
    	if( i == letters.size() ) return letters.front();
    	return letters[i];
    }
};

int main(int argc, char const *argv[]){
	// test example in Leetcode question
	vector<char> letters = {'c','f','j'};
	Solution sol;
	cout << sol.nextGreatestLetter(letters,'a') << endl;
	cout << sol.nextGreatestLetter(letters,'c') << endl;
	cout << sol.nextGreatestLetter(letters,'d') << endl;
	cout << sol.nextGreatestLetter(letters,'g') << endl;
	cout << sol.nextGreatestLetter(letters,'j') << endl;
	cout << sol.nextGreatestLetter(letters,'k') << endl;
	
	return 0;
}