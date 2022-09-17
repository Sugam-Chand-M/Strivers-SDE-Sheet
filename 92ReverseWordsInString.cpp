class Solution {
public:
    string reverseWords(string s) {
        string ans,temp;
        int i=0;
        bool flag=0;
        while(i<=s.size()-1)
        {
            if(s[i]!=' ')
            {
                temp+=s[i];
                flag=0;
            }
            else if(s[i]==' ' and flag==0)
            {
                if(ans=="")
                    ans=temp;
                else if(ans!="")
                    ans=temp+" "+ans;
                temp="",flag=1;
            }
            i++;
        }
        if(temp!="")
        {
            if(ans=="")
                ans=temp;
            else
                ans=temp+" "+ans;
        }
        return ans;
    }
};