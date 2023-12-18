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

void change(pair<int,int>& y,pair<int,int>& x)
{
    int num=abs(x.first-y.first)+abs(x.second-y.second);
    if(num<2) return;
    else if(num==2) {
        if(x.first!=y.first && x.second!=y.second) return;
        else {
            y.first=(x.first+y.first)/2;
            y.second=(x.second+y.second)/2;
        }
    }
    else if(num==3) {
        if(abs(x.first-y.first)==1) {
            y.first=x.first;
            y.second=(x.second+y.second)/2;
        }
        else {
            y.first=(x.first+y.first)/2;
            y.second=x.second;
        }
    }
    else {
        y.first=(x.first+y.first)/2;
        y.second=(x.second+y.second)/2;
    }
    return;
}

void mega_change(vector<pair<int,int>>& t,pair<int,int>& h)
{
    pair<int,int> x=h;
    for(int i=0;i<9;i++) { change(t[i],x); x=t[i]; }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day9.txt", fstream::in);
    map<pair<int,int>,bool> mat;
    pair<int,int> h={0,0};
    vector<pair<int,int>> t(9,{0,0});
    mat[t[8]]=true;
    while(getline(fin, s)) {
        char d=s[0]; int i=2,num=0;
        while(i<s.length()) { num=num*10+(s[i]-'0'); i++; }
        while(num--) {
            if(d=='R') h.first++;
            else if(d=='L') h.first--;
            else if(d=='U') h.second++;
            else h.second--;
            mega_change(t,h); mat[t[8]]=true;
        }
    }
    cout<<mat.size()<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
