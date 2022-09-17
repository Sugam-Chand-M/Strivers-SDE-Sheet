class LFUCache {
public:
    map<int,list<pair<int,int>>> cache;
    unordered_map<int,pair<int,int>> mpp;
    unordered_map<int,list<pair<int,int>>::iterator> ump;
    int cap;
    LFUCache(int capacity) {
        cap=capacity;
    }
    void updateMap(int count, int key, int val){
        cache[count].erase(ump[key]);
        cache[count+1].push_front({key,val});
        ump[key]=cache[count+1].begin();
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            int count=mpp[key].first;
            int val=mpp[key].second;
            mpp[key]={count+1,val};
            updateMap(count,key,val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            int count=mpp[key].first;
            int val=mpp[key].second;
            mpp[key]={count+1,value};
            updateMap(count,key,value);
        }
        else{
            if(mpp.size()==cap){
                auto it2=cache.begin();
                for(it2=cache.begin();it2!=cache.end();it2++){
                    if(cache[it2->first].size()>0) break;
                }
                if(it2==cache.end()) return;
                int cnt=it2->first;
                auto it=cache[cnt].back();
                mpp.erase(it.first);
                ump.erase(it.first);
                cache[cnt].pop_back();
            }
            mpp[key]={1,value};
            cache[1].push_front({key,value});
            ump[key]=cache[1].begin();
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */