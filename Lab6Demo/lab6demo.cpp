#include<iostream>
#include<fstream>
#include<set>
#include<sstream>
#include<algorithm>
#include<map>
using namespace std;


struct movie_deets{
    set<string> crew_members;
    int earnings;
};


void fix_me(const string &file_name){
    map<string, movie_deets> movies;
    ifstream infs(file_name);
    string line, word, movie_name, user_input;
    getline(infs,line); //This line reads the header so that stoi doesnt break
    while(getline(infs,line)){
            movie_deets temp;
            stringstream ss(line);
            getline(ss,movie_name,',');
            while(getline(ss,word, ',')){

                if(isdigit(word.at(0))){
                    break;
                }
                else{
                    if(word != " "){// This if statement basically prevents the erronous blank from being counted as a  crew member in tenet
                        temp.crew_members.insert(word);
                    }
                }
                
            }
            temp.earnings = stoi(word);
        movies[movie_name] = temp;

    }
    do{
        cout<<"\nEnter the movie name: ";
        getline(cin,user_input);
        if(movies.find(user_input)!=movies.end()){
            cout<<"\nHere's how many crew members were in "<<user_input<<": "<< movies[user_input].crew_members.size();
        }
        else{
            cout<<"\nMovie not found. Try again\n";
        }
    }while(user_input!="exit");

        
}

int main(){

    fix_me("movies.txt");
    return 0;
}