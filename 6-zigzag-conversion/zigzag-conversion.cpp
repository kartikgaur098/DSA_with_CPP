class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() < numRows){
            return s ;
        }
        vector<string> rows(numRows) ;
        int currRow = 0 ;
        bool goingDown = true ;

        for(int i = 0 ; i< s.size() ; i++){
            rows[currRow] = rows[currRow] + s[i] ;

            if(currRow == 0){
                goingDown = true ;
            } 

            if(currRow == numRows - 1){
                goingDown = false ;
            }

            if(goingDown == true){
                currRow++ ;
            }else{
                currRow-- ;
            }
        }

        string ans = "" ;

        for(int i = 0 ; i< rows.size() ;i++){
            ans = ans + rows[i];
        }  

        return ans ;
    }
};