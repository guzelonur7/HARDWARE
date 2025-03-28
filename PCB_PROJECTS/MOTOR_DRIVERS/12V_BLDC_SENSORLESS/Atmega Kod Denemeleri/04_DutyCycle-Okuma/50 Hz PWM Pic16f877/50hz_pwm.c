/*
* bldc reciver sinyalini test etmek i�in olu�turulan 250hz pwm sinyal kodu. 
* analog potansiyometre ile kontrol edilmektedir. 
* 
*
*    !!!! OSIALTOR FREKANSI G�NCELLEND� KODU TEKRAR KONTROL ET VE Y�KLE !!!!
*/

#include<18f4550.h>
#device ADC=8
#use delay(clock=500KHz)
#fuses intrc,cpudiv1,nolvp,nobrownout,intrc_io
#define PWM_MIN 12   // 1ms 1000us
#define PWM_MAX 25   // 2ms 2000us

unsigned int deger=0;


void main(){

setup_oscillator(OSC_500KHZ);
set_tris_a(0x01);
set_tris_c(0x00);
output_c(0x00);
setup_adc(ADC_CLOCK_INTERNAL);
setup_adc_ports(AN0);
setup_ccp2(CCP_PWM);
setup_timer_2(T2_DIV_BY_16,156,1) ; // 50hz pwm 
set_pwm2_duty(PWM_MIN);




   while(true){
      
      set_adc_channel(0);
      delay_us(50);
      deger=read_adc();
      deger=(deger/33)+7.8;
      set_pwm2_duty(deger);
      
      
   
   }

}
