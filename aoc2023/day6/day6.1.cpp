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

int bsearch1(int time,int rec) {
    int low=0,high=(time/2),mid;
    while(low<=high) {
        mid=low+(high-low)/2;
        int num=mid*(time-mid);
        if(num<=rec) low=mid+1;
        else if(mid==low || (mid-1)*(time-mid+1)<=rec) return mid;
        else high=mid-1;
    }
    return -1;
}

int bsearch2(int time,int rec) {
    int low=ceil(float(time)/2.0),high=time,mid;
    while(low<=high) {
        mid=low+(high-low)/2;
        int num=mid*(time-mid);
        if(num<=rec) high=mid-1;
        else if(mid==high || (mid+1)*(time-mid-1)<=rec) return mid;
        else low=mid+1;
    }
    return -1;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=1;
    string s; vector<vector<int>> mat(2);
    fstream fin("day6.txt", fstream::in);
    for(int i=0;i<2;i++) {
        getline(fin, s);
        for(int j=0;j<s.length();j++) {
            if(s[j]<'0' || s[j]>'9') continue;
            else mat[i].push_back(read_num(s,j));
        }
    }
    for(int i=0;i<mat[0].size();i++) {
        int a=bsearch1(mat[0][i],mat[1][i]);
        int b=bsearch2(mat[0][i],mat[1][i]);
        // cout<<a<<" "<<b<<"\n";
        if(a==-1 || b==-1) ans=0;
        else ans=(ans*(b-a+1));
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
