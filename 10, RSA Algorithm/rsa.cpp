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



ll n, e; // public key

ll coprime(ll n){
    ll x;
    do{
        x = rand()%n+1;
    }while(__gcd(x,n) != 1);

    return x;
}

ll mod_inverse(ll a, ll m){
    for(ll i = 1; i < m; i++){
        if(((a*i)%m == 1)) return i;
    }
    return -1;
}

ll rsa_key_generation(ll p, ll q){
    ll phi,d;
    n = p*q;
    phi = (p-1)*(q-1);

    e = coprime(phi);
    d = mod_inverse(e, phi);

    return d;
}


string encrypt(string msg, int block_size){
    string cipher = "";
    char num[100];
    ll en,k,j;
    //cout<<msg<<endl;
    for(int i = 0; i < msg.size(); i+=block_size){
        for(j = 0; j < block_size && (i+j) < msg.size(); j++){
            //cout<<msg[i+j]<<endl;
            num[j] = msg[i+j];
        }
        num[j] = '\0';
        //cout<<num<<endl;
        en = atol(num);
        en = bigmod(en, e, n);
        ltoa(en, num, 10);
        k = 0;
        while(num[k]){
            cipher += num[k];
            k++;
        }
        cipher += " ";
    }

    return cipher;
}

string decrypt(string cipher, ll d){
    string msg = "";
    char num[100];

    ll en,k;

    for(int i = 0; i < cipher.size();i++){
        k = 0;
        while(cipher[i] != ' ' && i < cipher.size()){
            num[k++] = cipher[i];
            i++;
        }
        num[k] = '\0';

        en = atol(num);
        en = bigmod(en, d, n);
        ltoa(en, num, 10);
        k = 0;
        //cout<<num<<endl;
        while(num[k]){
            msg += num[k];
            k++;
        }
    }

    return msg;
}


int main(){
    ll d;

    string msg;
    string cipher;

    d = rsa_key_generation(97, 23);
    //cout<<bigmod(bigmod(390, e, n), d, n)<<endl;

    ifstream input;
    ofstream output;

    input.open("in.txt");
    output.open("out.txt");

    getline(input, msg);

    cipher = encrypt(msg, 3);
    msg = decrypt(cipher, d);

    cout<<"Original message : "<<msg<<endl;
    cout<<"Cipher message : "<<cipher<<endl;

    output<<"Original message : "<<msg<<endl;
    output<<"Cipher message : "<<cipher<<endl;

    input.close();
    output.close();

    return 0;
}
