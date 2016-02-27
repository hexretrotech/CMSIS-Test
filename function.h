#define alt_open_drain 0
#define input_floating 1
#define	input_pull_up 2
#define input_pull_down 3
#define analog 4
#define output_open_drain 5
#define output_push_pull 6
#define alt_push_pull 7


#define P0 0
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define P6 6
#define P7 7
#define P8 10
#define P9 11
#define P10 12
#define P11 13
#define P12 14
#define P13 15
#define P14 16
#define P15 17

#define PORTA 1
#define PORTB 2
#define PORTC 3

uint8_t modeR[8];

void APinConf(int pin, int mode, int port);
