#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007
#define round 10

void dkj() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i) {
    if(i>=s.length()) return 0;
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

int move(vector<string>& ground,int i,int j,queue<char> cur) {
    if(ground[i][j]=='.') return -1;
    int num=0;
    for(int d1=-1;d1<=1;d1++) {
        for(int d2=-1;d2<=1;d2++) num+=(ground[i+d1][j+d2]=='.');
    }
    if(num==8) return -1;
    // cerr<<num;
    while(!cur.empty()) {
        char x=cur.front(); cur.pop();
        // cerr<<x<<" ";
        if(x=='N' && ground[i-1][j-1]=='.' && ground[i-1][j]=='.' && ground[i-1][j+1]=='.') return 3;
        else if(x=='E' && ground[i-1][j+1]=='.' && ground[i][j+1]=='.' && ground[i+1][j+1]=='.') return 0;
        else if(x=='W' && ground[i-1][j-1]=='.' && ground[i][j-1]=='.' && ground[i+1][j-1]=='.') return 2;
        else if(x=='S' && ground[i+1][j-1]=='.' && ground[i+1][j]=='.' && ground[i+1][j+1]=='.') return 1;
    }
    return -1;
}

void iteration(vector<string>& ground,queue<char>& cur_queue) {
    map<pair<int,int>,int> mp,ctr;
    // cerr<<cur_queue.front()<<" ";
    for(int i=0;i<ground.size();i++) {
        for(int j=0;j<ground[i].length();j++) {
            int dir=move(ground,i,j,cur_queue);
            mp[{i,j}]=dir;
            // if(dir!=-1) cerr<<dir;
            if(dir==0) ctr[{i,j+1}]++;
            else if(dir==1) ctr[{i+1,j}]++;
            else if(dir==2) ctr[{i,j-1}]++;
            else if(dir==3) ctr[{i-1,j}]++;
        }
    }
    // for(int i=0;i<ground.size();i++) {
    //     for(int j=0;j<ground[i].length();j++) cout<<ctr[{i,j}]<<" ";
    //     cerr<<"\n";
    // }
    for(int i=0;i<ground.size();i++) {
        for(int j=0;j<ground[i].length();j++) {
            if(mp[{i,j}]==-1) continue;
            int x=i,y=j;
            if(mp[{i,j}]==0) y++; else if(mp[{i,j}]==1) x++;
            else if(mp[{i,j}]==2) y--; else if(mp[{i,j}]==3) x--;
            // if(x>=ground.size() || y>=ground[x].length()) cerr<<i<<" "<<j<<'\n';
            if(ctr[{x,y}]>1 || ground[x][y]=='#') continue;
            // cerr<<"("<<i<<","<<j<<")->("<<x<<","<<y<<")"<<"\n";
            ground[i][j]='.'; ground[x][y]='#';
        }
    }
    cur_queue.push(cur_queue.front());
    cur_queue.pop();
    return;
}

int32_t main() {
    dkj();

    // Code for the programming exercise //
    string s; int ctr=0,extra=round;
    fstream fin("day23.txt", fstream::in);
    vector<string> ground;
    while(getline(fin, s)) {
        if(ctr==0) {
            int num=s.length()+2*extra; string p(num,'.');
            for(int i=0;i<round;i++) ground.push_back(p);
        }
        // cerr<<s<<"\n";
        string row="";
        for(int i=0;i<extra;i++) row.push_back('.');
        for(int i=0;i<s.length();i++) row.push_back(s[i]);
        for(int i=0;i<extra;i++) row.push_back('.');
        ctr++; ground.push_back(row);
    }
    int num=ground[0].length(); string p(num,'.');
    for(int i=0;i<round;i++) ground.push_back(p);
    queue<char> cur_queue;
    cur_queue.push('N'); cur_queue.push('S');
    cur_queue.push('W'); cur_queue.push('E');
    // for(int i=0;i<ground.size();i++) cerr<<ground[i]<<"\n";
    for(int i=0;i<round;i++) {
        // cerr<<"here";
        // return 0;
        iteration(ground,cur_queue);
    }
    // for(int i=0;i<ground.size();i++) cerr<<ground[i]<<"\n";
    int min_x=inf,max_x=-1*inf,min_y=inf,max_y=-1*inf,cmr=0;
    for(int i=0;i<ground.size();i++) {
        for(int j=0;j<ground[0].length();j++) {
            if(ground[i][j]=='.') continue;
            else cmr++;
            min_x = __min(min_x,i);  max_x = __max(max_x,i);
            min_y = __min(min_y,j);  max_y = __max(max_y,j);
        }
    }
    int ans=(max_x-min_x+1)*(max_y-min_y+1)-cmr;
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
