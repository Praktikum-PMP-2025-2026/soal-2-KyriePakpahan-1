/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : Kyrie Eleison Jacob Pakpahan (13224006)
 *   Nama File           : soal2.c
 *   Deskripsi           : Program yang berguna untuk mengurutkan dua buah list terurut naik, kemudian menggabungkan kedua list tersebut terurut naik.
 *                          Program ini menggunakan linked list untuk menyimpan data, kemudian mengurutkan kedua list tersebut menggunakan merge sort, lalu menggabungkan kedua list tersebut menggunakan merge procedure.
 * 
 */

/*
Format Input

N a1 ... aN M b1 ... bM 
*/

/*Format Output
Jika list tidak kosong
MERGED ... 

Jika list kosong
MERGED EMPTY
*/

/*
Testcase Input
3 1 4 7 4 2 3 6 8

Testcase Output
MERGED 1 2 3 4 6 7 8 
*/

#include <stdio.h>
#include <stdlib.h>

// struktur data untuk menyimpan node pada linked list
typedef struct NodeList {
    int data;
    struct NodeList *next;
} NodeList;

// fungsi untuk menginisialisasi list
void init_list(NodeList **head) {
    *head = NULL;
}

// fungsi untuk menambahkan node baru ke dalam list
void add_node(NodeList **head, int data) {
    NodeList *new_node = (NodeList *)malloc(sizeof(NodeList));
    if (!new_node) {
        printf("Error: Alokasi memori gagal.\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    NodeList *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}


// fungsi untuk menggabungkan dua list menjadi satu list yang terurut naik
NodeList* merge_sorted_lists(NodeList *list1, NodeList *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    NodeList *merged_head = NULL;
    NodeList *merged_tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        NodeList *temp = NULL;
        if (list1->data <= list2->data) {
            temp = list1;
            list1 = list1->next;
        } else {
            temp = list2;
            list2 = list2->next;
        }
        temp->next = NULL;

        if (merged_head == NULL) {
            merged_head = temp;
            merged_tail = temp;
        } else {
            merged_tail->next = temp;
            merged_tail = temp;
        }
    }

    // Attach the remaining nodes
    if (list1 != NULL) {
        merged_tail->next = list1;
    } else if (list2 != NULL) {
        merged_tail->next = list2;
    }

    return merged_head;
}




// fungsi untuk memprint list yang sudah terurut naik
void print_list(NodeList *head) {
    if (head == NULL) {
        printf("MERGED EMPTY\n");
        return;
    }
    printf("MERGED ");
    NodeList *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main (){
    NodeList *list1, *list2, *merged_list, *merged_sorted;
    init_list(&list1);
    init_list(&list2);

    int N, M, data;
    
    // menghandle input untuk dua list dalam satu kali input
    if (scanf("%d", &N) != 1){
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &data) != 1){   
            return 0;
        }
        add_node(&list1, data);
    }

    if (scanf("%d", &M) != 1){
        return 0;
    }
    for (int i = 0; i < M; i++) {
        if (scanf("%d", &data) != 1){
            return 0;
        }
        add_node(&list2, data);
    }
    
    merged_list = merge_sorted_lists(list1, list2);
    print_list(merged_list);


    return 0;
}
