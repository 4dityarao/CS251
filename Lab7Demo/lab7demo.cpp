#include <iostream>
#include <vector>
using namespace std;

class Stack {
    private:
        string* arr;
        int size;
        int top;

    public:
        Stack() {
            arr = new string[4];
            this->size = 4;
            top = -1;
        }

        void push(string ele){
            arr[++top] = ele;
        }
        string pop(){
            string result = arr[top];
            top--;
            return result;
        }
        void show_stack(){
            cout<<"\n\n************State of Stack************"<<endl;
            for(int i=top;i>=0;i--){
                if(i==top){
                    cout<<arr[i]<<" <--Top"<<endl;
                }
                else{
                cout<<arr[i]<<endl;
                }
            }
        }
};

int main(){
    Stack s =Stack();
    string back_page = "";
    vector<string> browser_history= {"youtube.com","reddit.com","shady_link.com"};
    for (auto a: browser_history){
        s.push(a);
        s.show_stack();
    }
    s.show_stack();
    //Going back from shady_link to reddit.com
    back_page = s.pop();
    cout<<"Going back to "<<back_page;
    //Visit few more links
    s.push("twitter.com");
    s.show_stack();

    s.push("shady_link2.com");
    s.show_stack();

    s.push("reuters.com");
    s.show_stack();
    



}
