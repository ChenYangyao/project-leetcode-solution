#include <mystd.h>
using namespace MYSTD;
using namespace std;

// Just make a unique number with each encoded URL, record it with a map.
// Retrive it when decoding.
class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        size_t v_hash; char *p = nullptr;
        do{
            v_hash = _cnt++;
            p = (char *)&v_hash;
            for(size_t i=0; i<sizeof(size_t); ++i) 
                if( p[i] == '\0' ) ++p[i];
        }while( _map.find(v_hash) != _map.end() );
        _map.emplace( v_hash, longUrl );
        p = (char *)&v_hash;
        return string( p, p+sizeof(size_t) );
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t v_hash; char *p = (char *)&v_hash;
        for(auto &c: shortUrl){
            *p++ = c;
        }
        return _map[v_hash];
    }
private:
    static unordered_map<size_t, string> _map;
    static size_t _cnt;
};
size_t Solution::_cnt = 0;
unordered_map<size_t, string> Solution::_map;


// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
int main(int argc, char const *argv[]){
    // cases for some usual URL
    string _s;
    {
        Solution sol;
        string s = sol.encode( "http://www.cplusplus.com" );
        cout << s << endl;
        cout << sol.decode(s) << endl;
        _s = s;
    }
    {
        Solution sol;
        string s = sol.encode( "https://leetcode.com/problems/design-tinyurl" );
        cout << s << endl;
        cout << sol.decode(s) << endl;
        cout << sol.decode(_s) << endl;
    }
    return 0;
}