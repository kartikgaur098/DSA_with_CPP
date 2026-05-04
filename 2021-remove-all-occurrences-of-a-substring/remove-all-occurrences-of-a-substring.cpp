class Solution {
public:
    string removeOccurrences(string full, string pattern) {
        int findkaindex = full.find(pattern) ;

        while(findkaindex != -1){

            full.erase(findkaindex , pattern.length());
            findkaindex = full.find(pattern) ; 
        }

        return full ;
    }
};