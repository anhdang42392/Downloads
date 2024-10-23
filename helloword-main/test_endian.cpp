# include <stdio.h>
# include <iostream>
using namespace std ;
int main(){
    int test = 0;
    char *bytes = (char*) &test;
    *bytes = 0x1;
    cout << "Byte Order: " ;
    if(test ==1){
        cout << "little" ;
    } 
    else{
        cout << "big" ;

    }
    cout << " endian" << endl;
    return 0;
}