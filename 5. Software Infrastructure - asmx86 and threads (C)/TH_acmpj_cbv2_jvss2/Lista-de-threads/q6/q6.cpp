// Multiplicação de uma matriz esparsa por um vetor denso (vetor comum de C)
// Multiplicação de uma matriz esparsa por outra matriz esparsa
// Multiplicação de uma matriz esparsa por uma matriz densa (matriz comum de C)


//Para rodar:
//Terminal estando aberto na pasta Lista-de-threads, insira:
// - cd q6
// - g++ -pthread q6.cpp -o q6
// - ./q6

//Casos Teste (copiar e colar no terminal apos rodar o programa)
//Primeiro digito representa a operacao desejada, o segundo o numero de linhas, o terceiro o numero de colunas da matriz esparsa, seguido dos seus elementos
//Se a operacao for multiplicao por vetor, os seguintes sao os elementos do vetor
//Se for uma das outras duas operacoes, o proximo digito sera o numero de colunas da segunda matriz, seguido dos seus elementos
//Por ultimo indica se quer continuar e recomeca ou encerra

//   1 2 4 0 0 3 7 6 0 5 0 7 8 5 1 0
//      Operacao 1 (matriz esparsa por vetor denso)
//      2 linhas e 4 colunas (da matriz esparsa)
//      Matriz esparsa: 0 0 3 7
//                      6 0 5 0
//      Precisa ter 4 linhas e uma coluna 
//      Vetor Denso:    7 8 5 1
//      0 para encerrar o programa
//     Output esperado: 22  
//                      67 

//    2 3 2 0 3 0 0 7 9 2 0 1 5 0 0 
//      Operacao 2 (matriz esparsa por matriz esparsa)
//      3 linhas e 2 colunas (da matriz esparsa)
//      Matriz esparsa: 0 3 
//                      0 0 
//                      7 9 
//      2 colunas (precisa ter 2 linhas) 
//      Matriz Densa:   0 1
//                      5 0
//      0 para encerrar o programa
//     Output esperado: 15 0
//                      0  0
//                      45 7

//   3 3 3 0 0 0 0 1 0 2 3 4 2 2 5 6 7 1 8 0 
//      Operacao 3 (matriz esparsa por matriz densa)
//      3 linhas e 3 colunas (da matriz esparsa)
//      Matriz esparsa: 0 0 0
//                      0 1 0
//                      2 3 4
//      2 colunas (precisa ter 3 linhas) 
//      Matriz Densa:   2 5
//                      6 7
//                      1 8
//      0 para encerrar o programa
//     Output esperado: 0  0
//                      6  7
//                      26 63

//Inicio da parte de threads na main: linha 155, 201 e 248

#include <bits/stdc++.h>
#include <pthread.h>        //Biblioteca de threads
using namespace std;

vector<vector<float>>matrizResposta;
vector<vector<float>>matrizDensa;
vector<vector<pair<int,float>>>matrizEsparsa;
vector<vector<pair<int,float>>>matrizEsparsa_2o;
int linha_1o, coluna_1o, linha_2o, coluna_2o;

void* esparsaXdensa(void*arg){     //Cada thread ira processar o resultado de uma posicao da matriz resposta
    int *pos = (int *)arg;         //O elemento eh indicado como 0, 1, 2, 3... ate (linha*coluna) - 1
    int linha = *pos / coluna_2o;  //Descobrir a linha a que o elemento pertence
    int coluna = *pos % coluna_2o; //Descobrir a coluna a que o elemento pertence
    vector<pair<int, float>>primeiro = matrizEsparsa[linha];
    float elemento = 0;

    for(int i = 0; i < primeiro.size(); i++){
        elemento += primeiro[i].second*matrizDensa[primeiro[i].first][coluna];  //Realiza as multiplicacoes necessarias, buscando apenas os elementos que tem correspondencia com os termos nao nulos da matriz esparsa
    }   
    matrizResposta[linha][coluna] = elemento;    
    
    pthread_exit(NULL);             //Encerra a thread
}

