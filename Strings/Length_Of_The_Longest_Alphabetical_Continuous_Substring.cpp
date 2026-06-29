// LEETCODE - 2414

// TC : O(2n) = O(n)
// AS : O(n)
class Solution {
public:
    int longestContinuousSubstring(string str) {
        int n = str.length();

        int s = 0, e = 0, longSubLen = 0;
        deque<char> dq;

        while (e < n) {
            if (!dq.empty() && dq.back() + 1 != str[e]) {
                while (!dq.empty()) {
                    dq.pop_front();
                    s++;
                }
            }
            dq.push_back(str[e]);
            longSubLen = max(longSubLen, e - s + 1);
            e++;
        }

        return longSubLen;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
class Solution {
public:
    int longestContinuousSubstring(string str) {
        int n = str.length();

        int s = 0, e = 0, longSubLen = 0;

        while (e < n) {
            if (e != 0 && str[e-1]+1 != str[e]) s = e;
            longSubLen = max(longSubLen, e - s + 1);
            e++;
        }

        return longSubLen;
    }
};