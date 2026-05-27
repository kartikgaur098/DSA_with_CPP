class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans ;
        
        vector<int> freqP(26 , 0) ;
        vector<int> window(26 , 0) ;

        int n = s.size();
        int m = p.size();

        if(m > n)
        return ans ;

        for(char ch : p){
          freqP[ch - 'a']++;
        }

        int left = 0 ;
        for(int right = 0 ; right < s.size() ; right++){

            window[s[right] - 'a']++ ;
            int windowSize = right - left + 1;

            if(windowSize > m){
                window[s[left] - 'a']--;
                left++ ; 
            }

            if(window == freqP) 
            {
                ans.push_back(left);
            }
        }
        return ans ;
    }
};