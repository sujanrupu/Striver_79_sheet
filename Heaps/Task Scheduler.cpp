class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);
        for(auto it : tasks)
            freq[it - 'A']++;
        sort(freq.begin(), freq.end());
        int chunks = freq[25] - 1;
        int intervals = chunks * n;
        for(int i = 24; i >= 0; i--)
            intervals -= min(chunks, freq[i]);
        if(intervals < 0)   intervals = 0;
        return intervals + tasks.size();
    }
};
