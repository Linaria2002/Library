class Warshall_Floyd{
    const long long WF_INF = 1001001001001001001ll;
    int size;
    vector<vector<long long>> dist;

    public:
    Warshall_Floyd(int N) : size(N), dist(N, vector<long long>(N, WF_INF)){
        for(int i = 0; i < N; i++) dist[i][i] = 0;
    }
    void add_edge(int u, int v, int w){
        dist[u][v] = w;
    }
    bool solve(){
        for(int k = 0; k < size; k++){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(dist[i][k] == WF_INF || dist[k][j] == WF_INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for(int i = 0; i < size; i++)
            if(dist[i][i] < 0) return false;
        return true;
    }
    int find_dist(int u, int v){
        return dist[u][v];
    }
    bool need_edge(int u, int v, int w){
        for(int i = 0; i < size; i++){
            if(i == u || i == v) continue;
            if(w >= dist[u][i] + dist[i][v]) return false;
        }
        return true;
    }
};