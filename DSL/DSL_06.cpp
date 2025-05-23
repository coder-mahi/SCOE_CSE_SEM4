#include <iostream>
using namespace std;
#define SIZE 10
struct Track 
{
    int trackID=0;
    string name ="0";
    string artist ="0";
    string album= "0";
};

Track musicLibrary[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insertTrack() {
    int id;
    string name,artist,album;
    cout<<"Enter Track ID, Name, Artist, Album: ";
    cin>>id>>name>>artist>>album;

    int index =hashFunction(id);
    int i=0;

    while(i <SIZE)
    {
        int probeIndex = (index+i)%SIZE;
        if(musicLibrary[probeIndex].trackID == 0) 
        {
            musicLibrary[probeIndex].trackID = id;
            musicLibrary[probeIndex].name = name;
            musicLibrary[probeIndex].artist = artist;
            musicLibrary[probeIndex].album = album;
             cout<<"Track insertedd at index:> "<<probeIndex<<endl;
            return;
        }else{
            cout<<"collision occurred at :> "<<i+1<<endl;
        }
        i++;
    }
    cout<<"Music library is full! Insertion failed.\n";
}

void updateTrack() {
    int id;
    cout<<"Enter Track ID to update: ";
    cin>>id;

    int index=hashFunction(id);
    int i=0;

    while (i<SIZE) 
    {
        int probeIndex = (index+i) % SIZE;
        if (musicLibrary[probeIndex].trackID == id) {
            cout<<"Enter new Name, Artist, Album: ";
            cin>>musicLibrary[probeIndex].name >> musicLibrary[probeIndex].artist >> musicLibrary[probeIndex].album;
            cout << "Track updated successfully!\n";
            return;
        }
        i++;
    }
    cout<<"Track not found!\n";
}

void deleteTrack(){
    int id;
    cout<<"Enter Track ID to delete: ";
    cin>>id;

    int index = hashFunction(id);
    int i = 0;
    while(i<SIZE) 
    {
        int probeIndex =(index + i) % SIZE;
        if (musicLibrary[probeIndex].trackID == id) 
        {
            musicLibrary[probeIndex] = Track(); 
            cout<<"Track deleted successfully!\n";
            return;
        }
        i++;
    }
    cout<<"Track not found!\n";
}

void displayLibrary() {
    cout<<"\nMusic lib systemm..\n";
    for (int i=0; i < SIZE; i++)
    {
        if(musicLibrary[i].trackID != 0) {
            cout<<"Index "<<i<<": "<<"ID="<<musicLibrary[i].trackID<< ", Name=" << musicLibrary[i].name<<", Artist="<< musicLibrary[i].artist<<", Album=" << musicLibrary[i].album << endl;
        } else {
            cout<<"Index "<<i<<": emptyy\n";
        }
    }
}

void searchLib(){
    int id;
    cout<<"Enter Track ID to search :>";
    cin>>id;
    int index=hashFunction(id);
    int i=0;

    bool flag = false;
    int x;
    while(i<SIZE) 
    {
        int probeIndex = (index+ i) %SIZE;
        if(musicLibrary[index].trackID == id){
            flag = true;
            x = index;
            break;
        }
        i++;
    }
    if(flag){
        cout<<"track found at index :> "<<x<<endl;
    }else{
        cout<<"track not found :> "<<endl;
    }
}
int main() {
    int choice;
    do {
        cout<<"\nmusic libraryy menu..\n";
        cout<<"1.Insert Track\n2.Update Track\n3. Delete Track\n4.displayy Library\n5.Search\n6.Exit";
        cout<<"Enter choice :";
        cin>>choice;
        switch(choice)
        {
            case 1: 
                insertTrack(); 
                break;
            case 2: 
                updateTrack(); 
                break;
            case 3: 
                deleteTrack(); 
                break;
            case 4: 
                displayLibrary();
                break;
            case 5:
                searchLib();
                break;
            case 6: 
                cout<<"Exiting Music Library...\n"; 
                break;
            default: 
                cout<<"Invalid choice!\n";
        }
    }while(choice!=6);
    return 0;
}
