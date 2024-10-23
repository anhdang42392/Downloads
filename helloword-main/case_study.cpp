#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

int getProdNum(int, int);
void displayProd(int id[], string nameProd[], string description[], double price[], int size, int min, int max);
int binarySearch(const int[], int, int);

void calcScales(int[], double[], double[], int size);
void dualSort(double[], int[],int size);
void showOrder(int[], double[], int size);
void showTotals(int[], double[],int size);
void EnterProd(int prodnum[],int units[], double prices[], double sales[], int size);

int main()
{
    // const int NUM_PRODS = 9,
    //           MIN_PRODNUM = 0,
    //           MAX_PRODNUM = 950;
    // int id[NUM_PRODS];
    // string title[NUM_PRODS];
    // string description[NUM_PRODS];
    // double prices[NUM_PRODS];

    // displayProd(id, title, description, prices, NUM_PRODS, MIN_PRODNUM, MAX_PRODNUM);

    const int NUM_PRODS = 9;
    int prodNum[NUM_PRODS] ;
    int units[NUM_PRODS];
    double prices[NUM_PRODS];
    double sales[NUM_PRODS];

    EnterProd(prodNum,units,prices,sales,NUM_PRODS);
    calcScales(units,prices,sales,NUM_PRODS);
    dualSort(sales,prodNum,NUM_PRODS);
    showOrder(prodNum,sales,NUM_PRODS);
    showTotals(units,sales,NUM_PRODS);
    return 0;
}




int getProdNum(int max, int min)
{
    int prodNum;
    cout << "The item's product number: ";
    cin >> prodNum;
    while (prodNum < min || prodNum > max)
    {
        cout << "Enter the number in range " << min << " to " << max << ": ";
        cin >> prodNum;
    }
    return prodNum;
}

void displayProd(int id[], string nameProd[], string description[], double price[], int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        cout << "The number of prod" << i + 1 << endl;
        id[i] = getProdNum(max, min);
        cout << "prod" << i + 1 << " " << id[i] << endl;
        cin.ignore();
        cout << "Title of prod" << i + 1 << ": ";
        getline(cin, nameProd[i]);
        cout << "Description of prod" << i + 1 << ": ";
        getline(cin, description[i]);

        cout << "The price of Prod" << i + 1 << ": ";
        cin >> price[i];
        cout << endl;
    }
    cout << endl;
    ofstream outFile;
    outFile.open("output.txt");
    for (int i = 0; i < size; i++)
    {
        cout << setprecision(2) << fixed << showpoint;
        cout << setw(30) << left << nameProd[i] << setw(8) << description[i] << "\t\t" << id[i] << "\t\t" << price[i] << endl;
        outFile << setw(30) << left << nameProd[i] << setw(8) << description[i] << "\t\t" << id[i] << "\t\t" << price[i] << endl;
    }
}
int binarySearch(const int array[], int size, int value)
{
    // int value;
    // cout << "Enter the value to search: ";
    // cin >> value;
    // cin.ignore();
    int first = 0,       // First array element
        last = size - 1, // Last array element
        middle,          // Midpoint of search
        position = -1;   // Position of search value
    bool found = false;  // Flag
    cout << "The value of found: " << found << endl;
    cout << "The value of !found: " << !found << endl;
    while (!found && first <= last)
    {

        middle = (first + last) / 2; // Calculate midpoint
        if (array[middle] == value)  // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }
    return position;
}

int searchList(const int list[], int numEle, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;
    while (index < numEle && !found)
    {
        if (list[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

void swap(int &lhs, int &rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void bubbleSort(int a[], int n)
{
    bool havesw = false;
    for (int i = 0; i < n - 1; i++)
    {                   //  so lan lap lai viec so sanh la n-1 lan
        havesw = false; // bien de kiem tra xem cs swap hay ko
        for (int j = 0; j < n - i - 1; j++)
        { // so lan so sanh la n - i - 1
            if (a[j] > a[j + 1])
            {                         // so sanh phan tu can xe va phan tu sau no
                swap(a[j + 1], a[j]); // neu phan tu phia sau lon hon thi swap 2 phan tu voi nhau
                havesw = true;        // bien kiem tra se la true
                                      // neu khong thi thoat khoi vong lap
            }
        }
        if (havesw == false)
        {
            break;
        }
    }
}

void bubbleSorting(int a[], int n)
{
    bool haveswap;
    do
    {
        haveswap = false;
        for (int count = 0; count < (n - 1); count++)
        {
            if (a[count] < a[count + 1])
            {
                swap(a[count], a[count + 1]);
                haveswap = true;
            }
        }
    } while (haveswap);
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {                // chon phan tu thu nhat
        int min = i; // gan vi tri phan tu dau tien la vi tri min

        for (int j = i + 1; j < n; j++)
        { // chon phan tu sau phan tu thu nhat
            if (a[j] < a[min])
            {            // so sanh gia tri cua phan tu thu hai va phan tu thu nhat
                min = j; // neu phan  tu thu  2 lon hon thi vi tri phan tu thu 2 dc gan vao min
            } // doi vi tri cua 2 phan tu cho nhau
        }
        swap(a[i], a[min]);
    }
}

void selectionSorting(int array[], int size)
{
    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}




void calcScales(int units[], double prices[], double sales[], int size){
    for(int i = 0; i < size; i++) {
        sales[i] = units[i] * sales[i];
    }
}

void dualSort(double sales[], int prodnum[],int size){
int startScan, maxIndex, tempProd ;
double maxValue;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;
        maxValue = sales[startScan];
        tempProd = prodnum[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (sales[index] > maxValue)
            {
                maxValue = sales[index];
                maxIndex = index;
                tempProd = prodnum[index];
            }
        }
        sales[maxIndex] = sales[startScan];
        sales[startScan] = maxValue;
        prodnum[maxIndex] = prodnum[startScan];
        prodnum[startScan] = tempProd;
    }
}


void showOrder(int prodnum[], double sales[], int size){
    cout << "Product Number\t\tSales" << endl;
    cout << "--------------------------------" << endl;
    for(int i = 0; i < size;i++){
cout << prodnum[i] << "\t\t\t $ " << sales[i] << endl;
    }
}

// show the total
void showTotals(int units[], double sales[],int size){
    int  sum =0 ;
    double total =0;
    for(int i = 0; i < size; i++){
        sum = sum + units[i];
        total = total + sales[i];
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "Total of units sold: " << sum << endl;
    cout << "Total of sales: " << total << endl;
    
}

// Enter the Product
void EnterProd(int prodnum[],int units[], double prices[], double sales[], int size){
    for(int i= 0; i < size; i++){
        cout << "The Product Number " << i + 1 <<": " ;
        cin >> prodnum[i] ;
        cin.ignore();
        cout << "The units sold of product " << prodnum[i] << ": " ;
        cin >> units[i];
        cin.ignore();
        cout << "The price of product " << prodnum[i] <<": ";
        cout << prices[i];
        cin.ignore();
        
    }
}
void InsertionSort(){
    ;
}
