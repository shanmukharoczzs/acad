#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PAGE_SIZE 4
#define TOTAL_PAGES 8
#define MEMORY_SIZE (PAGE_SIZE * TOTAL_PAGES)

int memory[MEMORY_SIZE] = {0};
int page_table[TOTAL_PAGES] = {0};

void load_page(int page, int frame){
    page_table[page] = frame;
    
    for (int i = 0; i < PAGE_SIZE; i++){
        memory[frame * PAGE_SIZE + i] = page * 10 + i;
    }
    
}

void access_page(int page){
    int frame = page_table[page];

    printf("Page %d is in frame %d frame", page, frame);

    for(int i = 0 ; i < PAGE_SIZE; i++){
        printf("%d ", memory[frame * PAGE_SIZE + i]);
        printf("\n");
    }
}



int main() {
    load_page(0, 0);
    load_page(1,1);
    access_page(0);
    access_page(1);
    

    return 0;
}