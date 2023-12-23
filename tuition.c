/* Homework 1 Engineering student tuition calculator */
#include <stdio.h>
#include <math.h>

/* function main begins program execution */
int main( void ) 
{

    int num1; /* Student ID to be entered by user */
    int hours; /* Number of credit hours student is taking */
    float base = 282.00; /* Base tuition per credit hour */
    float basecost; /* Base cost of tuition */
    float cost2 = 557.30; /* cost of out of state tuition */
    float cost3; /* cost of out of state times amount of credit hours */
    float cost4 = 90.00; /* Cost of engineering credits */
    float cost5; /* cost of engineering credits timed amount of credits */ 
    int state; 
    int ecredits; /* number of engineering credits enrolled */
    int schol; 
    float grandtotal; 
    float scholtotal;

    /* This block determines whether or not ID is valid */
    printf( "Enter a student ID number (8 digits beginning with '1'):\n" );
    scanf( "%d", &num1 ); /* reads student ID */

    while ( num1 >= 99999999 || num1 <= 11111111 ) { 
        printf( "\nPlease re-enter a valid student ID number:" " " ); 
        scanf( "%d", &num1 );        
    }  /* end while statement requiring 8 digits */

    while ( num1 == 99999999 || num1 == 23456789 ) {
        printf( "\nPlease re-enter a valid student ID number:" " " );
        scanf( "%d", &num1 );
    } /* end while statement requiring first digit to be 1 */ 

    /* This block evaluates tuition cost */
    printf( "\nHow many credit hours is this student enrolled in?" " " );
    scanf( "%d", &hours );
    basecost = ( float ) base * hours; /* Calculate base cost of tuition */
    /* End calculation */ 

    /* Asks if student is out of state or not */
    printf( "\nIs this student an out-of-state resident? '1' if yes, any" ); 
    printf( "\nother value if no:" " " );
    scanf( "%d", &state ); 

    if ( state == 1 ) {
        cost3 = ( float ) cost2 * hours; /* out of state tuition * credit hours */
        basecost = ( float ) basecost + cost3; /* Add basecost + out of state if  1 */
    } /* end if */
    else { /* don't add out of state tuition */
    } /* end else */ 

    /* Asks how many of the credit hours are for engineering */
    printf( "\nHow many credit hours are within the College of\n" );
    printf( "Engineering?" " " );
    scanf( "%d", &ecredits );

    if ( ecredits > 0 ) {
        cost5 = ( float ) cost4 * ecredits; /* Cost of engineering credits times amount */
        basecost = ( float ) basecost + cost5; /* Add basecost + engineer credits total */
    } /* end if */

    /* Asks for any scholarship money applied */
    printf( "\nTotal grant or scholarship funds for this student\n" );
    printf( "(dollars):" " " );
    scanf( "%d", &schol );  

    while ( schol > basecost ) {
        printf( "\nThe scholarship total cannot exceed the tuition total.\n" ); 
        printf( "\nTotal grant or scholarship funds for this student\n" );
        printf( "(dollars): " " " );
        scanf( "%d", &schol );
        scholtotal = ( float ) + schol; 
    } /* end while statement */

    /* Tuition grand total */
    grandtotal = ( float ) basecost - schol;

    {
        /* This block prints data to user */
        printf( "\n***** TUITION STATEMENT *****\n" );
        printf( "\nStudent ID: %d\n", num1 );
        printf( "\nCredit hours: %d\n", hours );
        printf( "\n*****\n" );
        printf( "\nBase tuition: $%.2f\n", basecost );
        printf( "\nScholarships and grants: $%.2f\n", scholtotal ); 
        printf( "\n*****\n" );
        printf( "\nTUITION GRAND TOTAL: $%.2f\n\n", grandtotal ); 
    }

    return 0; /* indicates the program ended successfully */ 
} /* end function main */  
