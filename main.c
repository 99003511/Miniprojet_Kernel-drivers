#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    FILE *sio, *sdir, *sval;
    FILE *lio, *ldir, *lval;

    sio = fopen("/sys/class/gpio/export", "w");
    fseek(sio, 0, SEEK_SET);
    fprintf(sio, "%d", 115);
    fflush(sio);
    fclose(sio);

    lio = fopen("/sys/class/gpio/export", "w");
    fseek(lio, 0, SEEK_SET);
    fprintf(lio, "%d", 49);
    fflush(lio);
    fclose(lio);

    sdir = fopen("/sys/class/gpio/gpio115/direction", "w");
    fseek(sdir, 0, SEEK_SET);
    fprintf(sdir, "in");
    fflush(sdir);
    fclose(sdir);

    ldir = fopen("/sys/class/gpio/gpio49/direction", "w");
    fseek(ldir, 0, SEEK_SET);
    fprintf(ldir, "out");
    fflush(ldir);

    lval = fopen("/sys/class/gpio/gpio49/value", "w");
    fseek(lval, 0, SEEK_SET);

    volatile int s_rate;

    while (1)
    {
        fprintf(lval, "%d", 1);
        fflush(lval);
        if (lval)
        {
            sval = fopen("/sys/class/gpio/gpio115/value", "r");
            fseek(sval, 0, SEEK_SET);
            fscanf(sval, "%d", &s_rate);
            if (s_rate)
            {

                int c = c + 1;
                //sleep(10);
                printf("No. of persons detected =%d\n", c);
                
            }
        }

        if (s_rate == 0)
        {
            fprintf(lval, "%d", 0);
            fflush(lval);
            printf("Not detected come once again\n");
        }
        sleep(1);

        fflush(sval);
    }
    return 0;
}
