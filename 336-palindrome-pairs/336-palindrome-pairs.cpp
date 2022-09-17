class Solution {
private:
	struct TrieNode {
		TrieNode() {
			child.resize(26);
		}
		vector<TrieNode*> child;
		int wi = -1;
	};

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> ans;

		for (int i = 0; i < words.size(); ++i) {
			insert(words[i], i);
		}

		auto isPalindrome = [&](string &w, int l, int r) {
			while (l <= r) {
				if (w[l] != w[r]) {
					return false;
				}
				++l;
				--r;
			}
			return true;
		};

		for (int i = 0; i < words.size(); ++i) {
			vector<int> cands = find(words[i]);

			for (auto &j : cands) {
				if (i == j) {
					continue;
				}

				if (words[i].size() > words[j].size()) {
					if (isPalindrome(words[i], words[j].size(), words[i].size()-1)) {
						ans.push_back({i, j});
					}
				} else if (isPalindrome(words[j], 0, words[j].size()-words[i].size()-1)) {
					ans.push_back({i, j});
				}
			}
		}

		return ans;
    }

	void insert(string &w, int wi) {
		TrieNode *cur = &root;

		for (int i = w.size()-1; i >= 0; --i) {
			int j = w[i]-'a';
			if (!cur->child[j]) {
				cur->child[j] = new TrieNode();
			}
			cur = cur->child[j];
		}
		cur->wi = wi;
	}

	vector<int> find(string &w) {
		vector<int> wis; // word index set
		TrieNode *cur = &root;

		for (auto &c : w) {
			if (cur->wi >= 0) {
				wis.push_back(cur->wi);
			}
			int j = c-'a';
			if (!cur->child[j]) {
				return wis;
			}
			cur = cur->child[j];
		}

		// trace the subtree rooted in cur
		queue<TrieNode*> q;
		q.push(cur);
		while (q.size()) {
			cur = q.front();
			q.pop();

			if (cur->wi >= 0) {
				wis.push_back(cur->wi);
			}

			for (int i = 0; i < 26; ++i) {
				if (cur->child[i]) {
					q.push(cur->child[i]);
				}
			}
		}

		return wis;
	}

private:
	TrieNode root;
};