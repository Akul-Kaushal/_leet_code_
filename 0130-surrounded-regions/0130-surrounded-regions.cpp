class Solution {
public:
    void logic(vector<vector<char>>& board, int i, int j)
    {
        if(i<0||j<0 || i>=board.size()||j>=board[0].size() || 'O'!=board[i][j]) { return; }

        board[i][j]='*';

        logic(board,i+1,j);
        logic(board,i-1,j);
        logic(board,i,j+1);
        logic(board,i,j-1);
    }

    void solve(vector<vector<char>>& board) {

        for(int i=0; i<board.size(); i++)
        {
            if('O' == board[i][0]) { logic(board, i ,0);}
            if('O' == board[i][board[0].size()-1]) { logic(board, i ,board[0].size()-1);}
        }

        for(int j=0; j<board[0].size(); j++)
        {
            if('O' == board[0][j]) { logic(board, 0 ,j);}
            if('O' == board[board.size()-1][j]) { logic(board, board.size()-1, j);}
        }

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if('O' == board[i][j]) { board[i][j] = 'X';}
                if('*' == board[i][j]) { board[i][j] = 'O';}
            }
        }
    }
};