//#include <stdlib.h>
/* 
 * File:   leds.h
 * Author: Fabio WD/Felipe Cabral
 *
 * Created on 12 de Junho de 2017, 08:48
 */

//
#define LED_ONOFF PIN_D0

#define LED_W_P2 PIN_D1
#define LED_W_P1 PIN_D2

#define LED_YELLOW PIN_D3
#define LED_RED PIN_D4
#define LED_GREEN PIN_D5
#define LED_BLUE PIN_D6

/*
 * recebe o endereço da cor que sera 
 * acendida e pisca por um periodo(delay)
 */
void turn_on_led(int16 color)
{
    output_high(color);
    delay_ms(300);
    output_low(color);
    delay_ms(300);
}
/*
 *apresenta sequencia de cores para o usuário
 */
void show_sequence(int16 sequence[], int size)
{
    for(int i = 0; i < size; i++)
    {
        turn_on_led(sequence[i]);
    }
}
/*
 *apresenta sequencia de piscar dos leds para
 *quando dois jogadores erram na mesma rodada
 */
void turn_on_led_two_losers()
{
    for(int i = 0; i < 2; i++)
    {
        output_high(LED_W_P2);
        output_high(LED_W_P1);
        output_high(LED_ONOFF);
        delay_ms(200);
        output_low(LED_W_P1);
        output_low(LED_W_P2);
        output_low(LED_ONOFF);
        delay_ms(200);
    }
    
}
/*
 *apresenta sequencia de piscar dos leds para
 *quando os dois chegam ao nivel máximo do jogo sem errar 
 */
void turn_on_led_two_winners() 
{
    for(int i = 0; i < 2; i++)
    {
        output_high(LED_W_P2);
        output_high(LED_W_P1);
        delay_ms(100);
        output_low(LED_W_P1);
        output_low(LED_W_P2);
        delay_ms(100);
        output_high(LED_W_P1);
        output_high(LED_W_P2);
        delay_ms(50);
        output_low(LED_W_P1);
        output_low(LED_W_P2);
        delay_ms(50);
        output_high(LED_W_P1);
        output_high(LED_W_P2);
        delay_ms(30);
        output_low(LED_W_P1);
        output_low(LED_W_P2);
        delay_ms(30);
    }
    output_high(LED_W_P1);
    output_high(LED_W_P2);
}
/*
 *apresenta sequencia de piscar dos leds para
 *quando há um vencedor no jogo
 */
void turn_on_led_winner(int16 player)
{
    for(int i = 0; i < 2; i++)
    {
        output_high(player);
        delay_ms(100);
        output_low(player);
        delay_ms(100);
        output_high(player);
        delay_ms(50);
        output_low(player);
        delay_ms(50);
        output_high(player);
        delay_ms(30);
        output_low(player);
        delay_ms(30);
    }
    output_high(player);
}

void turn_on_led_onoff()
{
    output_high(LED_ONOFF);
}

void turn_off_led_onoff()
{
    output_low(LED_ONOFF);
}

