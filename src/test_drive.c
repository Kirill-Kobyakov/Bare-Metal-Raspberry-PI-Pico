#include <extcircuit.h>
#include <stdint.h>

#define CYCLES_FOR_40HZ 520256
#define CYCLES_PER_US 21

#define BTNR (1<<21)
#define BTNL (1<<22)
#define BTND (1<<26)
#define BTNC (1<<27)
#define BTNU (1<<28)
#define BTN  (BTNR | BTNL | BTND | BTNC | BTNU)

#define SW0 (1<<17)
#define SW1 (1<<18)
#define SW2 (1<<19)
#define SW3 (1<<20)
#define SW  (SW0 | SW1 | SW2 | SW3)

#define LED_PICO                (1<<25)
#define LED_GRN                 (1<<13)
#define LED_YLW                 (1<<14)
#define LED_RED                 (1<<15)
#define LED_BLU                 (1<<16)

#define PWM_L                   (1<<0)
#define L_MOTOR_DIRECTION_1     (1<<1)
#define L_MOTOR_DIRECTION_2     (1<<2)

#define PWM_R                   (1<<3)
#define R_MOTOR_DIRECTION_1     (1<<4)
#define R_MOTOR_DIRECTION_2     (1<<5)

#define ENC_L                   (1<<10)
#define ENC_R                   (1<<11)
#define ENC                     (ENC_L | ENC_R)

#define ENC_R_TO_INCH 50
#define ENC_TO_DEGREES 2.8
#define PWM_TOP 100

void sleep_us(uint32_t delay) {
    for(int i = 0; i < delay; i++);
}

void setDirectionForward() {
    set_gpio(L_MOTOR_DIRECTION_1);
    set_gpio(R_MOTOR_DIRECTION_1);
    clear_gpio(L_MOTOR_DIRECTION_2);
    clear_gpio(R_MOTOR_DIRECTION_2);
}

void setDirectionReverse() {
    set_gpio(L_MOTOR_DIRECTION_2);
    set_gpio(R_MOTOR_DIRECTION_2);
    clear_gpio(L_MOTOR_DIRECTION_1);
    clear_gpio(R_MOTOR_DIRECTION_1);
}

void setDirectionRight() {
    set_gpio(L_MOTOR_DIRECTION_1);
    set_gpio(R_MOTOR_DIRECTION_2);
    clear_gpio(L_MOTOR_DIRECTION_2);
    clear_gpio(R_MOTOR_DIRECTION_1);
}

void setDirectionLeft() {
    set_gpio(L_MOTOR_DIRECTION_2);
    set_gpio(R_MOTOR_DIRECTION_1);
    clear_gpio(L_MOTOR_DIRECTION_1);
    clear_gpio(R_MOTOR_DIRECTION_2);
}

void drive(uint32_t distance, uint8_t speed, float left_motor_bias) {
	uint32_t pins_read;
    uint32_t enc_l_cnt = 0;
    uint32_t enc_r_cnt = 0;

    uint32_t enc_l_lv = 0;
    uint32_t enc_r_lv = 0;

    unsigned int pwm_counter = 0;
    uint8_t duty_l = speed;
    uint8_t duty_r = speed;

    do {
        pins_read = read_gpio();
        if(((pins_read & ENC_L) >> 10) && (enc_l_lv == 0))
            enc_l_cnt++;
        if(((pins_read & ENC_R) >> 11) && (enc_r_lv == 0))
            enc_r_cnt++;

        enc_l_lv = (pins_read & ENC_L) >> 10;
        enc_r_lv = (pins_read & ENC_R) >> 11;

        pwm_counter++;
        if (pwm_counter >= PWM_TOP)
            pwm_counter = 0;

        if (pwm_counter < duty_l)
            set_gpio(PWM_L);
        else
            clear_gpio(PWM_L);

        if (pwm_counter < duty_r)
            set_gpio(PWM_R);
        else
            clear_gpio(PWM_R);

        if(enc_r_cnt < enc_l_cnt * left_motor_bias){
            if(duty_r + 3 <= PWM_TOP)
                duty_r += 3;
            if(duty_l - 3 >= 0)
                duty_l -= 3;
        }

        if(enc_l_cnt * left_motor_bias < enc_r_cnt){
            if(duty_l + 3 <= PWM_TOP)
                duty_l += 3;
            if(duty_r - 3 >= 0)
                duty_r -= 3;
        }
        sleep_us(10);
    } while (enc_r_cnt < distance);

    clear_gpio(PWM_L);
    clear_gpio(PWM_R);

}


int main ( void )
{
	configure_pins();
    // Enable Inputs on SW and ENC GPIO pins
	clear_gpio_output_enable(SW);
    clear_gpio_output_enable(ENC);

	uint32_t pins_read;
    target:

    while((read_gpio() & BTNR) == 0);

    setDirectionForward();
    drive(30 * ENC_R_TO_INCH, 80, 1);

    sleep_us(10000);

    setDirectionRight();
    //drive(100 * ENC_R_TO_INCH, 80, 1);
    drive(90 * ENC_TO_DEGREES, 80, 1);
    
    sleep_us(10000);


    setDirectionForward();
    drive(30 * ENC_R_TO_INCH, 80, 1);
    // setDirectionRight();
    // drive(90 * 2, 80, 0.2);

	while(1){
		pins_read = read_gpio();


        // if((rm_quad_count / ENC_R_TO_INCH) % 2 == 0)
        //     set_gpio(LED_RED);
        // else
        //     clear_gpio(LED_RED);

        if(pins_read & ENC_L)
            set_gpio(LED_GRN);
        else
            clear_gpio(LED_GRN);
        if(pins_read & ENC_R)
            set_gpio(LED_YLW);
        else 
            clear_gpio(LED_YLW);

        if(pins_read & SW3)
            set_gpio(LED_BLU);
        else
            clear_gpio(LED_BLU);

        if(pins_read & BTNR)
            goto target;

        // if(count > r_pwm_thresh)
        //     clear_gpio(PWM_R);
        // else
        //     set_gpio(PWM_R);

        // if(count > l_pwm_thresh)
        //     clear_gpio(PWM_L);
        // else
        //     set_gpio(PWM_L);
	}
}
