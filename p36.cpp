class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check line
        std::set<char> t;
        for (int i = 0; i< 9; i++) {
            for (int j = 0; j<9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (t.find(board[i][j]) != t.end()) {
                    return false;
                }
                t.insert(board[i][j]);
            }
            t.clear();
        }
        //check column
        for (int i = 0; i< 9; i++) {
            for (int j = 0; j<9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (t.find(board[j][i]) != t.end()) {
                    return false;
                }
                t.insert(board[j][i]);
            }
            t.clear();
        }
        // check block
        for (int i = 0; i< 3; i++) {
            for (int j = 0; j < 3; j++) {
                int p_x = 3*i;
                int p_y = 3*j;
                for (int ix = 0; ix<3; ix++) {
                    for (int jx = 0; jx<3; jx++) {
                        if (board[p_x+ix][p_y+jx] == '.') {
                            continue;
                        }
                        if (t.find(board[p_x+ix][p_y+jx]) != t.end()) {
                            return false;
                        }
                        t.insert(board[p_x+ix][p_y+jx]);
                    }
                }
                t.clear();
            }    
        }
        return true;
    }
};