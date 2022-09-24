#include <stdio.h>
#include <math.h>

int diferenteS(long double a, long double b)
{
    if ((((a > 0)) && ((b < 0)))  || (((a < 0)) && ((b > 0))))
    {
        return 1;
    }else
    {
        return 0;
    }
}

//Funcion a encontrar raiz
//
long double f(long double x)
{
    return ((x) * pow(((15 * x)/(15 + (2 * x))) , 2/3)) - (((0.015) * (20))/((15) * (sqrt(0.001))));
}

int main(int argc, char const *argv[])
{
    int i;
    long double a, b, p, fa, fb, fp, E;

    printf("a> ");
    scanf("%Lf", &a);
    printf("b> ");
    scanf("%Lf", &b);
    printf("E> ");
    scanf("%Lf", &E);

    fa = f(a);
    fb = f(b);

    if(diferenteS(fa, fb) == 0) return -1;

    printf("|   a   |   b   | f(a)  | f(b)  |   p   | f(p)  |\n");
    printf("|%Lf|%Lf|%Lf|%Lf|%Lf|%Lf|\n", a, b, fa, fb, p, fp);

    do
    {
        //printf("??\n");
        i++;
        p = (a+b)/2;
        fp = f(p);

        if(fabs(fp) < E) break;

        if(diferenteS(fa, fp) == 1)
        {
            b = p;
            //printf("//b//\n");
        }else
        {
            a = p;
            //printf("//a//\n");
        }
        printf("|%Lf|%Lf|%Lf|%Lf|%Lf|%Lf|\n", a, b, fa, fb, p, fp);

        if(i > 1000000) break; 
    }while(fabs(fp) > E);

    printf("Iteraciones: %d\n", i);
    printf("raiz aproximada: %Lf", p);

    return 0;
}
