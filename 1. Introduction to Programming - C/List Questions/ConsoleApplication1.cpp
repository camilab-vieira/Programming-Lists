// ConsoleApplication1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <iostream>
#include <stdio.h>

int conv(int c) {
	int k;
	k = c + 273;
	return k;
}
int main(){
	int c;
	int t;
	std::cout << "Informe uma temperatura em celsius: ";
	std::cin >> c;
	t = conv(c);
	std::cout << "A temperatura e de  " << t << " kelvin";
}

/**
#include <stdio.h>

int main(){
	char s[10];
	scanf("%[^\n]",s);
	gets(s);
	for(int i=0; s[i] ;i++){
		switch(s[i]){
			case "\t":
				s[i]= "\n";
				break;
			default:
				s[i]=s[i];
		}
	}
}
**/
// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
