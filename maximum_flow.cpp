
class Flow {
public:
	const static int N = 500+ 2;
	vector< int > adj[N];
	vector<int> parent;
	vector< vector<int> > cap;
	int source, sink;
	Flow(int s, int t) {
		source = s; sink = t;
		parent.assign(N, 0);
		cap.assign(N, vector<int> (N, 0));
	}
	void add_edge(int a, int b, int w) {
		cap[a][b]  += w;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int find_augmenting_path() {
		fill(parent.begin(), parent.end(), -1);
		queue< pair<int,int > > q;
		q.push({source, INT_MAX});
		while(q.size()) {
			int cur = q.front().first;
			int flow = q.front().second;
			q.pop();
			for(auto nxt: adj[cur]) {
				if(!cap[cur][nxt] || parent[nxt] != -1) continue;
				int new_flow = min(flow, cap[cur][nxt]);
				q.push({nxt, new_flow});
				parent[nxt] = cur;
				if(nxt == sink) return new_flow;
			}
		}
		return 0;
	}
	int get_max_flow() {
		int flow;
		int ans  = 0;
		while(flow = find_augmenting_path()) {
			int cur = sink;
			ans += flow;
			while(cur != source) {
				int p = parent[cur];
				cap[p][cur] -= flow;
				cap[cur][p] += flow;
				cur = p;
			}
		}
		return ans;
	}
};
