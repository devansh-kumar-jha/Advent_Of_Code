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

void pusher(vector<stack<char>>& st,vector<char> q)
{
    stack<char> s;
    for(auto it:q) s.push(it);
    st.push_back(s);
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    vector<stack<char>> st;
    //         [Q] [B]         [H]        
    //     [F] [W] [D] [Q]     [S]        
    //     [D] [C] [N] [S] [G] [F]        
    //     [R] [D] [L] [C] [N] [Q]     [R]
    // [V] [W] [L] [M] [P] [S] [M]     [M]
    // [J] [B] [F] [P] [B] [B] [P] [F] [F]
    // [B] [V] [G] [J] [N] [D] [B] [L] [V]
    // [D] [P] [R] [W] [H] [R] [Z] [W] [S]
    // 1   2   3   4   5   6   7   8   9 
    pusher(st,{'D','B','J','V'});
    pusher(st,{'P','V','B','W','R','D','F'});
    pusher(st,{'R','G','F','L','D','C','W','Q'});
    pusher(st,{'W','J','P','M','L','N','D','B'});
    pusher(st,{'H','N','B','P','C','S','Q'});
    pusher(st,{'R','D','B','S','N','G'});
    pusher(st,{'Z','B','P','M','Q','F','S','H'});
    pusher(st,{'W','L','F'});
    pusher(st,{'S','V','F','M','R'});

    string s,ans;
    fstream fin("day5.txt", fstream::in);
    while(getline(fin, s)) {
        int ctr=5,num1=0,num2=0,num3=0;
        while(s[ctr]>='0' && s[ctr]<='9') { num1=num1*10+(s[ctr]-'0'); ctr++; }
        ctr+=6;
        while(s[ctr]>='0' && s[ctr]<='9') { num2=num2*10+(s[ctr]-'0'); ctr++; }
        ctr+=4;
        while(ctr<s.length()) { num3=num3*10+(s[ctr]-'0'); ctr++; }
        stack<char> stim;
        while(num1--) { stim.push(st[num2-1].top()); st[num2-1].pop(); }
        while(!stim.empty()) { st[num3-1].push(stim.top()); stim.pop(); }
    }
    for(auto it:st) { if(!it.empty()) ans.push_back(it.top()); }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