void* esparsaXesparsa(void*arg){   //Cada thread ira processar o resultado de uma posicao da matriz resposta
    int *pos = (int *)arg;         //O elemento eh indicado como 0, 1, 2, 3... ate (linha*coluna) - 1
    int linha = *pos / coluna_2o;  //Descobrir a linha a que o elemento pertence
    int coluna = *pos % coluna_2o; //Descobrir a coluna a que o elemento pertence
    vector<pair<int, float>>primeiro = matrizEsparsa[linha];
    vector<pair<int, float>>segundo = matrizEsparsa_2o[coluna];
    float elemento = 0;
     
    int m = 0;
    //A segunda matriz foi armazenada de forma transposta para facilitar o calculo
    //O codigo verifica se ha elemento nao nulos correspondentes na linha e coluna em questao
    if(primeiro.size()){
        for(int i = 0; i < segundo.size(); i++){
            while(primeiro[m].first < segundo[i].first){
                if(m < (primeiro.size() - 1)) m++;
                else break;
            }
            if(primeiro[m].first == segundo[i].first){
                elemento += primeiro[m].second*segundo[i].second;
                if(m < (primeiro.size() - 1)) m++;
                else break;
            }
        }
    }
    matrizResposta[linha][coluna] = elemento;
        
    pthread_exit(NULL);            //Encerra a thread
}
int main(){
    int operacao = 0, continuar = 1;
    float input;
    while(continuar){
        cout<<endl;     //Menu
        cout<<"================================ OPERACOES COM MATRIZ ESPARSA ================================"<<endl;
        cout<<endl;
        cout<<"             1. Multiplicação de uma matriz esparsa por um vetor denso (vetor coluna)"<<endl;
        cout<<"             2. Multiplicação de uma matriz esparsa por outra matriz esparsa"<<endl;
        cout<<"             3. Multiplicação de uma matriz esparsa por uma matriz densa"<<endl;
        cout<<"             4. Sair"<<endl;
        cout<<endl;
        cout<<"Digite o número da operacao desejada: ";
        cin>>operacao;
        if(operacao == 1){
            cout<<"Insira o numero de linhas da matriz esparsa: ";
            cin>>linha_1o;
            cout<<"Insira o numero de colunas da matriz esparsa: ";
            cin>>coluna_1o;
            
            matrizEsparsa.resize(linha_1o); //Inserir 1o matriz
            cout<<"Insira a matriz esparsa: "<<endl;
            for(int i = 0; i < linha_1o; i++){
                for(int j = 0; j < coluna_1o; j++){
                    cin>>input;
                    if(input != 0) matrizEsparsa[i].push_back(make_pair(j, input));
                }
            }

            cout<<"*O numero de linhas do vetor denso precisa ser igual ao numero de colunas da matriz esparsa"<<endl;
            cout<<"Insira os "<<coluna_1o<< " elementos do vetor coluna denso: ";
            coluna_2o = 1;
            matrizDensa.resize(coluna_1o);
            for(int i = 0; i < coluna_1o; i++){ //Inserir vetor
                cin>>input;
                matrizDensa[i].push_back(input);
            }
            cout<<endl;
            matrizResposta.resize(linha_1o);
            for(int i = 0; i < linha_1o; i++){
                matrizResposta[i].resize(coluna_2o);
            }
            pthread_t threads[linha_1o];  //Declara quantas threads serao criadas
            int ids[linha_1o]; //Vetor de ID's da threads
            for(int i = 0; i < linha_1o; i++){
                ids[i] = i;     //Define o id da thread
                if(pthread_create(&threads[i], NULL, &esparsaXdensa, (void *)&ids[i])){ //Cria a thread e passando a função 'esparsaXdensa' como parâmetro e o ID da thread como argumento
                    perror("Failed to create thread");      //Verifica se houve erro na criaçao da thread
                }
            }
            for(int i = 0; i < linha_1o; i++){ 
                if(pthread_join(threads[i], NULL) != 0){    //Join em todas as threads criadas
                    perror("Failed to join thread");       //Verifica se houve erro no join
                }
            }
        }else if(operacao == 2){
            cout<<"Insira o numero de linhas da primeira matriz esparsa: ";
            cin>>linha_1o;
            cout<<"Insira o numero de colunas da primeira matriz esparsa: ";
            cin>>coluna_1o;
            linha_2o = coluna_1o;

            matrizEsparsa.resize(linha_1o);
            cout<<"Insira a matriz esparsa: "<<endl;
            for(int i = 0; i < linha_1o; i++){        //Inserir 1o matriz
                for(int j = 0; j < coluna_1o; j++){
                    cin>>input;
                    if(input != 0) matrizEsparsa[i].push_back(make_pair(j, input));
                }
            }
            
            cout<<"*O numero de linhas da segunda matriz esparsa precisa ser igual ao numero de colunas da primeira matriz esparsa ("<<coluna_1o<<" linhas)"<<endl;
            cout<<"Insira o numero de colunas da segunda matriz esparsa: ";
            cin>>coluna_2o;

            matrizEsparsa_2o.resize(coluna_2o);
            cout<<"Insira a segunda matriz esparsa: "<<endl;
            for(int i = 0; i < linha_2o; i++){       //Inserir 2o matriz
                for(int j = 0; j < coluna_2o; j++){
                    cin>>input;
                    if(input != 0) matrizEsparsa_2o[j].push_back(make_pair(i, input)); //Armazena de modo inverso, semelhante a uma matriz transposta para facilitar o calculo
                }
            }
            cout<<endl;
            matrizResposta.resize(linha_1o);
            for(int i = 0; i < linha_1o; i++){
                matrizResposta[i].resize(coluna_2o);
            }
            pthread_t threads[linha_1o*coluna_2o];     //Declara quantas threads serao criadas
            int ids[linha_1o*coluna_2o]; //Vetor de ID's da threads
            for(int i = 0; i < linha_1o*coluna_2o; i++){
                ids[i] = i;     //Define o id da thread
                if(pthread_create(&threads[i], NULL, &esparsaXesparsa, (void *)&ids[i])){ //Cria a thread e passando a função 'esparsaXesparsa' como parâmetro e o ID da thread como argumento
                    perror("Failed to create thread");       //Verifica se houve erro na criaçao da thread
                }
            }
            for(int i = 0; i < linha_1o*coluna_2o; i++){ 
                if(pthread_join(threads[i], NULL) != 0){    //Join em todas as threads criadas
                    perror("Failed to join thread");       //Verifica se houve erro no join
                }
            }
        }else if(operacao == 3){
            cout<<"Insira o numero de linhas da matriz esparsa: ";
            cin>>linha_1o;
            cout<<"Insira o numero de colunas da matriz esparsa: ";
            cin>>coluna_1o;
            linha_2o = coluna_1o;

            matrizEsparsa.resize(linha_1o);
            cout<<"Insira a matriz esparsa: "<<endl;
            for(int i = 0; i < linha_1o; i++){       //Inserir 1o matriz
                for(int j = 0; j < coluna_1o; j++){
                    cin>>input;
                    if(input != 0) matrizEsparsa[i].push_back(make_pair(j, input));
                }
            }

            cout<<"*O numero de linhas da matriz densa precisa ser igual ao numero de colunas da matriz esparsa ("<<coluna_1o<<" linhas)"<<endl;
            cout<<"Insira o numero de colunas da matriz densa: ";
            cin>>coluna_2o;

            matrizDensa.resize(linha_2o);
            cout<<"Insira a matriz densa: "<<endl;
            for(int i = 0; i < linha_2o; i++){       //Inserir 2o matriz
                for(int j = 0; j < coluna_2o; j++){
                    cin>>input;
                    matrizDensa[i].push_back(input);
                }
            }
            cout<<endl;
            
            matrizResposta.resize(linha_1o);
            for(int i = 0; i < linha_1o; i++){
                matrizResposta[i].resize(coluna_2o);
            }
            pthread_t threads[linha_1o*coluna_2o];     //Declara quantas threads serao criadas
            int ids[linha_1o*coluna_2o]; //Vetor de ID's da threads
            for(int i = 0; i < linha_1o*coluna_2o; i++){
                ids[i] = i;     //Define o id da thread
                if(pthread_create(&threads[i], NULL, &esparsaXdensa, (void *)&ids[i])){ //Cria a thread e passando a função 'esparsaXdensa' como parâmetro e o ID da thread como argumento
                    perror("Failed to create thread");         //Verifica se houve erro na criaçao da thread
                }
            }
            for(int i = 0; i < linha_1o*coluna_2o; i++){
                if(pthread_join(threads[i], NULL) != 0){    //Join em todas as threads criadas
                    perror("Failed to join thread");       //Verifica se houve erro no join
                }
            }
        }else if(operacao == 4){
            continuar = 0;
        }else{
            cout<<"Input inválido."<<endl;
        }
        for(int i = 0; i < matrizResposta.size(); i++){
            for(int j = 0; j < matrizResposta[i].size(); j++){
                cout<<setw(4)<<matrizResposta[i][j]<<" ";
            }
            cout<<endl;
        }
        matrizEsparsa.clear();
        matrizEsparsa_2o.clear();
        matrizDensa.clear();
        matrizResposta.clear();
        cout<<"Continuar [Sim -> 1/ Nao -> 0]? ";
        cin>>continuar;
    }
    pthread_exit(NULL);    //Encerra a thread (main)
}