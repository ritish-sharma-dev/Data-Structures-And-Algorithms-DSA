// LEETCODE - 3986

// TC : O(1)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int n = startTime.length();
        int i = 0;
        int j = 1;
        
        int h1 = (startTime[i]- '0') * 10 + (startTime[j] - '0');
        int h2 = (endTime[i]- '0') * 10 + (endTime[j] - '0');
        i += 3;
        j += 3;
        int m1 = (startTime[i]- '0') * 10 + (startTime[j] - '0');
        int m2 = (endTime[i]- '0') * 10 + (endTime[j] - '0');
        i += 3;
        j += 3;
        int s1 = (startTime[i]- '0') * 10 + (startTime[j] - '0');
        int s2 = (endTime[i]- '0') * 10 + (endTime[j] - '0');
        
        int x1 = h1*60*60 + m1*60 + s1;
        int x2 = h2*60*60 + m2*60 + s2;

        return x2 - x1;
    }
};


// TC : O(1)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    void f(int& x, int& y, int i, int j, string &startTime, string &endTime) {
        x = (startTime[i] - '0') * 10 + (startTime[j] - '0');
        y = (endTime[i] - '0') * 10 + (endTime[j] - '0');
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        int i = 0;
        int j = 1;

        int h1, h2, m1, m2, s1, s2;
        f(h1, h2, 0, 1, startTime, endTime);
        f(m1, m2, 3, 4, startTime, endTime);
        f(s1, s2, 6, 7, startTime, endTime);

        int x1 = h1 * 60 * 60 + m1 * 60 + s1;
        int x2 = h2 * 60 * 60 + m2 * 60 + s2;

        return x2 - x1;
    }
};