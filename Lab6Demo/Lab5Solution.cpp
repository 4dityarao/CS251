#include<iostream>
#include<set>
#include<algorithm>
using namespace std;


int uncommonElements(const set<int> &a, const set<int> &b){
    set<int> uncommon;
    set_difference(a.begin(),a.end(),
                    b.begin(),b.begin(),
                    inserter(uncommon,uncommon.end()));
    set_difference(b.begin(),b.begin(),
                        a.begin(),a.end(),
                    inserter(uncommon,uncommon.end()));

    //Another way to do it ->

    // set_symmetric_difference(a.begin(),a.end(),
    //                 b.begin(),b.begin(),
    //                 inserter(uncommon,uncommon.end()));
    return uncommon.size();    
}

int main(){

    int counter = 0, num, result;
    set<int> a,b;

    while(counter!=10){
            cin>>num;
            
        if (counter<5){
            a.insert(num);
            counter++;
            continue;
          
        }
        b.insert(num);
        counter++;

    }
    result = uncommonElements(a,b);
    cout<<"Elements in set a: ";
    for(auto i : a){
        cout<< i <<'\t';}
    cout<<"\nElements in set b: ";
    for(auto i : b)
        cout<< i <<'\t';
    cout<<"\nNumber of uncommon elements: "<<result;
}