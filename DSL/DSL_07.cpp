#include<iostream>
using namespace std;
#define SIZE 10

struct Patient{
    int patient_id =0;
    string patient_name ="0";
    string disease ="0";
};

Patient medicalHistory[SIZE];
int hashFunction(int key){
    return key % SIZE;
}

void insertPatient() {
    int id;
    string name, disease;
    cout<<"Enter patient ID, Name, Disease :> "<<endl;
    cin>>id>>name>>disease;

    int index = hashFunction(id);
    int i=0;
    while(i<SIZE)
    {
        int probeIndex =(index + i*i)%SIZE; 
        if (medicalHistory[probeIndex].patient_id==0)
        {
            medicalHistory[probeIndex].patient_id =id;
            medicalHistory[probeIndex].patient_name =name;
            medicalHistory[probeIndex].disease = disease;
            cout<<"Inserted at index :> "<<probeIndex<<endl;
            return;
        }
        i++;
    }
    cout<<"Hash table is full..."<<endl;
}

void updatePatient()
{
    int id;
    cout<<"Enter id of the patient you want to update ? "<<endl;
    cin>>id;
    int index=hashFunction(id);
    int i=0;

    while(i<SIZE) 
    {
        int probeIndex =(index+i*i)%SIZE; 
        if (medicalHistory[probeIndex].patient_id == id) {
            cout<<"Enter new name and disease :> " << endl;
            cin>>medicalHistory[probeIndex].patient_name;
            cin>>medicalHistory[probeIndex].disease;
            cout<<"Updated successfully..." << endl;
            return;
        }
        i++;
    }
    cout<<"Patient not found..."<<endl;
}

void deletePatient() 
{
    int id;
    cout<<"Enter id of the patient you want to delete ? "<<endl;
    cin>>id;
    int index = hashFunction(id);
    int i = 0;

    while (i<SIZE){
        int probeIndex = (index + i * i) % SIZE; // quadratic probing
        if(medicalHistory[probeIndex].patient_id == id) {
            medicalHistory[probeIndex].patient_id = 0;
            medicalHistory[probeIndex].patient_name ="0";
            medicalHistory[probeIndex].disease = "0";
            cout<<"Deleted successfully..."<<endl;
            return;
        }
        i++;
    }
cout<<"Patient not found..."<<endl;
}

void displayPatients(){
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<i<<"\t"<<medicalHistory[i].patient_id<<", "<<medicalHistory[i].patient_name<<", "<<medicalHistory[i].disease<<endl;
    }
}

int main(){
    int ch;
    cout<<"\nMedical Record Management"<<endl;
    do{
        cout<<"\n1.Insert\n2.Update patient record\n3.delete record\n4.Display record\n5.Exit"<<endl;
        cout<<"Enter choice :"<<endl;
        cin>>ch;
    switch(ch){
        case 1:
            insertPatient();
            break;
        case 2:
            updatePatient();
            break;
        case 3:
            deletePatient();
            break;

        case 4:
            displayPatients();
            break;
    }
    }
    while(ch<5);
    return 0;
}