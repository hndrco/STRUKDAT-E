/* Nama = Hendrico Edhent Surya Pratama
     Npm = 23081010070
  */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *nxt;
};
typedef struct node node;

void inputPertama(node **head);
void inputData(node **head);
void inputAkhir(node **head);
void hpsData(node **head);
void hpsPertama(node **head);
void hpsData(node **head);
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
        fflush(stdin);
        scanf("%c", &ch);

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
        	tampilanData(head);
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

//=====================================================
void inputPertama(node **head)
{
    int num;
    node *pNew;

    system("cls");
    printf("Inputkan nilai : ");
    fflush(stdin);
    scanf("%d", &num);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = num;
        pNew->nxt = *head;
        *head = pNew;
    }
    else
    {
        printf("Kesalahan/Gagal");
        getch();
    }
}
//=================================================
void inputData(node **head)
{
    int pos, num;
    node *pNew, *pCur;

    system("cls");
    tampilanData(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nNilai : ");
    fflush(stdin);
    scanf("%d", &num);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos)
    {
        pCur = pCur->nxt;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL)
    {
        printf("\nNode tidak ditemukan\n");
        getch();
    }
    else if (pNew == NULL)
    {
        printf("\Kesalahan/Gagal\n");
        getch();
    }
    else
    {
        pNew->data = num;
        pNew->nxt = pCur->nxt;
        pCur->nxt = pNew;
    }
}
//==================================
void inputAkhir(node **head)
{
    int num;
    node *pNew, *pCur;

    system("cls");
    printf("Input nilai : ");
    fflush(stdin);
    scanf("%d", &num);

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL)
    {
        printf("Kesalahan/Gagal");
        getch();
        return;
    }

    pNew->data = num;
    pNew->nxt = NULL;

    if (*head == NULL)
    {
        *head = pNew;
    }
    else
    {
        pCur = *head;
        while (pCur->nxt != NULL)
        {
            pCur = pCur->nxt;
        }
        pCur->nxt = pNew;
    }
}
//=====================================
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
    fflush(stdin);
    scanf("%d", &ch);

    if(ch == 1) {
    	hpsAwal(head);
    	return;
	}
	else if (ch == 2) {
		hpsTengah(head);
		return;
	}
	else if (ch == 3) {
		hpsAkhir(head);
		return;
	}
	else {
		printf("Input salah!");
		return;
	}
}
//====================================================
void hpsAwal(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->nxt;
    free(temp);
    printf("Node Pertama berhasil dihapus.\n");
}
//===================================================
void hpsTengah(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    tampilanData(*head);

    int data;
    printf("\nMasukkan nilai data yang ingin dihapus : ");
    fflush(stdin);
    scanf("%d", &data);

    node *pCur = *head, *pPrev = NULL;

    while (pCur != NULL && pCur->data != data)
    {
        pPrev = pCur;
        pCur = pCur->nxt;
    }

    if (pCur == NULL)
    {
        printf("Data %d tidak ditemukan\n", data);
        return;
    }

    if (pPrev == NULL)
    {
        *head = pCur->nxt;
    }
    else
    {
        pPrev->nxt = pCur->nxt;
    }
    free(pCur);
    printf("Node dengan nilai %d berhasil dihapus.\n", data);
}
//=================================================
void hpsAkhir(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    node *pCur = *head, *pPrev = NULL;

    if (pCur->nxt == NULL)
    {
        free(pCur);
        *head = NULL;
        printf("Node di akhir berhasil dihapus.\n");
        return;
    }

    while (pCur->nxt != NULL)
    {
        pPrev = pCur;
        pCur = pCur->nxt;
    }

    pPrev->nxt = NULL;
    free(pCur);
    printf("Node di akhir berhasil dihapus.\n");
}
//===================================================
node *crData(node *head, int num)
{
    node *pCur = head;
    while (pCur != NULL)
    {
        if (pCur->data == num)
        {
            return pCur;
        }
        pCur = pCur->nxt;
    }
    return NULL;
}
//==================================================
void tampilanData(node *head)
{
    node *pWalker = head;

    system("cls");
    printf("Data dalam linked list :\n");
    if (pWalker == NULL)
    {
        printf("Linked list kosong\n");
    }
    else
    {
        while (pWalker != NULL)
        {
            printf("%d -> ", pWalker->data);
            pWalker = pWalker->nxt;
        }
        printf("NULL\n");
    }
}
//============================================================
int htgjmlhData(node *head)
{
	system("cls");
    tampilanData(head);
    int cnt = 0;
    node *pWalker = head;

    while (pWalker != NULL)
    {
        cnt++;
        pWalker = pWalker->nxt;
    }

    return cnt;
}

//================================================s
int jmlhData(node *head)
{
	system("cls");
    tampilanData(head);
    int sum = 0;
    node *pWalker = head;

    while (pWalker != NULL)
    {
        sum += pWalker->data;
        pWalker = pWalker->nxt;
    }

    return sum;
}

