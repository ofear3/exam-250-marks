#include <stdio.h>

int main() {
    int no_f, no_p,i,j;

    printf("Enter number of frames: ");
    scanf("%d", &no_f);

    printf("Enter number of pages: ");
    scanf("%d", &no_p);

    int frame[no_f], page[no_p];
    int hit = 0, fault = 0;
    int index = 0;

    for ( i = 0; i < no_f; i++) {
        frame[i] = -1;
    }

    printf("Enter page reference string:\n");
    for (i = 0; i < no_p; i++) {
        scanf("%d", &page[i]);
    }

    for (i = 0; i < no_p; i++) {
        int found = 0;

        for ( j = 0; j < no_f; j++) {
            if (frame[j] == page[i]) {
                hit++;
                found = 1;
                break;
            }
        }

        if (!found) {
            frame[index] = page[i];
            index = (index + 1) % no_f;
            fault++;
        }
    }

    printf("\nTotal Hits = %d\n", hit);
    printf("Total Page Faults = %d\n", fault);

    return 0;
}
