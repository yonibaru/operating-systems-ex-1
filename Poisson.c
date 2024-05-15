#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

//Support of a Poisson Distribution is strictly Natural numbers therefore 
//factorial() recieves and returns an integer.
int factorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

long double poisson(long double lambda,int k){
    return (pow(lambda,k)/factorial(k)) * expf(-lambda);
}

int main(int argc,char* argv[]){
    //argv[1] = lambda (positive real), argv[2] = k (integer)
    if(argc != 3){
        printf("Error\n");
        exit(1);
    }
    long double lambda = strtold(argv[1],NULL);
    int k = atoi(argv[2]);
    if(k < 0 || lambda < 0){
        printf("Wrong args\n");
        exit(1);
    }
    long double probability = poisson(lambda,k);
    printf("Poisson Dist. with arguments k = %d and λ = %Lf equals to: %Lf",k,lambda,probability);

}