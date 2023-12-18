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

int points(string hand) {
    map<char,int> mp;
    for(auto it:hand) mp[it]++;
    if(mp.size()==1) return 7;
    else if(mp.size()==5) return 1;
    else if(mp.size()==4) return 2;
    else if(mp.size()==2) {
        auto it=(*mp.begin());
        if(it.second==1 || it.second==4) return 6;
        else return 5;
    }
    else {
        vector<int> p;
        for(auto it:mp) p.push_back(it.second);
        sort(p.begin(),p.end());
        return p[2]+1;
    }
}

int num(char x) {
    switch(x) {
        case 'A': return 13;
        case 'K': return 12;
        case 'Q': return 11;
        case 'J': return 10;
        case 'T': return 9;
        case '9': return 8;
        case '8': return 7;
        case '7': return 6;
        case '6': return 5;
        case '5': return 4;
        case '4': return 3;
        case '3': return 2;
        case '2': return 1;
        default: return -1;
    }
    return -1;
}

bool compare(pair<string,int> p1,pair<string,int> p2) {
    int point1=points(p1.first),point2=points(p2.first);
    if(point1<point2) return true;
    else if(point1>point2) return false;
    else {
        for(int i=0;i<5;i++) {
            int a=num(p1.first[i]),b=num(p2.first[i]);
            if(a<b) return true;
            else if(a>b) return false;
        }
        return (p1.second < p2.second);
    }
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s; vector<pair<string,int>> mat;
    fstream fin("day7.txt", fstream::in);
    while(getline(fin, s)) {
        int j=6; int num=read_num(s,j);
        string p=s.substr(0,5);
        mat.push_back({p,num});
    }
    sort(mat.begin(),mat.end(),compare);
    for(int i=0;i<mat.size();i++) {
        // cout<<(i+1)<<" "<<mat[i].first<<" "<<mat[i].second<<"\n";
        int num=(i+1)*mat[i].second;
        ans+=num;
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
