//------*------
// Create a vector containing n 
//vectors of size m, all u=initialized with 0
//vector<vector<int> > vec( n , vector<int> (m, 0));  
//------*------

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
         vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};


