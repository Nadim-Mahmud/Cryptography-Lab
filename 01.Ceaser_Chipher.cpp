#include<bits/stdc++.h>
using namespace std;

#define MX 1000000

char str[MX];

int enc(int ch){
    ch = (ch + 3) % 26;
}

int dec(int ch){
    ch = (ch - 3 + 26) % 26;
}

int main(){
    cout<<"Enter the plain text : ";
    gets(str);

    for(int i = 0; str[i]; i++){
        if(isupper(str[i])){
            str[i] = (char)(enc((str[i] - 'A')) + 'A');
        }
        else if(islower(str[i])){
            str[i] = (char)(enc((str[i] - 'a')) + 'a');
        }
    }

    cout<<"Encrypted Text : "<<str<<endl;

    for(int i = 0; str[i]; i++){
        if(isupper(str[i])){
            str[i] = (char)(dec((str[i] - 'A')) + 'A');
        }
        else if(islower(str[i])){
            str[i] = (char)(dec((str[i] - 'a')) + 'a');
        }
    }

    cout<<"Decripted Text : "<<str<<endl;

    return 0;
}
