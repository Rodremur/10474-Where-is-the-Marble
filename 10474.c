/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 10474 - Where is the Marble?
 * Fecha: 02-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *A, int low, int high, int key);
int previousSearch(int m, int *A, int key);
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[])
{
	int *marbles;
	marbles = (int*)malloc(10000*sizeof(int*));
	int n = -1, q = -1, cse = 0;
	int i, key, result;
	while (n != 0 && q != 0) {
		cse += 1;
		scanf("%d %d", &n, &q);
		for (i=0; i<n; i++) {
			scanf("%d", &marbles[i]);
		}
		qsort(marbles, n, sizeof(int), compare);
		if (n!=0 && q !=0){
            printf("CASE# %d:\n", cse);
		}
		for (i=0; i<q; i++) {
			scanf("%d", &key);
			result = binarySearch(marbles, 0, n-1, key);
			if (result == -1) {
				printf("%d not found\n", key);
			} else {
				printf("%d found at %d\n", key, result+1);
			}

		}
	}
	return 0;
}

int binarySearch(int *A, int low, int high, int key) {
    if (low <= high) {
        int mid = (high+low)/2;
        if (key == A[mid]) {
            if (key == A[mid-1]){
                return previousSearch(mid-1, A, key);
            } else {
                return mid;
            }
        }
        else if (key < A[mid]) {
            binarySearch(A, low, mid-1, key);
        }
        else {
            binarySearch(A, mid+1, high, key);
        }
    } else {
    return -1;
    }
}

int previousSearch(int m, int *A, int key) {
    if (key == A[m-1]) {
        return previousSearch(m-1, A, key);
    } else {
        return m;
    }
}
