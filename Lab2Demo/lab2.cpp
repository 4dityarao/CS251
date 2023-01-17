#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

    string file_name = "input.txt";
    ifstream infs(file_name);
    int a,b,c;
    // Example 1,Three at a time at a time
    // while(infs>>a>>b>>c)
    // {

    //     cout<<"Value of a: "<<a<<endl;
    //     cout<<"Value of b: "<<b<<endl;
    //     cout<<"Value of c: "<<c<<endl;
    //     cout<< "Sum: "<<a+b+c<<endl;
    // }
  


    // Example 2, only put first element as a conditional of the while loop and read the other two later. 

    while(infs>>a)
    {
        infs>>b;
        infs>>c;
        cout<<"Value of a: "<<a<<endl;
        cout<<"Value of b: "<<b<<endl;
        cout<<"Value of c: "<<c<<endl;
        cout<< "Sum: "<<a+b+c<<endl;

    }
    return 0;

}