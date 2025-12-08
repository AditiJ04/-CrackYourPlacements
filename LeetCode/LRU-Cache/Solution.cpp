1class LRUCache {
2public:
3    
4    list<int>dll;
5
6    map<int,pair<list<int>::iterator,int>>mp;
7
8    int n;
9    LRUCache(int capacity) {
10        n=capacity;
11    }
12    void makeRecently(int key)
13    {
14        dll.erase(mp[key].first);
15        dll.push_front(key);
16
17        mp[key].first=dll.begin();
18    }
19    int get(int key) {
20        if(mp.find(key)==mp.end())
21        {
22            return -1;
23        }
24        makeRecently(key);
25        return mp[key].second;
26    }
27    
28    void put(int key, int value) {
29        if(mp.find(key)!=mp.end())
30        {
31            mp[key].second=value;
32            makeRecently(key);
33        }
34        else
35        {
36            dll.push_front(key);
37            mp[key]={dll.begin(),value};
38            n--;
39        }
40
41        if(n<0)
42        {
43            int k=dll.back();
44
45            dll.pop_back();
46            mp.erase(k);
47            n++;
48        }
49    }
50};
51
52/**
53 * Your LRUCache object will be instantiated and called as such:
54 * LRUCache* obj = new LRUCache(capacity);
55 * int param_1 = obj->get(key);
56 * obj->put(key,value);
57 */