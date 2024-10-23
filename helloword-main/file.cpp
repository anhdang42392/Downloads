#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std ;
int main(){
    int price = 10 ;
    string name ;
    string namely ;
    int age ;

    cout << "Writing data to file: " << endl;
    cout << "Enter the name: ";
    getline(cin,name) ;

    cout << "Enter the age: ";
    cin >> age ; 
    cin.ignore() ;
    // khởi tạo file input
    ifstream inputFile ;
    inputFile.open("input.txt");
    // đọc dữ liệu từ file input

    
    cout << "Reading from input file: " << endl ;
    for ( int i = 0 ; i < 4; i++){
    inputFile >> namely ;
    cout << namely << "\t" ;
    }
    cout << endl;
    //

    // khởi tạo file output
    ofstream outFile ;
    outFile.open("FileNumber.txt") ;

    outFile << 100 << endl;
    outFile << 200 << endl; 
    outFile << 300 << endl;
    outFile << 400 << endl;
    outFile << 500 << endl ;
    outFile << 600 << endl;
    outFile << 700 << endl ;
    outFile << 800 << endl ;
    outFile << 900 << endl ;

    ifstream inFile ;
    inFile.open("FileNumber.txt") ;

    int number ;
    int value = 0;
    while(inFile >> number){
        cout << number << "\t";
        value = value + number ;
    }
    cout << endl;
    cout <<"The sum of numbers: " << value << endl ;
    //

    

    ofstream outputFile;
    outputFile.open("output.txt");
    // ghi dữ liệu vào file output
    outputFile << "hello world\n" ;
    outputFile << "Price: " << price <<endl ;
    outputFile <<"Name: " << name << endl;
    outputFile <<"Age: " << age << endl ;
{
    ofstream fileOut;
    string fileName;
    int num4;
    cout << "Enter the name of file: " ; cin >> fileName;
    cin.ignore();
    fileOut.open("fileNumber.txt") ;
    fileOut << 150 << endl;
    fileOut << 250 << endl;
    fileOut << 350 << endl;
    fileOut << 450 << endl;
    fileOut << 550 << endl;

    ifstream fileIn ;
    fileIn.open(fileName);
    if(fileIn.fail()){
        cout << "Error file\n" ;
    } else {
        cout <<"The numbers in fileNumber.txt:" << endl;
        while(fileIn >> num4) {
            cout << num4 <<"\t" ;
        }
        cout << endl ;
        fileIn.close();
    }
    fileOut.close();
}
      


    // đóng file
    inFile.close() ;
    outFile.close();
    inputFile.close();
    outputFile.close();
    cout << "Done"<< endl;
    return 0;   
}