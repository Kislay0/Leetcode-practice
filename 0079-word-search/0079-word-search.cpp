class Solution {
private:
    bool sol(vector<vector<char>>& board, string word, vector<vector<bool>>& flag, int index, int i, int j){
        // cout<<"\nPlace 1 "<<i<<":"<<j<<" ";
        if (i<0 || j<0 || i>= board.size() || j >= board[0].size()) return false;
        // cout<<"Place 2 "<<flag[i][j];
        if (flag[i][j]) return false;
        // cout<<" "<<word[index]<<":"<<board[i][j]<<" ";
        if (word[index] != board[i][j]) return false;
        // cout<<"HERE ";
        index++;
        flag[i][j] = true;
        if (index == word.size()) return true;
        bool up = sol(board, word, flag, index, i-1, j);
        bool down = sol(board, word, flag, index, i+1, j);
        bool left = sol(board, word, flag, index, i, j-1);
        bool right = sol(board, word, flag, index, i, j+1);
        if (up || down || left|| right) return true;
        flag[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<bool>temp(board[0].size(), false);
        vector<vector<bool>> flag(board.size(), temp);
        // vector<vector<bool>> check(board[0].size(), temp);
        for (int i = 0; i< board.size(); i++){
            for (int j = 0; j<board[0].size(); j++){
                if (board[i][j] == word[0]){
                    if (word.size() == 1) return true;
                    // cout<<"\ndebug"<<endl;
                    flag[i][j] = true;
                    bool up = sol(board, word, flag, 1, i-1, j);
                    bool down = sol(board, word, flag, 1, i+1, j);
                    bool left = sol(board, word, flag, 1, i, j-1);
                    bool right = sol(board, word, flag, 1, i, j+1);
                    if(up || down || left|| right) return true;
                    flag[i][j] = false;
                }
            }
        }
        return false;
    }
};