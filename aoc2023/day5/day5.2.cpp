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

vector<vector<int>> combine(vector<vector<int>> mat) {
    vector<vector<int>> ans;
    if(mat.size()==0) return ans;
    ans.push_back(mat[0]);
    for(int i=1;i<mat.size();i++) {
        vector<int> p=ans.back();
        if(p[1]>=(mat[i][0]-1)) p[1]=max(p[1],mat[i][1]);
        else ans.push_back(mat[i]);
    }
    return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=INT32_MAX;
    vector<vector<vector<int>>> seeds(8);
    string s;
    fstream fin("day5.txt", fstream::in);
    for(int part=0;part<8;part++) {
        getline(fin, s);
        // cout<<s<<endl;
        vector<vector<int>> mapping;
        do {
            if(part==0) {
                vector<int> seed;
                int i=7;
                while(i<s.length()) {
                    seed.push_back(read_num(s,i));
                    i++;
                }
                for(int p=0;p<seed.size();p+=2) seeds[part].push_back({seed[p],seed[p]+seed[p+1]-1});
            }
            else if(s[0]<'0' || s[0]>'9') continue;
            else {
                int i=0; int a=read_num(s,i);
                i++; int b=read_num(s,i);
                i++; int c=read_num(s,i);
                mapping.push_back({b,a,c});
            }
        }while(getline(fin, s) && s!="");
        sort(mapping.begin(),mapping.end());
        // for(auto it:mapping) cout<<"("<<it[0]<<","<<it[1]<<","<<it[2]<<") ";
        // cout<<endl;
        if(part>0) {
            int i=0;
            for(auto itx:seeds[part-1]) {
                // cout<<"("<<itx[0]<<","<<itx[1]<<")"<<endl;
                vector<int> it=itx;
                while(it[0]<=it[1]) {
                    if(i>=mapping.size()) { seeds[part].push_back({it[0],it[1]}); it[0]=it[1]+1; }
                    else {
                        int start=mapping[i][0],end=start+mapping[i][2]-1,conv=mapping[i][1]-start;
                        if(start>it[1]) { seeds[part].push_back({it[0],it[1]}); it[0]=it[1]+1; }
                        else if(end<it[0]) i++;
                        else if(start<=it[0]) {
                            if(end>=it[1]) { seeds[part].push_back({it[0]+conv,it[1]+conv}); it[0]=it[1]+1; }
                            else { seeds[part].push_back({it[0]+conv,end+conv}); it[0]=end+1; }
                        }
                        else { seeds[part].push_back({it[0],start-1}); it[0]=start; }
                    }
                    // cout<<"here"<<endl;
                }
                // cout<<"("<<seeds[part].back()[0]<<","<<seeds[part].back()[1]<<") ";
            }
            // cout<<endl;
        }
        sort(seeds[part].begin(),seeds[part].end());
        seeds[part]=combine(seeds[part]);
        // for(int i=0;i<seeds[part].size();i++) cout<<"("<<seeds[part][i][0]<<","<<seeds[part][i][1]<<") ";
        // cout<<endl;
    }
    for(int i=0;i<seeds[7].size();i++) ans = (((ans) < (seeds[7][i][0])) ? (ans) : (seeds[7][i][0]));
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
