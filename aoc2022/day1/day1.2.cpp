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
    vector<int> ans;
    int cur=0,num=-1,cur_id=1;
    char ch;
    fstream fin("day1.txt", fstream::in);
    while (fin >> noskipws >> ch) {
        if(ch=='\n') {
            if(num!=-1) { cur+=num; num=-1; }
            else { ans.push_back(cur); cur=0; cur_id++; }
        }
        else {
            if(num==-1) num=ch-'0';
            else num=num*10+(ch-'0');
        }
    }
    sort(ans.rbegin(),ans.rend());
    cout<<ans[0]+ans[1]+ans[2]<<"\n";
    cout<<cur_id-1<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
