class Prim{
    const long long PRIM_INF = 1001001001001001001ll;
    int size;
    vector<vector<pair<long long, int>>> G;
    vector<long long> dist;
    vector<int> prev;

    public:
    Prim(int N) : size(N), G(N), dist(N, PRIM_INF), prev(N, -1) {}
    void add_edge(int from, int to, long long cst){
        G[from].emplace_back(make_pair(cst, to));
    }
    long long solve(int R){
        using PRIM_T = tuple<long long, int, int>;
        priority_queue<PRIM_T, vector<PRIM_T>, greater<PRIM_T>> heap;
        dist[R] = 0, prev[R] = R;
        for(auto it : G[R]){
            heap.push(make_tuple(it.first, R, it.second));
        }

        long long res = 0;
        int num = 1;
        if(size == 1) return 0;

        while(!heap.empty()){
            tuple<long long, int, int> T = heap.top();
            heap.pop();
            int u = get<1>(T);
            int v = get<2>(T);
            if(prev[v] != -1) continue;

            prev[v] = u;
            dist[v] = dist[u] + get<0>(T);
            num++;
            res += get<0>(T);

            if(num == size) return res;

            for(auto it : G[v]){
                heap.push(make_tuple(it.first, v, it.second));
            }
        }
        return -1;
    }
};