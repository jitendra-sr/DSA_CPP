#include<iostream>
using namespace std;

char shiftChar(char ch, int k) {

    // To handle negative k value efficiently.
    bool sign=(k<0)?false:true;
    int shift=abs(k)%26;
    if(!sign) shift=-shift;

    if (ch >= 'a' && ch <= 'z') {
        return 'a' + (ch - 'a' + shift + 26) % 26;
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