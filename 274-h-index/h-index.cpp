class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i = 0; i < n; i++) {
            int h = n - i;
            if (citations[i] >= h) {
                ans = h;
                break;
            }
        }
        return ans;
    }
};

// Maan lo citations = [3, 0, 6, 1, 5] diya gaya hai. Sabse pehle hum is array ko sort karte hain: [0, 1, 3, 5, 6]. Ab hum left se right check karte hain. Pehle element 0 pe total bache hue papers hain 5 (n - i), lekin citation 0 hai jo 5 se kam hai, isliye move on. Fir 1 pe 4 papers bache hain, lekin citation 1 < 4, so continue. Jab 3 pe aate hain, tab bache hue papers hain 3 aur citation bhi 3 hai — yeh condition satisfy ho gayi, iska matlab hai ki kam se kam 3 papers aise hain jinke paas 3 ya usse zyada citations hain. Isliye yeh hi researcher ka H-index = 3 hoga.

