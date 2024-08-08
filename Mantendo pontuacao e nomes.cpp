#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include<locale.h>
#include<time.h>
using namespace std;
void menuInicial();

void limpaTela(){
	system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]){
	
	int linha, coluna;
	
	for(linha = 0; linha < 3; linha++){
		for(coluna = 0; coluna < 3; coluna++){
			tabuleiro[linha][coluna] ='-';
		}
	}
}

void exibeTabuleiro(char tabuleiro[3][3]){

	int linha, coluna;
	
	for(linha= 0; linha < 3; linha++){
		for(coluna= 0; coluna < 3; coluna++){
			cout << tabuleiro[linha][coluna];
		}
		cout <<"\n";
	}
}

// RETORNA 1 SE O "X" VENCER, RETORNA 2 SE O "O" VENCER, RETORNA 0 SE EMPATAR.
int confereTabuleiro(char tabuleiro[3][3]){
	int linha, coluna;
	
	// CONFERE LINHAS.
	for(linha= 0; linha < 3; linha++){
			if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
				
				return 1;
			}else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
				
				return 2;
			}
		}
		
	// CONFERE COLUNAS.
	for(coluna= 0; coluna < 3; coluna++){
		if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
			return 1;
		}else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
			return 2;
		}
	}
	
	// CONFERE DIAGONAL PRINCIPAL.
	if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
		if(tabuleiro[0][0] == 'X'){
			return 1;
			
		}else{
			return 2;			
		}
	}
	
	// CONFERE DIAGONAL SECUNDÁRIA.
	if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
		if(tabuleiro[0][2] == 'X'){
			return 1;
		}else{
			return 2;
		}
	}
	return 0;	
}

void exibeTutorial(){
	cout <<"\nMAPA DE POSIÇÕES\n";
	cout<<"7 8 9\n";
	cout<<"4 5 6\n";
	cout<<"1 2 3\n";
}

void jogo(string nomeDoJogador1, string nomeDoJogador2, int pontuacao1, int pontuacao2){
	
	//variáveis gerais
	string jogadorAtual;
	char tabuleiro[3][3];
	int linhaJogada, colunaJogada, posicaoJogada;
	int estadoDeJogo = 1;
	int turnoDoJogador = 1;
	int rodada = 0, maxRodada = 9;
	int reinicio;
	
	iniciaTabuleiro(tabuleiro); // Exibe o tabuleiro com "-".

	
	
	while(rodada < maxRodada && estadoDeJogo == 1){
		
		limpaTela();
		cout <<"Rodadas restantes: " << maxRodada - rodada <<"\n";
		cout << "\nPontuação " << nomeDoJogador1 <<": " << pontuacao1;
		cout << "\nPontuação " << nomeDoJogador2 <<": " << pontuacao2 <<"\n";
		
		exibeTabuleiro(tabuleiro); // Exibe o tabuleiro para o jogador.
		
		exibeTutorial(); // Exibe qual numero corresponde a qual posição.
		
		// Atualiza conforme o nome do jogador da vez.
		if(turnoDoJogador == 1){
			jogadorAtual = nomeDoJogador1;
		}else{
			jogadorAtual = nomeDoJogador2;
		}
		
		// Matriz de posições possiveis.
		int posicoes[9][2] = {{2,0}, {2,1}, {2,2}, {1,0}, {1,1}, {1,2}, {0,0},{0,1}, {0,2}};
	
		// Lê a posição desejada.
		cout << jogadorAtual << ", digite uma posição conforme o MAPA: "; cin >> posicaoJogada;
		
		// Passa a linha e a coluna de acordo com a matriz de posições exibida no mapa.
		linhaJogada = posicoes[posicaoJogada - 1] [0];
		colunaJogada = posicoes[posicaoJogada - 1] [1];
		
		// Verifica se a posição está vazia.
		if(tabuleiro[linhaJogada][colunaJogada] == '-'){
			
			// Verifica de quem é a vez para posicionar o marcador.
			if(turnoDoJogador == 1){
				tabuleiro[linhaJogada][colunaJogada] = 'X';
				turnoDoJogador = 2;
			}else{
				tabuleiro[linhaJogada][colunaJogada] = 'O';
				turnoDoJogador = 1;	
			}
			rodada ++;
			
		}else{
			cout <<"\nPosição inválida, tente outra";
		}
			
		if(confereTabuleiro(tabuleiro) == 1){
			limpaTela();
			cout <<"\nO jogador X venceu";
			pontuacao1++;
			estadoDeJogo = 0;
		}else if(confereTabuleiro(tabuleiro) == 2){
			limpaTela();
			cout <<"\nO jogador O venceu";
			pontuacao2++;
			estadoDeJogo = 0;
		}else{
			limpaTela();
			cout <<"\nEMPATE";
		}
	}
	cout <<"\n";
	exibeTabuleiro(tabuleiro);
	cout <<"\nFim de jogo";
	cout<<"\nO que deseja fazer?\n1 - Continuar jogando\n2 - Menu Inicial\n3 - Sair\n"; cin >> reinicio;
	
	if(reinicio == 1){
		jogo(nomeDoJogador1, nomeDoJogador2, pontuacao1, pontuacao2);
	}else if( reinicio == 2){
		menuInicial();
	}else{
		cout << "Até mais :D";
	}

} 

void menuInicial(){
	
	int opcao;
	string nomeDoJogador1, nomeDoJogador2;
	
	// Menu inicial que fica aparecendo para o usuário enquanto ele digita valores menores que 1 ou maiores que 3.
	while(opcao < 1 || opcao > 3){
		
		limpaTela();
		
		cout << "JOGO DA VELHA\n\n";
		cout << "Escolha uma opção\n\n";
		cout << "1 - JOGAR\n";
		cout << "2 - SOBRE\n";
		cout << "3 - SAIR\n";
		cin >> opcao;
		
		switch(opcao){
			case 1:
				cout <<"Digite o nome do jogador 1: "; cin >> nomeDoJogador1;
				cout <<"Digite o nome do jogador 2: "; cin >> nomeDoJogador2;
				jogo(nomeDoJogador1, nomeDoJogador2, 0 , 0);
				break;
				
			case 2:
				cout <<" Informações do jogo";
				break;
				
			case 3:
				cout <<" Até a proxima :D";
				break;
		}	
	}	
}

int main (){
	srand (time(NULL));
	setlocale(LC_ALL,"");
	
	menuInicial();

	return 0;
}
