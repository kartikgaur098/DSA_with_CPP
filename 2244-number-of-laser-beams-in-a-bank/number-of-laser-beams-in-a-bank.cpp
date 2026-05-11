class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int PreviousRowBeams = 0 ;
        int totalBeams = 0 ;

        for(int i = 0 ; i<bank.size() ; i++){
            int currRowBeams = 0;
            for(int j = 0 ; j < bank[i].size() ; j++){
                if(bank[i][j] == '1')
                  currRowBeams++ ;
            }
            if(currRowBeams > 0){
                totalBeams = totalBeams +  currRowBeams*PreviousRowBeams;
                PreviousRowBeams = currRowBeams ;
            }

        } 
return totalBeams ;  
  }
};