template<int char_size, int base>
class Trie{
    struct Node{
        vector<int> next;
        vector<int> accept;
        int c;
        int common;
        Node(char c_) : c(c_), common(0), next(char_size, -1) {}
    };
    int root;
    vector<Node> nodes;
    void insert(const string &word, int word_id){
        int node_id = 0;
        for(int i = 0; i < (int)word.size(); i++){
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if(next_id == -1){
                next_id = (int)nodes.size();
                nodes.emplace_back(Node(c));
            }
            nodes[node_id].common++;
            node_id = next_id;
        }
        nodes[node_id].common++;
        nodes[node_id].accept.emplace_back(word_id);
    }
    public:
    Trie() : root(0) {
        nodes.emplace_back(Node(root));
    }
    void insert(const string &word){
        insert(word, nodes[0].common);
    }
    int search(const string &word, bool prefix = false){
        int node_id = 0;
        for(int i = 0; i < (int)word.size(); i++){
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if(next_id == -1) return 0;
            node_id = next_id;
        }
        return prefix ? nodes[node_id].common : nodes[node_id].accept.size() > 0;
    }
};