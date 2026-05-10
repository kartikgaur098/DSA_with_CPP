class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes ;
        for(int i =0 ; i< timePoints.size() ; i++){
            string t = timePoints[i] ;
            int hours = stoi(t.substr(0 , 2)) ;
            int mins = stoi(t.substr(3,2)) ;

            int totaltime = hours*60 + mins ;
            minutes.push_back(totaltime) ;
        }

        sort(minutes.begin() , minutes.end());
        int ans = 1440  ;
        for(int i = 1 ; i < minutes.size()  ; i++){
            int temp = minutes[i] - minutes[i-1]  ;
            ans = min(ans , temp) ;
        }

        int currans = 1440 -(minutes.back() - minutes.front()) ;
        ans = min(ans , currans) ;

        return ans ;
    }
};