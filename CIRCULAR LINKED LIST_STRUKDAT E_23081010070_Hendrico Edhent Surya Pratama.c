#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node *nxt;
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

int main()
{
    node *head = NULL;
    char ch;
    int num;

    do
    {
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
        scanf(" %c", &ch);

        switch (ch)
        {
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
            printf("\nMasukkan data yang dicari : ");
            scanf("%d", &num);
            node *hasil = crData(head, num);
            if (hasil != NULL)
            {
                printf("Data %d ditemukan\n", hasil->data);
            }
            else
            {
                printf("Data %d tidak ditemukan\n", num);
            }
            getch();
            break;
        case '7':
            printf("\nJumlah data dalam linked list : %d\n", htgjmlhData(head));
            getch();
            break;
        case '8':
            printf("\nHasil penjumlahan semua nilai : %d\n", jmlhData(head));
            getch();
            break;
        }

    } while (ch != 'x');

    return 0;
}

void inputPertama(node **head)
{
    int num;
    node *pNew, *pCur;

    system("cls");
    printf("Inputkan nilai : ");
    scanf("%d", &num);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = num;
        if (*head == NULL)
        {
            *head = pNew;
            pNew->nxt = *head;
        }
        else
        {
            pCur = *head;
            while (pCur->nxt != *head)
            {
                pCur = pCur->nxt;
            }
            pNew->nxt = *head;
            pCur->nxt = pNew;
            *head = pNew;
        }
    }
    else
    {
        printf("Kesalahan/Gagal");
        getch();
    }
}

void inputData(node **head)
{
    int pos, num;
    node *pNew, *pCur;

    system("cls");
    tampilanData(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    scanf("%d", &pos);
    printf("\nNilai : ");
    scanf("%d", &num);

    pCur = *head;
    while (pCur->data != pos && pCur->nxt != *head)
    {
        pCur = pCur->nxt;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur->nxt == *head && pCur->data != pos)
    {
        printf("\nNode tidak ditemukan\n");
        getch();
    }
    else if (pNew == NULL)
    {
        printf("Kesalahan/Gagal");
        getch();
    }
    else
    {
        pNew->data = num;
        pNew->nxt = pCur->nxt;
        pCur->nxt = pNew;
    }
}

void inputAkhir(node **head)
{
    int num;
    node *pNew, *pCur;

    system("cls");
    printf("Input nilai : ");
    scanf("%d", &num);

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL)
    {
        printf("Kesalahan/Gagal");
        getch();
        return;
    }

    pNew->data = num;

    if (*head == NULL)
    {
        *head = pNew;
        pNew->nxt = *head;
    }
    else
    {
        pCur = *head;
        while (pCur->nxt != *head)
        {
            pCur = pCur->nxt;
        }
        pCur->nxt = pNew;
        pNew->nxt = *head;
    }
}

void hpsData(node **head)
{
    int ch;

    system("cls");
    tampilanData(*head);
    printf("\nPilih opsi hapus :\n");
    printf("1. Hapus nilai Pertama\n");
    printf("2. Hapus nilai (Tengah)\n");
    printf("3. Hapus nilai Akhir\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &ch);

    if (ch == 1)
        hpsAwal(head);
    else if (ch == 2)
        hpsTengah(head);
    else if (ch == 3)
        hpsAkhir(head);
    else
        printf("Input salah!");
}

void hpsAwal(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    node *pCur = *head;

    if (pCur->nxt == *head)
    {
        free(pCur);
        *head = NULL;
    }
    else
    {
        node *pLast = *head;
        while (pLast->nxt != *head)
        {
            pLast = pLast->nxt;
        }
        *head = (*head)->nxt;
        pLast->nxt = *head;
        free(pCur);
    }

    printf("Node pertama berhasil dihapus\n");
}

void hpsTengah(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    int pos;
    printf("Masukkan nilai data yang ingin dihapus: ");
    scanf("%d", &pos);

    node *pCur = *head, *pPrev = NULL;

    if (pCur->nxt == *head)
    {
        printf("List hanya memiliki satu node, gunakan opsi hapus pertama atau akhir\n");
        return;
    }

    do
    {
        if (pCur->data == pos)
            break;
        
        pPrev = pCur;
        pCur = pCur->nxt;
    } while (pCur != *head);

    if (pCur == *head && pPrev == NULL)
    {
        printf("\nNode dengan nilai %d tidak ditemukan\n", pos);
        return;
    }

    pPrev->nxt = pCur->nxt;
    free(pCur);
    printf("\nNode dengan nilai %d berhasil dihapus\n", pos);
}

void hpsAkhir(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    node *pCur = *head, *pPrev = NULL;

    if (pCur->nxt == *head)
    {
        free(pCur);
        *head = NULL;
    }
    else
    {
        while (pCur->nxt != *head)
        {
            pPrev = pCur;
            pCur = pCur->nxt;
        }
        pPrev->nxt = *head;
        free(pCur);
    }

    printf("Node terakhir berhasil dihapus\n");
}

node *crData(node *head, int num)
{
    if (head == NULL)
        return NULL;

    node *pCur = head;

    do
    {
        if (pCur->data == num)
            return pCur;

        pCur = pCur->nxt;
    } while (pCur != head);

    return NULL;
}

void tampilanData(node *head)
{
    if (head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    node *pCur = head;

    printf("Data dalam linked list:\n");
    do
    {
        printf("%d -> ", pCur->data);
        pCur = pCur->nxt;
    } while (pCur != head);

    printf("(kembali ke head)\n");
}

int htgjmlhData(node *head)
{
    if (head == NULL)
        return 0;

    int count = 0;
    node *pCur = head;

    do
    {
        count++;
        pCur = pCur->nxt;
    } while (pCur != head);

    return count;
}

int jmlhData(node *head)
{
    if (head == NULL)
        return 0;

    int total = 0;
    node *pCur = head;

    do
    {
        total += pCur->data;
        pCur = pCur->nxt;
    } while (pCur != head);

    return total;
}

