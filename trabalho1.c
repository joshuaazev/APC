#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void escolha_certa () {
printf("\n Você deve escrever como resposta apenas 'a', 'b' ou 'c'(sem as aspas)\n Faça sua escolha de novo:\n\n");
}
void escolha_certa_2 () {
  printf("\n Você deve escrever como resposta apenas 'a' ou 'b'(sem as aspas)\n Faça sua escolha de novo:\n\n");
}
char escolha() {
  char resposta1, enter;
  int contador = 0;
  scanf(" %c", &resposta1);
  do { 
  scanf("%c", &enter);
  contador ++;
  }
  while (enter != '\n');
  if (contador == 1) {
    return resposta1;
  }
  return 'e';
}
char escolha_batalha() {
    char resposta;
    printf("\n\t a) Atacar\n\t b) Defender\n\t c) Recarregar\n\n");
    printf(" Escolha: ");
    resposta = escolha();
    printf("\n\n*******************************************************************\n");
    return resposta;
  }
char escolha_batalha_certa (char resposta) {
  while (resposta != 'a' && resposta != 'b' &&  resposta != 'c') {
    escolha_certa();
    resposta = escolha_batalha ();
}
  return resposta;
}
char batalha1 (){
  int rodada = 1, energia1 = 1, vida1 = 3, energia2 = 1, vida2 = 3, numrand;
  char resposta, respant = 'k', respinimigo, respantinimigo = 'k', enter;
  srand(time(NULL));
  printf("\n\n Regras da Batalha\n\n\t-Em cada rodada, cada oponente poderá escolher uma opção de ação entre três: atacar, defender e recarregar\n\t-Cada oponente começa a batalha com 3 pontos de vida e 1 ponto de energia\n\t-Um ataque utiliza 1 ponto de energia e retira 1 ponto de vida do adversário");
  printf("\n\t-Uma defesa não utiliza nenhum ponto de energia e bloqueia o ataque do adversário\n\t-Uma recarga aumenta os pontos de energia em 1 unidade\n\t-Uma ação NÃO pode ser realizada 2 VEZES CONSECUTIVAS\n\t-O máximo de pontos de energia que se pode ter são 3 pontos, então não tome cuidado para não recarregar quando já estiver cheio");
  printf("\n\t-Ganha a batalha o combatente que tirar primeiro os 3 pontos de vida do adversário\n\t-Caso os dois combatentes morram na mesma rodada, a batalha vai terminar empatada\n\n Clique ENTER para começar a batalha ");
  do enter = getchar();
  while (enter != '\n');
    while ( vida1 != 0 && vida2 != 0) {
    system ("clear");
    if (respant =='a') {
      printf("\n Você atacou!\t\t\t\t");
    }
    else if (respant =='b') {
      printf("\n Você defendeu!\t\t\t\t");
    } 
    else if (respant == 'c') {
      printf("\n Você recarregou!\t\t\t");
      }
    if (respantinimigo =='a') {
      printf("O inimigo atacou!\n\n\n");
    }
    else if (respantinimigo =='b') {
      printf("O inimigo defendeu!\n\n\n");
    }
    else if (respantinimigo == 'c') {
      printf("O inimigo recarregou!\n\n\n");
      }
    
    printf("*******************************************************************");
    printf("\n\n\t\t\t Rodada %d\n\n Sua Vida :    %d\t\t\tVida do adversário :    %d\n\n Sua Energia : %d\t\t\tEnergia do adversário : %d\n", rodada, vida1, vida2, energia1, energia2);
    resposta = escolha_batalha ();
    resposta = escolha_batalha_certa (resposta);
    if (resposta == respant) {
      if (resposta == 'a') {
      do {
      printf("\n Você já atacou na rodada passada, logo nesta rodada você só pode defender ou recarregar\n Escolha novamente\n");
      resposta = escolha_batalha ();
      resposta = escolha_batalha_certa (resposta);
      } 
      while (resposta == 'a');
    }
      else if (resposta == 'b') {
      do {
      printf("\n Você já defendeu na rodada passada, logo nesta rodada você só pode atacar ou recarregar\n Escolha novamente\n");
      resposta = escolha_batalha ();
      resposta = escolha_batalha_certa (resposta);
      }
      while (resposta == 'b');
    }
      else if (resposta == 'c') {
      do {
      printf("\n Você já recarregou na rodada passada, logo nesta rodada você só pode atacar ou defender\n Escolha novamente\n");
      resposta = escolha_batalha ();
      resposta = escolha_batalha_certa (resposta);
      }     
      while (resposta == 'c');
    }
  }
      while (resposta == 'a' && energia1 == 0) {
        printf("\n Você não possui pontos de energia, logo você não pode atacar\n Escolha novamente\n");
        resposta = escolha_batalha ();
        resposta = escolha_batalha_certa (resposta);
            if (resposta == respant) {
      if (resposta == 'a') {
      do {
      printf("\n Você já atacou na rodada passada, logo nesta rodada você só pode defender ou recarregar\n Escolha novamente\n");
      resposta = escolha_batalha ();
      resposta = escolha_batalha_certa (resposta);
      } 
      while (resposta == 'a');
    }
      else if (resposta == 'b') {
      do {
      printf("\n Você já defendeu na rodada passada, logo nesta rodada você só pode atacar ou recarregar\n Escolha novamente\n");
      resposta = escolha_batalha ();
      resposta = escolha_batalha_certa (resposta);
      }
      while (resposta == 'b');
    }
      else if (resposta == 'c') {
      do {
      printf("\n Você já recarregou na rodada passada, logo nesta rodada você só pode atacar ou defender\n Escolha novamente\n");
      resposta = escolha_batalha ();
      resposta = escolha_batalha_certa (resposta);
      }     
      while (resposta == 'c');
    }
  }
      }
    

      if (((energia1 > 0 && vida2 == 1 && energia2 == 0 && respant != 'a') || (energia1 == 3 && respant == 'b') || (vida2 == 1 && energia1 == 3 && respant != 'a') || (vida1 > 1 && vida2 == 1 && energia1 > 1 && respant != 'a') || (respant == 'c' && respantinimigo == 'a' && energia1 > 0)) && (respantinimigo != 'b')) {
        respinimigo = 'b';
      }

      else if (((energia1 == 0 && respant == 'b') || (respant == 'b' && respantinimigo == 'b' && energia2 >= energia1)|| (vida1 == 1 && respant == 'b')) && (energia2 > 0) && (respantinimigo != 'a')) {
        energia2 --;
        respinimigo = 'a';
        if (resposta != 'b') {
          vida1 --;
        }

      }     
      else if (((energia1 == 0 && energia2 == 0) || ((energia2 == 0 || respantinimigo == 'a') && respant == 'a')) && respantinimigo != 'c') {
        respinimigo = 'c';
        if(energia2 < 3) {
          energia2 ++;
        }

      }
      else if (respantinimigo == 'a' && energia2 == 3 && (respant == 'a' || energia1 == 0)) {
        respinimigo = 'b';
      }
    
     else {
        numrand = rand() % 3;
        while((numrand == 0 && (respantinimigo == 'a' || energia2 == 0)) || (numrand == 1 && ((respantinimigo == 'b') || (respant == 'a') || (energia1 == 0))) || (numrand == 2 && (respantinimigo == 'c' || energia2 == 3))) {
        numrand = rand() % 3;
        }
        if (numrand == 0) {
        /* O inimigo atacou */
        energia2 --;
        respinimigo = 'a';
        if (resposta != 'b') {
          vida1 --;
        }
      }
        else if (numrand == 1) {
      /* O inimigo defendeu*/  
        respinimigo = 'b';
      }

        else {
        /* O inimigo recarregou*/
        respinimigo = 'c';
        if(energia2 < 3) {
          energia2 ++;
        }

      }
        
       }

        if (resposta == 'a') {
        energia1 --;
        if (respinimigo != 'b') {
          vida2--;
        }
        }
        else if (resposta == 'c' && energia1 < 3) {
          energia1 ++;
          }
    
    respant = resposta;
    respantinimigo = respinimigo;
    rodada ++; 

    }
    system ("clear");
    if (respant =='a') {
      printf("\n Você atacou!\t\t\t\t");
    }
    else if (respant =='b') {
      printf("\n Você defendeu!\t\t\t\t");
    } 
    else if (respant == 'c') {
      printf("\n Você recarregou!\t\t\t");
      }
    if (respantinimigo =='a') {
      printf("O inimigo atacou!\n\n");
    }
    else if (respantinimigo =='b') {
      printf("O inimigo defendeu!\n\n");
    }
    else if (respantinimigo == 'c') {
      printf("O inimigo recarregou!\n\n");
      }
    printf("*******************************************************************\n\n");
    printf("\t\t\t Rodada %d\n\n Sua Vida :    %d\t\t\tVida do adversário :    %d\n\n Sua Energia : %d\t\t\tEnergia do adversário : %d\n", rodada, vida1, vida2, energia1, energia2);





    if (vida1 == 0 && vida2 == 0) {
        printf("\n\n A batalha terminou empatada!\n");
        printf("\n*******************************************************************\n\n");
        return 'e';
      }
    else if (vida1 == 0) {
        printf("\n\n Você perdeu a batalha!\n");
        printf("\n*******************************************************************\n\n");
        return 'd';
      }
    else  {
        printf("\n\n Você ganhou a batalha!\n");
        printf("\n*******************************************************************\n\n");
        return 'v';
    }

}

int main () {
  char resposta1, resposta2, resposta3, resposta4, resposta5, resposta6, resposta7, resposta8,resposta9, resposta10, resposta11, resultado_batalha1, resultado_batalha2, jogar_novamente; 
  do {
    resposta5 = 'k', resposta7 = 'k', resposta8 = 'k';/* Isto foi feito com a intenção de mudar os valores das respostas, para que se o jogador quiser jogar novamente, as escolhas da jogatina passado não influenciem na jogatina seguinte*/
  system("clear");
  printf("\n Domingo, dia 21/7/2019\n Em uma manhã normal de domingo, você acorda às 9 horas da manhã, como sempre, e já tem que tomar a sua primeira decisão do dia:\n\n");
  printf(" O que você faz primeiro?\n\n\ta) Colocar os óculos\n\tb) Olhar o celular\n\tc) Ir ao banheiro enxaguar o rosto\n\n");
  printf(" Escolha: ");
  resposta1 = escolha();
  system("clear");
  while (resposta1 != 'a' && resposta1 != 'b' && resposta1 != 'c'){
  escolha_certa();
  printf(" O que voce faz primeiro?\n\n\ta) Colocar os óculos\n\tb) Olhar o celular\n\tc) Ir ao banheiro enxaguar o rosto\n\n");
  printf(" Escolha: ");
  resposta1 = escolha();
  system("clear");
}

  if (resposta1 == 'a') { 
    printf("\n Você coloca seus óculos, olha para o seu celular");
  } 
  else if (resposta1 == 'b') {
    while (resposta1 == 'b') {
      printf("\n Você tem certeza que você vai olhar o seu celular antes mesmo de colocar seus óculos?\n Esqueceu que você tem 5 graus de hipermetropia?\n\n Faça sua escolha novamente: ");
      printf("\n\ta) Colocar os óculos\n\tb) Olhar o celular\n\tc) Ir ao banheiro enxaguar o rosto\n\n");
      printf(" Escolha: ");
      resposta1 = escolha();
      system("clear");  
    }
    while (resposta1 != 'a' && resposta1 != 'c'){
      escolha_certa();
      printf(" O que voce faz primeiro?\n\n\ta) Colocar os óculos\n\tb) Olhar o celular\n\tc) Ir ao banheiro enxaguar o rosto\n\n");
      printf(" Escolha: ");
      resposta1 = escolha();
      system("clear");  
      while (resposta1 == 'b') {
      printf("\n Você tem certeza que você vai olhar o seu celular antes mesmo de colocar seus óculos?\n Esqueceu que você tem 5 graus de hipermetropia?\n\n Faça sua escolha novamente: ");
      printf("\n\ta) Colocar os óculos\n\tb) Olhar o celular\n\tc) Ir ao banheiro enxaguar o rosto\n\n");
      printf(" Escolha: ");
      resposta1 = escolha();
      system("clear");  
    }
  }

    if (resposta1 == 'a') { 
      printf("\n Você coloca seus óculos e olha para o seu celular");
    } 
    else {
      printf("\n Você vai ao banheiro enxaguar o rosto, volta pro seu quarto, coloca seus óculos e olha para o seu celular");
    }
  } 
  else {
    printf("\n Você vai ao banheiro enxaguar o rosto, volta pro seu quarto, coloca seus óculos, olha para o seu celular");
  }
 printf(" e percebe que recebeu uma mensagem de um número desconhecido durante a madrugada.\n Você desbloqueia seu celular, abre o Whastaspp e lê a mensagem:\n\n");
 printf("\t'Seu futuro está em minhas mãos'\n\n A pessoa que enviou a mensagem não possui foto de perfil e você não entende direito a mensagem, mas cabe a você tomar uma decisão.\n\n");
 printf(" O que você vai fazer agora?\n\n\ta) Responder a mensagem perguntando quem é a pessoa que enviou\n\tb) Ignorar a mensagem e não fazer mais nada a respeito\n\tc) Bloquear o contato para não receber mais mensagens\n\n");
 printf(" Escolha: ");
 resposta2 = escolha();
 system("clear"); 
 while (resposta2 != 'a' && resposta2 != 'b' && resposta2 != 'c'){
  escolha_certa();
   printf(" O que você vai fazer agora?\n\n\ta) Responder a mensagem perguntando quem enviou\n\tb) Ignorar a mensagem e não fazer mais nada a respeito\n\tc) Bloquear o contato para não receber mais mensagens\n\n");
   printf(" Escolha: ");
   resposta2 = escolha();
   system("clear"); 
  }
  if (resposta2 == 'a') {
    printf("\n Você responde a mensagem e imediamente já recebe uma resposta exatamente assim:\n\n\t'Você saber da minha identidade não vai fazer diferença alguma, o que você deve saber é que eu estou tomando as suas decisões por você'\n");
  }
  else if (resposta2 == 'c') {
    printf("\n Você vai bloquear o contato, e quando está prestes a clicar no botão, você recebe uma mensagem do próprio dizendo o seguinte:\n\n");
    printf("\t'Eu sei que você está prestes a fazer isso, mas não me bloqueie, você precisa saber que eu que estou tomando suas decisões por você,\n\t eu sabia que você ia me bloquear porque fui eu quem escolhi isso, acredite em mim!'\n");
  }
  else {
    printf("\n Você visualiza a mensagem e ignora, instantes depois disso, você recebe outra mensagem do desconhecido exatamente assim:\n\n");
    printf("\t'Agora que você decidiu me ignorar, por favor, acredite em mim, eu estou tomando suas decisões por você, foi eu quem decidi que você ignorasse a mensagem'\n");
  }
  printf("\n Você lê a mensagem e começa a pensar a respeito. Por um lado, você pensa que é impossível que outra pessoa esteja fazendo as decisões por você.\n Por outro lado, ");
  if (resposta2 == 'a') 
    printf("você pensa em como a pessoa respondeu tão rápido a sua mensagem, como se ela até já soubesse que você ia enviar e já tinha a resposta pronta,\n");
  else if (resposta2 == 'b' )
    printf("você pensa em como a pessoa te mandou mensagem sabendo que você tinha decidido ignorar a mensagem.\n");
  else
    printf("você pensa em como a pessoa te mandou uma mensagem instantes antes de você a bloquear, como se ela realmente soubesse a sua decisão.\n");
  if (resposta1 == 'a') {
    printf("\n Nesse instante você se lembra que você, quando acordou, colocou os óculos e olhou o celular, sem nem mesmo antes ter ido ao banheiro enxaguar o rosto, assim como você faz todos os dias\n");
  }
    printf(" Você pensa a respeito e tem de tomar uma decisão:\n O que você faz agora?\n\n\ta) Você vai acreditar na história do desconhecido e mandar uma mensagem para ele para saber mais a respeito\n\tb) Você não vai acreditar na história do desconhecido, e vai simplesmente deixá-lo de lado e nao fazer mais nada a respeito\n\n");
    printf(" Escolha: ");
    resposta3 = escolha ();
    system("clear");  
    while (resposta3 != 'a' && resposta3 != 'b') {
      escolha_certa_2();
      printf(" O que você faz agora?\n\n\ta) Você vai acreditar na história do desconhecido e mandar uma mensagem para ele para saber mais a respeito\n\tb) Você não vai acreditar na história do desconhecido, e vai simplesmente deixá-lo de lado e nao fazer mais nada a respeito\n\n");
      printf(" Escolha: ");
      resposta3 = escolha();
      system("clear");  
    }
    if(resposta3 == 'a') {
      printf("\n Você então acredita na história, apesar de ainda estar achando isso muito estranho, e envia uma mensagem pro desconhecido para saber mais sobre o que está acontecendo\n");
      printf(" Ele te responde:\n\n\t'Prazer, pode me chamar de Lester! Para te dar uma sensação de livre arbítrio, mesmo que falsa, vou deixar você me fazer a pergunta que você quiser mesmo já sabendo qual vai ser a pergunta'\n\n");
      printf(" O quê você pergunta ao Lester?\n\n\ta) Como e por que você está tomando as decisões por mim?\n\tb) Qual era o nome do meu cachorro da infância?\n\tc) Você poderia escrever todos os números inteiros de 1 a 1000 para mim?\n\n");
      printf(" Escolha: ");
      resposta4 = escolha();
      system("clear");
      while (resposta4 != 'a' && resposta4 != 'b' && resposta4 != 'c'){
      escolha_certa();
      printf(" O quê você pergunta ao Lester?\n\n\ta) Por que e como você está tomando as decisões por mim?\n\tb) Qual era o nome do meu cachorro da infância?\n\tc) Você poderia escrever todos os números inteiros de 1 a 1000 para mim?\n\n");
      printf(" Escolha: ");
      resposta4 = escolha();
      system("clear");
      }
      switch (resposta4) {
        case 'a':
          printf("\n Milésimos de segundos depois de você enviar a mensagem, ele já responde:\n\n");
          printf("\t 'O por quê de eu estar fazendo isso eu ainda não entendi completamente, mas eu posso te dizer o como.\n\t  Estão sendo apresentadas para mim de 2 a 3 opções de escolha que são ações para você fazer, e eu tenho que decidir qual dessas ações você vai realizar'\n");
        break;
        case 'b':
          printf("\n Milésimos de segundos depois de você enviar a mensagem, ele já responde:\n\n");
          printf("\t 'O seu cachorro de infância era um poodle muito fofinho que se chamava Antônio Luciano, mas isso não tem relevância ao caso,\n\t  só escolhi essa pergunta pra dar uma zoada rsrs. O que realmente importa é o por quê e como eu estou fazendo isso.\n");
          printf("\t  O por quê de eu estar fazendo isso eu ainda não entendi completamente, mas eu posso te dizer o como.\n\t  Estão sendo apresentadas para mim de 2 a 3 opções de escolha que são ações para você fazer, e eu tenho que decidir qual dessas ações você vai realizar'\n");        
        break;
        default:
          printf("\n Milésimos de segundos depois de você enviar a mensagem, ele responde com os 1000 números que você pediu e com algumas frases:\n\n");
          printf("\t 'Esses números não tem relevância alguma para o caso,\n\t  só escolhi essa pergunta pra dar uma zoada rsrs. O que realmente importa é o por quê e como eu estou fazendo isso.\n");
          printf("\t  O por quê de eu estar fazendo isso eu ainda não entendi completamente, mas eu posso te dizer o como.\n\t  Estão sendo apresentadas para mim de 2 a 3 opções de escolha que são ações para você fazer, e eu tenho que decidir qual dessas ações você vai realizar'\n");
        }
      printf("\n O que já não fazia nenhum sentido na sua cabeça passa a fazer menos sentido ainda, você começa a pensar sobre tudo o que aconteceu e sobre tudo o que o Lester te disse\n e começa a questionar se é possível que tudo isso esteja acontecendo. Depois de pensar bastante, é hora de tomar uma decisão\n");
      printf("\n O que você vai fazer agora?\n\t a) Perguntar ao Lester se exise alguma maneira de acabar com tudo isso\n\t b) Não responder ao Lester, fingir que nada aconteceu e tentar seguir a vida\n\n");
      printf(" Escolha: ");
      resposta5 = escolha();
      system("clear");
      while (resposta5 != 'a' && resposta5 != 'b'){
      escolha_certa_2();
      printf("\n O que você vai fazer agora?\n\n\t a) Perguntar ao Lester se exise alguma maneira de acabar com tudo isso\n\t b) Não responder ao Lester, fingir que nada aconteceu e tentar seguir a vida\n\n");
      printf(" Escolha: ");
      resposta5 = escolha();
      system("clear");
      }


}   
    else if (resposta3 == 'b'){
      printf("\n Você não acredita em toda esta história, deixa o desconhecido de lado e segue a vida\n Passam-se 30 minutos e ele não te manda mais nenhuma mensagem. Você começa a estranhar, pois parecia que ele estava com muita vontade\n de falar com você, e depois de você ignorá-lo, ele simplesmente não te mandou mais nada. Cabe a você tomar uma decisão no momento\n");
      printf("\n O quê você vai fazer agora?\n\n\ta) Mandar uma mensagem pro desconhecido perguntando o por quê de ele não ter mais insistido\n\tb) Esperar mais tempo para ver se o desconhecido manda outra mensagem\n\n");
      printf(" Escolha: ");
      resposta6 = escolha();
      system("clear");
      while (resposta6 != 'a' && resposta6 != 'b'){
      escolha_certa_2();
      printf("\n O quê você vai fazer agora?\n\n\ta) Mandar uma mensagem pro desconhecido perguntando o por quê de ele não insistido mais\n\tb) Esperar mais tempo para ver se o desconhecido manda outra mensagem\n\n");
      printf(" Escolha: ");
      resposta6 = escolha();
      system("clear");
      }
      if (resposta6 == 'a') {
        printf("\n Você então manda outra mensagem para ele e ele prontamente te responde:\n\n\t'Hehehehe, se você realmente não acreditou em mim, por quê você veio me mandar mensagem? Será que é por que eu estou 'te controlando'?\n");
        printf("\t Vou-lhe explicar melhor o que está acontecendo, eu me chamo Lester e estou tomando decisões por você. Estão sendo apresentadas a mim de 2 a 3 opções\n\t de escolha que são ações para você fazer e eu tenho de escolher uma dessas, e você realiza a ação que eu escolhi. Confuso, mas pode acreditar que é verdade!'\n");
      }
      else if (resposta6 == 'b'){
        printf("\n Você então não envia outra mensagem pro desconhecido e fica à espera para ver se ele manda outra mensagem. Instantes após isso, você recebe uma mensagem dele:\n\n\t'Hahahaha, achou que iria conseguir se livrar de mim de maneira tão fácil assim? Você por acaso se esqueceu que eu que estou tomando as decisões por você?\n");
        printf("\t Vou-lhe explicar o que está acontecendo de maneira mais detalhada. Prazer, meu nome é Lester e eu sou o cara que pode mudar seu futuro.\n\t Estão sendo apresentadas a mim de 2 a 3 opções de escolha que são ações para você executar. Cabe a mim escolher uma dessas opções e, dessa forma, determinar a maneira com que você age");
        printf("\n\t Como eu gosto de jogar no modo hard, eu escolhi que você não acreditasse em mim no primeiro momento, mas agora já te dei provas mais que suficientes para provar que é tudo verdade'\n");
      }
      printf("\n Cabe a você tomar uma decisão tomar uma decisão importante nesse momento\n");
      printf("\n O que você vai fazer agora?\n\n\t a) Continuar não acreditando na história do Lester, e passar a ignorar todas as suas mensagens a partir de agora\n\t b) Passar a acreditar na história de Lester e mandar uma mensagem pra ele para saber mais sobre e perguntando se existe algum jeito de acabar com isso\n\n");
      printf(" Escolha: ");
      resposta7 = escolha();
      system("clear");
      while (resposta7 != 'a' && resposta7 != 'b'){
      escolha_certa_2();
      printf("\n O que você vai fazer agora?\n\n\t a) Continuar não acreditando por que não faz nenhum sentido\n\t b) Passar a acreditar na história de Lester e mandar uma mensagem pra ele para saber mais sobre e perguntando se existe algum jeito de acabar com isso\n\n");
      printf(" Escolha: ");
      resposta7 = escolha();
      system("clear");
      }
    }
      if (resposta5 == 'a' || resposta7 == 'b') {
        printf("\n Você então manda uma mensagem pro Lester peguntando como acabar com tudo isso e ele prontamente te responde:\n\n\t'Existe apenas uma maneira de você acabar com isso e eu vou te explicar como: você terá que sair de casa e terá que matar a primeira pessoa que você vir na rua.\n\t");
        printf(" Quando eu digo a primeira pessoa, tem que ser a primeira pessoa mesmo, por que senão, não vai funcionar.Você não poderá usar nenhuma arma\n\t Se você conseguir matar essa pessoa, você vai estar livre para tomar suas decisões pro resto da vida assim como era antes\n\t Por mais que pareça bizarro, pode acreditar em mim, é verdade!'\n\n Então você lê a mensagem, fica muito mais confuso do que já estava, mas mesmo assim tem de tomar uma decisão: \n");
        printf(" O quê você faz agora?\n\n\t a) Você vai acreditar que essa é sua única opção, e vai até a rua para tentar matar uma pessoa, assim como foi pedido pelo Lester.\n\t b) Você vai tentar se safar de outra maneira, pois você acha que não é capaz de matar uma pessoa apenas para seu pŕoprio bem\n\n");
        printf(" Escolha: ");
        resposta8 = escolha();
        system("clear");
        while (resposta8 != 'a' && resposta8 != 'b'){
        escolha_certa_2();
        printf("O quê você faz agora?\n\n\t a) Você vai acreditar que essa é sua única opção, e vai até a rua para tentar matar uma pessoa, assim como foi pedido pelo Lester.\n\t b) Você vai tentar se safar de outra maneira, pois você acha que não é capaz de matar uma pessoa apenas para seu próprio bem\n\n");
        printf(" Escolha: ");
        resposta8 = escolha();
        system("clear");
        }
        if (resposta8 == 'a') {
          printf("\n O Lester te dá mais algumas instruções de como tudo deve ser feito pelo Whatsapp, e então você após aquecer e ver uns vídeos no YouTube de como lutar melhor\n vai à rua em busca da liberdade. Você abre a porta de casa, sai e a primeira pessoa que você vê é um senhor de uns 50 anos usando uma bengala\n");
          printf(" Você olha bem pra ele e nota que, devido às condições do senhor, será uma luta teoricamente fácil para vencer. Você então respira bem fundo, e vai se aproximando por trás de senhor\n Quando você está a uns 5 metros dele, ele se vira e diz assim:\n\n\t-Olá menino, prazer, eu sou o Lester, você não é nem de longe a primeira pessoa contra quem eu batalho, mas talvez seja a primeira a vencer de mim, mate-me se for capaz!");
          printf("\n\n Então ele joga a bengala pra longe e vocês começam a batalhar");
          resultado_batalha1 = batalha1();
          if (resultado_batalha1 == 'v') {
            printf("\n Você então mata o Lester e aparentemente ninguém testemunhou o ato. Você leva o corpo para sua casa e tem de decidir como se livrar dele\n\n");
            printf(" Como você vai se livrar do corpo\n\n\ta) Você vai cortar o corpo em pedacinhos dar de comida pro seu cachorro\n\tb) Você vai enterrar o corpo no seu pŕoprio quintal\n\tc) Você vai queimar o corpo até virar pó e depois dar o pó para um viciado cheirar\n\n");
            printf(" Escolha: ");
            resposta9 = escolha();
            system("clear");
            while (resposta9 != 'a' && resposta9 != 'b' && resposta9 != 'c'){
            escolha_certa();
            printf("Como você vai se livrar do corpo\n\n\ta) Você vai cortar o corpo em pedacinhos dar de comida pro seu cachorro\n\tb) Você vai enterrar o corpo no seu pŕoprio quintal\n\tc) Você vai queimar o corpo até virar pó e depois dar o pó para um viciado cheirar\n\n");
            printf(" Escolha: ");
            resposta9 = escolha();
            system("clear");
            }
            switch (resposta9) {
              case 'a':
              printf("\n Você então corta o corpo em pedacinhos e da de comida pro seu cachorro que você tanto ama (por mais que não pareça)");
              break;
              case 'b' :
              printf("\n Você então enterra o corpo no seu próprio quintal");
              break;
              case 'c' :
              printf("\n Você então queima o corpo até virar pó, guarda o pó para depois dar pra um viciado cheirar (WTF?)");
              break;            
            }

            printf(" e depois, já se sentindo melhor (mesmo tendo matado uma pessoa)\n e sentindo que agora você tem controle das suas decisões, você vai para o seu quarto tentar dormir e esquecer tudo o que aconteceu.\n");
            printf(" Você se deita na cama e tenta dormir, passam-se 30 minutos, e você continua acordado. Será que é por que você já estava dormindo desde o começo de tudo?");
            printf("\n\n FIM DE JOGO\n\n");
          } 
          else if (resultado_batalha1 == 'd') {
          printf("\n Você então perde a batalha para o Lester, assim como todas as pessoas que lutaram contra ele na vida, e acaba morrendo.\n Lester faz com seu corpo o que ele faz com o corpo de todos os derrotados por ele: come no jantar.");
          printf("\n Como nem toda história tem um final feliz, você acaba sendo devorado pelo Lester, que ainda está vivíssimo e prontíssimo para conseguir novos corpos para saborear.");
          printf("\n\n FIM DE JOGO\n\n");
          }
          else if (resultado_batalha1 == 'e') {
          printf("\n Você e Lester então se matam ao mesmo tempo! Esse não é o final mais feliz da história mas pelo menos você foi o cara que conseguiu deter o Lester\n e que impediu ele de fazer mais vítimas. Você perdeu a sua vida, mas salvou a de dezenas de outras pessoas!");
          printf("\n\n FIM DE JOGO\n\n"); 
            }
          }
        else if (resposta8 == 'b') {
          printf("\n Você então manda outra mensagem pro Lester, perguntando se existe qualquer outra forma de resolver isso, e ele te responde que não, apenas matando alguém.\n Então só lhe resta uma opção: Passar a ignorar o Lester e tentar resolver isso sozinho.\n");
          }
        }
        if (resposta5 == 'b' || resposta7 == 'a' || resposta8 == 'b'){
            printf("\n Você então vai cortar o contato com o Lester, mas antes disso, você começa pensar que está louco ou que está apenas em um pesadelo\n Para descobrir se você está dormindo, você vai fazer o quê? \n");
            printf("\n O quê você vai fazer agora?\n\n\ta) Jogar um copo de água na cara para descobrir se está dormindo\n\tb) Se beliscar para descobrir se está dormindo\n\n");
            printf(" Escolha: ");
            resposta10 = escolha();
            system("clear");
            while (resposta10 != 'a' && resposta10 != 'b'){
            escolha_certa_2();
            printf("\n O quê você vai fazer agora?\n\n\ta) Jogar um copo de água na cara para descobrir se está dormindo\n\tb) Se beliscar para descobrir se está dormindo\n\n");
            printf(" Escolha: ");
            resposta10 = escolha();
            system("clear");
          }
            switch (resposta10) {
              case 'a':
              printf("\n Você então joga um copo de água gelada na cara, mas a única coisa que acontece é você ficar com frio.\n");
              break;
              case 'b':
              printf("\n Você então se belisca, mas a única coisa que acontece é você sentir dor, pois deu um belisco muito forte tamanha a sua raiva no momento.\n");
              break;
            }
            printf("\n Agora que você já sabe que não está sonhando, você esconde o seu celular para cortar o contato com o Lester, e após isso, você tem que fazer outra escolha\n");
            printf("\n O que você faz agora:\n\n\ta) Assistir televisão para tentar esquecer tudo isso que está acontecendo\n\tb) Sentar no sofá e começar a refletir sobre tudo o que está acontecendo\n\n");
            printf(" Escolha: ");
            resposta11 = escolha();
            system("clear");
            while (resposta11 != 'a' && resposta11 != 'b'){
            escolha_certa_2();
            printf("\n O que você faz agora:\n\n\ta) Assistir televisão para tentar esquecer tudo isso que está acontecendo\n\tb) Sentar no sofá e começar a refletir sobre tudo o que está acontecendo\n\n");
            printf(" Escolha: ");
            resposta11 = escolha();
            system("clear");
          }
            switch (resposta11) {
              case 'a':
              printf("\n Você então liga a televisão e começa a assistir a um filme qualquer, quando de repente, no meio do filme, a imagem do filme é interrompida e é mostrada uma mensagem na tela:\n\n\t'Você não vai conseguir se livrar de mim tão facilmente'\n\n");
              printf(" Como você já decidiu que não quer ter mais contato com o Lester, você rapidamente desliga a televisão.\n Depois disso, você começa a pensar que está realmente tendo sua escolhas decididas por outra pessoa, e começa a surtar.\n");
              printf(" Você começa a pensar também que está sendo perseguido pelo Lester, e que não vai conseguir fugir dele jamais.\n");
              break;
              case 'b' :
              printf("\n Você então senta no sofá e começa a pensar. Você começa a achar que realmente está sendo manipulado por outra pessoa.\n");
              break;
              }
              printf(" Você pensa mais, mais, mais um pouco, e começa literalmente a surtar.\n Você está totalmente surtado, até que você começa uma luta contra o seu cérebro\n E como tudo no mundo, esta luta tem regras");
              resultado_batalha2 = batalha1();
              switch (resultado_batalha2) {
                  case 'v':
                    printf("\n Você então vence a batalha contra seu cérebro e aparentemente, tudo parece normal, você não se sente mais manipulado.\n Você entra no Whatsapp para ver o que aconteceu com o Lester, e você nota que a conversa com ele não está mais lá.\n Você percebe que tudo isso que aconteceu não passou de um delírio da sua cabeça e que agora tudo voltou a ser como era antes...");
                    printf("\n\n FIM DE JOGO\n\n");
                  break;
                  case 'e':
                  printf("\n A batalha contra seu cérebro termina empatada, e o seu surto acaba.\n Você chega a conclusão de que você está apenas sonhando mesmo\n");
                  if (resposta10 == 'a')
                      printf("E se você tivesse se beliscado ao invés de ter jogado o copo de água no rosto, será que você teria concluído isso antes?");
                  else if (resposta10 == 'b')
                      printf(" E se você tivesse jogado o copo água no rosto ao invés de ter se beliscado, será que você teria concluído isso antes?");
                  printf("\n\n FIM DE JOGO\n\n");
                  break;
                  case 'd':
                  printf("\n Você então perde a luta para o seu cérebro e, sem ter mais o que fazer, você vai até a cozinha, abre a gaveta, pega um facão e se mata...\n Mas e se tudo isso tiver sido apenas um sonho?");
                  printf("\n\n FIM DE JOGO\n\n");
                  break;
                  }
              }
              printf(" Você deseja jogar novamente desde o início?\n\n\ta) Sim\n\tb) Não\n\n");
              printf(" Escolha: ");
              jogar_novamente = escolha();
              system("clear");
              while (jogar_novamente != 'a' && jogar_novamente != 'b'){
              escolha_certa_2();
              printf(" Você deseja jogar novamente desde o início?\n\n\ta) Sim\n\tb) Não\n\n");
              printf(" Escolha: ");
              jogar_novamente = escolha();
              system("clear");
              }
      }
        while(jogar_novamente == 'a');


      










    
return 0;
}
