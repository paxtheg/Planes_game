#include "./utils.h"

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define THIRTEEN 13
#define FOURTYNINE 49
#define FIFTY 50
#define SIXTYNINE 69
#define SEVENTYEIGHT 78
#define EIGHTYTHREE 83
#define EIGHTYSEVEN 87

void SolveTask4(void* info, int nr_avioane, int nr_obstacole, int* x, int* y, int N) {
    // TODO(student) : Stuff

    const char* buf = info;
    int i = 0, j = 0, cnt = 0, k = ONE, q = 0;

    int remaining_planes = nr_avioane;
    for (k = ONE; k <= nr_avioane; k++) {
        const char direction = *(buf + FOUR + cnt);
        const char plane_type = *(buf + FIVE + cnt);
        if (plane_type == FOURTYNINE) {  // if plane type is 1
            for (q = 0; q < nr_obstacole; q++) {
                if (direction == SEVENTYEIGHT) {  // north
                    for (i = 0; i < FOUR; i++) {
                        if (x[q] == *(buf + 0 + cnt) + i) {
                            remaining_planes--;
                        }
                    }
                    if (y[q] == *(buf + TWO + cnt)) {
                        remaining_planes--;
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - TWO + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < THREE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - ONE + i) {
                            remaining_planes--;
                        }
                    }
                    cnt += THIRTEEN;
                }
                if (direction == EIGHTYTHREE) {  // south
                    for (i = 0; i < FOUR; i++) {
                        if (x[q] == *(buf + 0 + cnt) - i) {
                            remaining_planes--;
                        }
                    }
                    if (y[q] == *(buf + TWO + cnt)) {
                        remaining_planes--;
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - TWO + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < THREE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - ONE + i) {
                            remaining_planes--;
                        }
                    }
                    cnt += THIRTEEN;
                }
                if (direction == EIGHTYSEVEN) {  // west
                    if (x[q] == *(buf + 0 + cnt)) {
                        remaining_planes--;
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - TWO + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < THREE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - ONE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < FOUR; i++) {
                        if (y[q] == *(buf + TWO + cnt) + i) {
                            remaining_planes--;
                        }
                    }
                    cnt += THIRTEEN;
                }
                if (direction == SIXTYNINE) {  // east
                    if (x[q] == *(buf + 0 + cnt)) {
                        remaining_planes--;
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - TWO + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < THREE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - ONE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < FOUR; i++) {
                        if (y[q] == *(buf + TWO + cnt) - i) {
                            remaining_planes--;
                        }
                    }
                    cnt += THIRTEEN;
                }
            }
        }
        if (plane_type == FIFTY) {  // if plane type is 2
            for (q = 0; q < nr_obstacole; q++) {
                if (direction == SEVENTYEIGHT) {  // north
                    for (i = 0; i < FIVE; i++) {
                        if (x[q] == *(buf + 0 + cnt) + i) {
                            remaining_planes--;
                        }
                    }
                    if (y[q] == *(buf + TWO + cnt)) {
                        remaining_planes--;
                    }
                    for (i = 0; i < THREE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - ONE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < SEVEN; i++) {
                        if (y[q] == *(buf + TWO + cnt) - THREE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - TWO + i) {
                            remaining_planes--;
                        }
                    }
                    cnt += THIRTEEN;
                }
                if (direction == EIGHTYTHREE) {  // south
                    for (i = 0; i < FIVE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - i) {
                            remaining_planes--;
                        }
                    }
                    if (y[q] == *(buf + TWO + cnt)) {
                        remaining_planes--;
                    }
                    for (i = 0; i < THREE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - ONE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < SEVEN; i++) {
                        if (y[q] == *(buf + TWO + cnt) - THREE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - TWO + i) {
                            remaining_planes--;
                        }
                    }
                    cnt += THIRTEEN;
                }
                if (direction == EIGHTYSEVEN) {  // west
                    if (x[q] == *(buf + 0 + cnt)) {
                        remaining_planes--;
                    }
                    for (i = 0; i < THREE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - ONE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < SEVEN; i++) {
                        if (x[q] == *(buf + 0 + cnt) - THREE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - TWO + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (y[q] == *(buf + TWO + cnt) + i) {
                            remaining_planes--;
                        }
                    }
                    cnt += THIRTEEN;
                }
                if (direction == SIXTYNINE) {  // east
                    if (x[q] == *(buf + 0 + cnt)) {
                        remaining_planes--;
                    }
                    for (i = 0; i < THREE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - ONE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < SEVEN; i++) {
                        if (x[q] == *(buf + 0 + cnt) - THREE + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (x[q] == *(buf + 0 + cnt) - TWO + i) {
                            remaining_planes--;
                        }
                    }
                    for (i = 0; i < FIVE; i++) {
                        if (y[q] == *(buf + TWO + cnt) - i) {
                            remaining_planes--;
                        }
                    }
                    cnt += THIRTEEN;
                }
            }
        }
    }
    if (remaining_planes >= 0) {
        printf("%d", remaining_planes);
    } else {
        printf("0");
    }
}
