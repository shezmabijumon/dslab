#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* link;
}list;

list* getnode() {
    list* n = (list*)malloc(sizeof(list));
    n->link = NULL;
    return n;
}

int hashfunction(int key) {
    return key % 10;
}

void linearprobe(int hashtable[], int data[], int n) {
    int i, j, h;
    printf("Linear Probing:\n");
    for (i = 0; i < n; i++) {
        h = hashfunction(data[i]);
        for (j = 0; j < 10; j++) {
            if (hashtable[(h + j) % 10] == -1) {
                hashtable[(h + j) % 10] = data[i];
                break;
            }
            else if (hashtable[(h + j) % 10] == data[i]) {
                break;
            }
        }
        if (j == 10) {
            printf("Hashing unsuccessful. Overflow occured.\n");
            break;
        }
    }
    printf("Successfully completed hashing.\n");
}

void chaining(list* hashlinktable[], int data[], int n) {
    int i, j, h;
    list* ptr;
    printf("Chaining:\n");
    for (i = 0; i < n; i++) {
        h = hashfunction(data[i]);
        if (hashlinktable[h] == NULL) {
            hashlinktable[h] = getnode();
            hashlinktable[h]->data = data[i];
        }
        else {
            ptr = hashlinktable[h];
            while (ptr->link != NULL)
                ptr = ptr->link;
            ptr->link = getnode();
            ptr->link->data = data[i];       
        }
    }
    printf("Successfully completed hashing.\n");
}

void displayHashtable(int hashtable[]) {
    int i;
    printf("Hashtable :\nIndex\tKey\n");
    for (i = 0; i < 10; i++) {
        if (hashtable[i] != -1)
            printf("%d:\t%d\n", i, hashtable[i]);
        else 
            printf("%d:\n", i);
    }
    printf("\n");
}

void displayHashlinktable(list* hashlinktable[]) {
    int i;
    list* ptr;
    printf("Hashlinktable :\nIndex\tKey\n");
    for (i = 0; i < 10; i++) {
        printf("%d:\t", i);
        if (hashlinktable[i] == NULL)
            printf("EMPTY\n");
        else {
            ptr = hashlinktable[i];
            while (ptr != NULL) {
                printf("%d\t", ptr->data);
                ptr = ptr->link;
            }
            printf("\n");
        }
    }
}

int main(void) {
    list* hashlinktable[25];
    int hashtable[25], data[25], n, i;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    printf("Enter the keys: ");
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);
    for (i = 0; i < 10; i++) {
        hashtable[i] = -1;
        hashlinktable[i] = NULL;
    }
    linearprobe(hashtable, data, n);
    displayHashtable(hashtable);
    chaining(hashlinktable, data, n);
    displayHashlinktable(hashlinktable);
}