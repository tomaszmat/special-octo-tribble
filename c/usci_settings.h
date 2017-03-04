/* Header */

typedef char data[8];

struct port
{
    data Recive;
    data Send;
    
    uint32_t Clock;
    int ClockSource;
    int Baudrate;
    
    int BR0;
    int BR1;
    int BRS; 

}UCA1, UCA0, UCB0;

void UCA0_Init(int _baudrate, uint32_t _clk, int _clk_source, int _interrupt);
void UCA1_Init(int _baudrate, uint32_t _clk, int _clk_source, int _interrupt);
void UCB0_Init(int _baudrate, uint32_t _clk, int _clk_source);