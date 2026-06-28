// LEETCODE - 2379


// BRUTE FORCE APPROACH
// TC : O(n^2)
// AS : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();

        int minRecolors = INT_MAX;
        for (int i=0; i<n; i++){
            int white = 0;
            for (int j=i; j<n; j++){
                if (blocks[j] == 'W') white++;
                if ((j - i + 1) == k) minRecolors = min(minRecolors, white);
            }
        }
        return minRecolors;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();

        int s = 0, e = k - 1, white = 0, minRecolors = INT_MAX;
        for (int i=s; i<=e; i++){
            if (blocks[i] == 'W') white++;
        }
        while (e < n){
            minRecolors = min(minRecolors, white);

            e++;
            if (e < n && blocks[e] == 'W') white++;
            if (blocks[s] == 'W') white--;
            s++;
        }
        return minRecolors;
    }
};