#include "./utils.h"

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define THIRTEEN 13
#define FOURTYNINE 49
#define FIFTY 50

/*
sortare crescator dupa tip
    pentru tipuri egale, descrescator dupa Codul Aeroportului
        pentru coduri egale, crescator dupa viteza
*/

int compare_plane_types(const void* a, const void* b) {
    const char* plane_a = a, * plane_b = b;
    const char plane_type_a = *(plane_a + FIVE);
    const char plane_type_b = *(plane_b + FIVE);
    if (plane_type_a < plane_type_b)
        return -1;
    if (plane_type_a > plane_type_b)
        return 1;
    return 0;
}

int compare_plane_codes(const void* a, const void* b) {
    const char* plane_a = a, * plane_b = b;
    const char plane_a_code_1 = *(plane_a + SIX);
    const char plane_a_code_2 = *(plane_a + SEVEN);
    const char plane_a_code_3 = *(plane_a + EIGHT);
    const char plane_b_code_1 = *(plane_b + SIX);
    const char plane_b_code_2 = *(plane_b + SEVEN);
    const char plane_b_code_3 = *(plane_b + EIGHT);

    if (plane_a_code_1 == plane_b_code_1) {
        if (plane_a_code_2 == plane_b_code_2) {
            if (plane_a_code_3 == plane_b_code_3) {
                return 0;
            } else if (plane_a_code_3 > plane_b_code_3) {
                return -1;
            } else if (plane_a_code_3 < plane_b_code_3) {
                return 1;
            }
        } else if (plane_a_code_2 > plane_b_code_2) {
            return -1;
        } else if (plane_a_code_2 < plane_b_code_2) {
            return 1;
        }
    } else if (plane_a_code_1 > plane_b_code_1) {
        return -1;
    } else if (plane_a_code_1 < plane_b_code_1) {
        return 1;
    }
}

int compare_plane_velocity(const void* a, const void* b) {
    const char* plane_a = a, * plane_b = b;
    int velocity_a = *(plane_a + NINE);
    int velocity_b = *(plane_b + NINE);
    if (velocity_a < velocity_b) {
        return -1;
    }
    if (velocity_a > velocity_b) {
        return 1;
    }
    return 0;
}

void SolveTask3(void* info, int nr_avioane) {
    unsigned char* buf = info;
    int buf_plane_1_size = 0, buf_plane_2_size = 0;
    int i = 0, k = 0, cnt = 0, airport1_cnt = ONE, airport2_cnt = ONE, same_code_cnt = 0;

    qsort(info, nr_avioane, THIRTEEN, compare_plane_types);
    // planes are sorted by type

    for (k = 1; k <= nr_avioane; k++) {
        const char plane_type = *(buf + FIVE + cnt);
        if (plane_type == FOURTYNINE) {  // if plane type is 1
            buf_plane_1_size++;  // determines how many planes are of type 1
        } else if (plane_type == FIFTY) {  // if plane type is 2
            buf_plane_2_size++;  // determines how many planes are of type 2
        }
        cnt += THIRTEEN;
    }

    qsort(info, buf_plane_1_size, THIRTEEN, compare_plane_codes);
    qsort(info + THIRTEEN * buf_plane_1_size, buf_plane_2_size, THIRTEEN, compare_plane_codes);
    // planes are sorted by both type and airport code
    cnt = 0;

    for (k = ONE; k <= nr_avioane; k++) {
        const char plane_type = *(buf + FIVE + cnt);
        const char plane_code_1 = *(buf + SIX + cnt);
        // first letter of the plane code
        const char plane_code_2 = *(buf + SEVEN + cnt);
        // second letter of the plane code
        const char plane_code_3 = *(buf + EIGHT + cnt);
        // third letter of the plane code
        const char next_plane_code_1 = *(buf + SIX + THIRTEEN + cnt);
        // first letter of the code of the the second plane
        const char next_plane_code_2 = *(buf + SEVEN + THIRTEEN + cnt);
        // second letter of the code of the next plane
        const char next_plane_code_3 = *(buf + EIGHT + THIRTEEN + cnt);
        // third letter of the code of the next plane

        if (plane_type == FOURTYNINE) {  // if plane type is 1
            if (plane_code_1 == next_plane_code_1 && plane_code_2 == next_plane_code_2
                && plane_code_3 == next_plane_code_3) {
                // if the current plane and the next plane have the same codes
                airport1_cnt++;  // increment the number of planes with the same code
            } else if (plane_code_3 != next_plane_code_3) {
                // else, if they do not have the same code, do a qsort
                // on the planes with the same code
                qsort(info + same_code_cnt * THIRTEEN, airport1_cnt,
                    THIRTEEN, compare_plane_velocity);
                same_code_cnt += airport1_cnt;  // saves the number of planes with the same code
                airport1_cnt = ONE;
            } else if (plane_code_2 != next_plane_code_2) {
                qsort(info + same_code_cnt * THIRTEEN, airport1_cnt,
                    THIRTEEN, compare_plane_velocity);
                same_code_cnt += airport1_cnt;
                airport1_cnt = ONE;
            } else if (plane_code_1 != next_plane_code_1) {
                qsort(info + same_code_cnt * THIRTEEN, airport1_cnt,
                    THIRTEEN, compare_plane_velocity);
                same_code_cnt += airport1_cnt;
                airport1_cnt = ONE;
            }
        }
        if (plane_type == FIFTY) {  // if plane type is 2
            if (plane_code_1 == next_plane_code_1 && plane_code_2 == next_plane_code_2
                && plane_code_3 == next_plane_code_3) {
                // if the current plane and the next plane have the same codes
                airport2_cnt++;
                // increment the number of planes with the same code
            } else if (plane_code_3 != next_plane_code_3) {
                // else, if they do not have the same code, do a qsort
                // on the planes with the same code
                qsort(info + same_code_cnt * THIRTEEN, airport2_cnt,
                    THIRTEEN, compare_plane_velocity);
                same_code_cnt += airport2_cnt;
                // saves the number of planes with the same code
                airport2_cnt = ONE;
            } else if (plane_code_2 != next_plane_code_2) {
                qsort(info + same_code_cnt * THIRTEEN, airport2_cnt,
                    THIRTEEN, compare_plane_velocity);
                same_code_cnt += airport2_cnt;
                airport2_cnt = ONE;
            } else if (plane_code_1 != next_plane_code_1) {
                qsort(info + same_code_cnt * THIRTEEN, airport2_cnt,
                    THIRTEEN, compare_plane_velocity);
                same_code_cnt += airport2_cnt;
                airport2_cnt = ONE;
            }
        }
        cnt += THIRTEEN;
    }

    // the printing is the same as the one from task1
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
