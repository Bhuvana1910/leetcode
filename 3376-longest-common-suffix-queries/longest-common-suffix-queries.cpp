class Solution {
public:

    struct trie {
        int idx;
        int len;
        trie* children[26];

        trie() {
            idx = -1;
            len = INT_MAX;

            for(int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };

    trie* getnode() {
        return new trie();
    }

    void update(trie* node, int index, int length) {

        if(length < node->len ||
          (length == node->len && index < node->idx)) {

            node->len = length;
            node->idx = index;
        }
    }
    void freeTrie(trie* root) {

        if(root == NULL)
            return;

        for(int i = 0; i < 26; i++) {
            freeTrie(root->children[i]);
        }

        delete root;
    }

    void insert(trie* root, string &s, int index) {

        trie* cur = root;

        int n = s.size();

        update(cur, index, n);

        for(int j = n - 1; j >= 0; j--) {

            int c = s[j] - 'a';

            if(cur->children[c] == NULL)
                cur->children[c] = getnode();

            cur = cur->children[c];

            update(cur, index, n);
        }
    }

    int search(trie* root, string &s) {

        trie* cur = root;

        int ans = root->idx;

        for(int j = s.size() - 1; j >= 0; j--) {

            int c = s[j] - 'a';

            if(cur->children[c] == NULL)
                break;

            cur = cur->children[c];

            ans = cur->idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie* root = getnode();

        for(int i = 0; i < wordsContainer.size(); i++) {
            insert(root, wordsContainer[i], i);
        }

        vector<int> ans;

        for(int i = 0; i < wordsQuery.size(); i++) {
            ans.push_back(search(root, wordsQuery[i]));
        }
        freeTrie(root);
        return ans;
    }
};