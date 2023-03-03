#include <iostream>
#include <fstream>

struct list{
    list * pred;
    list * next;
    float el;
};

using namespace std;
void vuvod(list *head);

list* pop(list *head, float a);

int main(){
    ifstream input;
    input.open("file.txt");
    list *head = new list;
    list *x = new list;
    x = head;
    while (!input.eof()){
        float d;
        input >> d;
        x->el = d;
        x->next = new list;
        x->next->pred = x;
        x = x->next;
    }
    vuvod(head);
    //head = pop(head, 2);
    head->pred->el;
    cout << "  " << endl;
    vuvod(head);
}

void vuvod(list *head){
    while (head->pred != NULL){
        head = head->pred;
    }
    while(head->next != NULL){
        std::cout << head->el <<endl;
        head = head->next;
    }

}
