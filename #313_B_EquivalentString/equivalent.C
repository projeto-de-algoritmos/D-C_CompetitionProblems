#include<bits/stdc++.h>
using namespace std;
    
string separaJuntando(string palavra)
{
    int tamanho = palavra.size();
    if(tamanho%2) return palavra; // a condição de parada da recursão é uma string de tamanho 1
     
    string esquerda = separaJuntando(palavra.substr(0,tamanho/2));
    string direita = separaJuntando(palavra.substr(tamanho/2));

    return min(esquerda + direita, direita + esquerda);// o + faz a operação de concatenação de strings
}
    
int main()
{
    string compara1, compara2, firstS,secondS;
    
    cin >> firstS >> secondS;
    
    compara1 = separaJuntando(firstS);
    compara2 = separaJuntando(secondS);

    if (compara1 == compara2 ) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}