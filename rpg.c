/**
 * Descrição:
 *      Projeto de implementação de pipes em um programa que contém mais de 1 processo
 *      para a disciplina de Sistemas Operacionais
 *
 * Autoria:
 *      Tuanne Assenço - tuanne.assenco@gmail.com
 *      Gabriel Garcia
 *
 * Compilado da seguinte forma:
 *      $ gcc -Wall rpg.c -o rpg; ./rpg
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "instructions.h"
#include "player_cutomization_race.h"
#include "player_customization_class.h"
#include "decks.h"
#include "attack_move.h"
#include "defense_move.h"
#include "player_1.h"
#include "player_2.h"
#include "print_colors.h"

// VERIFICA O SISTEMA OPERACIONAL PARA SUBSTITUIR FUNÇÕES DE LIMPEZA DE TELA, BUFFER E SLEEP
#if defined(__MINGW32__) || defined(_MSC_VER)
#define clean_input() fflush(stdin)
#define clear_screen() system("cls")
#define sleep() system("timeout 1")
#else
#include <stdio_ext.h>
#define clean_input() __fpurge(stdin)
#define clear_screen() system("clear")
#define sleep() system("sleep 1")
#endif

// funções de controle de cor para visualização do usuário
void print_pink(char *s);
void print_yellow(char *s);
void print_blue(char *s);
void print_green(char *s);
void print_green(char *s);
void print_red(char *s);
void print_white(char *s);
void print_cyan(char *s);

  int attack_move(Attack_arr player_attack);
  float defense_move(int damage);
  int player_1(int readfd, int writefd);
  int player_2(int readfd, int writefd);

int main()
{

  //system("clear");

  void instructions();
  int player_customization_race();
  int player_customization_class();
  Attack_arr selected_deck(int deck_index);


  int descriptor, // usado para criar o processo filho pelo fork
      pipe1[2],  // comunicação, pai -> filho jogador1
      pipe2[2];  // comunicação, filho -> pai  jodagor2


  getchar();


  instructions();


  if (pipe(pipe1) < 0 || pipe(pipe2) < 0)
	{
		print_red("\nrpg.c: Erro na chamada do pipe");
		printf("\nerror: pipe1 = %d pipe2 = %d", pipe(pipe1), pipe(pipe2));
		exit(0);
	}

  if((descriptor = fork()) < 0) {

    print_red("Error: Call FORK()");
    exit(0);

  } else if(descriptor > 0) { // Processo PAI

    close(pipe1[0]);          // Fecha leitura no pipe1
    close(pipe2[1]);          // Fecha escrita no pipe2

    player_1(pipe2[0], pipe1[1]);

    close(pipe1[1]); // fecha escrita pipe1
    close(pipe2[0]); // fecha leitura pipe2

  } else {

    close(pipe1[1]); // fecha escrita no pipe1
    close(pipe2[0]); // fecha leitura no pipe2

    player_2(pipe1[0], pipe2[1]); //

    close(pipe1[0]); // fecha leitura no pipe1
    close(pipe2[1]); // fecha escrita no pipe1


    fflush(stdout);
    printf("Teve bom!");
    getchar();

  }

  return 0;
}
