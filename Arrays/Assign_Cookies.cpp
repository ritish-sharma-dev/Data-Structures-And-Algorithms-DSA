// LEETCODE - 455. Assign Cookies





// TC : O(n^2)
// AS : O(n)
class Solution {
public:
    void removeGreed(unordered_map<int, int> &mp, int cookies){
        int maxGreed = 0;

        for (auto x : mp){
            if (x.first <= cookies){
                maxGreed = max(maxGreed, x.first);
            }
        }

        if (maxGreed != 0){
            mp[maxGreed]--;
            if (mp[maxGreed] == 0) mp.erase(maxGreed);
        }
    }


    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();

        unordered_map <int, int> mp;
        for (int x : g){
            mp[x]++;
        }

        for (int cookies : s){
            removeGreed(mp, cookies);
        }

        int ans = m;
        for (auto z : mp){
            ans -= z.second;
        }

        return ans;
    }
};



// TC : O(mlogm + nlogn + m + n)
// AS : O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        while (i < m && j < n){
            if (g[i] <= s[j]){
                i++;
            }
            j++;
        }

        return i;
    }
};