Andra şi Ştefan, doi studenţi la ACS, s-au hotărât să se joace faimosul joc de strategie, Avioanele. Fiind foarte competitivi din fire, aceştia au decis să complice puţin regulile jocului. Astfel, fiecare dintre ei o să deseneze nr_avioane avioane şi nr_obstacole obstacole, într-o matrice de dimensiune N * N.

Despre Avioane
Avioanele pot fi de 2 tipuri:
...*...  ....*....
.*****.  ...***...
...*...  .*******.
..***..  ....*....
         ..*****..


Ele pot avea capul îndreptat în 4 direcţii, N, S, W si E.



Ca lucrurile să fie şi mai complicate, fiecare avion o să aibă o anumită viteză v. Astfel, la un moment de timp T, un avion o să se deplaseze cu v * T unități în direcţia deja stabilită.

Despre Obstacole
Obstacolele sunt de dimensiune 1 x 1 şi sunt alese pentru a încurca adversarul.

După ce fiecare dintre ei îşi desenează pe foaie avioanele, aceştia realizează că nu mai au timp să şi înceapă jocul. Ştiind că are o strategie bună, Ştefan doreşte să îşi păstrează informaţiile despre avioanele lui. Astfel, el stochează datele într-un vector generic void *info, păstrând pentru fiecare avion, în ordine, următoarele informaţii:

linia, respectiv coloana pe care se găseşte capul avionului, păstrate pe câte doi octeţi fiecare (atât linia, cât şi coloana sunt numere naturale din intervalul [0, N - 1])
direcţia spre care se deplasează avionul (N, S, E, W), păstrată pe un octet
patru caractere care reprezintă codul avionului, astfel:
primul caracter reprezintă tipul avionului(‘1’, ‘2’)
următoarele trei caractere reprezintă codul aeroportului din care şi-au imaginat fiecare că o să zboare avionul
viteza de deplasare (v poziţii/secundă), păstrată pe patru octeţi.
Din păcate pentru el, Andra reușește să obţină acest vector, dar are nevoie de ajutorul vostru pentru a extrage informaţiile necesare.

Task 1 - 20 de puncte
void SolveTask1(void *info, int nr_avioane)
Funcţia primeşte ca parametri vectorul descris anterior, numărul de avioane și afișează pe ecran informațiile despre fiecare avion în ordinea următoare:

pe prima linie 2 numere naturale care reprezintă coordonatele la care se găseşte capul avionului(linia, respectiv coloana) ex. : (1, 3)
pe a doua linie un caracter care reprezintă direcţia de deplasare a avionului(‘N’, ‘S’, ‘E’, ‘V’)
pe a treia linie 4 caractere care reprezintă codul aeroportului
pe ultima linie un număr natural care reprezintă viteza de deplasare a avionului
Între 2 avioane consecutive se va lăsa un rând gol.

Input:
1		// numărul task-ului
2		// numărul de avioane din vector
 
0 2 N		// linia, coloana şi direcţia primului avion
1BUC		// codul primului avion
1		// viteza primului avion
 
6 4 W		
2AMS 		
2
Output:
(0, 2)
N
1BUC
1

(6, 4)
W
2AMS
2

Task 2 - 30 de puncte
void SolveTask2(void *info, int nr_avioane, int N, char **mat)
Funcţia primeşte ca parametri vectorul descris anterior, numărul de avioane, dimensiunea matricii de caractere mat care trebuie completată cu ‘*’ sau ‘.’ astfel: dacă la linia i şi coloana j se găseşte un avion, atunci mat[i][j] = ‘*’, în caz contrar mat[i][j] = ‘.’.

Se garantează că toate avioanele se găsesc integral în interiorul matricii.
Input:
2
2
 
0 2 N
1BUC
1
 
6 4 W
2AMS
3
 
10		//valoarea lui N    
Output:
..*.......
*****.....
..*.......
.***..*...
......*.*.
.....**.*.
....*****.
.....**.*.
......*.*.
......*...


Task 3 - 50 de puncte
void SolveTask3(void *info, int nr_avioane)
Funcţia primeşte ca parametri vectorul descris anterior, numărul de avioane şi sortează avioanele astfel:

crescător după tipul avionului (1 sau 2)
la tipuri egale, descrescător lexicografic după codul aeroportului(ex. BUD < OTP)
la coduri egale, crescător după viteză
După ce au fost sortate, informaţiile despre avioane o să fie afişate la fel ca la Task-ul 1.

Sortarea o să se facă folosind doar funcţia qsort.

Input:
3
6

0 2 N
1BUC
1

6 4 W
2AMS
3

12 20 N
1CDB
5

13 25 S
1PRC
10

20 4 W
2BUC
7

45 54 E
1BUC
4
Output:
(13, 25)
S
1PRC
10

(12, 20)
N
1CDB
5

(0, 2)
N
1BUC
1

(45, 54)
E
1BUC
4

(20, 4)
W
2BUC
7

(6, 4)
W
2AMS
3
Task 4 - 50 de puncte
void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N)
Funcţia primeşte ca parametri vectorul descris anterior, numărul de avioane, numărul de obstacole puse de Andra, 2 vectori x și y care păstrează linia, respectiv coloana unde se găsesc obstacolele şi dimensiunea matricii. Funcţia afişează numărul de avioane care ar putea să se deplaseze până la ieşirea de pe hartă în siguranţă (pe tot traseul nu au lovit niciun obstacol)

Input:
4
2

0 2 N
1BUC
1

6 4 W
2AMS
3

4          // numărul de obstacole 
1 8      // linia şi coloana primului obstacol
5 1
7 7
9 3

10
Output:
1

Bonus: Task 5 - 50 de puncte
void SolveTask5(void *info, int nr_avioane, int T, int nr_pct_coord, int *X, int *Y, int N)
Funcţia primeşte ca parametri vectorul descris anterior, numărul de avioane, un timp T, nr_pct_coord coordonate care sunt păstrate în vectorii X şi Y (X[0] şi Y[0] reprezintă linia, respectiv coloana primul obstacol) şi dimensiunea matricii. Funcţia afişează pentru fiecare moment de timp de la 0 la T câte avioane se află în punctele păstrate în cei 2 vectori descrişi anterior.

Un avion se mişcă cu v poziţii în fiecare moment de timp, în direcţia sa de deplasare.
Input:
5
2

0 2 N
1OTP
1

6 4 W
2LTN
3

2          // T     

5          // nr_pct_coord
1 4
5 1
7 7
6 4
9 6

10
Output:
0: 2
1: 1
2: 0

Precizări suplimentare
N < = 100
nr_avioane < = 50
nr_obstacole < = 20
nr_pct_coord < = 20
T < = 50
Pentru primele 4 task-uri se garantează faptul că avioanele se află complet în matrice.
