class Solution {
private:
    bool sol(vector<vector<char>>& board, string word,  int index, int i, int j){
        if (i<0 || j<0 || i>= board.size() || j >= board[0].size()) return false;
        if (word[index] != board[i][j]) return false;
        index++;
        char temp = board[i][j];
        board[i][j] = '0';
        if (index == word.size()) return true;
        bool up = sol(board, word, index, i-1, j);
        bool down = sol(board, word, index, i+1, j);
        bool left = sol(board, word, index, i, j-1);
        bool right = sol(board, word, index, i, j+1);
        if (up || down || left|| right) return true;
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = board.size()*board[0].size();
        if(word[0]!= word[word.size()-1]){
            int scnt = 0, ecnt = 0;
            for (int i = 0; i<board.size(); i++){
                for (int j = 0; j<board[0].size(); j++){
                    if(board[i][j] == word[0]) scnt++;
                    else if(board[i][j] == word[word.size()-1]) ecnt++;
                }
            }
            if (ecnt>scnt) reverse(word.begin(), word.end());
        }
        if (len<word.size()) return false;
        vector<bool>temp(board[0].size(), false);
        for (int i = 0; i< board.size(); i++){
            for (int j = 0; j<board[0].size(); j++){
                if (board[i][j] == word[0]){
                    if (word.size() == 1) return true;
                    char temp = board[i][j];
                    board[i][j] = '0';
                    bool up = sol(board, word, 1, i-1, j);
                    bool down = sol(board, word, 1, i+1, j);
                    bool left = sol(board, word, 1, i, j-1);
                    bool right = sol(board, word, 1, i, j+1);
                    if(up || down || left|| right) return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};