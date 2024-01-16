class RandomizedSet {
    vector<int>s;
public:
    RandomizedSet() {
        s = vector<int>();
    }
    
    bool insert(int val) {
        if(find(s.begin(),s.end(),val)==s.end()){
            s.emplace_back(val);
            return true;
        }
        return false;

    }
    
    bool remove(int val) {
        auto it = find(s.begin(),s.end(),val);
        if(it!=s.end()){
            s.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return s[rand()%s.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
