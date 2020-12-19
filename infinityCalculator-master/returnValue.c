#include "calculator.h"

void returnValue(pDigit digit)
{
    // ���Ӱ� ������ pNum�� �ʱ�ȭ ���ش�.
    pNum resultBefore = NULL;
    pNum resultAfter = NULL;
//    printf("before : %d, after : %d", digit->beforeSize, digit->afterSize);
    // ���� ���ڰ� ������ - �� �߰� �����ش�.
    if(!(digit->positive))
    {
        printf("-");
    }

    // ���������� ���ڸ� ���������� ����ϱ� ���� �������ִ� ����
    for(int i = 0; i < digit->beforeSize; i++)
    {
        pushNum(&resultBefore, popNum(&(digit->before)));
    }
    for(int i = 0; i< digit->afterSize; i++)
    {
        pushNum(&resultAfter, popNum(&(digit->after)));
    }

    // ���� �ڿ� �ڸ��� ���ٸ�
    if(digit->afterSize == 0)
    {
        // �ܼ��� �������� ����ϰ�
        for(int i = 0; i < digit->beforeSize; i++)
        {
            printf("%d", popNum(&resultBefore));
        }
        printf(".0");
    }
    else
    {
        // �ƴϸ� �ڿ� �ڸ����� ������ش�.
        int i = 0;
        for(i; i < digit->beforeSize; i++)
        {
            printf("%d", popNum(&resultBefore));
        }
        printf(".");
        for(int j = 0; j < digit->afterSize; j++)
        {
            printf("%d", popNum(&resultAfter));
        }
    }
}