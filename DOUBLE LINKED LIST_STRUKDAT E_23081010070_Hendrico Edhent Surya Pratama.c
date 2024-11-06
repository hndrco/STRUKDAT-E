/* 
Nama	: Hendrico Edhent Surya Pratama 
NPM 	: 23081010070 
Kelas	: Struktur Data E081
Tugas	: Membuat Double Linked List dari Tugas Linked List Sebelumnya 
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node *nxt;
    struct node *prev;
};
typedef struct node node;

void inputPertama(node **head);
void inputData(node **head);
void inputAkhir(node **head);
void hpsData(node **head);
void hpsAwal(node **head);
void hpsTengah(node **head);
void hpsAkhir(node **head);
void tampilanData(node *head);
int htgjmlhData(node *head);
int jmlhData(node *head);
node *crData(node *head, int num);

int main() {
    node *head = NULL;
    char ch;
    int num;

    do {
        system("cls");
        printf("Masukkan pilihan kamu :\n");
        printf("1. Input data Pertama\n");
        printf("2. Input data Tengah\n");
        printf("3. Input data Akhir\n");
        printf("4. Hapus data\n");
        printf("5. Tampilkan semua data\n");
        printf("6. Cari data\n");
        printf("7. Tampilkan jumlah data\n");
        printf("8. Tampilkan hasil penjumlahan semua data\n");
        printf("Pilih disini (Ket : 'x' untuk keluar) : ");
        fflush(stdin);
        scanf(" %c", &ch);  

        switch (ch) {
            case '1':
                inputPertama(&head);
                break;
            case '2':
                inputData(&head);
                break;
            case '3':
                inputAkhir(&head);
                break;
            case '4':
                hpsData(&head);
                getch();
                break;
            case '5':
                tampilanData(head);
                getch();
                break;
            case '6':
            	system("cls");
                printf("\nMasukkan data yang dicari: ");
                scanf("%d", &num);
                node *hasil = crData(head, num);
                tampilanData(head);
                if (hasil != NULL) {
                    printf("Data %d ditemukan\n", hasil->data);
                } else {
                    printf("Data %d tidak ditemukan\n", num);
                }
                getch();
                break;
            case '7':
                printf("\nJumlah data dalam linked list: %d\n", htgjmlhData(head));
                getch();
                break;
            case '8':
                printf("\nHasil penjumlahan semua nilai: %d\n", jmlhData(head));
                getch();
                break;
        }
    } while (ch != 'x');

    return 0;
}

void inputPertama(node **head) {
    int num;
    node *pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL) {
        printf("Gagal alokasi memori\n");
        return;
    }

    system("cls");
    printf("Inputkan nilai: ");
    scanf("%d", &num);

    pNew->data = num;
    pNew->nxt = *head;
    pNew->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = pNew;
    }
    *head = pNew;
}

void inputData(node **head) {
    int pos, num;
    node *pNew = (node *)malloc(sizeof(node));
    node *pCur = *head;

    if (pNew == NULL) {
        printf("Gagal alokasi memori\n");
        return;
    }

    system("cls");
    tampilanData(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    scanf("%d", &pos);
    printf("Nilai: ");
    scanf("%d", &num);

    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->nxt;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan\n");
        free(pNew);
        return;
    }

    pNew->data = num;
    pNew->nxt = pCur->nxt;
    pNew->prev = pCur;

    if (pCur->nxt != NULL) {
        pCur->nxt->prev = pNew;
    }
    pCur->nxt = pNew;
}

void inputAkhir(node **head) {
    int num;
    node *pNew = (node *)malloc(sizeof(node));
    node *pCur = *head;

    if (pNew == NULL) {
        printf("Gagal alokasi memori\n");
        return;
    }

    system("cls");
    printf("Input nilai: ");
    scanf("%d", &num);

    pNew->data = num;
    pNew->nxt = NULL;

    if (*head == NULL) {
        pNew->prev = NULL;
        *head = pNew;
    } else {
        while (pCur->nxt != NULL) {
            pCur = pCur->nxt;
        }
        pCur->nxt = pNew;
        pNew->prev = pCur;
    }
}

void hpsData(node **head) {
    int ch;
    system("cls");
    tampilanData(*head);
    printf("\nPilih opsi hapus:\n");
    printf("1. Hapus nilai Pertama\n");
    printf("2. Hapus nilai (Tengah)\n");
    printf("3. Hapus nilai Akhir\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            hpsAwal(head);
            break;
        case 2:
            hpsTengah(head);
            break;
        case 3:
            hpsAkhir(head);
            break;
        default:
            printf("Input salah!\n");
    }
}

void hpsAwal(node **head) {
    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->nxt;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Node pertama berhasil dihapus.\n");
}

void hpsTengah(node **head) {
    int data;
    printf("Masukkan nilai data yang ingin dihapus: ");
    scanf("%d", &data);

    node *pCur = *head;

    while (pCur != NULL && pCur->data != data) {
        pCur = pCur->nxt;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan\n");
        return;
    }

    if (pCur->prev != NULL) {
        pCur->prev->nxt = pCur->nxt;
    } else {
        *head = pCur->nxt;
    }

    if (pCur->nxt != NULL) {
        pCur->nxt->prev = pCur->prev;
    }

    free(pCur);
    printf("Node berhasil dihapus.\n");
}

void hpsAkhir(node **head) {
    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    node *pCur = *head;

    while (pCur->nxt != NULL) {
        pCur = pCur->nxt;
    }

    if (pCur->prev != NULL) {
        pCur->prev->nxt = NULL;
    } else {
        *head = NULL;
    }

    free(pCur);
    printf("Node terakhir berhasil dihapus.\n");
}

void tampilanData(node *head) {
    node *pWalker = head;
    system("cls");
    printf("Data dalam linked list:\n");
    while (pWalker != NULL) {
        printf("%d <-> ", pWalker->data);
        pWalker = pWalker->nxt;
    }
    printf("NULL\n");
}

int htgjmlhData(node *head) {
	system("cls");
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->nxt;
    }
    return cnt;
}

int jmlhData(node *head) {
	system("cls");
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->nxt;
    }
    return sum;
}

node *crData(node *head, int num) {
	system("cls");
    while (head != NULL) {
        if (head->data == num) {
            return head;
        }
        head = head->nxt;
    }
    return NULL;
}

