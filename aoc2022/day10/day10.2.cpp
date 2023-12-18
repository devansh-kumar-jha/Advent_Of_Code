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

void draw(vector<vector<char>>& crt,int cycle,int x)
{
    if(cycle>240) return;
    else {
        int horiz=(cycle-1)%40,row=(cycle-1)/40;;
        if(horiz>=(x-1) && horiz<=(x+1)) crt[row][horiz]='#';
    }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day10.txt", fstream::in);
    int cycle=1,x=1;
    vector<vector<char>> crt(6,vector<char>(40,'.'));
    draw(crt,cycle,x);
    while(getline(fin, s)) {
        if(s[0]=='n') cycle++;
        else {
            int num=0,i=5;
            if(s[5]=='-') i++;
            while(i<s.length()) { num=num*10+(s[i]-'0'); i++; }
            if(s[5]=='-') num=-1*num;
            cycle++; draw(crt,cycle,x);
            x+=num; cycle++;
        }
        draw(crt,cycle,x);
    }
    for(auto it:crt) { for(auto p:it) cout<<p; cout<<"\n"; }
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
