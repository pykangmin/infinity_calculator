#include <stdio.h>
#include "calculator.h"

pDigit mul(pDigit digit, int x){
    pNum front = NULL;
    pNum back = NULL;
    pNum result = NULL;
    int beforeSize = 0;
    int afterSize = 0;
    int new,quo,rem,up;             //pop받을 변수, 몫, 나머지, 올림수 처리
    
    if(x != 0){              //정수부분 곱
        for(int i = 0; i < digit->beforeSize; i++){             
            new = popNum(&(digit->before));
            quo = new * x / 10;
            if(i == 0){
                if(quo != 0){
                    pushNum(&front,quo);
                }
            }
            else
            {
                pushNum(&front,quo + rem);
            }
            rem = new * x % 10;
            if(i == digit->beforeSize){
                pushNum(&front,rem);
            }
        }
        
        for(int j= 0; j < digit->afterSize; j++){               //소수부분 곱
            new = popNum(&(digit->after));
            quo = new * x / 10;
            if(j == 0){
                if(quo > 0){
                    int f;
                    f = popNum(&front);
                    pushNum(&front,f + quo);
                }
            }
            else
            {
                pushNum(&back,quo + rem);
            }
            rem = new * x % 10;
            if(j == digit->afterSize){
                pushNum(&back,rem);
            }
        }

        int up = 0;
        for(int a = 0; a < digit->beforeSize; a++){             //정수부분 넣기
            int A = popNum(&front) + up;                //처음 up은 0이므로 첫번째부터 올림이 발생하지 않음
            if (A > 10){
                A -= 10;
                pushNum(&result,A);
                up = 1;
            }
            else
            {
                pushNum(&result,A);
                up = 0;
            }
        }

        pushNum(&result,46);                                                                   //정수부분 다 넣고 점 추가

        for(int b = 0; b < digit->afterSize; b++){
            int B = popNum(&back) + up;                                                        
            if (B > 10){
                B -= 10;
                pushNum(&result,B);
                up = 1;
            }
            else
            {
                pushNum(&result,B);
                up = 0;
            }
        }
        pDigit result = initializeDigit();
        return result;
    }
    else
    {
        return beforeSize, afterSize;
    }
    
}