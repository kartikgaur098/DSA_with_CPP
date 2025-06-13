class Solution {
public:
    bool solve(vector<vector<char>>& B, string word,int row , int col,int i){
        if(i== word.size())
        return true;

        if(row<0|| col<0|| row>= B.size()|| col>= B[0].size()||B[row][col]!=word[i] ){
            return false;
        }
            char temp = B[row][col];
            B[row][col]= '%';
            bool found = solve(B , word , row+1,col , i+1)// right 
                      || solve(B , word , row, col+1, i+1)// down
                      || solve(B , word , row-1, col, i+1)// left
                      || solve(B , word , row ,col-1, i+1);//up
            B[row][col]= temp ;
            return found;           
        
    }


    bool exist(vector<vector<char>>& board, string word) {
        for (int i =0 ; i<=board.size();i++){
            for(int j=0 ; j<board[0].size();j++){
                if(solve( board , word , i , j ,0)){
                    return true;
                }
            }
        }
    return false ;
    }
};