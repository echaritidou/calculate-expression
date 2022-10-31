#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

//Δημιουργώ μία στοίβα με σταθερό μέγεθος
int stack[SIZE];
int top;
int i;
int pop();
void push();
void display();

//Φτιάχνω μία συνάρτηση που θα εισάγει στοιχεία στη στοίβα
void push(int elem){
    //Ελέγχω αν η στοίβα είναι γεμάτη
    if (top==SIZE-1)
        printf("Stack overflow\n");
    //Αν δεν είναι, το στοιχείο που ει΄σαγεται μπαίνει στην κορυφή της στοίβας
    else{
        top++;
        stack[top]=elem;
    }
}

//Φτιάχνω μία συνάρτηση για τον υπολογισμό της έκφρασης
void eval(char op)
{
    int temp;
    //Φτιάχνω μία δομή ελέγχου για τους τελεστές
    switch(op) {
        //Αν ο τελεστής είναι '+', εξάγονται 2 στοιχεία από την κορυφή της στοίβας
        //προστίθενται μεταξύ τους και το αποτέλεσμα μπαίνει στην κορυφή της στοίβας
        case '+': push( pop() + pop());
            break;
        //Αν ο τελεστής είναι '*', εξάγονται 2 στοιχεία από την κορυφή της στοίβας
        //πολλαπλασιάζονται μεταξύ τους και το αποτέλεσμα μπαίνει στην κορυφή της στοίβας
        case '*': push( pop() * pop());
            break;
        //Αν ο τελεστής είναι '-', εξάγεται το στοιχείο της κορυφής της στοίβας,
        //αποθηκεύεται σε μία μεταβλητή, εξάγεται το επόμενο στοιχείο της κορυφής της στοίβας
        //γίνεται η αφαίρεση μεταξύ του στοιχείου της κορυφής μείον το στοιχείο που αποθηκεύθηκε
        //στη μεταβλητή και το αποτέλεσμα μπαίνει στην κορυφή της στοίβας
        case '-': temp = pop(); push( pop() - temp);
            break;
    }
}

//Φτιάχνω μία συνάρτηση για την εξαγωγή του στοιχείου της κορυφής από τη στοίβα
int pop(){
    int elem;
    //Ελέγχω αν η στοίβα είναι άδεια
    if (top==-1)
        printf("Stack underflow\n");
    //Αν δεν είναι, εξάγεται το στοιχείο της κορυφής της στοίβας
    else{
        printf("The last element has been deleted.\n");
        elem=stack[top];
        top--;
    }
    return elem;
}

//Φτιάχνω μία συνάρτηση για να τυπώνει όλα τα στοιχεία της στοίβας
void display(){
    //Ελέγχω αν η στοίβα είναι άδεια
    if (top==-1)
        printf("Stack underflow\n");
    //Αν δεν είναι, τυπώνει τα στοιχεία της στοίβας από την κορυφή και προς τα κάτω
    else if (top>0){
        printf("The elements of the stack are:\n");
        for (i=top; i>=0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    //Αρχικοποιώ τη στοίβα
    top=-1
    int elem;
    char op;
    int selected;
    //Φτιάχνω ένα μενιύ επιλογών για το χρήστη
    do
    {
        printf("1:insert operand\n2:Insert number\n3:Display\n4:Delete\n5:Exit\n");
        printf("Enter your selection: \n");
        scanf("%d",&selected);
        //Φτιάχνω μία δομή ελέγχου για τις επιλογές του χρήστη
        switch (selected)
        {
            case 1:
                printf("Enter the operant: \n");
                scanf(" %c",&op);
                eval(op);
                break;
            case 2:
                printf("Enter the element: \n");
                scanf("%d", &elem);
                push(elem);
                break;
            case 3:
                display();
                break;
            case 4:
                pop();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    }while (selected!=5);
    return 0;
}