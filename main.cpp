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
    head = pop(head, 2);
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

list* pop(list *head, float a){
    while (head->pred != NULL){ //проход до первого элемента
        head = head->pred;
    }
    if (head->el == a){         //первый элемент
        list* tmp = head;
        head = head->next;
        head->pred = new list;
        delete tmp;
    }
    while (head->next->next != NULL){   //между первым и вторым элементом
        list* tmp = head;
        head = head->next;
        if (tmp->el == a){
            tmp->pred->next = head;
            head->pred = tmp->pred;
            delete tmp;
            }
    }
    if (head->el == a){         //последний элемент
        list* tmp = head;
        head = head->pred;
        head->next = NULL;
        delete tmp;
        return head;
    }
    return head;
}
// ЕБАЛРОТVSCODE