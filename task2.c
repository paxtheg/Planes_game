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

void SolveTask2(void* info, int nr_avioane, int N, char** mat) {
    // TODO(student) : Stuff
    const char* buf = info;
    int i = 0, j = 0, cnt = 0, k = ONE;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            mat[i][j] = '.';

    for (k = ONE; k <= nr_avioane; k++) {
        const char direction = *(buf + FOUR + cnt);
        const char plane_type = *(buf + FIVE + cnt);
        if (plane_type == FOURTYNINE) {  // if plane type is 1
            if (direction == SEVENTYEIGHT) {  // north
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < FIVE; i++)
                    mat[*(buf + 0 + cnt) + ONE][*(buf + TWO + cnt) - TWO + i] = '*';
                mat[*(buf + 0 + cnt) + TWO][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < THREE; i++)
                    mat[*(buf + 0 + cnt) + THREE][*(buf + TWO + cnt) - ONE + i] = '*';
                cnt += THIRTEEN;
            } else if (direction == EIGHTYTHREE) {  // south
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < FIVE; i++)
                    mat[*(buf + 0 + cnt) - ONE][*(buf + TWO + cnt) - TWO + i] = '*';
                mat[*(buf + 0 + cnt) - TWO][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < THREE; i++)
                    mat[*(buf + 0 + cnt) - THREE][*(buf + TWO + cnt) - ONE + i] = '*';
                cnt += THIRTEEN;
            } else if (direction == EIGHTYSEVEN) {  // west
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < FIVE; i++)
                    mat[*(buf + 0 + cnt) - TWO + i][*(buf + TWO + cnt) + ONE] = '*';
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt) + TWO] = '*';
                for (i = 0; i < THREE; i++)
                    mat[*(buf + 0 + cnt) - ONE + i][*(buf + TWO + cnt) + THREE] = '*';
                cnt += THIRTEEN;
            } else if (direction == SIXTYNINE) {  // east
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < FIVE; i++)
                    mat[*(buf + 0 + cnt) - TWO + i][*(buf + TWO + cnt) - ONE] = '*';
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt) - TWO] = '*';
                for (i = 0; i < THREE; i++)
                    mat[*(buf + 0 + cnt) - ONE + i][*(buf + TWO + cnt) - THREE] = '*';
                cnt += THIRTEEN;
            }
        } else if (plane_type == FIFTY) {  // if plane type is 2
            if (direction == SEVENTYEIGHT) {  // north
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < THREE; i++)
                    mat[*(buf + 0 + cnt) + ONE][*(buf + TWO + cnt) - ONE + i] = '*';
                for (i = 0; i < SEVEN; i++)
                    mat[*(buf + 0 + cnt) + TWO][*(buf + TWO + cnt) - THREE + i] = '*';
                mat[*(buf + 0 + cnt) + THREE][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < FIVE; i++)
                    mat[*(buf + 0 + cnt) + FOUR][*(buf + TWO + cnt) - TWO + i] = '*';
                cnt += THIRTEEN;
            } else if (direction == EIGHTYTHREE) {  // south
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < THREE; i++)
                    mat[*(buf + 0 + cnt) - ONE][*(buf + TWO + cnt) - ONE + i] = '*';
                for (i = 0; i < SEVEN; i++)
                    mat[*(buf + 0 + cnt) - TWO][*(buf + TWO + cnt) - THREE + i] = '*';
                mat[*(buf + 0 + cnt) - THREE][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < FIVE; i++)
                    mat[*(buf + 0 + cnt) - FOUR][*(buf + TWO + cnt) - TWO + i] = '*';
                cnt += THIRTEEN;
            } else if (direction == EIGHTYSEVEN) {  // west
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < THREE; i++)
                    mat[*(buf + 0 + cnt) - ONE + i][*(buf + TWO + cnt) + ONE] = '*';
                for (i = 0; i < SEVEN; i++)
                    mat[*(buf + 0 + cnt) - THREE + i][*(buf + TWO + cnt) + TWO] = '*';
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt) + THREE] = '*';
                for (i = 0; i < FIVE; i++)
                    mat[*(buf + 0 + cnt) - TWO + i][*(buf + TWO + cnt) + FOUR] = '*';
                cnt += THIRTEEN;
            } else if (direction == SIXTYNINE) {  // east
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt)] = '*';
                for (i = 0; i < THREE; i++)
                    mat[*(buf + 0 + cnt) - ONE + i][*(buf + TWO + cnt) - ONE] = '*';
                for (i = 0; i < SEVEN; i++)
                    mat[*(buf + 0 + cnt) - THREE + i][*(buf + TWO + cnt) - TWO] = '*';
                mat[*(buf + 0 + cnt)][*(buf + TWO + cnt) - THREE] = '*';
                for (i = 0; i < FIVE; i++)
                    mat[*(buf + 0 + cnt) - TWO + i][*(buf + TWO + cnt) - FOUR] = '*';
                cnt += THIRTEEN;
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%c", mat[i][j]);
        printf("\n");
    }
}
