

//calculate the minimum distance of each node form source
const int N = 1e5+2;
std::vector<pii>  adj[N]; // first ele is min distance from souce and second ele is the node
vi d(N,1e9);

void dijkstra(int source) {
    set<pii> s;
    s.insert({0,source});
    while(s.size()) {
        pii f = *s.begin();
        s.erase(s.begin());
        for(auto i:adj[f.se]) {
            if(d[i.se] > i.fi + d[f.se]) { // just update if it is smaller or not
                auto it = s.find(make_pair(d[i.se],i.se));
                if(it != s.end())
                    s.erase(it);
                d[i.se] = i.fi + d[f.se];;
                s.insert({d[i.se],i.se});
            }
        }
    }   
}
