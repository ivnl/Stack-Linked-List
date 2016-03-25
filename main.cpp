#include <iostream>
#include <fstream>
using namespace std;

class listnode {

    public:

        int data;
        listnode* next;

        listnode(int s) {
            this->data = s;
            next = nullptr;
            }

    };

class liststack {

    public:

        listnode *top;


        liststack() {

            top = nullptr;

            }

        ~liststack() {
            listnode* ptr = top;
            listnode* temp;
            while (ptr != nullptr) {
                temp = ptr;
                ptr  = ptr->next;
                delete temp;
                }
            }

        bool isEmpty() {

            if(top==nullptr) return true;
            else return false;

            }

        void push(int x) {

            listnode* newnode; //same as listnode* n = new listnode(x);
            newnode = new listnode(x);
            newnode -> next = top;
            cout<<newnode->next;
            top = newnode;
            }



        int pop() {

            if(top==nullptr) {
                cout<<"Stack Empty";
                return 0;
                }

            else {

                int temp = top->data;
                top = top->next;
                return temp;

                }

            }

        void display() {

            listnode* temp = top;

            if(temp==nullptr) cout<<"\nStack Empty!\n";

            while(temp!=nullptr) {

                cout<<temp->data<<" ";
                temp = temp->next;

                }

            }



    };


int main(int argc, char * argv[]) {

    cout<<"Elements within input file: ";

    ifstream ReadFile;
    ReadFile.open(argv[1]);

    int count=0;

    int num;

    if (ReadFile.is_open()) {

        while (ReadFile>>num) {

            count++; //count num of elements in txt file
            cout<<num<<" ";
            
            }

        cout<<"\n\n"<<"Total number of elements found in file: "<<count<<"\n";

        ReadFile.close();

        }

    liststack stk;

    ReadFile.open(argv[1]);

    if (ReadFile.is_open()) {

        while (ReadFile>>num) {

            cout<<"\nPushing: "<<num<<" in to stack"<<" ..... mem addr of Node->next is: ";
            stk.push(num);

            }

        cout<<"\n";

        ReadFile.close();


        }

    cout<<"\nCurrent values within stack from top to bottom: ";
    stk.display();
    cout<<"\n\n";

    while(!stk.isEmpty()) {

        cout<<"Popping: "<<stk.pop()<<" from stack\n";

        }

    stk.display();


    return 0;

    }
