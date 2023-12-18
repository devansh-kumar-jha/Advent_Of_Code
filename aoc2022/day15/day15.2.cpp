#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i)
{
    if(i>=s.length()) return 0;
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

void joiner(vector<vector<pair<int,int>>>& cave,int i,pair<int,int> next)
{
    int flag=0;
    vector<pair<int,int>> ans;
    for(int j=0;j<cave[i].size();j++) {
        if(flag==1 || cave[i][j].second+1<next.first) ans.push_back(cave[i][j]);
        else if(cave[i][j].first>next.second+1) { ans.push_back(next); j--; flag=1; }
        else if(cave[i][j].second>=next.second) {
            if(cave[i][j].first<=next.first) { ans.push_back(cave[i][j]); flag=1; }
            else next.second=cave[i][j].second;
        }
        else {
            if(cave[i][j].first>=next.first) continue;
            else next.first=cave[i][j].first;
        }
    }
    if(flag==0) ans.push_back(next);
    cave[i]=ans;
    return;
}

void simulate(vector<vector<pair<int,int>>>& cave,pair<int,int> s,pair<int,int> b,int counter)
{
    int man=abs(s.first-b.first)+abs(s.second-b.second);
    for(int i=(__max(0,s.first-man));i<=(__min(counter,s.first+man));i++) {
        int x=abs(s.first-i);
        pair<int,int> next={s.second-(man-x),s.second+(man-x)};
        next.first = __max(0,next.first);
        next.second = __min(counter,next.second);
        // if(i==14) cerr<<"["<<next.first<<","<<next.second<<"]"<<" ";
        joiner(cave,i,next);
        // if(i==11) { for(auto x:cave[i]) cerr<<"["<<x.first<<","<<x.second<<"]"<<" "; cerr<<"\n"; }
    }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day15.txt", fstream::in);
    // int counter=20;
    int counter=4000000;
    vector<vector<pair<int,int>>> cave(counter+1);
    while(getline(fin, s)) {
        vector<pair<int,int>> vec(2); int i=12;
        vec[0].second=read_num(s,i); i+=4;
        vec[0].first=read_num(s,i); i+=25;
        vec[1].second=read_num(s,i); i+=4;
        vec[1].first=read_num(s,i);
        simulate(cave,vec[0],vec[1],counter);
    }
    // cerr<<"\n";
    // for(int i=0;i<=counter;i++) {
    //     // if(i!=11) continue;
    //     for(auto x:cave[i]) cerr<<"["<<x.first<<","<<x.second<<"]"<<" ";
    //     cerr<<"\n";
    // }
    int ans=0;
    for(int i=0;i<=counter;i++) {
        if(cave[i].size()==1) continue;
        else { ans=i+4000000*(cave[i][0].second+1); break; }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
