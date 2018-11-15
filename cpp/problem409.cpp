/**
 * The key point is that each pair of identical characters
 * can extend the Palindrime by 2.
 * If there is one un-paired character, we may put it in the
 * center of the Palindrome, that extend the sequence by 1.
 */
class Solution {
public:
    int longestPalindrome(string s) {
        int counter[52] = {0};
        for(auto c: s){
            if( isupper(c) ) ++counter[ c-'A' ];
            else ++counter[ c - 'a' + 26 ];
        }

        bool hasodd = false;
        int npairs = 0;
        for (int i = 0; i < 52; ++i){
            npairs += counter[i] >> 1;
            if( counter[i] & 1 ) hasodd = true;
        }
        npairs *= 2;
        if( hasodd ) npairs += 1;
        return npairs;
    }
};
