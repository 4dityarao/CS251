#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
using namespace std;

void countryExport(){
    map<string,set<string>> country_map;
    string file_name = "input.txt";
    string line,country,item,user_input;
    ifstream infs(file_name);
    while(getline(infs,line)){
        stringstream ss(line);
        getline(ss,item,';');
        getline(ss,country,';');
        country_map[item].insert(country);
    }
    cout<<"Enter the item: ";
    getline(cin,user_input);
    cout<<endl;
    while(user_input!="exit"){
        if(country_map.find(user_input)!= country_map.end()){
            cout<<user_input<<"==> ";
            for(auto i: country_map[user_input]){
                cout<<i <<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"Item not found. Try again"<<endl;
        }
        cout<<"Enter the item: ";
        getline(cin,user_input);
        cout<<endl;
    }


}


int main() {
     countryExport();
}
