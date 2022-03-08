#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll bigmod(ll n, ll r, ll m){
    if(r == 0) return 1;
    if(r == 1) return n%m;
    ll x;
    if(r%2==1) x = bigmod(n, r-1, m)*n;
    else{
        x = bigmod(n, r/(ll)2, m);
        x = x*x;
    }
    return x%m;
}

// is prime using lehamans algorithm
bool isPrime(ll p, int iter){
    if(p <= 1 || p%2 == 0) return false;
    if(p == 2 || p == 3) return true;

    ll a, x;
    for(int i = 0; i < iter; i++){
        a = 2 + rand()%(p-3);
        x = bigmod(a, p-1, p);
        if(x != 1 && x != -1 && x != (p-1)) return false;
    }
    return true;
}

int main(){

    ll p;
    cin>>p;

    if(isPrime(p, 100)){
        puts("Prime!");
    }
    else{
        puts("Not Prime !");
    }

    return 0;
}
