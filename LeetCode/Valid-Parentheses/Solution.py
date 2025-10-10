class Solution:

    def getVal(self,c):
        if c=='(':
            return 1
        
        if c=='{':
            return 2

        if c=='[':
            return 3

        if c==')':
            return -1

        if c=='}':
            return -2

        return -3

    def isValid(self, s: str) -> bool:
        st=[]

        for i in range(0,len(s)):
            ch=self.getVal(s[i])
            if(ch>0):
                st.append(ch)
            else:
                if st and abs(ch)==st[-1]:
                    st.pop()
                else:
                    return False

        if len(st)==0:
            return True

        return False
        