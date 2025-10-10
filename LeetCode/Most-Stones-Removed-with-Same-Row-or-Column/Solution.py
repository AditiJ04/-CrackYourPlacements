class Disjoint:
    parent=[]
    size=[]

    def __init__(self,n):
        self.parent=[i for i in range(n)]
        self.size=[1]*n

    
    def findUParent(self,node):
        if node==self.parent[node]:
            return node

        self.parent[node]=self.findUParent(self.parent[node])
        return self.parent[node]

    def unionBySize(self,u,v):
        ulp_u=self.findUParent(u)
        ulp_v=self.findUParent(v)

        if ulp_u==ulp_v:
            return

        if self.size[ulp_u]<self.size[ulp_u]:
            self.size[ulp_v]+=self.size[ulp_u]
            self.parent[ulp_u]=ulp_v

        else:
            self.size[ulp_u]+=self.size[ulp_v]
            self.parent[ulp_v]=ulp_u


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n=len(stones)
        ds=Disjoint(n)

        cnt=0

        for i in range(0,n):
            for j in range(i+1,n):
                if stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]:
                    u=ds.findUParent(i)
                    v=ds.findUParent(j)

                    if u!=v:
                        ds.unionBySize(u,v)
                        cnt+=1
        
        return cnt