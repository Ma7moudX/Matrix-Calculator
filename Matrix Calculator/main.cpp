#include <iostream>
using namespace std;


long long determinant ( int f_M [100][100] , int n ) ;
long long determinant2 ( int f_M [100][100] , int n ) ;
double mahmoud [10][10];



int main()
{
    int f_M1 , f_M2 , s_M1 , s_M2 , operation , sum , h = 0 ;   double one_over_det = 0;
    int f_M [100][100];   int s_M [100][100]; double result [100][100]; int result2 [100][100];  double inverse_det [100][100]; int  mahmoud2 [100][100];

   cout << "Please enter dimensions of Matrix A:" ;
   cin >> f_M1 >> f_M2 ; cout << endl ;

   cout << "Please enter dimensions of Matrix B:" ;
   cin >> s_M1 >> s_M2 ; cout << endl ;

   cout << "Please enter values of Matrix A:\n" ;
        for ( int i=0 ; i < f_M1 ; i ++ ) { for ( int j=0 ; j < f_M2 ; j ++ ) cin >> f_M [i][j];    }

   cout << "Please enter values of Matrix B:\n" ;
        for ( int i=0 ; i < s_M1 ; i ++ ) { for ( int j=0 ; j < s_M2  ; j ++ ) cin >> s_M [i][j];    }


   while (1){

        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n" ;
        cin >> operation ;

    switch (operation) {

        case 1 :  if ( s_M1 == f_M1 && s_M2 == f_M2  ) { for ( int i2=0 ; i2 < s_M1 ; i2 ++)     { for ( int j2=0 ; j2 < s_M1 ; j2 ++ ) result [i2][j2] = f_M [i2][j2] + s_M [i2][j2];}
                  for ( int i2=0 ; i2 < s_M1 ; i2 ++)     { for ( int j2=0 ; j2 < s_M1 ; j2 ++ ) cout << result [i2][j2] << " " ; cout << "\n" ; } }
                  else  cout << "The operation you chose is invalid for the given matrices.\n" ;
                                                   break ;

        case 2 :  if ( s_M1 == f_M1 && s_M2 == f_M2  )  { for ( int i2=0 ; i2 < s_M1 ; i2 ++)     { for ( int j2=0 ; j2 < s_M1 ; j2 ++ ) result [i2][j2] = f_M [i2][j2] - s_M [i2][j2];}
                  for ( int i2=0 ; i2 < s_M1 ; i2 ++)      { for ( int j2=0 ; j2 < s_M1 ; j2 ++ ) cout << result [i2][j2] << " " ; cout << "\n" ;} }
                  else  cout << "The operation you chose is invalid for the given matrices.\n" ;
                                                   break ;


        case 3 :  if ( f_M2 == s_M1 )
                {
                    for ( int i2=0 ; i2 < f_M1 ; i2 ++)
                        {
                            for ( int j2=0 ; j2 < s_M2 ; j2 ++ )
                            {
                               result [i2][j2] = 0;

                              for ( int l=0 ; l < s_M2 ; l ++ )

                               result [i2][j2] = f_M [i2][l] * s_M [l][j2] + result [i2][j2];
                            }

                        }

                    for ( int i2=0 ; i2 < f_M1 ; i2 ++)     { for ( int j2=0 ; j2 < s_M2 ; j2 ++ ) cout << result [i2][j2] << " " ; cout << "\n" ; }

                }
                 else { cout << "The operation you chose is invalid for the given matrices.\n" ; }          break ;





        case 4 :    if ( f_M2 == s_M1 && s_M2 == s_M1 && determinant ( s_M , s_M1 ) != 0 )
                {
                    one_over_det =   1.0 / determinant ( s_M , s_M1 );
                    determinant2 ( s_M , s_M1 );


                    for ( int y =0 ; y < 3 ; y++)
                        {
                    for ( int y2 =0 ; y2 < 3 ; y2++){

                         mahmoud2 [y][y2] =  mahmoud [y][y2] ;
                         if ( y == 0 || (y==1 && y2==2) ) mahmoud  [y][y2] =  mahmoud [y2][y] ;
                         else mahmoud  [y][y2] =  mahmoud2 [y2][y] ;
                         }                          }



                    for ( int z =0; z < 3 ; z++)
                    {
                        for ( int z2 =0 ; z2 < 3 ; z2++)
                        {inverse_det [z][z2] =  one_over_det * mahmoud [z][z2] ;}
                    }




                    for ( int i2=0 ; i2 < f_M1 ; i2 ++)
                        {
                            for ( int j2=0 ; j2 < s_M2 ; j2 ++ )
                                {
                                     result [i2][j2] = 0;
                                     for ( int l=0 ; l < s_M2 ; l ++ )    result [i2][j2] = f_M [i2][l] * inverse_det [l][j2] + result [i2][j2];
                                }
                        }


                     for ( int g =0; g < 3 ; g++)
                       {
                        for ( int g2 =0 ; g2 < 3 ; g2++)
                        {
                            if (  result [g][g2] >= 0 ) result2 [g][g2] =  result [g][g2] + 0.5 ;
                            else result2 [g][g2] =  result [g][g2] - 0.5 ;
                        }
                       }


                    for ( int i2=0 ; i2 < f_M1 ; i2 ++)     { for ( int j2=0 ; j2 < s_M2 ; j2 ++ ) cout << result2 [i2][j2] << " " ; cout << "\n" ; }

                }   else { cout << "The operation you chose is invalid for the given matrices.\n" ; }          break ;



        case 5 :     if ( f_M2 == f_M1 )  {cout << determinant ( f_M , f_M1 ) << endl ; break ;} else cout << "The operation you chose is invalid for the given matrices.\n" ; break;

        case 6 :     if ( s_M2 == s_M1 )  {cout << determinant ( s_M , s_M1 ) << endl ; break ;} else cout << "The operation you chose is invalid for the given matrices.\n" ; break;

        case 7 : cout << "Thank you!" ; return 0 ;


                       };

           }
    return 0;
}







