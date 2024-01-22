class Solution {
public:
    bool valid (int i,int j,char c,vector<vector<char>>& board){
        board[i][j]='#';
        for(int k=0;k<9;k++){
            if(board[i][k]==c)return 0;
            if(board[k][j]==c)return 0;
            if(board[3*(i/3)+(k/3)][3*(j/3)+(k%3)]==c)return 0;
        }
        board[i][j]=c;
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    char c=board[i][j];
                    if(!valid(i,j,c,board))return 0;
                }
            }
        }
        return 1;
    }
};