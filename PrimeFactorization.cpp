#include<iostream>
#include<vector>
using namespace std;
//Sieve of eratosthenes
void printAllPrimeNumbers(int num);
void printAllFactors(int num);
void printHCF(int a, int b);
int main() {

    //Q1. Print all prime numbers between 1 to 100
    // printAllPrimeNumbers(100);
    // printAllFactors(72);
    printHCF(22, 88);
    return 0;
}

//Euclid Algorithm to find GCD/HCF
void printHCF(int a, int b) {
    int tempa = a, tempb = b;
    while(b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    cout << "HCF of (" << tempa << ", " << tempb <<") is " << a;
}

void printAllFactors(int num) {
    for(int i = 2; i <= num; i++) {
        while(num % i == 0) {
            cout << i << " ";
            num /= i;
        }
    }
}

void printAllPrimeNumbers(int num) {
    vector<bool> arePrimes(num+1, true);
    for(int i = 2; i <= num; i++) {
        if(arePrimes[i]) {
            for(int j = i*i; j <= num; j += i) {
                arePrimes[j] = false;
            }
        }
    }
    for(int i = 2; i <= num; i++) {
        if(arePrimes[i]) cout << i << " ";
    }
    cout << endl;
}