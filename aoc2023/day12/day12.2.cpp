#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i)
{
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

int check(string& pat,int start,int i,int len) {
    if(start>(i-len)) return 0;
    for(int j=start;j<=i;j++) {
        if(j<(i-len) && pat[j]=='#') return 0;
        if(j>=(i-len) && j<i && pat[j]=='.') return 0;
        if(j==i && pat[j]=='#') return 0;
    }
    return 1;
}

int dp_algo(string& pat,vector<int>& nums) {
    pat.push_back('.');
    int n=nums.size(),m=pat.length();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(j==0) dp[i][j]=0;
            else if(i==0) {
                if(pat[j]!='#') dp[i][j]=dp[i][j-1]+check(pat,0,j,nums[0]);
                else dp[i][j]=0;
            }
            else {
                if(pat[j]=='#') dp[i][j]=0;
                else if(j-nums[i]>0) dp[i][j]=dp[i][j-1]+(dp[i-1][j-nums[i]-1]*check(pat,j-nums[i],j,nums[i]));
                else dp[i][j]=dp[i][j-1];
            }
        }
    }
    return dp[n-1][m-1];
}

int find_tot_ways(string pat, vector<int> nums) {
    int n=nums.size();
    pat=pat+"?"+pat+"?"+pat+"?"+pat+"?"+pat;
    for(int i=0;i<4*n;i++) nums.push_back(nums[i%n]);
    // sort(nums.begin(),nums.end());
    int ans=dp_algo(pat,nums);
    return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s;
    fstream fin("day12.txt", fstream::in);
    while(getline(fin, s)) {
        string pat; vector<int> nums;
        int i=0;
        for(;i<s.length();i++) {
            if(s[i]==' ') { i++; break; }
            else pat.push_back(s[i]);
        }
        while(i<s.length()) { nums.push_back(read_num(s,i)); i++; }
        int num=find_tot_ways(pat,nums); ans+=num;
        // cout<<num<<"\n";
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
