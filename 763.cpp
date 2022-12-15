/*
#763. Partition Labels

You are given a string s. We want to partition the string into as many parts as possible so 
that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant 
string should be s.

Return a list of integers representing the size of these parts.

Example:
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
*/

class Solution {
public:
    // Time:  O(n), where n is the size of the input string
    // Space: O(1)
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> lastIndex(26, -1); // store the last occurenced index for each letter
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            lastIndex[c - 'a'] = i;
        }

        int curr_max = 0, prev = -1;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            curr_max = max(curr_max, lastIndex[c - 'a']);
            if (curr_max == i) {
                res.push_back(curr_max - prev);
                prev = curr_max;
            }
        }

        return res;
    }
};