#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

//Solves it in O(n)
void kadaneApproach(int arr[],int n){
    int best = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = max(arr[i],sum+arr[i]);
        best = max(best,sum);
    }
    printf("Using the Kadane's Algorithm approach (O(n)) the result is: %d\n", best);
}
//Solves it in O(n^2)
void bruteFroceApproach(int arr[],int n){
    int best = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int k = i; k < n; k++) {
            sum += arr[k];
            best = max(best,sum);
        }
    }
    printf("Using the brute force approach (O(n^2)) the result is: %d\n", best);
}
//Solves it in O(n^3)
void naiveApproach(int arr[],int n){
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int k = i; k < n; k++) {
            int sum = 0;
            for (int j = i; j <= k; j++) {
                sum += arr[j];
            }
            best = max(best,sum);
        }
    }
    printf("Using the naive approach (O(n^3)) the result is: %d\n", best);
}

int* generate_rand_array(int random_seed,int size){
    srand(random_seed); 
    int* arr = (int*)malloc(size * sizeof(int)); 
    if (arr == NULL) { 
        printf("malloc failed.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (74 - (-25) + 1) + (-25); // Thanks to https://www.geeksforgeeks.org/c-rand-function/ for this trick!
    }
    return arr;
}


int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Error\n");
        exit(1);
    }
    int random_seed = atoi(argv[1]);
    int arr_size = atoi(argv[2]);
    int* arr = generate_rand_array(random_seed,arr_size);
    naiveApproach(arr,arr_size);
    bruteFroceApproach(arr,arr_size);
    kadaneApproach(arr,arr_size);
    return 0;

}