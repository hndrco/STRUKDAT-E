/* 
Nama	: Hendrico Edhent Surya Pratama 
NPM 	: 23081010070 
Kelas	: Struktur Data E081
Tugas	: STACK
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int count;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
    s->count = 0;
}

int empty(Stack* s) {
    return s->top == NULL;
}

int full(Stack* s) {
    return s->count == max;
}

void push(Stack* s, int value) {
    if (full(s)) {
        printf("Stack penuh! Tidak dapat menambahkan elemen.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    printf("Elemen %d berhasil ditambahkan.\n", value);
}

void pop(Stack* s) {
    if (empty(s)) {
        printf("Stack kosong!\n");
        return;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    printf("Elemen %d berhasil dihapus.\n", temp->data);
    free(temp);
    s->count--;
}

void top(Stack* s) {
    if (empty(s)) {
        printf("Stack kosong!\n");
    } else {
        printf("Elemen paling atas adalah %d.\n", s->top->data);
    }
}

int count(Stack* s) {
    return s->count;
}

void destroy(Stack* s) {
    Node* current = s->top;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    s->top = NULL;
    s->count = 0;
    printf("Stack berhasil dihancurkan.\n");
}

void print(Stack* s) {
    if (empty(s)) {
        printf("Stack kosong!\n");
    } else {
        Node* temp = s->top;
        printf("Isi Stack: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


void menu() {
    printf("\n--- MENU STACK ---\n");
    printf("1. Push Stack\n");
    printf("2. Pop Stack\n");
    printf("3. Stack Top\n");
    printf("4. Empty Stack\n");
    printf("5. Full Stack\n");
    printf("6. Stack Count\n");
    printf("7. Destroy Stack\n");
    printf("8. Print Stack\n");
    printf("x. Keluar\n");
    printf("Pilih opsi: ");
}

int main() {
    Stack s;
    initStack(&s);
    int choice, value;
    char exitCh;

    do {
        system("cls"); 
        menu();
        exitCh = getch(); 

        if (exitCh == 'x' || exitCh == 'X') {
            break; 
        }

        // Memproses input yang diberikan (misalnya angka)
        if (exitCh >= '1' && exitCh <= '8') {
            choice = exitCh - '0'; // Mengubah karakter menjadi angka
            switch (choice) {
                case 1:
                	system("cls");
                    printf("Masukkan nilai untuk Push: ");
                    scanf("%d", &value);
                    push(&s, value);
                    break;
                case 2:
                    pop(&s);
                    break;
                case 3:
                    top(&s);
                    break;
                case 4:
                    if (empty(&s))
                        printf("Stack kosong.\n");
                    else
                        printf("Stack tidak kosong.\n");
                    break;
                case 5:
                    if (full(&s))
                        printf("Stack penuh.\n");
                    else
                        printf("Stack tidak penuh.\n");
                    break;
                case 6:
                    printf("Jumlah elemen di Stack: %d\n", count(&s));
                    break;
                case 7:
                    destroy(&s);
                    break;
                case 8:
                    print(&s);
                    break;
                default:
                    printf("Pilihan tidak valid.\n");
            }
        }

        printf("Tekan tombol apa saja untuk melanjutkan...");
        getch(); 
    } while (1); 
    destroy(&s);

    return 0;
}

