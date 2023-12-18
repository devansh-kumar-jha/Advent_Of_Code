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

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=-1*inf,id=-1;
    int cur=0,num=-1,cur_id=1;
    char ch;
    fstream fin("day1.txt", fstream::in);
    while (fin >> noskipws >> ch) {
        if(ch=='\n') {
            if(num!=-1) { cur+=num; num=-1; }
            else {
                if(cur>ans) { ans=cur; id=cur_id; }
                cur=0; cur_id++;
            }
        }
        else {
            if(num==-1) num=ch-'0';
            else num=num*10+(ch-'0');
        }
    }
    cout<<ans<<" "<<id<<"\n";
    cout<<cur_id-1<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