long long determinant ( int f_M [100][100] , int n )
    {

             long long det = 0 ;  int sign = 1 ; int sub_f [100][100] ;

             if ( n==2 ) return ( f_M[0][0] * f_M[1][1] - f_M[1][0] * f_M[0][1] );

                else {
                           for ( int x=0 ; x < n ; x++ ) {
                           int i2 = 0;
                           for ( int i=1 ; i < n ; i++ ) {
                           int j2 = 0;
                           for ( int j=0 ; j < n ; j++ ) {
                           if  ( j != x )
                           {sub_f [i2][j2] = f_M [i][j];
                                j2++;    }               }
                                i2++;                    }

                    det = det + ( sign * f_M[0][x] * determinant (sub_f , n - 1 ));
                    sign = - sign ;                      }
                    }

             return det ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  long long determinant2 ( int f_M [100][100] , int n )
    {

             long long det = 0 ; int sign = 1 , hi = 0 , a = 0 , a2 = -1; int sub_f [100][100] ;

             if ( n==2 ) return ( f_M[0][0] * f_M[1][1] - f_M[1][0] * f_M[0][1] );

                else {
                           for ( int x=0 ; x < 9 ; x++ ) {
                           int i2 = 0;
                           for ( int i=1 ; i < n ; i++ ) {
                           int j2 = 0;
                           for ( int j=0 ; j < n ; j++ ) {


                           if ( x == 0 || x == 3 || x== 6) hi = 0; else if ( x == 1 || x == 4 || x == 7) hi = 1; else if ( x == 2 || x == 5 || x== 8) hi = 2;

                                   if ( (x == 3|| x== 4 ||x== 5 || x == 6|| x== 7 ||x== 8) && i2 ==0   ) {i=  0; }
                              else if ( (x == 3|| x== 4 ||x== 5) && i2 ==1   ) {i = 2; }
                              else if ( (x == 6|| x== 7 ||x== 8) && i2 ==1   ) {i = 1; }
                                   if ( j == hi)                continue ;


                           sub_f [i2][j2] = f_M [i][j];
                               j2++;   }
                                i2++;    if ( i2 == 2 )  break ;                    }

                    det = ( sign * determinant2 (sub_f , n - 1 )); 			sign = - sign ;

                    a2 ++ ;
                    if (x == 3 || x == 6 || x == 9) {a ++; a2 = 0 ;}

                   mahmoud [a][a2] = det;
                  }
                    }
             return det ;
    }
