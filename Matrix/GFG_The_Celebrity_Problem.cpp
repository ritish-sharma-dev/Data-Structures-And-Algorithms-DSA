
// 
// TC : O(n^2 + n)
// SC : O(m + n) = O(2n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int totalPersons = mat.size();
        int rows = mat.size();
        int cols = mat[0].size();
        vector <int> personsIKnow(rows, 0);
        vector <int> personsKnowMe(rows, 0);
        
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (mat[i][j] == 1){
                    personsIKnow[i] += 1;
                    personsKnowMe[j] += 1;
                }
            }
        }
        
        for (int k=0; k<rows; k++){
            if (personsIKnow[k] == 1 && personsKnowMe[k] == totalPersons){
                return k;
            }
        }
        
        return -1;
       
    }
};

// TC: O(n^2)
// SC: O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        for (int i=0; i<rows; i++){
            int count = 0;
            for (int j=0; j<cols; j++){
                if (mat[i][j] == 0 && mat[j][i] == 1){
                    count++;
                }
            }
            
            if (count == rows-1){
                return i;
            }
        }
        
        return -1;
    }
};

// TC : O(n)
// SC : O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int i = 0;
        int j = mat.size()-1;
        int totalPersons = mat.size();
        
        while (i < j){
            if (mat[j][i] == 1){
                j--;
            }else if (mat[i][j] == 1){
                i++;
            }else {
                i++;
                j--;
            }
        }
        
        for (int k=0; k<totalPersons; k++){
            if (i == k) continue;
            if (mat[i][k] != 0){
                return -1;
            }
        }
        
        for (int k=0; k<totalPersons; k++){
            if (j == k) continue;
            if (mat[k][j] != 1){
                return -1;
            }
        }
        
        return i;
    }
};