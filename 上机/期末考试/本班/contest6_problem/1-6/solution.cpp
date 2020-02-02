#include <stdio.h>

int main() {
	int y, d, date, inputOk=1;
    int monthDays;

	scanf("%d%d", &y, &d);
    if (y < 1900 || y > 2100)
        inputOk = 0;
    if ( (y%4==0)&&(y%100!=0) || (y%400==0))
        monthDays = 29;
    else
        monthDays = 28;
    if (d < 1 || d > monthDays)
        inputOk = 0;

	if ( !inputOk )
        printf("-1");
    else {
	    printf("%d", d % 7);
    }

	return 0;
}