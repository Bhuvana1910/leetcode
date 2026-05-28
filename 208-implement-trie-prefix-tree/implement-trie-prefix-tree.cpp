class Trie {
public:
    struct trie{
        bool isend;
        trie*children[26];
    };
    trie*getnode(){
        trie*newnode=new trie();
        newnode->isend=false;
        for(int i=0;i<26;i++){
            newnode->children[i]=NULL;
        }
        return newnode;
    }
    trie*root;
    Trie() {
        root = getnode();
    }
    void insert(string word) {
      trie*f=root;
      for(int i=0;i<word.size();i++){
        int ch=word[i]-'a';
        if(f->children[ch]==NULL)
            f->children[ch]=getnode();
        f=f->children[ch];
        
      }  
      f->isend=true;
    }
    bool search(string word) {
     trie*f=root;
     for(int i=0;i<word.size();i++){
        int ch=word[i]-'a';
        if(f->children[ch]==NULL)
        return false;
        f=f->children[ch];
     }
     return f->isend==true;
    }
    
    bool startsWith(string prefix) {
      trie*f=root;
      for(int i=0;i<prefix.size();i++){
        int ch=prefix[i]-'a';
        if(f->children[ch]==NULL)
        return false;
        f=f->children[ch];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */