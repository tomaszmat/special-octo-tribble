
void UCA0_Init(int _baudrate, uint32_t _clk, int _clk_source, int _interrupt)
{// Init USCI_A0 UART0
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

void UCA1_Init(int _baudrate, uint32_t _clk, int _clk_source, int _interrupt)
{// Init USCI_A1 UART1
    UCA1.Clock = _clk;
    UCA1.Baudrate = _baudrate;
    UCA1.ClockSource = _clk_source;
    
    int USCI_DIV_INT = (int)(_clk/_baudrate);
    
    float USCI_DIV_FRAC_NUMERATOR    =   (_clk - (USCI_DIV_INT*_baudrate));
    int USCI_DIV_FRAC_NUM_X_8      =   (int)(USCI_DIV_FRAC_NUMERATOR*8);
    int USCI_DIV_FRAC_X_8          =   (int)(USCI_DIV_FRAC_NUM_X_8/_baudrate);

    
    UCA1.BR0 = (USCI_DIV_INT & 0x00FF) ;
    UCA1.BR1 = ((USCI_DIV_INT >> 8) & 0xFF);
    
    if (((USCI_DIV_FRAC_NUM_X_8-(USCI_DIV_FRAC_X_8*_baudrate))*10)/_baudrate < 5)
    {   
        UCA1.BRS  =  (USCI_DIV_FRAC_X_8<< 1);
    }
    else
    {   
        UCA1.BRS  =  ((USCI_DIV_FRAC_X_8+1)<< 1);
    }
    
    /*
    UCA1CTL1    |= UCA1.ClockSource  + UCSWRST;
    UCA1BR0      = UCA1.BR0;
    UCA1BR1      = UCA1.BR1;
    UCA1MCTLW    = UCA1.BRS;
    UCA1CTL1    &= ~UCSWRST; // Initialize USCI state machine
    if(_interrupt == 1) 
    {
            UC0IE |= UCA1RXIE;
    }
    */
}
void UCB0_Init(int _baudrate, uint32_t _clk, int _clk_source)
{// Init USCI_B0 spi
    UCB0.Clock = _clk;
    UCB0.Baudrate = _baudrate;
    UCB0.ClockSource = _clk_source;
    
    int USCI_DIV_INT = (int)(_clk/_baudrate);
    
    float USCI_DIV_FRAC_NUMERATOR    =   (_clk - (USCI_DIV_INT*_baudrate));
    int USCI_DIV_FRAC_NUM_X_8      =   (int)(USCI_DIV_FRAC_NUMERATOR*8);
    int USCI_DIV_FRAC_X_8          =   (int)(USCI_DIV_FRAC_NUM_X_8/_baudrate);

    
    UCB0.BR0 = (USCI_DIV_INT & 0x00FF) ;
    UCB1.BR1 = ((USCI_DIV_INT >> 8) & 0xFF);
    
    if (((USCI_DIV_FRAC_NUM_X_8-(USCI_DIV_FRAC_X_8*_baudrate))*10)/_baudrate < 5)
    {   
        UCB0.BRS  =  (USCI_DIV_FRAC_X_8<< 1);
    }
    else
    {   
        UCB0.BRS  =  ((USCI_DIV_FRAC_X_8+1)<< 1);
    }
    
    /*
    UCB0CTL1    |= UCB0.ClockSource  + UCSWRST;
    UCB0CTL0    |= UCCKPH + UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master, Clock Polarity High
    UCB0BR0      = UCB0.BR0;
    UCB0BR1      = UCB0.BR1;
    UCB0MCTLW    = UCB0.BRS;
    UCB0CTL1    &= ~UCSWRST; // Initialize USCI state machine 
	*/
}