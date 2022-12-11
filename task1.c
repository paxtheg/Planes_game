#include "./utils.h"

#define ONE 1
#define THREE 3

void SolveTask1(void* info, int nr_avioane) {
    // TODO(student) : Stuff
    unsigned char* buf = info;

    int i = 0, k = ONE;
    for (k = ONE; k <= nr_avioane; k++) {
        printf("(%hi, ", *(buf + i));  // prints the line
        i += sizeof(short int);
        printf("%hi)\n", *(buf + i));  // prints the column
        i += sizeof(short int);
        printf("%c\n", *(buf + i));  // prints the direction
        i += sizeof(unsigned char);
        printf("%c", *(buf + i));  // prints the plane type
        for (int j = 0; j < THREE; j++) {
            i += sizeof(unsigned char);
            printf("%c", *(buf + i));
        }  // prints the plane destination
        // overall, the previous two comments point out to the
        // printing of the airport code
        printf("\n");
        i += sizeof(unsigned char);
        printf("%d\n", *(buf + i));  // prints the velocity
        printf("\n");
        i += sizeof(int);
    }
}
