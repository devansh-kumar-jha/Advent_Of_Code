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

void recurse(string& pat,int& ans,vector<int>& nums,int i) {
    if(i==pat.length()) {
        vector<int> pieces; int cur=0;
        for(auto it:pat) {
            if(it=='#') cur++;
            else { if(cur>0) pieces.push_back(cur); cur=0; }
        }
        if(cur>0) pieces.push_back(cur);
        // sort(pieces.begin(),pieces.end());
        if(nums == pieces) {
            ans++;
            // for(auto it:pat) cout<<it; cout<<"\n";
        }
    }
    else if(pat[i]=='?') {
        pat[i]='.';
        recurse(pat,ans,nums,i+1);
        pat[i]='#';
        recurse(pat,ans,nums,i+1);
        pat[i]='?';
    }
    else recurse(pat,ans,nums,i+1);
    return;
}

int find_tot_ways(string pat, vector<int> nums) {
    int ans=0;
    // sort(nums.begin(),nums.end());
    recurse(pat,ans,nums,0);
    return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    cout<<"Please wait this code will take a few seconds!!"<<endl;
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
