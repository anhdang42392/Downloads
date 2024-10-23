#include <iostream>
#include<iomanip>
#include<string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std ;


// int main(){
//     int j = 0;
// for (int i = 0; i < 128; i++){
//     j++ ;
//     cout << static_cast<char>(i) << "  " ;
//     if(j > 15){
//         cout << endl;
//         j = 0 ;
//     }
// }
// return 0;
// }



// int main(){
//     double levels = 1.5 ;
//     int year = 2024 ;
//     cout << "Years\tSea level(mm)\n" ;
//     cout << setprecision(1) << fixed << showpoint ;
//     cout << year << "\t" << levels << endl; 
//     for (int i = 1 ; i < 26 ; i++){
//         cout << (year += 1) << "\t" << (levels+= 1.5) << endl; 
//     }
//     return 0;
// }


// int main(){
//     srand(time(NULL));
//     int num = rand() % 100;
//     int length ;
//     cout << "Enter the length < 15: ";
//     cin >> length ;
//     for(int i = 1; i <= length; i++){
//         for(int j = 1 ; j <= length; j++){
//             cout << "X" ;
//         }
//         cout << endl;
//     }
//             int value = 12345;
//         cout << setw(7) << value << endl ;
//     int t = 11;
//     int j = 0;
//     cout << "Pattern A\tPattern B\n";
//     for(int i = 1; i <= 10;i++){
//             int a = i;
//             int b = 11 - i;
//             if(i == 1){
//             while(a > 0){
//                 cout << "+" ;
//                 a--;
//             }
//             cout << setw(16) ;
//             while(b > 0){
//                 cout <<"+";
//                 b--;
//             }
//             cout << endl;
//         }
//             if(i > 1){
//                 j = j + 1;
//                 while(a > 0){
//                 cout << "+" ;
//                 a--;
//             }
//             cout << setw(16 - j) ;
//             while(b > 0){
//                 cout <<"+";
//                 b--;
//             }
//             cout << endl;

//         }
//     }

// }


// double calculateRetail(double,double) ;
// //


// int main(){
//     double cost, markup;
//     cout << "Enter the item cost: " ; cin >> cost ;
//     cin.ignore() ;
//     cout << "Enter the markup: " ; cin >> markup;
//     cin.ignore();
//     cout << fixed << showpoint<< setprecision(2);
//     cout << "The item retail price: " << calculateRetail(cost,markup) << endl;
    

// }


// double calculateRetail(double cost, double markup){
//     return cost + (cost*markup/100) ;
// }


// double getSale(string);
// void findHighest(double, double,double,double);
// int main(){
//     string Northeast , Southeast, Northwest,  Southwest;

// }

// double getSale(string divisons ){
//     double sales;
// cout << "The sales figure of "<< divisons << ": " ; cin >> sales ;
// return sales ;
// }

// void findHighest(double northeast, double southeast, double northwest, double southwest){
//     if(northeast >= southeast && northeast >= northwest && northeast >= southwest){
//         cout << "Northeast has the greatest sales for a quarter" << endl;
//     }

//     else if(northeast <= southeast && southeast >= northwest && southeast >= southwest){
//         cout << "Southeast has the greatest sales for a quarter" << endl;
//     }

//     else if(northwest >= southeast && northeast <= northwest && northwest >= southwest){
//         cout << "Northwest has the greatest sales for a quarter" << endl;
//     }

//     else if(northeast <= southwest && southeast <= southwest && northwest <= southwest){
//         cout << "Southwest has the greatest sales for a quarter" << endl;
//     }

// }


int main(){
    const int MAX = 10;
    int hours[MAX] ;
    // cout << "Enter the number of array:" << endl;
    // for(int i = 0; i < 10; i++){
    //     cout <<"Enter hours[" <<i<<"]: ";
    //     cin >> hours[i] ;
    // }
    // for(int i = 0;i <10 ; i++){
    //     cout << "hours["<< i<< "]: " << hours[i] << endl ;
    // }

    // ofstream Fileout;
    // Fileout.open("FileNumber.txt") ;
    // for(int i = 0; i < 10;i++){
    //     Fileout << i*2 << endl ;
    // }
    // ifstream Filein;
    // Filein.open("FileNumber.txt");
    // for(int i = 0; i < 10; i++){
    //     Filein  >> hours[i];
    // }

    // ofstream outputFile;
    // outputFile.open("output.txt");
    // for(int i = 0;i <10 ; i++){
    //     outputFile << "hours["<< i<< "]: " << hours[i] << endl ;
    // }
    
    // cout << "The new array of hours: ";

    // for(int i = 0;i<10;i++){
    //      cout << hours[i] <<"\t" ;
    // }



    // cout << endl;
    // //Usinng range-based for loop
    // int j = 0;
    // for(auto  &value : hours){
    //   cout <<"Enter hours[" <<j<<"]: ";
    //     cin >> value ;
    //     j++ ;  
    // }
    // j =0;
    // int total =0 ;
    // ofstream output;
    // output.open("input.txt") ;    
    // for(auto value : hours){
    //     cout <<"The value from hours[ "<<j<<"]: "<< value << endl;
    //     output << value << endl;
    //     total += value;
    //     j++;
    // }
    // cout << "the total of array: " << total << endl;



    // // two dimension array
    // const int ROW = 5;
    // const int COL = 5;
    // int sales[ROW][COL] ;
    // for(int i=0; i < ROW; i++){
    //     for(int j= 0;j < COL;j++){
    //         cout << "sales["<<i<<"]["<<j<<"]: ";
    //         cin >> sales[i][j] ;
    //     }
    //     cout << endl;
    // }
    // int sum;
    // for(int i=0;i<ROW;i++){
    //     for(int j=0;j <COL;j++){
    //         cout << sales[i][j] <<"\t";
    //         sum += sales[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << "The sum of sales: " << sum << endl;

    // outputFile.close();
    // Filein.close();
    // Fileout.close();



    //vector
    vector<int> number(5);
    int i = 0;
    for(auto &value : number){
        cout << "Enter the value " << i << ": " ;
        cin >> value ;
        i++ ;
    }
    cout << "The list of vector: " ;
    for(auto value : number){
        cout << value << " " ;
    }
    cout << endl;
    for(int i = 10; i < 30 ; i += 2 ){
        number.push_back(i) ;
    }

    cout << "Vector after push back: " ;

    for(auto value : number){
        cout << value << " " ;
    }
    cout << endl;


    // binary search
    int value;
    cout << "Enter the value to search: ";
    cin >> value;
    cin.ignore();
    int first = 0, // First array element 
    last = number.size() - 1, // Last array element 
    middle, // Midpoint of search 
    position = -1 ; // Position of search value 
    bool found = false; // Flag
    cout <<"The value of found: " << found << endl;
    cout <<"The value of !found: " << !found << endl;
    while (!found && first <= last)
    {
        
        middle = (first + last) / 2; // Calculate midpoint
        if (number[middle] == value)  // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (number[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }

    cout << "The elements is found in: " << position << endl;



    if(number.empty()){
        cout << "Vector is full" << endl;
    }
    number.clear();
    if(number.empty()){
        cout << "Vector is cleared" << endl;
    }

    return 0;
}

