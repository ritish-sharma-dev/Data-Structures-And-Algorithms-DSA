// LEETCODE - 2260



// TC : O(n)
// AS : O(n)
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();

        unordered_map <int, int> mp;

        int i = 0, j = 0, minimum = INT_MAX;

        while (j < n){
            mp[cards[j]]++;

            while (mp[cards[j]] == 2){
                minimum = min(minimum, j - i + 1);
                mp[cards[i]]--;
                i++;
            }

            j++;
        }

        return minimum == INT_MAX ? -1 : minimum;
    }
};