#include<bits/stdc++.h>
using namespace std;

string encrypt(string msg){
    string cipher = "", pad;

    ifstream input("random_string.txt");
    input>>pad;

    for(int i = 0; i <= msg.size(); i++){
        if(isupper(msg[i])){
            cipher += (char)(((msg[i] - 'A') + (pad[i] - 'A')) % 26 + 'A');
        }
        else if(islower(msg[i])){
            cipher += (char)(((msg[i] - 'a') + (pad[i] - 'A')) % 26 + 'a');
        }
        else{
            cipher += msg[i];
        }
    }

    input.close();

    return cipher;
}

string decrypt(string cipher){
    string msg = "", pad;

    ifstream input("random_string.txt");
    input>>pad;

    for(int i = 0; i <= cipher.size(); i++){
        if(isupper(cipher[i])){
            msg += (char)(((cipher[i] - 'A') - (pad[i] - 'A') + 26) % 26 + 'A');
        }
        else if(islower(cipher[i])){
            msg += (char)(((cipher[i] - 'a') - (pad[i] - 'A') + 26) % 26 + 'a');
        }
        else{
            msg += cipher[i];
        }
    }

    input.close();

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
