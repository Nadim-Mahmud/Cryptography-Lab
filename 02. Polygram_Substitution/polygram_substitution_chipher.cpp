#include<bits/stdc++.h>
using namespace std;

map<string, string>en_dictionary, dec_dictionary;

void create_dictionary(){
    string w1,w2;

    ifstream input;
    input.open("dictionary.txt");

    while(input>>w1>>w2){
        en_dictionary[w1] = w2;
        dec_dictionary[w2] = w1;
    }
}

string encrypt(string msg){
    string cipher = "", tmp = "";

    for(int i = 0; i < msg.size(); i++){
        if((msg[i]>='A'&&msg[i]<='Z')||(msg[i]>='a'&&msg[i]<='z')){
            tmp += msg[i];
            //cout<<tmp<<endl;
            if(en_dictionary.find(tmp) != en_dictionary.end()){
                cipher += en_dictionary[tmp];
                tmp = "";
            }
        }
        else cipher += msg[i];
    }

    return cipher;
}

string decrypt(string cipher){
    string msg = "", tmp = "";

    for(int i = 0; i < cipher.size(); i++){
        if((cipher[i]>='A'&&cipher[i]<='Z')||(cipher[i]>='a'&&cipher[i]<='z')){
            tmp += cipher[i];
            //cout<<tmp<<endl;
            if(dec_dictionary.find(tmp) != dec_dictionary.end()){
                msg += dec_dictionary[tmp];
                tmp = "";
            }
        }
        else msg += cipher[i];
    }

    return msg;
}


int main(){

    string msg;
    string cipher;

    ifstream input;
    ofstream output;

    input.open("in.txt");
    output.open("out.txt");

    create_dictionary();

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
