#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007

void dkj() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int move(map<pair<int,int>,char>& ground,int i,int j,queue<char> cur) {
    int num=0;
    for(int d1=-1;d1<=1;d1++) {
        for(int d2=-1;d2<=1;d2++) num+=(ground.find({i+d1,j+d2})==ground.end());
    }
    if(num==8) return -1;
    // cerr<<num;
    while(!cur.empty()) {
        char x=cur.front(); cur.pop();
        // cerr<<x<<" ";
        if(x=='N' && ground.find({i-1,j-1})==ground.end()
        && ground.find({i-1,j})==ground.end() && ground.find({i-1,j+1})==ground.end()) return 3;
        else if(x=='E' && ground.find({i-1,j+1})==ground.end()
        && ground.find({i,j+1})==ground.end() && ground.find({i+1,j+1})==ground.end()) return 0;
        else if(x=='W' && ground.find({i-1,j-1})==ground.end()
        && ground.find({i,j-1})==ground.end() && ground.find({i+1,j-1})==ground.end()) return 2;
        else if(x=='S' && ground.find({i+1,j-1})==ground.end()
        && ground.find({i+1,j})==ground.end() && ground.find({i+1,j+1})==ground.end()) return 1;
    }
    return -1;
}

int iteration(map<pair<int,int>,char>& ground,queue<char>& cur_queue) {
    map<pair<int,int>,int> mp,ctr;
    for(auto it:ground) {
        int i=it.first.first,j=it.first.second;
        // cerr<<ground.size()<<"\n";
        int dir=move(ground,i,j,cur_queue);
        // cerr<<ground.size()<<"\n";
        mp[{i,j}]=dir;
        if(dir==-1) ctr[{i,j}]++;
        else if(dir==0) ctr[{i,j+1}]++;
        else if(dir==1) ctr[{i+1,j}]++;
        else if(dir==2) ctr[{i,j-1}]++;
        else if(dir==3) ctr[{i-1,j}]++;
    }
    int counter=0;
    vector<pair<int,int>> adds,subs;
    for(auto it:ground) {
        int i=it.first.first,j=it.first.second;
        if(mp[{i,j}]==-1) continue;
        int x=i,y=j;
        if(mp[{i,j}]==0) y++; else if(mp[{i,j}]==1) x++;
        else if(mp[{i,j}]==2) y--; else if(mp[{i,j}]==3) x--;
        if(ctr[{x,y}]>1 || ground.find({x,y})!=ground.end()) continue;
        // cerr<<"here"<<i<<" "<<j<<"\n";
        adds.push_back({x,y}); subs.push_back(it.first);
        counter++;
    }
    for(int i=0;i<adds.size();i++) {
        ground.erase(subs[i]);
        ground[adds[i]]='#';
    }
    cur_queue.push(cur_queue.front());
    cur_queue.pop();
    return counter;
}

int32_t main() {
    dkj();

    // Code for the programming exercise //
    string s; int ctr=0;
    fstream fin("day23.txt", fstream::in);
    map<pair<int,int>,char> ground;
    // cerr<<"here"<<"\n";
    while(getline(fin, s)) {
        // cerr<<s<<"\n";
        for(int i=0;i<s.length();i++) {
            if(s[i]=='#') ground[{ctr,i}]='#';
        }
        ctr++;
    }
    queue<char> cur_queue;
    cur_queue.push('N'); cur_queue.push('S');
    cur_queue.push('W'); cur_queue.push('E');
    int ans=-1,cmr=0;
    while(1) {
        int counter=iteration(ground,cur_queue); cmr++;
        // if(cmr%50==0) cerr<<"In the "<<cmr<<"th iteration the changes are in "<<counter<<" number of # positions"<<"\n";
        // return 0;
        if(counter==0) { ans=cmr; break; }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
