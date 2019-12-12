// problem https://codeforces.com/contest/1036/problem/E

#define int long long int


// let us assume that two segments which lies on x axis intersect or not.
// how do you check whether they do intersect or not, i know this might seem a bit silly by this often 
// irritates me, i just can't handle it so i have decided to properly write it down so that i never
// need to waste my time on this.

// (a,b) is the fist segment on x axis and a and b are it's x coordinates
// similarly (c,d)

bool inter1(int a,int b,int c,int d) {
        if(a > b) {
                swap(a,b);
        }
        if(c > d) {
                swap(c,d);
        }
        return max(a,c) <= min(b,d); // this means if they intersect both of left corrdinate will be on one side
        // and right ones are on other.
        //  a-----------------b
        //         c--------------------d
        // now we can say a < b and c < d (always) without losing generality.
        // then if they intersect then max of a,c should be less then min(b,d);
        // imagine that segment c-d moves left right and observe that as soon as it crosses a-b
        // above condition fails, i have wasted around 45 min on this shit so i have written it here.
        // hope it helps :).

        // other way to think is if seg a-b is on left of seg c-d then b < c and
        // if seg a-b is on the right of seg c-d then d < a so combining these two we got it. 
}

// generalising it for any collinear line segment == >

// if two lines segments are collinear then how do you check whether they intersect or not

// simple if projection on x axis intersect AND projection on y-axis intersect or.
// you should check both otherwise collinear segments parallel to axis intersect for one but actually they don't

int sign(int x) { // signum function.
        if(x > 0) {
                return 1;
        }
        if(x  < 0) {
                return -1;
        }
        return 0;
}

int det(int a,int b,int c,int d) {
        // determinant of 2X2 
        return a * d - b * c;
}


struct point {
        int x,y;
        point operator+= (point b) {
                x += b.x;
                y += b.y;
                return *this;
        }
        point operator-= (point b) {
                x -= b.x;
                y -= b.y;
                return *this;
        }
        point operator+ (point b) {
                point temp = *this;
                temp += b;
                return temp;
        }       
        point operator- (point b) {
                point temp = *this;
                temp -= b;
                return temp;
        }       

};

/*
x1 X2
y1 y2
*/
int dot(point a,point b) {
        return (a.x * b.x + a.y * b.y);
}
/* normal to x and y, that is in z
cross det() =   |ex ey|
                |x1 y1|
                |x2 y2|
similarly we can extend this to 3d.
just use crammer's rule.
*/
int cross(point a,point b) {
        return (a.x * b.y - a.y * b.x);
}

struct line {
        int a,b,c;
        line(point x,point y) {
                int x1 = x.x, y1 = x.y, x2 = y.x, y2 = y.y;
                a = y1 - y2;
                b = x2 - x1;
                c = x1 * (y2 - y1) - y1*(x2 - x1);
        }
};
// checking whether two point intersect or not, this can be easily done using cross product
// here we go.

bool check(point a,point b, point c, point d) {
        // collinear that is (a,b,d are in same line and a,b,c are int same line)
        if(cross(a-b,a-d) == 0 and cross(a-b,a-c) == 0) {
                return inter1(a.x,b.x,c.x,d.x) and inter1(a.y,b.y,c.y,d.y);
        }
        if(sign(cross(b-a,c-a)) != sign(cross(b-a,d-a)) and sign(cross(d-c,a-c)) != sign(cross(d-c,b-c))) {
                return true;
        }
        return false;
}

point pointOfIntersection(struct line p, struct line q) {
        int dd = det(p.a, p.b, q.a, q.b);
        int x = -1 * (det(p.c, p.b, q.c, q.b))/ dd;
        int y = -1 * (det(p.c, p.a, q.c, q.a))/ dd;
        point temp = {x,y};
        return temp;
}

bool bet(int x,int a,int b) {
	if(a > b)
		swap(a,b);
	return ( a <= x and x <= b);
}

point red = {(int)-1e18,(int)(-1e18)};
point f(struct line p, struct line q) {
        int dd = det(p.a, p.b, q.a, q.b);
        int x = -1 * (det(p.c, p.b, q.c, q.b));
        int y = -1 * (det(p.a, p.c, q.a, q.c));
        if(dd == 0) {
        	return red;
        }
        if(x % dd != 0 or y % dd != 0)
        	return red;
        x /= dd;
        y /= dd;
        return {x,y};
}

void solve() {
        int ans = 0;
        int n;
        cin >> n;
        std::vector<pair <point, point > > v;
        for(int i = 0; i < n; ++i) { 
                int a, b, c, d;
                cin >> a >> b >>c >> d;
                v.pb({{a,b},{c,d}});
                ans += (__gcd(abs(a-c),abs(b-d)) + 1 );
        }
        debug(ans);

        for(int i = 0; i < n; ++i) {
        	set<pair < int,int > > s;
                for(int j = i-1; j >= 0; --j) {
                	line a = line(v[i].fi,v[i].se);
                	line b = line(v[j].fi,v[j].se);
                       	if(check(v[i].fi,v[i].se,v[j].fi,v[j].se)) {
                       		point temp = f(a,b);
                       		int x = temp.x;
                       		int y = temp.y;
                       		if(temp.x != red.x or temp.y != red.y) {
                       			if(bet(x,v[i].fi.x,v[i].se.x) and bet(x,v[j].fi.x,v[j].se.x) and bet(y,v[i].fi.y,v[i].se.y) and bet(y,v[j].fi.y,v[j].se.y))
                       				s.insert({temp.x,temp.y});
                       		}
                       	}
                }
                ans -= s.size();
        }
        cout << ans << endl;
}       

int32_t main()
{
        fast;
        int t = 1;
        // cin >> t;
        for(int i = 1; i <= t; ++i)
                solve();
        cerr << "Time taken: " << ((clock() * 1000) / CLOCKS_PER_SEC) << "ms\n";
}
