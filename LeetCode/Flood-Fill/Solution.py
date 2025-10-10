class Solution:
    n=0
    m=0
    def fillImage(self,sr:int,sc:int,ori:int,color:int,image:List[List[int]]):

        if sr<0 or sr>=Solution.n or sc<0 or sc>=Solution.m or image[sr][sc]!=ori or image[sr][sc]==color:
            return

        image[sr][sc]=color

        self.fillImage(sr,sc-1,ori,color,image)
        self.fillImage(sr,sc+1,ori,color,image)
        self.fillImage(sr-1,sc,ori,color,image)
        self.fillImage(sr+1,sc,ori,color,image)


    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        
        Solution.n=len(image)
        Solution.m=len(image[0])

        ori=image[sr][sc]

        if ori!=color:
            self.fillImage(sr,sc,ori,color,image)

        return image
        