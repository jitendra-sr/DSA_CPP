#include<iostream>
using namespace std;

char shiftChar(char ch, int k) {
    if (ch >= 'a' && ch <= 'z') {
        return 'a' + (ch - 'a' + k + 26) % 26;
    }
    return ch;
}

char shiftChar2(char ch, int k) {
    if (ch >= 'A' && ch <= 'Z') {
        return 'A' + (ch - 'A' + k + 26) % 26;
    }
    return ch;
}

int main(){
    char ch; cout<<"Enter Character To Shift: "; cin>>ch;
    int k; cout<<"Enter Shift Value: "; cin>>k;
    cout<<shiftChar(ch,k);

    return 0;
}