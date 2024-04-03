// Time Complexity : O(3 * n * m)  
//                   ...  n is number rows
//                   ...  m is number of columns
// Space Complexity :  O(1)                      
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :

/*
Leet code : https://leetcode.com/problems/valid-sudoku/description/

following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            bool hMap[10]{false};
            for(int j = 0; j < m; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j] - '0';
                    if(hMap[val]) return false;
                    hMap[val] = true;
                }
            }
        }

        for(int i = 0; i < n; i++){
            bool hMap[10]{false};
            for(int j = 0; j < m; j++){
                if(board[j][i] != '.'){
                    int val = board[j][i] - '0';
                    if(hMap[val]) return false;
                    hMap[val] = true;
                }
            }
        }

        for(int block = 0; block < 9; block++){
            int newN = block/3*3;
            int newM = block%3*3;
            bool hMap[10]{false};
            for(int i = newN; i< newN+3; i++){
                for(int j = newM; j < newM+3; j++){
                    if(board[j][i] != '.'){
                        int val = board[j][i] - '0';
                        if(hMap[val]) return false;
                        hMap[val] = true;
                    }       
                }
            }
        }
        return true;
    }
};