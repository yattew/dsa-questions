// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = -1;
        int c = -1;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    r = i;
                    c = j;
                    break;
                }
            }
        } 
        if(r==-1) return;
        for(int r_it = 0; r_it<matrix.size(); r_it++){
            if(matrix[r_it][c] != 0)
                matrix[r_it][c] = 2;
        }
        for(int c_it = 0; c_it<matrix[0].size(); c_it++){
            if(matrix[r][c_it] !=0)
                matrix[r][c_it] = 2;
        }
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    matrix[r][j] = 1;
                    matrix[i][c] = 1;
                }
            }
        }
        
        
        for(int r_it = 0; r_it<matrix.size(); r_it++){
            if(r_it!=r && matrix[r_it][c] == 1){
                for(int c_it = 0; c_it<matrix[0].size(); c_it++)
                    matrix[r_it][c_it] = 0;
            }
        }
        for(int c_it = 0; c_it<matrix[0].size(); c_it++){
            if(matrix[r][c_it] == 1){
                for(int r_it = 0; r_it<matrix.size(); r_it++)
                    matrix[r_it][c_it] = 0;
            }
        }
        for(int c_it = 0; c_it<matrix[0].size(); c_it++)
            matrix[r][c_it] = 0;
    }
};