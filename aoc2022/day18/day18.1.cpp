#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007
#define width 7

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

void counter(vector<int>& p1,vector<int>& p2,int& num)
{
    int flag=0;
    for(int i=0;i<3;i++) {
        if(p1[i]==p2[i]) flag++;
    }
    int ctr=abs(p1[0]-p2[0])+abs(p1[1]-p2[1])+abs(p1[2]-p2[2]);
    if(flag==2 && ctr==1) num+=2;
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day18.txt", fstream::in);
    vector<vector<int>> points;
    while(getline(fin, s)) {
        int i=0;
        int x=read_num(s,i); i++;
        int y=read_num(s,i); i++;
        int z=read_num(s,i);
        points.push_back({x,y,z});
    }
    int num=0,tot=points.size()*6;
    for(int i=0;i<points.size();i++) {
        for(int j=i+1;j<points.size();j++) {
            counter(points[i],points[j],num);
        }
    }
    cout<<(tot-num)<<"\n";
    // cout<<counter<<" "<<(size-top)<<" "<<id<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
