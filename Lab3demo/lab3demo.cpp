#include<iostream>
#include<vector>
#include<array>
#include<fstream>
using namespace std;


// Array Implementation
// void songFinder(){


//     string album_name,song_name,key;
//     ifstream infs;
//     cout<<"##### Array Implementation #####"<<endl<<endl;
//     cout <<"Enter the album name (Ends with .txt): "<<endl;
//     cin>>album_name;
//     infs.open(album_name);
//     array<string, 20> track_list;
//     int i = 0;
//     while(getline(infs, song_name)){
//         if(!infs.fail()){
//             track_list[i] = song_name;
//             cout<<"Element "<<i<<" added, the size is now "<< track_list.size()<<endl<<endl;
//             i++;
       
//         }
//     }
//     cout<<endl;
//     cout<<"Size: "<<track_list.size()<<endl;
//     cout<<"Max Size: " <<track_list.max_size()<<endl;
//     cout<<"Album "<<album_name.substr(0,album_name.length()-4)<<" loaded!"<<endl;
//     cout <<"Enter character(s) to search songs from this album: "<<endl;
//     cin>>key;

//     cout<< "Showing results that contain "<<key<<" :"<<endl;

//     // Demonstration of size() and max_size() in array

//     for(i=0;i<track_list.max_size();i++){
//         if(track_list[i].find(key)!=string::npos){

//             cout<<track_list[i]<<endl;
//         }
        
//     }
//     cout<<"i at the end of the search was: "<<i<<endl;

// }



// Vector Implementation

void songFinder(){


    string album_name,song_name,key;
    ifstream infs;
    cout<<"##### Vector Implementation #####"<<endl<<endl;
    cout <<"Enter the album name (Ends with .txt): "<<endl;
    cin>>album_name;
    infs.open(album_name);
    vector<string> track_list;
    int i = 0;
    while(getline(infs, song_name)){
        if(!infs.fail()){
            // track_list[i] = song_name;
           
            track_list.push_back(song_name);
            cout<<"Element "<<i<<" added, the size is now "<< track_list.size()<<endl<<endl;
             i++;
        }
    }
    cout<<endl;
    cout<<"Size: "<<track_list.size()<<endl;
    cout<<"Album "<<album_name.substr(0,album_name.length()-4)<<" loaded!"<<endl;
    cout <<"Enter character(s) to search songs from this album: "<<endl;
    cin>>key;

    cout<< "Showing results that contain \" "<<key<<" \" :"<<endl;

    // Demonstration of size() and max_size() in array

    for(i=0;i<track_list.size();i++){
        if(track_list[i].find(key)!=string::npos){

            cout<<track_list[i]<<endl;
        }
        
    }
    cout<<"i at the end of the search was: "<<i<<endl;

}

int main(){
    
    songFinder();
    return 0;
}