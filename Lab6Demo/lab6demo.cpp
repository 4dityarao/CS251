#include<iostream>
#include<fstream>
#include<set>
#include<sstream>
#include<algorithm>
#include<map>
#include <vector>
using namespace std;


struct movie_deets{
    set<string> crew_members;
    int earnings;
};

void working1(const string &file_name, vector<string> &v)
{
    ifstream infs;
    infs.open(file_name);
    string line;

    if(!infs.is_open())
        return;

    while(getline(infs,line))
    {
        if (!line.empty())
            v.push_back(line);
    }

    infs.close();
}

void fun1(const auto &file_name, auto &v)
{
    ifstream infs;
    infs.open(file_name);
    string line;

    // TODO - REMOVE - Error: No is_open() check

    while(getline(infs,line))
    {
        // TODO - REMOVE - Error: Empty lines added
        v.push_back(line);
    }

    infs.close();
}


void working2(const vector<string> &v, auto &movies)
{
    string word, movie_name;
    bool first = true;
    for (auto line : v)
    {
        if (first)
        {
            first = false;
            continue;
        }
        
        movie_deets temp;
        stringstream ss(line);
        getline(ss, movie_name, ',');

        while(getline(ss, word, ','))
        {
            if(isdigit(word.at(0)))
            {
                break;
            }
            else if (!word.empty())
            {
                temp.crew_members.insert(word);
            }
        }

        temp.earnings = stoi(word);
        movies[movie_name] = temp;
    }
}

void fun2(const auto &v, auto &movies)
{
    string word, movie_name;
    bool first = true;
    for (auto line : v)
    {
        // TODO - REMOVE - Error: First line is not skipped
        
        movie_deets temp;
        stringstream ss(line);
        getline(ss, movie_name, ',');

        while(getline(ss, word, ','))
        {
            if(isdigit(word.at(0)))
            {
                break;
            }
            // TODO - REMOVE - Error: Empty lines are inserted
            temp.crew_members.insert(word);
        }

        temp.earnings = stoi(word);
        movies[movie_name] = temp;
    }
}

string trim(const string &input)
{
    int start, end;
    string s = input;

    start = -1;
    while(start < s.size() && isspace(s.at(++start)));   

    if (start > 0)
        s = s.substr(start);

    end = s.size();
    while(end > 0 && isspace(s.at(--end)));

    if (end+1 < s.size())
        s = s.substr(0, end+1);

    return s;
}

void working3(const auto &movies)
{
    string user_input;
    
    while(trim(user_input) != "exit")
    {
        cout << "Enter the movie name: " << endl;
        getline(cin, user_input);
        if (movies.count(user_input) != 0)
        {
            cout << endl << "Here's how many crew members were in "
                << user_input << ": " 
                << movies.at(user_input).crew_members.size()
                << endl << endl;
        }
        else if (movies.count(user_input) == 0 && trim(user_input) != "exit")
        {
            cout << endl << "Movie not found. Try again" << endl << endl;
        }
    }     
}

// TODO - REMOVE - Error: cannot use [] with const
// void broken3(const map<string, movie_deets> &movies)
void fun3(auto &movies)
{
    string user_input;
    do
    {
        cout << "Enter the movie name: " << endl;
        getline(cin, user_input);
        if(user_input != "exit") // TODO - REMOVE - whitespace in getline prevents match 
        {
            // TODO - REMOVE - Error - Adds to map
            cout << endl << "Here's how many crew members were in "
                    << user_input << ": " 
                    << movies[user_input].crew_members.size()
                    << endl << endl;
        }
    }while(user_input != "exit");   // TODO - REMOVE - whitespace in getline prevents match   
}


int main(){
    vector<string> lines;
    map<string, movie_deets> m;

    // working1("movies.txt", lines);
    // working2(lines, m);
    // working3(m);

    // reset states
    lines.clear();
    m.clear();

    // Call the broken versions
    fun1("movies.txt", lines);
    fun2(lines,m);
    fun3(m);

    return 0;
}
