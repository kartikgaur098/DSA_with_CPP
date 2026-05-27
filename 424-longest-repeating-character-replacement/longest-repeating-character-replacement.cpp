class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26 , 0);
        
        int left = 0 ;
        int maxFreq = 0 ;
        int ans = 0 ;

        for(int right = 0 ; right < s.size() ; right++){
            
            freq[s[right] - 'A']++ ;

            maxFreq = max(maxFreq , freq[s[right] - 'A']);
            int windowSize = right - left + 1;

            int replacementNeeded = windowSize - maxFreq;

            while(replacementNeeded > k){
                freq[s[left] - 'A']--;
                left++ ;
                windowSize = right - left + 1;
                replacementNeeded = windowSize - maxFreq ; 
            }
            ans = max(ans , windowSize);
        }
        return ans ;
    }
};