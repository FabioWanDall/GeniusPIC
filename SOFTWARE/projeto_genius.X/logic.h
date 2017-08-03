/* 
 * File:   logic.h
 * Author: Fabio WD/Felipe Cabral
 *
 * Created on 12 de Junho de 2017, 11:11
 */
#include <stdlib.h>

int size_p1 = 0;
int16 seq_p1[LIMITE];       // vetor de sequencia jogador 

int size_p2 = 0;
int16 seq_p2[LIMITE];       // vetor de sequencia gerada

boolean add_in_sequence_player(int player, int16 color, int size)
{
    if(player == 1)
    {
        seq_p1[size_p1] = color;
        size_p1++;
        if(size_p1 == size)
            return true;
    }
    else if(player == 2)
    {
        seq_p2[size_p2] = color;
        size_p2++;
        if(size_p2 == size)
            return true;
    }
    return false;
}

void reset_size_vec_players()
{
    size_p1 = 0;
    size_p2 = 0;
}


/*
 * Cria uma nova cor randomica para a sequencia e incrementa o tamanho
 */
int increment_sequence_size(int16 * sequence, int size)
{
    int val = rand() % 4;  //gera numero randimico de 0 até 3
    
    switch(val)
    {
        case 0: sequence[size] = LED_YELLOW;
        break;
        case 1: sequence[size] = LED_BLUE;
        break;
        case 2: sequence[size] = LED_RED;
        break;
        case 3: sequence[size] = LED_GREEN;
        break;
        default: sequence[size] = LED_GREEN;
    }
    
    size++;
    return size;
}

//Compara a sequencia dos dois jogadores com o gabarito
int16 compare_sequence(int16 * sequence, int16 * sequence_p1, int16 * sequence_p2, int size)
{
    boolean p1_fail = false;
    boolean p2_fail = false;
    
    for(int i = 0; i < size; i++) //Percorre todas as cores 
    {
        if(sequence_p1[i] != sequence[i])  //Compara o gabaraito com o jogador 1
            p1_fail = true;                //Seta flag de erro do jogador 1
        
        if(sequence_p2[i] != sequence[i])  //Compara o gabarito com o jogador 2
            p2_fail = true;                //Seta flag de erro do jogador 2
    }
    
    if(p1_fail && p2_fail) //se os dois erraram, os dois erraram
        return 1;
    else if(p1_fail) // se p1 errou e p2 acertou, p2 ganhou
        return LED_W_P2;
    else if(p2_fail) // se p2 errou e p1 acertou, p1 ganhou
        return LED_W_P1;
    else // se os dois acertaram, os dois venceram
        return 0;
}

/*
 * controla qual a sequencia de leds sera apresentada
 * com base no motivo do fim de jogo(valor de is_end)
 */
void show_end_leds(int16 is_end)
{
    if(is_end == 0)
        turn_on_led_two_winners();  // dois venceram
    else if(is_end == 1)
        turn_on_led_two_losers();   // dois perderam
    else
        turn_on_led_winner(is_end); // um vencedor
}