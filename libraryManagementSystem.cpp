#include<iostream>
#include<fstream>
using namespace std;

class temp{
    
    string id,name,author,search;
    fstream file;
    public :
    void showAll();
    void addBook();
    void extractBook();

}obj;

int main(){
    while(1){
        cout<<"-----MENU-----\n";
        cout<<"1)SHOW ALL BOOKS IN LIBRARY\n2)ADD A BOOK TO THE COLLECTION\n3)EXTRACT BOOK\n4)EXIT\n";
        int choice;
        cout<<"Enter choice\n";
        cin>>choice;
        switch(choice){
            case 1:
                cin.ignore();
                obj.showAll();
                break;
            case 2:
                cin.ignore();
                obj.addBook();
                break;
            case 3:
                cin.ignore();
                obj.extractBook();
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}

void temp::showAll(){
    file.open("library.txt",ios::in);
    while(getline(file,id,'*') && getline(file,name,'*') && getline(file,author)){
                    cout<<"id : "<<id<<"name : "<<name<<"author : "<<author<<endl;
    }
    file.close();
}

void temp::addBook(){
    cout<<"Enter id of the book"<<endl;
    getline(cin,id);
    cout<<"Enter name of the book"<<endl;
    getline(cin,name);
    cout<<"Enter author of the book"<<endl;
    getline(cin,author);
    file.open("library.txt",ios::out|ios::app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
}

void temp::extractBook(){
    showAll();
    cout<<"Enter book id you wanna extract"<<endl;
    cin>>search;
    file.open("library.txt",ios::in);
    bool flag=false;
    while(getline(file,id,'*') && getline(file,name,'*') && getline(file,author)){
        if(id==search){
            cout<<"id : "<<id<<"name : "<<name<<"author : 1"<<author<<endl;
            flag=true;
            break;
        }
    }
    if(flag==false){
        cout<<"Book not found"<<endl;
    }
    file.close();
}