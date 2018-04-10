/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "*") �� true
isMatch("aa", "a*") �� true
isMatch("ab", "?*") �� true
isMatch("aab", "c*a*b") �� false
*/
#include<string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int idx_s = 0, idx_p = 0, idx_star = -1, idx_match = 0;
		while (idx_s < s.size()) {
			if (idx_p < p.size() && (s[idx_s] == p[idx_p] || p[idx_p] == '?')) {
				idx_p++;
				idx_s++;
			}
			else if (idx_p < p.size() && p[idx_p] == '*') {  // can't match or '?', record pos of *
				idx_star = idx_p;
				idx_p++;
				// record pos of mathced by *, identify with chars matched without *
				idx_match = idx_s;
			}
			else if (idx_star != -1) {  // met * before, match from last pos of *
				idx_p = idx_star + 1;  // trace back to last *
				idx_match++;  // pos of * matched inrease by 1
				idx_s = idx_match;
			}
			else
				return false;
		}
		// skip useless *
		while (idx_p < p.size() && p[idx_p] == '*') {
			idx_p++;
		}
		return idx_p == p.size();
	}
};