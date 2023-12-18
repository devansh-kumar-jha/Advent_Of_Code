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

int compute_north_load(vector<string>& mat) {
    int n=mat.size(),m=mat[0].length(),ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]=='O') ans+=(n-i);
        }
    }
    return ans;
}

void cycle(vector<string>& mat) {
    int n=mat.size(),m=mat[0].length();
    // Move the boulders towards north
    for(int j=0;j<m;j++) {
        int cur=0;
        for(int i=0;i<n;i++) {
            if(mat[i][j]=='#') cur=(i+1);
            else if(mat[i][j]=='.') continue;
            else { swap(mat[cur][j],mat[i][j]); cur++; }
        }
    }
    // Move the boulders towards west
    for(int i=0;i<n;i++) {
        int cur=0;
        for(int j=0;j<m;j++) {
            if(mat[i][j]=='#') cur=(j+1);
            else if(mat[i][j]=='.') continue;
            else { swap(mat[i][cur],mat[i][j]); cur++; }
        }
    }
    // Move the boulders towards south
    for(int j=0;j<m;j++) {
        int cur=n-1;
        for(int i=n-1;i>-1;i--) {
            if(mat[i][j]=='#') cur=(i-1);
            else if(mat[i][j]=='.') continue;
            else { swap(mat[cur][j],mat[i][j]); cur--; }
        }
    }
    // Move the boulders towards east
    for(int i=0;i<n;i++) {
        int cur=m-1;
        for(int j=m-1;j>-1;j--) {
            if(mat[i][j]=='#') cur=(j-1);
            else if(mat[i][j]=='.') continue;
            else { swap(mat[i][cur],mat[i][j]); cur--; }
        }
    }
    return;
}

void cycle_around(vector<string>& mat,int num_cycles) {
    int n=mat.size(),m=mat[0].length(),start=-1,end=-1;
    map<vector<string>,int> mp;
    map<int,vector<string>> inv_mp;
    map<int,int> graph;
    mp[mat]=0; inv_mp[0]=mat;
    // cout<<"Load at "<<0<<" cycles is "<<compute_north_load(mat)<<"\n";
    for(int num=1;num<=num_cycles;num++) {
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) cout<<mat[i][j];
        //     cout<<"\n";
        // }
        // cout<<"\n";
        cycle(mat);
        if(mp.find(mat)==mp.end()) {
            mp[mat]=num; inv_mp[num]=mat;
            graph[num-1]=num; graph[num]=num-1;
            // cout<<"Load at "<<num<<" cycles is "<<compute_north_load(mat)<<"\n";
        }
        else {
            // cout<<"Breakpoint and repeat for "<<mp[mat]<<" and "<<num<<"\n";
            start=mp[mat]; end=num; break;
        } 
    }
    if(start>-1 && end>-1) {
        int numx=(num_cycles-start+1)%(end-start);
        if(numx==0) mat=inv_mp[end-1];
        else mat=inv_mp[start+numx-1];
    }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0,num_cycles=1000000000;
    // cin>>num_cycles;
    string s; vector<string> mat;
    fstream fin("day14.txt", fstream::in);
    while(getline(fin, s)) mat.push_back(s);
    cycle_around(mat,num_cycles);
    cout<<compute_north_load(mat)<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
