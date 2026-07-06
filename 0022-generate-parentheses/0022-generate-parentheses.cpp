class Solution {
public:
vector<string>ans;
void solve(int open,int close,string s ,int n){
    if(s.size()==2*n){
        ans.push_back(s);
        return ;
    }
    if(open<n)
    solve(open+1,close,s+'(',n);
    if(close<open)
    solve(open,close+1,s+')',n);
}

    vector<string> generateParenthesis(int n) {
        solve(0,0,"",n);
        return ans;

        
    }
};