#include <mystd.h>
using namespace std;

/**
 * solution by hash set and hash map
 * Banned words are convert to a hash set, to allow quick look-up.
 * Count of appearances is implemented by a hash map.
 *
 * Author: Yangyao, 2018/12/31
 */
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int b = 0, e = 0;
        unordered_set<string> _banned( banned.begin(), banned.end() );
        unordered_map<string, int> cnt;
        while(next(paragraph,b,e)) {
            string s( paragraph.begin() + b, paragraph.begin() + e );
            if( _banned.find( s ) == _banned.end() )
            	++cnt[ s ];
            b = e;
        }
        int max_cnt = 0;
        pair<const string, int> *res = nullptr;
        for(auto & pair: cnt){
        	if( pair.second > max_cnt ){
        		max_cnt = pair.second;
        		res = &pair;
        	}
        }
        return res->first;
    }
    /**
     * find the next word in a given paragraph
     */
    int next(string &s, int &b, int &e) {
    	while( b != s.size() && !isalpha(s[b]) ) ++b;
    	if( b == s.size() ) return 0;
    	s[b] = tolower(s[b]);
    	e = b + 1;
    	while( e != s.size() && isalpha(s[e]) ){
    		s[e] = tolower(s[e]);
    		++e;
    	}
    	return 1;
    }
};

int main(int argc, char const *argv[]){
	// case in Leetcode problem
	string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
	vector<string> banned = {"hit"};

	Solution sol;
	cout << sol.mostCommonWord( paragraph, banned ) << endl;
	return 0;
}