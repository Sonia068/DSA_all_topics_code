/*Construct a class for implementing a stack for maximum 10
books. Each book will contain information like ‘title’, ‘author’
and ‘ISBN’. Your class should include methods for push(), pop(),
peek(), and isEmpty().*/

#include <iostream>
using namespace std;
#define size 10
     // or
//const int size =10;

class book{
    string title;
    string author;
    string isbn;

    public:
    // default constructor
    book(){
       title=" ";
       author=" ";
       isbn=" ";
    }

    // parameterised constructor
    book(string n,string m,string a){
        title=n;
        author=m;
        isbn=a;
    }

string getTitle(){
    return title;
}

string getAuthor(){
    return author;
}

string getisbn(){
    return isbn;
}

};


class  bookstack{
    int top;
    book stck [size];
    
    public:
    
    bookstack(){
    top=-1;
    }

  
    void push(book &b1 ){
        if(top==size-1){
            cout<<"Stack is full"<<endl;
        }

        else{
            top++;
            stck[top]=b1;
        }
    }


    void pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }

        else{
            book data=stck[top];
            top--;
            cout<<"Popped book :"<< data.getTitle() <<" "<<data.getAuthor()<<" "<<data.getisbn()<<" "<<endl;        }
    }

    void peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            book data=stck[top];
            cout<<"Peek :"<<endl;
            cout<<data.getTitle()<<" "<<data.getAuthor()<<" "<<data.getisbn()<<endl;
        }
    }


    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

          // or 
    // bool isempty(){
    //    return top==-1;
    // };


    void display(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }

        else{
           for(int i=0;i<=top;i++){
                cout<<"BOOK "<<i+1<<":"<<endl;
                cout<<"Title:"<<stck[i].getTitle()<<endl;
                cout<<"Author:"<<stck[i].getAuthor()<<endl;
                cout<<"Isbn no. :"<<stck[i].getisbn()<<endl;
                cout<<"---------------------------"<<endl;
            }
        }
    }

};




    int main(){
        bookstack s;


        int n;

        do{
        cout<<"----BOOK DETAILS------"<<endl;
        cout<<"1. Push the book"<<endl;
        cout<<"2. Pop the book"<<endl;
        cout<<"3. Peek the book"<<endl;
        cout<<"4. check if bookstack is empty"<<endl;
        cout<<"5. Display all the books"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"Enter the choice"<<endl;
        cin>>n;
        cin.ignore();


        switch (n){

            case 1:{
            string title,name,isbn;
            cout<<"Enter the title :"<<endl;
            getline(cin,title);

            cout<<"Enter the author name :"<< endl;
            getline(cin,name);

            cout<<"Enter the isbn no. :"<<endl;
            getline(cin,isbn);

            book b(title,name,isbn);
            s.push(b);
            break;
            }
            

            case 2:
            s.pop();
            break;

            case 3:
            s.peek();
            break;

           case 4: {
                if (s.isempty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
               }            

        
            case 5:
            s.display();
            break;

            case 6:
            cout<<"Exit"<<endl;
            break;

            default:
            cout<<"Invalid Choice!"<<endl;
        }
    }
        while(n!=6);
        return 0;


        }
