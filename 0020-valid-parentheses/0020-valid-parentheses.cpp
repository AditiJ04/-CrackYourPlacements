class Solution {
public:
         int get(char c)
        {
            if(c=='(')
            {
                return 1;
            }

            else if(c==')')
            {
                return -1;
            }


             if(c=='[')
            {
                return 2;
            }

            else if(c==']')
            {
                return -2;
            }

             if(c=='{')
            {
                return 3;
            }

            else if(c=='}')
            {
                return -3;
            }

            return -1;
        }

    bool isValid(string s) {
         

         stack<int>st;
         for(int i=0;i<s.length();i++)
         {
            int c=get(s[i]);

            if(c>0)
            {
                st.push(c);
            }

            else
            {
                int b;
                if(!st.empty())
                {
                    b=st.top();
                }
                else
                {
                    return false;
                }

                if(b==abs(c))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
         }

         if(st.empty())
         {
         return true;
         }

         return false;

    }
};