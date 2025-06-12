class Solution {
public:
   void solve(vector<string>& ans, string& out, int open,int close, int n) {
        if (open + close == 2 * n) {
            ans.push_back(out);
            return;
        }
        if (open < n) {
            out.push_back('(');
            solve(ans, out, open + 1, close, n);
            out.pop_back();
        }
        if (close < open) {
            out.push_back(')');
            solve(ans, out, open, close + 1, n);
            out.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string out;
        solve(ans, out, 0, 0, n);
        return ans;
    }
};

// iski approach ye h ki isme lgega recursion
// pehle to ek vector of string initialize krni pdegi jisme poora ans store hoga
// iska name h ans iske alava ek string or chahiye jisme output store hoga
// temporary ab function bnayenge solve wala jisme 5 parameters pass krne hain
// ans out open ki value close ki value or ek n isme fr 3 condition check krenge
// 1) agr n 0 hai to return false krdo
// 2) agr open + close dono ki value mila k 2*n k brabr honi chaiye to fr ans m
// out wali string ko pushback krdo kuki vhi to return krni hai 3)ab check kro
// ki open jo h vo n se km h ya nhi agr km hoga tbh he hm ( ise puchback krenge
// out m fr solve ko call krenge or open ki value bdha denge or backtracking k
// liye pop kr denge 4)iske alava check kro ki bhyi doosra bracket tbh he close
// hoga jbh pehle open ho rkha ho iska mtlb open ki value hmesha close se jada
// hogi us case m out m ) pushback krdo or close ka count bdha do fr pop back
// out m se backtracking k liye