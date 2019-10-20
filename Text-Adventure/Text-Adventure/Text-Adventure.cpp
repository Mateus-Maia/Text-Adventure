#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <string>

bool randomCombate() {
	srand(time(NULL));//Inicializa o random
	int valor = rand() % 2; //Gera o número randomico entre 0 e 1
	
	if (valor == 0) //Se o valor randomico for igual a zero a função retorna como true
		return true;
	return false; //Se não ela retorna como falso
}

bool randomPossuiChave() {
	srand(time(NULL));//Inicializa o random
	int valor = rand() % 2; //Gera o número randomico entre 0 e 1

	if (valor == 0) //Se o valor randomico for igual a zero a função retorna como true
		return true;
	return false; //Se não ela retorna como falso
}

int ataqueCombate(int vidas) {
		vidas -= 2; //Diminui duas vidas do atacado
		return vidas; //Retorna a quantidade de vida
}

int defesaCombate(int vidas) {
		vidas -= 1; //Diminui uma vida
		return vidas; //Retorna a quantidade de vida
}


int randomAtaqueOuDefesa() {
	srand(time(NULL));//Inicializa o random
	int valor = rand() % 2; //Gera o número randomico entre 0 e 1

	return valor; //Retorna o valor
}

void navegacao(int VidaJogador) {
	int porta = 0; //Esta variavel controlará o número de portas
	bool combate; //Esta variavel receberá o valor randomico de true ou false
	int ataque = 0;
	
	std::cout << "Escolha uma porta: \n"; //Mostra a mensagem no console
	std::cin >> porta; //Atribui o valor da porta para a variavel

	bool chave;  // vai controlar se há chave ou não

	switch (porta) //Para cada valor atribuido a variavel porta este bloco de código executará uma serie de comandos. 
	{
		//Inicializa a vida dos jogadores com 5
		
	case 1: std::cout << "Voce entrou na porta 1 \n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		combate = randomCombate(); //Atribui o valor randomico para a variavel combate
		if (combate == false) { //Se o valor randomico for falso...
			std::cout << "\nSEM COMBATE SORTUDO!!\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			navegacao(VidaJogador);
		}
		else {
			int vidaMaquina = 5;
			while (vidaMaquina > 0 || VidaJogador > 0) { //laço de repetição

				//Pergunto se o jogador que defender ou atacar //
				std::cout << "Voce deseja atacar ou defender? Para atacar digite 1, para defender digite qualquer tecla: \n";//Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cin >> ataque; //Lê a variavel e insere o valor que o jogador digitou na variavel ataque
				if (ataque == 1) { //Se ataque for 1 o sistema roda o bloco de codigo abaixo
					vidaMaquina = ataqueCombate(vidaMaquina); //Chamo a função ataque que retorno a quantidade de vida após o ataque
					std::cout << "Voce atacou. Quantidade de vida do inimigo:" + std::to_string(vidaMaquina) + "\n"; //Mostra a quantidade de vida no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo de ataque
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				else {
					//Se o jogador o jorgador digitar 2
					VidaJogador = defesaCombate(VidaJogador); //Jogador se defende
					std::cout << "Voce Defendeu. Sua quantidade de vida eh:" + std::to_string(VidaJogador) + "\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				if (VidaJogador <= 0)
				{
					std::cout << "Game Over\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				chave = randomPossuiChave();
				if (chave == true && vidaMaquina<=0) {
					std::cout << "voce achou chave!\n";
					std::cout << "Parabehns, voce saiu da masmorra!\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				if (vidaMaquina <= 0 && chave == false)
				{
					navegacao(VidaJogador);
				}
			}
		}
		break;
	case 2: std::cout << "voce entrou na porta 2 \n";
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		combate = randomCombate(); //Atribui o valor randomico para a variavel combate
		if (combate == false) { //Se o valor randomico for falso...
			std::cout << "\nSEM COMBATE SORTUDO!!\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			navegacao(VidaJogador);
		}
		else {
			int vidaMaquina = 5;
			while (vidaMaquina > 0 || VidaJogador > 0) { //laço de repetição

				//Pergunto se o jogador que defender ou atacar //
				std::cout << "Voce deseja atacar ou defender? Para atacar digite 1, para defender digite qualquer tecla: \n";//Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cin >> ataque; //Lê a variavel e insere o valor que o jogador digitou na variavel ataque
				if (ataque == 1) { //Se ataque for 1 o sistema roda o bloco de codigo abaixo
					vidaMaquina = ataqueCombate(vidaMaquina); //Chamo a função ataque que retorno a quantidade de vida após o ataque
					std::cout << "Voce atacou. Quantidade de vida do inimigo:" + std::to_string(vidaMaquina) + "\n"; //Mostra a quantidade de vida no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo de ataque
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				else {
					//Se o jogador o jorgador digitar 2
					VidaJogador = defesaCombate(VidaJogador); //Jogador se defende
					std::cout << "Voce Defendeu. Sua quantidade de vida eh:" + std::to_string(VidaJogador) + "\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				if (VidaJogador <= 0)
				{
					std::cout << "Game Over\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				chave = randomPossuiChave();
				if (chave == true && vidaMaquina <= 0) {
					std::cout << "voce achou chave!\n";
					std::cout << "Parabehns, voce saiu da masmorra!\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				if (vidaMaquina <= 0 && chave == false)
				{
					navegacao(VidaJogador);
				}
			}
		}
		break;
	case 3: std::cout << "voce entrou na porta 3 \n";
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		combate = randomCombate(); //Atribui o valor randomico para a variavel combate
		if (combate == false) { //Se o valor randomico for falso...
			std::cout << "\nSEM COMBATE SORTUDO!!\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			navegacao(VidaJogador);
		}
		else {
			int vidaMaquina = 5;
			while (vidaMaquina > 0 || VidaJogador > 0) { //laço de repetição

				//Pergunto se o jogador que defender ou atacar //
				std::cout << "Voce deseja atacar ou defender? Para atacar digite 1, para defender digite qualquer tecla: \n";//Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cin >> ataque; //Lê a variavel e insere o valor que o jogador digitou na variavel ataque
				if (ataque == 1) { //Se ataque for 1 o sistema roda o bloco de codigo abaixo
					vidaMaquina = ataqueCombate(vidaMaquina); //Chamo a função ataque que retorno a quantidade de vida após o ataque
					std::cout << "Voce atacou. Quantidade de vida do inimigo:" + std::to_string(vidaMaquina) + "\n"; //Mostra a quantidade de vida no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo de ataque
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				else {
					//Se o jogador o jorgador digitar 2
					VidaJogador = defesaCombate(VidaJogador); //Jogador se defende
					std::cout << "Voce Defendeu. Sua quantidade de vida eh:" + std::to_string(VidaJogador) + "\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				if (VidaJogador <= 0)
				{
					std::cout << "Game Over\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				chave = randomPossuiChave();
				if (chave == true && vidaMaquina <= 0) {
					std::cout << "voce achou chave!\n";
					std::cout << "Parabehns, voce saiu da masmorra!\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				if (vidaMaquina <= 0 && chave == false)
				{
					navegacao(VidaJogador);
				}
			}
		}
		break;

	case 4: std::cout << "voce entrou na porta 4\n";
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		combate = randomCombate(); //Atribui o valor randomico para a variavel combate
		if (combate == false) { //Se o valor randomico for falso...
			std::cout << "\nSEM COMBATE SORTUDO!!\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			navegacao(VidaJogador);
		}
		else {
			int vidaMaquina = 5;
			while (vidaMaquina > 0 || VidaJogador > 0) { //laço de repetição

				//Pergunto se o jogador que defender ou atacar //
				std::cout << "Voce deseja atacar ou defender? Para atacar digite 1, para defender digite qualquer tecla: \n";//Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cin >> ataque; //Lê a variavel e insere o valor que o jogador digitou na variavel ataque
				if (ataque == 1) { //Se ataque for 1 o sistema roda o bloco de codigo abaixo
					vidaMaquina = ataqueCombate(vidaMaquina); //Chamo a função ataque que retorno a quantidade de vida após o ataque
					std::cout << "Voce atacou. Quantidade de vida do inimigo:" + std::to_string(vidaMaquina) + "\n"; //Mostra a quantidade de vida no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo de ataque
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				else {
					//Se o jogador o jorgador digitar 2
					VidaJogador = defesaCombate(VidaJogador); //Jogador se defende
					std::cout << "Voce Defendeu. Sua quantidade de vida eh:" + std::to_string(VidaJogador) + "\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				if (VidaJogador <= 0)
				{
					std::cout << "Game Over\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				chave = randomPossuiChave();
				if (chave == true && vidaMaquina <= 0) {
					std::cout << "voce achou chave!\n";
					std::cout << "Parabehns, voce saiu da masmorra!\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				if (vidaMaquina <= 0 && chave == false)
				{
					navegacao(VidaJogador);
				}
			}
		}
		break;

	case 5: std::cout << "voce entrou na porta 5 \n";
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
		combate = randomCombate(); //Atribui o valor randomico para a variavel combate
		if (combate == false) { //Se o valor randomico for falso...
			std::cout << "\nSEM COMBATE SORTUDO!!\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
			navegacao(VidaJogador);
		}
		else {
			int vidaMaquina = 5;
			while (vidaMaquina > 0 || VidaJogador > 0) { //laço de repetição

				//Pergunto se o jogador que defender ou atacar //
				std::cout << "Voce deseja atacar ou defender? Para atacar digite 1, para defender digite qualquer tecla: \n";//Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
				std::cin >> ataque; //Lê a variavel e insere o valor que o jogador digitou na variavel ataque
				if (ataque == 1) { //Se ataque for 1 o sistema roda o bloco de codigo abaixo
					vidaMaquina = ataqueCombate(vidaMaquina); //Chamo a função ataque que retorno a quantidade de vida após o ataque
					std::cout << "Voce atacou. Quantidade de vida do inimigo:" + std::to_string(vidaMaquina) + "\n"; //Mostra a quantidade de vida no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo de ataque
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				else {
					//Se o jogador o jorgador digitar 2
					VidaJogador = defesaCombate(VidaJogador); //Jogador se defende
					std::cout << "Voce Defendeu. Sua quantidade de vida eh:" + std::to_string(VidaJogador) + "\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
					if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo
						VidaJogador = ataqueCombate(VidaJogador); //Ataca o jogador
						std::cout << "voce foi atacado! Sua vida eh:" + std::to_string(VidaJogador) + "\n"; //Mostra o resultado
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
					else {
						vidaMaquina = defesaCombate(vidaMaquina); //A maquina se defende
						//Mostra a quantidade de vida da maquina
						std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(vidaMaquina) + "\n";
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
						std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					}
				}
				if (VidaJogador <= 0)
				{
					std::cout << "Game Over\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				chave = randomPossuiChave();
				if (chave == true && vidaMaquina <= 0) {
					std::cout << "voce achou chave!\n";
					std::cout << "Parabehns, voce saiu da masmorra!\n";
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
					break;
				}
				if (vidaMaquina <= 0 && chave == false)
				{
					navegacao(VidaJogador);
				}
			}
		}
		break;

	default: std::cout << "Porta Inexistente \n"; break;
	}
}

int main()
{
	int start = 0; //Esta variavel irá controlar o inicio do jogo
    std::cout << "Para iniciar o jogo digite [1] ou digite qualquer tecla para sair do jogo\n"; //Mostra a mensagem no console

	std::cin >> start; //O valor digitado pelo usuário no console será atribuido a variavel start

	std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
	std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console
	std::cout << "\n--------------------------------------\n"; //Mostra a mensagem no console

	if (start == 1) { //Se a variavel start receber 1 o jogo eh iniciado
		std::cout << "Historinha\n"; //Mostra a mensagem no console
		int vidaJogador = 5;
		navegacao(vidaJogador); // Chama a função navegação. 
	}

	std::cout << "\nVoce saiu!\n";
}
