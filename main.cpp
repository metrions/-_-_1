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
    head->next = new list;
    head->next->pred = head;
    x = head->next;
    while (!input.eof()){
        float d;
        input >> d;
        x->el = d;
        x->next = new list;
        x->next->pred = x;
        x = x->next;
    }
    x->next = new list;
    x->next->pred = x;
    x = x->next;
    vuvod(head);
    head = pop(head, 2);
    head->pred->el;
    cout << "  " << endl;
    vuvod(head);
}

void vuvod(list *head){
    while (head->pred != NULL){
        head = head->pred;
    }
    head = head->next;
    while(head->next->next != NULL){
        std::cout << head->el <<endl;
        head = head->next;
    }

}

list* pop(list *head, float a){
    bool k = false;
    while (head->pred != NULL){
        head = head->pred;
    }
    head = head->next;
    while(head->next->next != NULL){
        if (head->el == a){
            head->pred->next = head->next;
            head->next->pred = head->pred;
            head = head->next;
            //delete head;
        }
        else{
        head = head->next;}
    }
    return head;
}