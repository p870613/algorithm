class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> sta;
    int maxfreq = 0;

    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val] ++;
        maxfreq = max(maxfreq, freq[val]);
        sta[freq[val]].push_back(val);
        
    }
    
    int pop() {
        int x = sta[maxfreq].back();
        freq[x] --;
        sta[maxfreq].pop_back();
        if(sta[maxfreq].size() == 0)
            maxfreq --;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
