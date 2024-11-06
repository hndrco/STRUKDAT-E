/* 
Nama 	= Hendrico Edhent Surya Pratama
Npm 	= 23081010070
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nama[50];
    char jenisKelamin;  
    struct Node* next;
} Node;

void tambah(Node** head, char* nama, char jenisKelamin, int* jumlah);
void hapusKembar(Node** head, char* nama, int* jumlah);
void periksaCindy(Node** gabungan, Node** mahasiswi, int* jumlah);
void tampilkanLingkaran(Node* head);
void pisahkanLingkaran(Node* gabungan, Node** mahasiswa, Node** mahasiswi);
void kosongkanLingkaran(Node** head);
void clearScreen();
int substringSama(char* nama1, char* nama2);

Node* buatNode(char* nama, char jenisKelamin) {
    Node* baru = (Node*)malloc(sizeof(Node));
    strcpy(baru->nama, nama);
    baru->jenisKelamin = jenisKelamin;
    baru->next = baru;  
    return baru;
}

void tambah(Node** head, char* nama, char jenisKelamin, int* jumlah) {
    if (*jumlah >= 20) {
        printf("Area terlalu sempit, tidak dapat menampung orang lagi.\n");
        return;
    }

    Node* baru = buatNode(nama, jenisKelamin);

    if (*head == NULL) {
        *head = baru;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->next = *head;
    }
    (*jumlah)++;
    printf("%s telah ditambahkan.\n", nama);  
}

int substringSama(char* nama1, char* nama2) {
    int len1 = strlen(nama1);
    int len2 = strlen(nama2);

    for (int i = 0; i <= len1 - 4; i++) {
        for (int j = 0; j <= len2 - 4; j++) {
            if (strncmp(&nama1[i], &nama2[j], 4) == 0) {
                return 1;  
            }
        }
    }
    return 0;
}

void hapusKembar(Node** head, char* nama, int* jumlah) {
    if (*head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }

    Node *temp = *head, *prev = NULL;
    Node* kembar = NULL;

    do {
        if (strcmp(temp->nama, nama) == 0) {
            Node* iter = *head;
            do {
                if (iter != temp && substringSama(temp->nama, iter->nama)) {
                    kembar = iter;
                    break;
                }
                iter = iter->next;
            } while (iter != *head);
            break;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);

    if (temp == NULL) {
        printf("%s tidak ditemukan.\n", nama);
        return;
    }

    if (prev == NULL) {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        if (temp == last) {
            *head = NULL;
        } else {
            last->next = temp->next;
            *head = temp->next;
        }
    } else {
        prev->next = temp->next;
    }
    printf("Data %s telah dihapus.\n", temp->nama); 
    free(temp);
    (*jumlah)--;

    if (kembar) {
        hapusKembar(head, kembar->nama, jumlah);
    }
}

void periksaCindy(Node** gabungan, Node** mahasiswi, int* jumlah) {
    Node* temp = *gabungan;
    do {
        if (strcmp(temp->nama, "Cindy") == 0) {
            Node* kiri = temp->next;
            Node* kanan = temp;
            while (kanan->next != temp) {
                kanan = kanan->next;
            }

            if (kiri->jenisKelamin != 'P' || kanan->jenisKelamin != 'P') {
                printf("Cindy tidak bisa bergandengan dengan laki-laki.\n");
                hapusKembar(gabungan, "Cindy", jumlah);
                tambah(mahasiswi, "Cindy", 'P', &(int){0});
            }
            break;
        }
        temp = temp->next;
    } while (temp != *gabungan);
}

void tampilkanLingkaran(Node* head) {
	system("cls");
    if (head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%s (%c) -> ", temp->nama, temp->jenisKelamin);
        temp = temp->next;
    } while (temp != head);
    printf("(Kembali ke awal)\n");
}

void kosongkanLingkaran(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* next_node;

    do {
        next_node = temp->next;
        free(temp);
        temp = next_node;
    } while (temp != *head);

    *head = NULL;
}

void pisahkanLingkaran(Node* gabungan, Node** mahasiswa, Node** mahasiswi) {
    kosongkanLingkaran(mahasiswa);
    kosongkanLingkaran(mahasiswi);

    if (gabungan == NULL) return;

    Node* temp = gabungan;
    do {
        if (temp->jenisKelamin == 'L') {
            tambah(mahasiswa, temp->nama, temp->jenisKelamin, &(int){0});
        } else {
            tambah(mahasiswi, temp->nama, temp->jenisKelamin, &(int){0});
        }
        temp = temp->next;
    } while (temp != gabungan);
}

void clearScreen() {
    system("cls");
}

int main() {
	system("cls");
    Node *gabungan = NULL, *mahasiswa = NULL, *mahasiswi = NULL;
    int jumlah_peserta = 0;
    int pilihan;
    char nama[50], jenisKelamin;

    while (1) {
    	system("cls");
        printf("\nMenu:\n");
        printf("1. Tambah Mahasiswa/Mahasiswi\n");
        printf("2. Keluarkan Mahasiswa/Mahasiswi\n");
        printf("3. Lihat Lingkaran Gabungan\n");
        printf("4. Lihat Lingkaran Mahasiswa\n");
        printf("5. Lihat Lingkaran Mahasiswi\n");
        printf("6. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        clearScreen();

        switch (pilihan) {
            case 1:
            	system("cls");
                printf("Nama: ");
                scanf("%s", nama);
                printf("Jenis Kelamin (L/P): ");
                scanf(" %c", &jenisKelamin);
                tambah(&gabungan, nama, jenisKelamin, &jumlah_peserta);
                break;
            case 2:
            	system("cls");
                printf("Nama yang Ingin Keluar: ");
                scanf("%s", nama);
                hapusKembar(&gabungan, nama, &jumlah_peserta);
                break;
            case 3:
            	system("cls");
                printf("Lingkaran Gabungan:\n");
                tampilkanLingkaran(gabungan);
                break;
            case 4:
            	system("cls");
                pisahkanLingkaran(gabungan, &mahasiswa, &mahasiswi);
                printf("Lingkaran Mahasiswa:\n");
                tampilkanLingkaran(mahasiswa);
                break;
            case 5:
            	system("cls");
                pisahkanLingkaran(gabungan, &mahasiswa, &mahasiswi);
                printf("Lingkaran Mahasiswi:\n");
                tampilkanLingkaran(mahasiswi);
                break;
            case 6:
            	system("cls");
                printf("Keluar dari program.\n");
                exit(0);
            default:
            	system("cls");
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}

