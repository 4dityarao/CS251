#include <vector>
#include <iostream>
using namespace std;
int main(){
    vector<string> v;
    string val;

    // Parsing variables    
    int loc = 0;
    int start = 0;

    cout << "Enter a sequence of words: " << endl;
    getline(cin, val);


    // String parsing, split by space and push into vector
    while (loc != string::npos && start < val.size())
    // i have     a
    // ofstream
    {
        loc = val.find(" ", start);
     while(val.at(loc+1)==' '){

    loc++;

    }
    

        // Last word?
        if (loc != string::npos)
        {
            v.push_back(val.substr(start,loc));
        }
        else
        {
            v.push_back(val.substr(start));
        }  

        // Move the start location beyond the space
        start = loc+1;
    }

    // Output the size of the vector as the quantity of words
    cout << "Your string contained " << v.size() << " words." << endl;


}