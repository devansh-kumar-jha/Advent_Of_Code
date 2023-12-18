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

int sum_check(vector<vector<int>>& adj,map<int,int>& mp,int i,int parent,vector<int>& final)
{
    int num=mp[i];
    for(auto it:adj[i]) {
        if(it==parent) continue;
        int ctr=sum_check(adj,mp,it,i,final);
        num+=ctr;
    }
    final.push_back(num);
    return num;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0,ctr=0; string s;
    fstream fin("day7.txt", fstream::in);
    vector<vector<int>> adj;
    map<int,int> mp;
    stack<int> st;
    while(getline(fin, s)) {
        if(s[0]=='$') {
            if(s[2]=='c') {
                if(s[5]=='.' && s[6]=='.') st.pop();
                else {
                    int parent=-1;
                    if(!st.empty()) parent=st.top();
                    st.push(ctr); mp[ctr]=0;
                    if(parent!=-1) adj[parent].push_back(ctr);
                    if(parent!=-1) adj.push_back({parent});
                    else adj.push_back({});
                    ctr++;
                }
            }
            else continue;
        }
        else {
            if(s[0]=='d') continue;
            else {
                int i=0,num=0;
                while(s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
                mp[st.top()]+=num;
            }
        }
    }
    vector<int> final;
    sum_check(adj,mp,0,-1,final);
    for(auto it:final) {
        cerr<<it<<"\n";
        if(it<=100000) ans+=it;
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
