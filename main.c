#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INFROOTS 3
#define NOROOT   0

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

int finding_quadratic_roots(double, double, double, double*, double*);

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

int finding_lineal_roots(double, double, double* );

int main(){

    printf("# Dolgodvorov.ev@phystech.edu\n");
    printf("solve of quadratic equation\n");
    printf("Enter a,b,c:\n");

    double a=0,b=0,c=0;
    double x1=0,x2=0;

    scanf("%lg %lg %lg", &a, &b, &c);

    int number_of_roots=finding_quadratic_roots( a, b, c, &x1, &x2);

    switch( number_of_roots ){
         case NOROOT:

            printf("There is no root");
            break;

         case 1:

            printf("There is only one root: %.3lg", x1);
            break;

         case 2:

            printf("There are two roots: %.3lg %.3lg", x1, x2);
            break;

         case INFROOTS:

            printf("There are infinity number of roots");
            break;

        default:

            printf("Something`s gone wrong");

    }

    return 0;
}

int finding_lineal_roots(double a, double b, double *x){
 if(a == 0){

           if(b == 0)

                return INFROOTS;

           else       /* c != 0 */

                return NOROOT;

      }else           /* b != 0 */

                *x=-b/a;
                return 1;
}

int finding_quadratic_roots(double a, double b, double c, double *x1,double *x2){
    if(a == 0){

     return finding_lineal_roots( b, c, x1);

    }else {            /* not lineal equation */

     double D=b*b-4.0*a*c;
     if( D<0 )

        return NOROOT;

     else{

        double sqrt_D=sqrt(D);

        if(D==0){

            *x1=-b/(2.0*a);
            return 1;

        }
        else { /* D>0 */

            *x1=(-b+sqrt_D)/(2.0*a);
            *x2=(-b-sqrt_D)/(2.0*a);
            return 2;
    }
   }
  }
}

