// Referred site url: https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/26837859

// 0-indexed
// Undirected Graph
// MaximumClique(G) == |G| - MinimumVertexCover(G') == MinimumIndependentSet(G^c)
// returned set is not always dictionally ordered.
template<int V>
struct MaximumClique {
    using B = bitset<V>;
    vector<B> g, col_buf;
    MaximumClique(int N) : g(N), col_buf(N) {}

    struct pp{
        int idx, col, deg;
        pp(int idx, int col, int deg) : idx(idx), col(col), deg(deg) {}
    };

    void add_edge(int a, int b){
        g[a].set(b);
        g[b].set(a);
    }

    vector<int> now, clique;
    //g -> 隣接行列
    //col_buf -> ある色の頂点集合
    //remの初期値は (頂点番号, -1, 次数)
    
    void dfs(vector<pp> &rem){
        if(clique.size() < now.size()) clique = now;
        //次数が大きい方から見る
        sort(begin(rem), end(rem), [](const pp &a, const pp &b){
            return a.deg > b.deg;
        });
        //適当に彩色
        //(この時、使う色が少ない方が当然嬉しいので、↑のソートが効いている、多分)
        int max_c = 1;
        for(auto &p : rem){
            p.col = 0;
            while((g[p.idx] & col_buf[p.col]).any()) ++p.col;
            max_c = max(max_c, p.idx + 1);
            col_buf[p.col].set(p.idx);
        }
        for(int i = 0; i < max_c; i++) col_buf[i].reset();
        //色順にソート
        sort(begin(rem), end(rem), [&](const pp &a, const pp &b){
            return a.col < b.col;
        });
        //remが残っている限り実行
        for(; !rem.empty(); rem.pop_back()){
            //大きい色から見ていく
            auto &p = rem.back();
            //同じ色はcliqueに入らないので、この枝狩りが効く
            if(now.size() + p.col + 1 <= clique.size()) break;
            vector<pp> nrem;
            B bs;
            for(auto &q : rem){
                //辺があったら、残す
                if(g[p.idx][q.idx]){
                    nrem.emplace_back(q.idx, -1, 0);
                    bs.set(q.idx);
                }
            }
            //次数を計算
            for(auto &q : nrem){
                q.deg = (bs & g[q.idx]).count();
            }
            now.emplace_back(p.idx);
            dfs(nrem);
            now.pop_back();
        }
    }
    
    vector<int> solve(){
        vector<pp> remark;
        for(int i = 0; i < (int)g.size(); i++){
            remark.emplace_back(i, -1, (int) g[i].count());
        }
        shuffle(remark.begin(), remark.end(), mt19937(61471));
        dfs(remark);
        return clique;
    }

};