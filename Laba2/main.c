#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void F(double S,double Poh,int n ) //Интерфейс
{
    printf("S = %lf\n",S);
    printf("poh.: = %lf\n",Poh);
    printf("Steps: = %d\n",n);
    printf("THE OPERATION WAS SUCCESSFUL :)\n\n");
}
double iva(double x) //Функция интеграл. Вариант11.
{
    return (pow(x,2)*exp(2*x));
}
double Rectangles(int n, double a, double b ) //Метод триугольников
{
   double h,S,x;
   h=(b-a)/n;
    for(x = a; x <= b ;x = x + h)
    {
    S=S+iva(x);
    }
    S=S*h;
    return S;
}
double Trapezoidal(int n, double a, double b)//Метод трапеций
{
   double h,S = 0,x;
   h=(b-a)/n;
   S=iva(a)+iva(b);
    for(x = a; x <= b ;x = x + h)
    {
    S=S+iva(x);
    }
    S=S*h;
    return S;
}
double Simpson(int n, double a, double b)//Метод Симсона
{
    double h,S = 0,SS = 0;
    int i = 0;
    h=((b-a)/n);
        for(i = 0; i <= n;i++)
        {
            if(i%2 != 0)
            {
              S=S+iva(a+h*i);
            }
            if(i%2 == 0)
            {
              SS=SS+iva(a+h*i);
            }
        }
        S=((b-a)/(3*n))*(iva(a)+4*S+2*SS+iva(b));
   return S;
}
int main()
{

    int var,n,i,j=1;
    double h,d,x,S=0.0,SS=0.0,L1,L2,a,b,e=2.27;
   while(1)
   {
    printf("Choise metod: \n");
    printf("1 - Metod \n2 - Metod \n3 - Simpson metod\n4 - Usual metod\n5 - Demo version(y = x^3)\n");
    scanf("%d",&var);
    switch(var)
    {
    case 1://Metod 1
        printf("Steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Rectangles(n,a,b);
               n=n+2;
              }
            SS = Rectangles(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                F(S,SS,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
    case 2://Metod 3
        printf("Steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Trapezoidal(n,a,b);
               n=n+2;
              }
            SS = Trapezoidal(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                F(S,SS,n);
                break;
            }
            else

            {
                j=0;
            }
        }
        break;
 case 3://Simpson method
        do
        {
            printf("There must be an even number of bins for this method. \n");
            printf("Steps: \n");
            scanf("%d",&n);
            printf("lower limit: \n");
            scanf("%lf",&a);
            printf("upper border: \n");
            scanf("%lf",&b);
        }
        while(n%2!=0);
        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Simpson(n,a,b);
               n=n+2;
              }
            SS = Simpson(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                F(S,SS,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
    case 4://Usual method
         printf("Steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        S=(pow(a,3)/3)*((pow(e,2)-1)/2);
       SS=(pow(b,3)/3)*((pow(e,2)-1)/2);
        S=S+iva(a+h*i);
        printf("S : %lf\n\n",S);
        break;
    case 5://Demo
        //y = x^2
        printf("My integral (0->1) y = x^3 \n");
        printf("Steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        printf("Calculator answer : 0.25\n");
        //1
        h = ((b-a)/n);
        h=(b-a)/n;
        for(x = a; x <= b ;x = x + h)
        {
          S=S+pow(x,3);
        }
        S=S*h;
        printf("Metod of rectangles : %lf\n",S);
        //2
        h=(b-a)/n;
        S=pow(a,3)+pow(b,3);
        for(x = a; x <= b ;x = x + h)
        {
        S=S+pow(x,3);
        }
        S=S*h;
        printf("Metod of trapezoidal : %lf\n",S);
        //3
        h=((b-a)/n);
        for(i = 0; i <= n;i++)
        {
            if(i%2 != 0)
            {
              S=S+pow(a+h*i,3);
            }
            if(i%2 == 0)
            {
              SS=SS+pow(a+h*i,3);
            }
        }
        S=((b-a)/(3*n))*(pow(a,3)+4*S+2*SS+pow(b,3));
        printf("Simpson metod : %lf\n\n",S);
        break;
    default:
        printf("Error\n");
        break;
    }
   }
    return 0;
}
