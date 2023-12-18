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
    int num=0;
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    return num;
}

vector<int> gcd_extended(int a,int m) {
    if(a<m) {
        vector<int> p=gcd_extended(m,a);
        return {p[0],p[2],p[1]};
    }
    else if(m==0) return {a,1,0};
    else {
        vector<int> p=gcd_extended(m,a%m);
        int y1=p[1]-(a/m)*p[2],x1=p[2];
        return {p[0],x1,y1};
    }
}

vector<vector<int>> sequence(string start, map<string,vector<string>>& graph, string& pat) {
    map<pair<string,int>,int> mp;
    pair<string,int> cur_state={start,0};
    vector<vector<int>> ans; int num=0,n=pat.length();
    while(mp.find(cur_state)==mp.end()) {
        mp[cur_state]=num;
        if(cur_state.first.back()=='Z') ans.push_back({num,-1});
        if(pat[num%n]=='L') cur_state={graph[cur_state.first][0],(num+1)%n};
        else cur_state={graph[cur_state.first][1],(num+1)%n};
        num++;
    }
    for(int i=0;i<ans.size();i++) {
        if(ans[i][0]<mp[cur_state]) continue;
        else ans[i][1]=(num-mp[cur_state]);
    }
    return ans;
}

vector<vector<int>> combine(vector<vector<int>>& cur, vector<vector<int>>& next) {
    map<vector<int>,int> mp;
    for(int i=0;i<cur.size();i++) {
        for(int j=0;j<next.size();j++) {
            if(cur[i][1]==-1 && next[j][1]==-1) {
                if(cur[i][0]==next[j][0]) mp[{cur[i][0],-1}]++;
            }
            else if(cur[i][1]==-1) {
                if(cur[i][0]>=next[j][0] && (cur[i][0]-next[j][0])%next[j][1]==0) mp[{cur[i][0],-1}]++;
            }
            else if(next[j][1]==-1) {
                if(cur[i][0]<=next[j][0] && ((-1*cur[i][0])+next[j][0])%cur[i][1]==0) mp[{next[j][0],-1}]++;
            }
            else {
                int a1=cur[i][0],a2=next[j][0],d1=cur[i][1],d2=next[j][1];
                // cout<<a1<<" "<<a2<<" "<<d1<<" "<<d2<<"\n";
                int gx=(__gcd(d1,d2)),d=(d1/gx)*d2;
                if((a1%gx) != (a2%gx)) continue;
                vector<int> nums=gcd_extended(d1,d2);
                int x=((nums[1]*(d1/gx)*a2)+(nums[2]*(d2/gx)*a1));
                int n=ceil(float(max(a1,a2)-x)/float(d));
                mp[{(x+(d*n)),d}]++;
            }
        }
    }
    vector<vector<int>> ans;
    for(auto it:mp) ans.push_back(it.first);
    return ans;
}

int lcm(vector<int> nums) {
    int ans=0;
    for(auto it:nums) {
        if(ans==0) ans=it;
        else { int gx=(__gcd(ans,it)),ans=(ans*it)/gx; }
    }
    return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=-1;
    string s,ins;
    map<string,vector<string>> graph; vector<string> cur;
    vector<vector<int>> sequences;
    fstream fin("day8.txt", fstream::in);
    getline(fin, ins); getline(fin, s);
    int n=ins.length();
    while(getline(fin, s)) {
        string a=s.substr(0,3);
        string r=s.substr(12,3);
        string l=s.substr(7,3);
        graph[a]={l,r};
        if(a.back()=='A') cur.push_back(a);
    }
    // for(auto it:cur) cout<<it<<" ";
    // cout<<"\n";
    for(int i=0;i<cur.size();i++) {
        vector<vector<int>> next=sequence(cur[i],graph,ins);
        // for(auto it:next) cout<<"("<<it[0]<<","<<it[1]<<") ";
        // cout<<"\n";
        if(i>0) sequences = combine(sequences, next);
        else sequences = next;
        // for(auto it:sequences) cout<<"("<<it[0]<<","<<it[1]<<") ";
        // cout<<"\n";
    }
    for(auto it:sequences) {
        if(ans == -1) ans = it[0];
        else ans = min(ans, it[0]);
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
