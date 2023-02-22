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
            //Deal w stack overflow by doubling the capacity
            // if(top==size-1){
            //    string* temp = new string[size*2];
            //     for(int i=0;i<size;i++){
            //         temp[i] = arr[i];
            //     }
            //     delete[] arr;
            //     arr = temp;
            //     size = size*2;
            // }
            arr[++top] = ele;
            

        }
        string pop(){
            string result = arr[top];
            top--;
            return result;
        }
        void show_stack(){
            cout<<"\n\n************Browser History************"<<endl;
            for(int i=top;i>=0;i--){

                cout<<arr[i]<<endl;
                
            }
            cout << "***************************************" << endl;
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
     //Pressing back
    back_page = s.pop();
    cout<<"Going back to "<<back_page<<endl;
    //Visit few more links
    cout<<"Browsing some more..."<<endl;
    
    s.push("twitter.com");
    s.show_stack();

    s.push("shady_link2.com");
    s.show_stack();

    s.push("reuters.com");
    cout<<"Something";
    s.show_stack();
    return 0;
}
