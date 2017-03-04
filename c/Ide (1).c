//Handlig setttings for USCI

#include <stdint.h>
#include <stdio.h>

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


void UCA0_Init(int _baudrate, uint32_t _clk, int _clk_source, int _interrupt)
{
    UCA0.Clock = _clk;
    UCA0.Baudrate = _baudrate;
    UCA0.ClockSource = _clk_source;
    
    int USCI_DIV_INT = (int)(_clk/_baudrate);
    
    float USCI_DIV_FRAC_NUMERATOR    =   (_clk - (USCI_DIV_INT*_baudrate));
    int USCI_DIV_FRAC_NUM_X_8      =   (int)(USCI_DIV_FRAC_NUMERATOR*8);
    int USCI_DIV_FRAC_X_8          =   (int)(USCI_DIV_FRAC_NUM_X_8/_baudrate);

    
    UCA0.BR0 = (USCI_DIV_INT & 0x00FF) ;
    UCA0.BR1 = ((USCI_DIV_INT >> 8) & 0xFF);
    
    if (((USCI_DIV_FRAC_NUM_X_8-(USCI_DIV_FRAC_X_8*_baudrate))*10)/_baudrate < 5)
    {   
        UCA0.BRS  =  (USCI_DIV_FRAC_X_8<< 1);
    }
    else
    {   
        UCA0.BRS  =  ((USCI_DIV_FRAC_X_8+1)<< 1);
    }
    
    /*
    UCA0CTL1    |= UCA0.ClockSource;
    UCA0BR0      = UCA0.BR0;
    UCA0BR1      = UCA0.BR1;
    UCA0MCTLW    = UCA0.BRS;
    UCA0CTL1    &= ~UCSWRST; // Initialize USCI state machine
    if(_interrupt == 1) 
    {
            UC0IE |= UCA0RXIE;
    }
    */
}

int main(void)
{
    UCA0_Init(9600,8000000);
	printf(" %d %d %d", UCA0.BR0, UCA0.BR1, UCA0.BRS);
	return 0;
}

