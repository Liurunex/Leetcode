struct TrieNode {
    bool isEndWord;
    char val;
    vector<TrieNode*> children;
    TrieNode(char theval) : val(theval), isEndWord(false), children(26, NULL) {}
};

class Trie {
private:    
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(' ');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); ++ i) {
            int index = int(word[i]-'a');
            if (!node->children.at(index)) {
                TrieNode* newnode = new TrieNode(word[i]);
                node->children[index] = newnode;
            }
            node = node->children[index];
        }
        node->isEndWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); ++ i) {
            int index = int(word[i]-'a');
            if (!node->children.at(index))
                return false;
            node = node->children[index];
        }
        return node && node->isEndWord;
        //return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); ++ i) {
            int index = int(prefix[i]-'a');
            if (!node->children.at(index))
                return false;
            node = node->children[index];
        }
        return true;
    }
};

/* the idea: simply to understand the tire and we are basically done;
 * each TireNode hold its values and a the child vector sotres all
 * its children, what we do here is just go check if the target char 
 * existed in its children, go check until no more char need to be matche
 * the trick: we change to vector version to accelerate intead of hash
 * table version; NOTICE when insert a word, we need to change the last 
 * character's variable isEnd to true
 */
struct TrieNode {
    bool isEndWord;
    char val;
    unordered_map<int, TrieNode*> children;
    TrieNode(char theval) : val(theval), isEndWord(false) {}
};

class Trie {
private:    
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(' ');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); ++ i) {
            if (node->children.find(int(word[i])) == node->children.end()) {
                TrieNode* newnode = new TrieNode(word[i]);
                node->children[int(word[i])] = newnode;
            }
            node = node->children[int(word[i])];
        }
        node->isEndWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); ++ i) {
             if (node->children.find(int(word[i])) == node->children.end())
                return false;
            node = node->children[int(word[i])];
        }
        return node && node->isEndWord;
        //return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); ++ i) {
            if (node->children.find(int(prefix[i])) == node->children.end())
                return false;
            node = node->children[int(prefix[i])];
        }
        return true;
    }
};
