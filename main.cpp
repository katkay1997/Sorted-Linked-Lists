#include<iostream>
using namespace std;
struct link {
    int value;
    link * next;
    link() { value = 0; next = 0; }
    link(int _value) {value = _value; next = 0; }
};
void printList( link * );

void insertElement(link*& top, int value){

} // new variable created
int main(){
    link * eventop = 0;

    link * oddtop = 0;
    link * mergetop = 0;
    link * mergebottom;
    link * previous = 0;
    link * current = 0;
    link * lptr = 0;
    int invalue;
    cout << "Input an integer, enter 0 to terminate: " << flush;
    cin >> invalue;
    while (invalue) {
        if(invalue%2 != 0){
            insertElement(oddtop, invalue);
        } else {
            insertElement(eventop, invalue);
        };
        cout << "Input an integer, enter 0 to terminate: " << flush;
        cin >> invalue;
    }
    printList( oddtop );
    cout << "\n\n";
    printList( eventop );
    cout << "\n\n";

    while (oddtop || eventop) {
        link * lptr;
        link * current;

        if( !eventop){
            lptr = oddtop;
            eventop = eventop->next;
        }
        else{
            lptr = eventop;
            oddtop = oddtop->next;
        }


        if(!mergetop){
            mergetop = mergebottom = lptr;

        } else{
            mergebottom->next = lptr;

            mergebottom = lptr;

        }
    }

    if (mergebottom) {
        mergebottom->next = nullptr;
    }
    printList ( mergetop );
    cout << "\n\n";
    previous = 0;
    current = mergetop;


    while (current ) {
        if(current->value%2 != 0){
            lptr =current;
            current = current ->next;
            delete lptr;
        } else {
            current = current ->next;
        }

    }
    //------separate
    printList ( mergetop );
    while ( mergetop ) {
        lptr = mergetop;
        mergetop = mergetop->next;
        delete lptr;
    }
    return 0; }
void printList( link * list){
    link * current = list;
    while(current){
        cout << current -> value;
        current = current -> next;
    }
}

