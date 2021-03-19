
// for numbers
const int BITS = 32;
class TrieBinary {
public:
        bool is_leaf = false;
        TrieBinary *children[2] = {0};
        int count = 0;

        void insert(int no, int idx = BITS) {
                count++;
                if(idx < 0) return;
                int ch = (no & (1ll << idx)) > 0;
                if(children[ch] == NULL) {
                        children[ch] = new TrieBinary();
                }
                children[ch]->insert(no, idx-1);
        }

        void del(int no, int idx = BITS) {
                count--;
                if(idx < 0) return;
                int ch = (no & (1ll << idx)) > 0;
                children[ch]->del(no, idx-1);
        }

        bool search(int no, int idx = BITS) {
                if(idx < 0) return 1;
                int ch = (no & (1ll << idx)) > 0;
                if(children[ch] == NULL || children[ch]->count == 0) {
                        return 0;
                }
                return children[ch]->search(no, idx-1);
        }

        int get_min_xor(int no, int idx = BITS) {
                if(idx < 0) return 0;
                int ch = (no & (1ll << idx)) > 0;
                if(children[ch] != NULL && children[ch]->count > 0) {
                        return children[ch]->get_min_xor(no, idx-1);
                }
                ch = ch ^ 1;
                if(children[ch] != NULL && children[ch]->count > 0) {
                        return (1ll << idx) + children[ch]->get_min_xor(no, idx-1);
                }
                return 0;
        }
};


// for strings
const int MAX_CHAR = 26;
class Trie {
public:
        bool is_leaf = false;
        Trie *children[MAX_CHAR] = {0};
        int count = 0;

        void insert(string &s, int idx = 0) {
                count++;
                if(idx > s.size()) return;
                int ch = s[idx] - 'a';
                if(children[ch] == NULL) {
                        children[ch] = new Trie();
                }
                children[ch]->insert(s, idx+1);
        }

        void del(string &s, int idx = 0) {
                count--;
                if(idx > s.size()) return;
                int ch = s[idx] - 'a';
                children[ch]->del(s, idx+1);
        }

        bool search(string &s, int idx = 0) {
                if(idx > s.size()) return true;
                int ch = s[idx] - 'a';
                if(children[ch] == NULL || children[ch]->count == 0)
                        return false;
                return children[ch]->search(s, idx+1);
        }
};