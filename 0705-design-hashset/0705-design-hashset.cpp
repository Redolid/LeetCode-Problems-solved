class MyHashSet {
private:
    std::vector<bool> set;

public:
    MyHashSet() {
        set = std::vector<bool>(1000001, false);
    }
    
    void add(int key) {
        if (key >= 0 && key <= 1000000) {
            set[key] = true;
        }
    }
    
    void remove(int key) {
        if (key >= 0 && key <= 1000000) {
            set[key] = false;
        }
    }
    
    bool contains(int key) {
        if (key >= 0 && key <= 1000000) {
            return set[key];
        }
        return false;
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */