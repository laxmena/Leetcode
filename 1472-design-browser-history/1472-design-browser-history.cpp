class BrowserHistory {
    public:
      vector<string> v;
      int id; 

      BrowserHistory(string homepage) {
        id = 0;
        v.push_back(homepage);
      }

      void visit(string url) {
        v.resize(++id);
        v.push_back(url);
      }

      string back(int steps) {
        return v[id = max(0, id - steps)];
      }

      string forward(int steps) {
          id = min( int(v.size() - 1), id + steps);
          return v[id];
      }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */