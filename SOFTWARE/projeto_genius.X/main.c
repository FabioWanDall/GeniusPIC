#define LIMITE 4
#include <main.h>    //01
#include <leds.h>    //02

#include <logic.h>   //04
#include <buttons.h> //03

#INT_TIMER0
void  TIMER0_isr(void) 
{

}

#INT_EXT
void  EXT_isr(void) 
{

}

void main()
{
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128);		//1,6 s overflow


	enable_interrupts(INT_TIMER0);
	enable_interrupts(INT_EXT);
	enable_interrupts(GLOBAL);
    
    //const int limit = 3;    // tamanho maximo do vetor; Nivel do jogo
    
    int size = 0;           // tamanho atual do vetor(preenchido)
    int16 seq[LIMITE];       // vetor de sequencia gerada
    
    int16 is_end = 0;       /* zero(0)  -> os dois acertaram 
                               um(1)    -> os dois erraram 
                               LED_W_P1 -> player 1 venceu
                               LED_W_P2-> player 2 venceu */
    
    boolean start = 0;
    
    
    
            boolean flag_p1 = false; //indica que o player 1 terminou sequencia
            boolean flag_p2 = false; //indica que o player 2 terminou sequencia
            int answer = 0;
    
            
    int8 atual_state_bt = input_a();
    
    while(TRUE)
    {
        while (!start) start = input_state(BT_ONOFF); // Aguarda botão de start para iniciar o jogo
        // zera variaveis de controle
        start = 0;
        is_end = 0;
        size = 0;

        while(is_end == 0) //Repete, enquanto jogo não acaba
        {


            turn_on_led_onoff();

            if(size < LIMITE && is_end == 0)   // Se não chegou no nivel máximo e nínguem errou
            {
                size = increment_sequence_size(&seq, size);   // gera sequencia
                show_sequence(seq, size);                     // mostra a sequencia
            }
            else  //caso fim de jogo
            {
               show_end_leds(is_end);        // mostra a sequencia de leds de fim de jogo
               is_end = -1;                  // seta flag de fim de jogo
            }

            //aguada entrada jogadores
            
            flag_p1 = false; //indica que o player 1 terminou sequencia
            flag_p2 = false; //indica que o player 2 terminou sequencia
            answer = 0;
            
            while(!flag_p1 && !flag_p2) // aguarda que os dois jogadores tenham completado asequencia
            {
                if(atual_state_bt != input_a())
                {
                    answer = select_buttomn_pressed(size);
                }
                if(answer == 1)
                    flag_p1 = true;
                if(answer == 2)
                    flag_p2 = true;
            }

            //turn_on_led_onoff();
            delay_ms(100);
            turn_off_led_onoff();

        }
    }
}
