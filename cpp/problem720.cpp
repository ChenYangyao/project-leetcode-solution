#include "mystd.h"
using namespace std;

/**
 * The hash-search algorithm
 * 
 * Solution by hash each sub-string of a given string, to test whether it is in the input
 * list.
 *
 * Time and space: O(N * nS), where N is number of string to be searched, nS is the
 * maximal length of strings.
 */
class Solution {
public:
    string longestWord(vector<string>& words) {
    	unordered_set<string> set_words(words.begin(), words.end());
    	size_t len = 0;
    	string res;
    	for(const auto &word: words){
    		if( word.size() < len ) continue;
    		size_t n = word.size(), i = 1;
    		for (; i < n; ++i)
    			if( set_words.find( word.substr( 0, i ) ) == set_words.end() ) break;
    		if( i == n && (n > len || word < res) ){
    			len = n; res = word;
    		}
    	}
    	return res;
    }
};


/**
 * The Trie algorithm
 * 
 * In principle it is not as nice as the solution based on hash map, especially for 
 * the case where the string can be very long. However for this problem, the length of
 * string in question is no more than 30. For this case the Trie algorithm can be 
 * comparable to the hash-solution.
 *
 * Time and space: O(N * nS), where N is number of string to be searched, nS is the
 * maximal length of strings.
 *
 * References: Leetcode user solution.
 */
class TrieNode{
public:
    struct pair{
        TrieNode *p = nullptr;
        string *s = nullptr;
    };
    unordered_map< char,  pair> map;
};

class Trie{
public:
    TrieNode *root;

    Trie(): root( new TrieNode ){  }
    /**
     * do not forget to release the memory of Trie Tree
     */
    ~Trie(){ delTree(root); }
    void insert(string &s){
        auto it = s.begin();
        auto * pair = & root->map[ *it++ ];
        while(it != s.end()) {
            if( ! pair->p ) pair->p = new TrieNode;
            pair = & pair->p->map[ *it++ ];
        }
        pair->s = &s;
    }
    string findLongest(){
        string* res = nullptr; size_t len = 0;
        findLongest( root, res, len );
        return *res;
    }
    void findLongest( TrieNode *p, string * &s, size_t &len){
        if( !p ) return;
        for(auto & i: p->map){
            string *temp = i.second.s;
            if( temp ){
                if( temp->size() > len || (temp->size() == len && *temp < *s ) ){
                    len = temp->size(); s = temp;
                }
                findLongest( i.second.p, s, len );
            }
        }
    }
    void delTree(TrieNode *p){
        if( p ){
            for(auto & i: p->map) delTree( i.second.p );
            delete p;
        }
    }
};

class Solution2 {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto & word: words) trie.insert(word);
        return trie.findLongest();
    }
};

int main(int argc, char const *argv[])
{
	vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"},
        words2 = {"w","wo","wor","worl", "world"};
	Solution sol;
	cout << sol.longestWord( words ) << endl;
    cout << sol.longestWord( words2 ) << endl;

    Solution2 sol2;
    cout << sol2.longestWord( words ) << endl;
    cout << sol2.longestWord( words2 ) << endl;

	return 0;
}