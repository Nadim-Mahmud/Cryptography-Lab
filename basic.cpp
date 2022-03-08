#include<bits/stdc++.h>
using namespace std;

string encrypt(string msg){
    string cipher = "";

    return cipher;
}

string decrypt(string cipher){
    string msg = "";

    return msg;
}


int main(){

    string msg;
    string cipher;

    ifstream input;
    ofstream output;

    input.open("in.txt");
    output.open("out.txt");

    getline(input, msg);

    cipher = encrypt(msg);
    msg = decrypt(cipher);

    cout<<"Original message : "<<msg<<endl;
    cout<<"Cipher message : "<<cipher<<endl;

    output<<"Original message : "<<msg<<endl;
    output<<"Cipher message : "<<cipher<<endl;

    input.close();
    output.close();

    return 0;
}
