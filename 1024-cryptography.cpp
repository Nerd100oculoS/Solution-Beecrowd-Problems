
/**
Solicitaram para que você construisse um programa simples de criptografia. Este programa deve possibilitar enviar mensagens codificadas sem que alguém consiga lê-las. O processo é muito simples. São feitas três passadas em todo o texto.
Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita, segundo a tabela ASCII: letra 'a' deve virar letra 'd', letra 'y' deve virar caractere '|' e assim sucessivamente. Na segunda passada, a linha deverá ser invertida. Na terceira e última passada, todo e qualquer caractere a partir da metade em diante (truncada) devem ser deslocados uma posição para a esquerda na tabela ASCII. Neste caso, 'b' vira 'a' e 'a' vira '`'.
Por exemplo, se a entrada for “Texto #3”, o primeiro processamento sobre esta entrada deverá produzir “Wh{wr #3”. O resultado do segundo processamento inverte os caracteres e produz “3# rw{hW”. Por último, com o deslocamento dos caracteres da metade em diante, o resultado final deve ser “3# rvzgV”.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 1*10^4), indicando a quantidade de linhas que o problema deve tratar. As N linhas contém cada uma delas M (1 ≤ M ≤ 1*10^3) caracteres.
Saída
Para cada entrada, deve-se apresentar a mensagem criptografada.
*/

// Gabriel Alves - Nerd100oculoS.

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main(){
    
    int amnt_test;
    vector<string> vec_strings;
    
    scanf("%d",&amnt_test);
    cin.ignore();
    
    // recebe o vetor de strings
    while(amnt_test--){
        
        string str;
        getline(cin, str);
        vec_strings.push_back(str);
    }

    // cout << endl << endl;
    
    // percorre cada string do vetor
    for(int j = 0; j < (int)vec_strings.size(); j++){

        string aux = vec_strings[j];
        string str_final = "";
        int cont = 0;

        // faz a primeira etapa
        for(int k = 0; k < (int)aux.length(); k++){
            
            if(islower(aux[k]) || (isupper(aux[k]) )){
                
                int cInt = int(aux[k]+3);
                char ch = char(cInt);

                str_final.push_back(ch);
                
            }else{
                
                str_final.push_back(aux[k]);
            }
        }

        // Faz a segunda etapa
        reverse(str_final.begin(), str_final.end());
        
        // Faz a terceira e ultima etapa
        cont = (int)str_final.length()/2.0;
        
        while(cont< (int)str_final.length()){
            
            str_final[cont] -= 1;
            cont++;
        }

        cout << str_final << endl; 
    }
       
    return 0;
}