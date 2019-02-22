#include "ft_printf.h"

int main()
{
	int	a;
	int	b;
    float c = 0.1234;
    
	a = ft_printf("\033[35mMY:%-10.7ld\n",847888877248);        //MY output
    b = printf("\033[36mLB:%-10.7ld\n",847888877248);          //LIB output
	printf("\033[mMY: %d, LB: %d", a, b);                     //Int value compare between LIB an MY printf
	return (0);
}
