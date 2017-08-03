/* 
 * File:   buttons.h
 * Author: Fabio WD/Felipe Cabral
 *
 * Created on 12 de Junho de 2017, 10:51
 */

#define BT_ONOFF        PIN_D7

#define BT_YELLOW_P1    PIN_A0
#define BT_BLUE_P1      PIN_A1
#define BT_RED_P1       PIN_A2
#define BT_GREEN_P1     PIN_A3

#define BT_YELLOW_P2    PIN_A4
#define BT_BLUE_P2      PIN_A5
#define BT_RED_P2       PIN_A6
#define BT_GREEN_P2     PIN_A7

int16 input_color;
int delay_debounce = 10;
int player = 0;

int select_buttomn_pressed(int size)
{
    if(input_state(BT_YELLOW_P1) == 1)
    {
        delay_ms(delay_debounce);
        if(input_state(BT_YELLOW_P1) == 1)
        {
            input_color = LED_YELLOW;
            player = 1;
        }
    }
    else if(input_state(BT_BLUE_P1) == 1)
    {
        delay_ms(delay_debounce);
        if(input_state(BT_BLUE_P1) == 1)
        {
            input_color = LED_BLUE;
            player = 1;
        }
    }
    else if(input_state(BT_RED_P1) == 1)
    {
        delay_ms(delay_debounce);
        if(input_state(BT_RED_P1) == 1)
        {   
            input_color = LED_RED;
            player = 1;
        }
    }    
    else if(input_state(BT_GREEN_P1) == 1)
    {
        delay_ms(delay_debounce);
        if(input_state(BT_GREEN_P1) == 1)
        {
            input_color = LED_GREEN;
            player = 1;
        }
    }    
    else if(input_state(BT_YELLOW_P2) == 1)
    {
        delay_ms(delay_debounce);
        if(input_state(BT_YELLOW_P2) == 1)
        {
            input_color = LED_YELLOW;
            player = 2;
        }
    }
    else if(input_state(BT_BLUE_P2) == 1)
    {
        delay_ms(delay_debounce);
        if(input_state(BT_BLUE_P2) == 1)
        {
            input_color = LED_BLUE;
            player = 2;
        }
    }
    else if(input_state(BT_RED_P2) == 1)
    {
        delay_ms(delay_debounce);
        if(input_state(BT_RED_P2) == 1)
        {   
            input_color = LED_RED;
            player = 2;
        }
    }    
    else if(input_state(BT_GREEN_P2) == 1)
    {
        delay_ms(delay_debounce);
        if(input_state(BT_GREEN_P2) == 1)
        {
            input_color = LED_GREEN;
            player = 2;
        }
    }    
    
    if(add_in_sequence_player(player, input_color, size))
    {
        if(player == 1)
            return 1;
        else 
            return 2;
    }
    return 0;
    
}
