class Solution {
public:
    bool logic(vector<vector<char>>& board, int i, int j, string& word, int count)
    {
        if(count == word.size()) { return true;}
        if(i<0||j<0 ||i>=board.size()||j>=board[0].size() || word[count]!=board[i][j]) { return false; }

        char temp=board[i][j];
        board[i][j] = '*';

        bool found =  logic(board,i,j+1,word,count+1) ||
        logic(board,i+1,j,word,count+1) || 
        logic(board,i,j-1,word,count+1) ||
        logic(board,i-1,j,word,count+1);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if( logic(board,i,j,word,0)) {return true;}
            }
        }
        return false;
    }
};