class Solution {
public:
    vector<string>res;

    int r,c;

    vector<pair<int,int>>dirs{{-1,0},{1,0},{0,1},{0,-1}};
    struct TrieNode{
        bool endOfWord;
        TrieNode* children[26];
        string word;
    };

    TrieNode* getNode()
    {
        TrieNode* tmp=new TrieNode();
        tmp->endOfWord=false;

        for(int i=0;i<26;i++)
        {
            tmp->children[i]=NULL;
        }
        tmp->word="";
        return tmp;
    }

    void Insert(TrieNode* root,string str)
    {
        TrieNode* crawl=root;

        for(char ch:str)
        {
            if(crawl->children[ch-'a']==NULL)
            {
                crawl->children[ch-'a']=getNode();
            }
            crawl=crawl->children[ch-'a'];
        }
        crawl->endOfWord=true;
        crawl->word=str;
    }

    void DFS(vector<vector<char>>&board,int i,int j,TrieNode* root)
    {
        if(i<0 || i>=r || j<0 || j>=c || board[i][j]=='$' || root->children[board[i][j]-'a']==NULL) return;


        root=root->children[board[i][j]-'a'];
        if(root->endOfWord==true)
        {
            res.push_back(root->word);
            root->endOfWord=false;
        }

        char tmp=board[i][j];
        board[i][j]='$';

        for(pair<int,int>p:dirs)
        {
            int ni=i+p.first;
            int nj=j+p.second;
            DFS(board,ni,nj,root);
        }

        board[i][j]=tmp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r=board.size();
        c=board[0].size();

        TrieNode* root=getNode();
        for(string str:words)
        {
            Insert(root,str);
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL)
                {
                    DFS(board,i,j,root);
                }
            }
        }

        return res;
    }
};