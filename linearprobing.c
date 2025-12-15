#include <stdio.h>

#define size 10

int hashtable[size];

void init() {
    int i;
    for (i = 0; i < size; i++)
        hashtable[i] = -1;
}

void insert(int key) {
    int index = key % size;
    int i = 0;

    // Linear probing
    while (hashtable[(index + i) % size] != -1) {
        i++;
        if (i == size) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }

    int newindex = (index + i) % size;
    hashtable[newindex] = key;
    printf("Inserted %d at index %d\n", key, newindex);
}

void display() {
    int i;
    printf("\nHashtable:\n");
    for (i = 0; i < size; i++) {
        printf("%d ---> %d\n", i, hashtable[i]);
    }
}

int main() {
    int keys[] = {23, 43, 56, 34, 87};
    int i, n = 5;

    init(); 

    for (i = 0; i < n; i++) {
        insert(keys[i]);
    }

    display();
    return 0;
}

