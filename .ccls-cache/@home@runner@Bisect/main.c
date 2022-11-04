#include <stdio.h>
#include <math.h>
#define EXP (exp(pow(sin(x), 3)))

double fun (double x)
{
    return EXP + pow(x, 6) -2*(pow(x, 4)) - pow(x, 3) - 1;
}

void bisection (double *m, double a, double b, int *iter_cnt)
{
    *m=(a+b)/2;
    ++(*iter_cnt);
    printf("Iteration no. %3d - Approximation is: %7.5f\n", *iter_cnt, *m);
}


int main(void)
{

    //BISECTION METHOD
    int iter_cnt_bisect = 0, iter_max_bisect;
    //double max_iter_vol2;
    double m, a, b, err_allowed_bisect, m_prev;
    printf("\nEnter the values of a, b, allowed error and maximum iterations: \n");
    scanf("%lf %lf %lf %d", &a, &b, &err_allowed_bisect, &iter_max_bisect);
    bisection (&m, a, b, &iter_cnt_bisect);
    //max_iter_vol2 = ceil(log(1/err_allowed_bisect)/log(2)); <- Stop iterating based on N instead of error
    do
    {
        if(fun(a)*fun(m) < 0)
            b=m;
        else
            a=m;
        bisection (&m_prev, a, b, &iter_cnt_bisect);
        if(fabs(m_prev-m) < err_allowed_bisect)
        {
            printf("After %d iterations, root = %6.9lf\n", iter_cnt_bisect, m_prev);
            return 0;
        }
        m=m_prev;
        //max_iter_vol2--;
    }while (iter_cnt_bisect < iter_max_bisect);
    //while (max_iter_vol2 > 0);
    printf("The solution does not converge or iterations are not sufficient");

}
