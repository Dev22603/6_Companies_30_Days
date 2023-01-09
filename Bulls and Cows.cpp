class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int>sec;
        map<char,int>gue;
        int bull=0,cow=0;
        int n=guess.size();
        for(int i=0; i<n;i++)
        {
            if(guess[i]==secret[i]) 
            {
                bull++;
                secret[i]='_';
            }
            else 
            {
                sec[secret[i]]++;
                gue[guess[i]]++;
            }
        }
        string ans="";
        ans+=to_string(bull);
        ans+="A";
        for(auto it:sec)
        {
            if(it.second>=1)
            {
                auto u=gue.find(it.first);
                if(u!=gue.end())
                {
                    cow+=(min((*u).second,it.second));
                }
            }
        }
        ans+=to_string(cow);
        ans+="B";
    return ans;
    }
};
