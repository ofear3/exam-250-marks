#include <stdio.h>
#include <limits.h>

int timer = 0;


int LRU(int time[], int no_f) {
    int i, pos = 0;
    int mt = INT_MAX;

    for (i = 0; i < no_f; i++) {
        if (time[i] < mt) {
            mt = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_f, no_p, i, j;

    printf("Enter number of frames: ");
    scanf("%d", &no_f);

    printf("Enter number of pages: ");
    scanf("%d", &no_p);

    int frame[no_f], page[no_p], time[no_f];
    int hit = 0, fault = 0;

    for (i = 0; i < no_f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("Enter page reference string:\n");
    for (i = 0; i < no_p; i++) {
        scanf("%d", &page[i]);
    }

    for (i = 0; i < no_p; i++) {
        int found = 0;

        for (j = 0; j < no_f; j++) {
            if (frame[j] == page[i]) {
                hit++;
                timer++;
                time[j] = timer;
                found = 1;
                break;
            }
        }


        if (!found) {
            int pos = -1;


            for (j = 0; j < no_f; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {
                pos = LRU(time, no_f);
            }

            frame[pos] = page[i];
            timer++;
            time[pos] = timer;
            fault++;
        }


    }

    printf("\nTotal Hits = %d\n", hit);
    printf("Total Page Faults = %d\n", fault);

    return 0;
}
