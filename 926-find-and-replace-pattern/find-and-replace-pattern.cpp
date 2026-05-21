class Solution {
public:

    bool match(string word , string pattern){
        unordered_map<char , char> mp1 ;
        unordered_map<char , char> mp2 ;

        for(int i = 0 ; i< word.size() ; i++){
            char wordChar = word[i];
            char patternChar = pattern[i];
            
            if(mp1.count(wordChar)){
                if(mp1[wordChar] != patternChar){
                    return false ;
                }
            }else{
                mp1[wordChar] = patternChar ;
            }

            if(mp2.count(patternChar)){
                if(mp2[patternChar] != wordChar){
                    return false ;
                }
            }else{
                mp2[patternChar] = wordChar ;
            }
        }

        return true ;

    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans ;
        
        for(string word : words){
            if(match(word , pattern)){
                ans.push_back(word);
            }
        }
        return ans ;
    }
};