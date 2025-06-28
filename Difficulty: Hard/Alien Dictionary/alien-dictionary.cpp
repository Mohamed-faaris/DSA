class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        return  foreignDictionary(words);
    }

    string foreignDictionary(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;

    for (string& w : words) {
        for (char c : w) {
            if (adj.find(c) == adj.end()) adj[c] = unordered_set<char>();
            if (indegree.find(c) == indegree.end()) indegree[c] = 0;
        }
    }

    for (int i = 0; i < words.size() - 1; i++) {
        string& w1 = words[i];
        string& w2 = words[i + 1];
        int minLen = min(w1.size(), w2.size());
        
        if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
            return "";
        }

        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break;
            }
        }
    }

    queue<char> q;
    for (auto it = indegree.begin(); it != indegree.end(); ++it) {
        if (it->second == 0) {
            q.push(it->first);
        }
    }

    string res;
    while (!q.empty()) {
        char ch = q.front();
        q.pop();
        res += ch;

        for (char neighbor : adj[ch]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return res.size() == indegree.size() ? res : "";
}

};
