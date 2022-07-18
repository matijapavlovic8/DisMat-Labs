#include<iostream>
#include<cmath>

using namespace std;

double formula(double lambda1, double lambda2, double a0, double a1, int n){
    if(lambda1 == 0 && lambda2 == 0)        
        return 0;                           
    if(n == 0)
        return a0;                          //ako se zatraži 1. ili 2. član niza redundantno ih je računati
    if(n == 1)  
        return a1;

    double A, B;
    lambda1 = -lambda1;                                                    
    lambda2 = -lambda2;                                                 //jer promijene stranu jednakosti prilikom mnozenja s an-2   
    double c1 = (-lambda1 + sqrt((lambda1*lambda1) - 4*lambda2)) / 2;      //računanje konstanti
    double c2 = (-lambda1 - sqrt((lambda1*lambda1) - 4*lambda2)) / 2;
    
    if(c1 == c2){                                                       // ukoliko su konstatne jednake 
        B = a0;                                                         // izraz je an = A*n*c1^n + Bc2^n te uvrstavanjem za a0 i a1 dobijamo
        A = a1/c1 - a0;                                                 // izraze za A i B
        return A * n * pow(c1, n) + B * pow(c1, n);
    }


    A = (a1 - a0*c2) / (c1 - c2);
    B = a0 - A;

    return A * pow(c1, n) + B * pow(c2, n); 


    if(c1 == c2){
        B = a0;
        A = a1/c1 - a0;
        return A * n * pow(c1, n) + B * pow(c1, n);
    }

    
    
}

double rekurzija(double lambda1, double lambda2, double anMin2, double anMin1, int n){
    if(n == 0)
        return anMin2;
    if(n == 1)
        return anMin1;

    return rekurzija(lambda1, lambda2, anMin2, anMin1, n - 1) * lambda1 + rekurzija(lambda1, lambda2, anMin2, anMin1, n - 2) * lambda2;
}



int main(void){
    double lambda1;
    double lambda2;
    double anMin2;
    double anMin1;
    int n;

    cout << "Unesite prvi koeficijent λ_1 rekurzivne relacije : " << endl;
    cin >> lambda1;
    cout << "Unesite drugi koeficijent λ_2 rekurzivne relacije : " << endl;
    cin >> lambda2;
    cout << "Unesite vrijednost nultog clana niza a_0: "<< endl;
    cin >> anMin2;
    cout << "Unesite vrijednost prvog clana niza a_1: "<< endl;
    cin >> anMin1;
    cout << "Unesite redni broj n trazenog clana niza: " << endl;
    cin >> n;


    double rezForm = formula(lambda1, lambda2, anMin2, anMin1, n);

    double rezRek = rekurzija(lambda1, lambda2, anMin2, anMin1, n);

    cout << "Vrijednost ntog clana niza pomocu formule: " << rezForm << endl;
    cout << "Vrijednost ntog clana niza pomocu rekurzije: " << rezRek << endl;

}