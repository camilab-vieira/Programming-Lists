

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int tam, item, crr = 0;
    string cmd, cmd2, r[1000000];
    string str;
    int n,val;
    cin>>n;
    vector< pair<string,int> >v;
    multiset<int>ans;
    while(n--)
    {
        cin>>str;
        if(str=="insert") {cin>>cmd2;
            val = stoi(cmd2);
            ans.insert(val);r[crr].append("insert ");
            r[crr].append(cmd2);
            crr++;}
        else if(str=="removeMin")
        {
            auto it=ans.begin();
            if(it!=ans.end()){
            ans.erase(it);
            }
            else {r[crr].append("insert 0");
                crr++;
            }r[crr].append("removeMin");
            crr++;
        }
        else if(str=="getMin")
        {
            cin>>cmd2;
            val = stoi(cmd2);
            auto it=ans.begin();
            if(val==(*it)&&it!=ans.end())
            {
                r[crr].append("getMin ");
            r[crr].append(cmd2);
            crr++;
            }
            else
            {
                while(!ans.empty())
                {
                it=ans.begin();
                if(val==(*it)||(val<(*it))) break;
                r[crr].append("removeMin");
                crr++;
                ans.erase(it);
                }
                if(ans.empty())
                {
                    r[crr].append("insert ");
                r[crr].append(cmd2);
                crr++;
                ans.insert(val);
                }
                else if((val<(*it)))
                {
                    r[crr].append("insert ");
                r[crr].append(cmd2);
                crr++;
                ans.insert(val);
                }
                r[crr].append("getMin ");
            r[crr].append(cmd2);
            crr++;
            }
        }
    }
    cout<<crr<<endl;
    for(int i = 0; i < crr; i++){
        cout<<r[i]<<endl;
    }
    return 0;
}
