#include<iostream>
#include<vector>
#include<sstream>
#include<set>
using namespace std;

/*
This program  counts the instances of profane words from the blocklist that a user inputs 
in a chat inside a video game.

The program simply takes the user input, lowers the first character in case the sentence begins 
with a profanity, and gives the count of the words from the block list of "no_no_words".
*/

int profanity_counter(string user_input){
    
     set<string> no_no_words({"poop","stupid","bufoon","doodie"});     
     string word;
     int counter = 0;
     stringstream ss(user_input);
     while(ss>>word){
        word[0] = tolower(word[0]);
        if(no_no_words.find(word)!=no_no_words.end()){
            counter++;
        }
     }
    return counter;
}


bool test1(){
    //Good Gamer;
    string user_input = "You dont play good but I respect you";
    return profanity_counter(user_input)==0;
}

bool test2(){
    //Bad Gamer;
    string user_input = "Stupid move! Only an absolute bufoon would do this";
    return profanity_counter(user_input)==2;
}

bool test3(){
    //Oversmart gamer
    string user_input = "You are stUpid bro.";
    return profanity_counter(user_input)==1;

}

int main(){
int pass = 0;
     int fail = 0;
     (test1()) ? pass++ :( cout<<"test 1 failed"<<endl,fail++);
     (test2()) ? pass++ :( cout<<"test 2 failed"<<endl,fail++);
     (test3()) ? pass++ :( cout<<"test 3 failed"<<endl,fail++);
      cout << "test cases passed: " << pass << endl;
      cout << "test cases failed: " << fail << endl;
return 0;
}

// Correct function that lowers each character of every word.


// int profanity_counter(string user_input){
//     //Lowers every character
//      set<string> no_no_words({"poop","stupid","idiot","doodie"});     
//      string word;
//      int counter = 0;
//      stringstream ss(user_input);
//      while(ss>>word){
//         for (int i=0;i<word.size();i++)
//             word[i] = tolower(word[i]);
//         if(no_no_words.find(word)!=no_no_words.end()){
//             counter++;
//         }
//      }
//     return counter;
// }


/* Questions

* Why does test 3 fail?
* What other tests can you think of? (Removing punctuation)
*/