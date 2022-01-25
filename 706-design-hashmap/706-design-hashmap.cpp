class MyHashMap {
public:

	vector<int> v;
	MyHashMap() {
		v.resize(1e6+1,-1);
	}
	void put(int key, int value) {
		v[key]=value;
	}

	int get(int key) {
		if(v[key]==-2) return -1;
		return v[key];
	}

	void remove(int key) {
		v[key]=-2;
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */