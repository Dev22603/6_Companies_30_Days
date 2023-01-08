class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int>op;
        int ans=0;
        int i=0,n=tokens.size();
        int temp;
        while(i<n)
        {
            if(tokens[i]!="+" &&tokens[i]!="-" && tokens[i]!="/" &&tokens[i]!="*")
            {
                temp=stoi(tokens[i]);
                op.push(temp);
                i++;
            }
            else
            {
                int a,b;
                b=op.top();
                op.pop();
                a=op.top();
                op.pop();
                if(tokens[i]=="*")
                {
                    ans=a*b;
                }
                else if(tokens[i]=="-")
                {
                    ans=a-b;
                }
                else if(tokens[i]=="+")
                {
                    ans=a+b;
                }
                else if(tokens[i]=="/")
                {
                    ans=(int)(a/b);
                }
                i++;
                op.push(ans);
            }
        }
        return op.top();
    }
};
