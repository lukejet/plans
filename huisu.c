/*
 * 回数 number in a range. questions in 2017/3/8
 */
#include <stdio.h>

int getNum(int shu)
{
    int aa = shu;
    int i = 1;
    if (shu == 0)
        return 0;
    while(1)
    {
        aa /= 10;
        if(aa > 0)
        {
            i++;
        }
        else 
            break;
    }
    return i;
}

int powr(int base, int a)
{
    int pw = 1;
    int i = 0;
    for(i; i< a; i++)
    {
        pw *= base;
    }
    return pw;
}
/*
int isHuisu(int shu)
{
    int arr[10] = {0};
    int num = getNum(shu);
    int k = num / 2;
    int ex = num % 2;
    int i=0;
    if (k == 0)
        return 1;
    for(i=0; i<k; i++)
    {
        int aa = shu % (powr(10, i+1))/powr(10, i);
        int ab = shu % (powr(10, num-i)) / powr(10, num-i-1);
        if (ab != aa)
            return 0;
       // printf("aa:%d, %d 10^1 %d\n", aa, ab, 10^1);
        //arr[i] = shu%10^k;
    }
    return 1;
}
*/

int isHuisu(char* str, int len)
{
    if (len < 2)
        return 1;

    if(str[0] != str[len-1])
    {
        return 0;
    }
    else
        return isHuisu(str+1, len-2);
}

int formStr(int shu, char* buf)
{
    int num = getNum(shu);
    int i=0;
    for(i; i<num; i++)
    {
        int aa = shu % (powr(10, i+1))/powr(10, i);
        if (aa >=0 && aa < 10)
            buf[i] = aa+'0';
    }
    buf[num] = '\0';
    return 0;
}

int main(int argc, char* argv[])
{
    int range = 10000000;
    int sum = 0;

    if(argc != 2) 
    {
        return 0;

    }
    range = atoi(argv[1]);
    //if (range >= 1<<30)
      //  return 0;
    printf("Will find huishu numbers in %d ++++++++++++++\n", range);

    int i= 0;
    char buf[32] = "";

    for(i = 0; i < range; i++)
    {
        formStr(i, buf);

        if(isHuisu(buf, strlen(buf)))
        {
            //printf("Find a huishu: %d \n", i);
            sum++;
        }
    }

    printf("There are %d huishu in %d. \n", sum, range);
}