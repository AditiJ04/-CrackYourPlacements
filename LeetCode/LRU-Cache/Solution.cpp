class LRUCache {
public:
    
    list<int>dll;

    map<int,pair<list<int>::iterator,int>>mp;
    int n;

    void makeRecently(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);

        mp[key].first=dll.begin();
    }
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }

        makeRecently(key);

        return mp[key].second;
    }
    //most recently element in front..
    //in brute force--mru was in front
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second=value;
            makeRecently(key);
        }
        else
        {
          dll.push_front(key);
          mp[key]={dll.begin(),value};   
          n--;
        }

        if(n<0)
        {
            int k=dll.back();
            dll.pop_back();
            mp.erase(k);

            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */