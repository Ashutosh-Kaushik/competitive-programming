"" it states that if p is prime then (a^p - a) is an integer multiple of p ""(^ is raised to power not xor)

so in case a is not divisible by p the take a common === > a(a^(p-1) - 1) is an integer multiple and a is not so === > (a^(p-1) - 1) 4

is an integer multiple of p. now take another a common  == > (a^(p-2) - (1/a)) is and integer multiple of p 
== > (a^(p-2) - (1/a))%p = 0;
== > a inverse = (a^(p-2))%p;

now coming to point of modular inverse :
if you have A%m and B%m and you want (A/B)%m so you can do that if you find x such that 
(A%m * (1/B)%m)%m ans you have (B%m) 
 
 to calculate x such that (x)%m = (1/B)%m and then multiplying by B%m n both sides we get this == > (x*B)%m = 1 which is modular inverse of B under modulo m


int gcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


int inverseUsingEuclid(int a,int m) { // inverse of a under modulo m
	int x, y;
	int g = gcd(a, m, x, y);
	if (g != 1) {
		cout << "worng input a and m should be relatively prime"
	    exit(0);
	}
	else {
	    x = (x % m + m) % m;
	    return x;
	}
}