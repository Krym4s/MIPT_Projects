#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INFROOTS 3
#define NOROOT   0

const double EPSILON = 1e-13;

//----------------------------------------------
//!  Solves a quadratic equation ax2+bx+c=0
//!
//!  @param [in] a a-cofficient
//!  @param [in] b b-cofficient
//!  @param [in] c c-cofficient
//!
//!  @param [out] x1 pointer to first root
//!  @param [out] x2 pointer to second root
//!
//!  @return number of roots
//!
//!  @note in case of infinite number of roots
//!  returns INFROOTS
//!  in case of no roots returns NOROOT
//----------------------------------------------

int finding_quadratic_roots(double a , double b , double c , double* x1 , double* x2 );  // ax2 + bx + c = 0

//----------------------------------------------
//!  Solves a lineal equation ax+b=0
//!
//!  @param [in] a a-cofficient
//!  @param [in] b b-cofficient
//!
//!  @param [out] x pointer to first root
//!
//!  @return number of roots
//!
//!  @note in case of infinite number of roots
//!  returns INFROOTS
//!  in case of no roots returns NOROOT
//----------------------------------------------

int finding_lineal_roots (double a, double b, double* res);   // x + ay + b = 0

//-------------------------------------------
//!
//! Checks if double is zero or not
//!
//! @param [in] a-number
//!
//! @return is zero or not
//!
//!
//!
//-------------------------------------------

bool is_zero (double a) {

      return (fabs(a) < EPSILON) ? true : false;

}


int main () {

    printf ("# Dolgodvorov.ev@phystech.edu\n"
            "Solve of quadratic equation\n");

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    char agreement[10];
    char d;

    while (true){

        printf ("Enter a, b, c\n");
        if (scanf ("%lg %lg %lg", &a, &b, &c) != 3){
           printf ("enter isn`t correct\n");
           fflush (stdin);
           continue;
        }

        int number_of_roots = finding_quadratic_roots ( a, b, c, &x1, &x2);

        switch (number_of_roots) {
             case NOROOT:

                printf("There is no root\n");
                break;

             case 1:

                printf("There is only one root: %.3lg\n", is_zero(x1) ? 0.0 : x1);
                break;

             case 2:

                printf("There are two roots: %.3lg %.3lg\n", is_zero(x1) ? 0.0 : x1, is_zero(x2) ? 0.0 : x2);
                break;

             case INFROOTS:

                printf("There are infinity number of roots\n");
                break;

            default:

                printf("Something`s gone wrong\n");

        }
        scanf("%c", &d);       // '\n'  after numbers
        while(true){

            printf ("Do you want to solve one more equation? y/n\n");
            scanf("%c", &agreement[0]);
            for ( int i = 1; agreement[i-1] != '\n' && i < 10  ; i++)
            scanf("%c", &agreement[i]);

            if ( (agreement[0] == 'y'  &&
                  agreement[1] == 'e'  &&
                  agreement[2] == 's') ||

                 (agreement[0] == 'Y'  &&
                  agreement[1] == 'e'  &&
                  agreement[2] == 's') ||

                 (agreement[0] == 'Y'  &&
                  agreement[1] == 'E'  &&
                  agreement[2] == 'S') ||

                 (agreement[0] == 'y') ||

                 (agreement[0] == 'Y')
                )

                break;


            else if ( (agreement[0] == 'n') ||

                      (agreement[0] == 'N') ||

                      (agreement[0] == 'N'  &&
                       agreement[1] == 'O') ||

                      (agreement[0] == 'N'  &&
                       agreement[1] == 'o') ||

                      (agreement[0] == 'n'  &&
                       agreement[1] == 'o')
                    )
                return 0;

            else {
                printf ("Enter is not correct. ");
                continue;
            }

        }
}

}

int finding_lineal_roots (double a, double b, double *x) {
    if (is_zero(a)) {

       if (is_zero(b))

            return INFROOTS;

        else       /* c != 0 */

            return NOROOT;

    } else         /* b != 0 */
                *x = -b / a;

    return 1;
}

int finding_quadratic_roots(double a , double b , double c , double *x1 , double *x2){
    if(is_zero(a)){

        return finding_lineal_roots( b, c, x1);

    }else          /* not lineal equation */
      {
        double D = b * b - 4.0 * a * c;

        if( D < 0 )

            return NOROOT;

        else {

            double sqrt_D = sqrt(D);

            if(is_zero(D)){

                *x1= - b / (2.0 * a);
                return 1;

            }else { /* D>0 */

                *x1 = (- b + sqrt_D) / (2.0 * a);
                *x2 = (- b - sqrt_D) / (2.0 * a);

                return 2;

                }
            }
    }
}
