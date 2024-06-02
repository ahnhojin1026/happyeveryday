#include <stdio.h>

int countOneBits(int x) {
  int a0 = 0x55; 
  int b0 = (a0<<8)+0x55;
  int one0 = (b0<<16)+b0;//0x55555555
  int a1 = 0x33; 
  int b1 = (a1<<8)+0x33;
  int one1 = (b1<<16)+b1; //0x33333333
  int a2 = 0x0f;
  int b2 = (a2<<8)+0x0f;
  int one2 = (b2<<16)+b2;//0x0f0f0f0f
  int a3 = 0xff;
  int one3 = a3 + (a3<<16);//0x00ff00ff
  int one4 = a3 + (a3<<8);//0x0000ffff
  x = (x&(one0))+((x>>1)&(one0));
  x = (x&(one1))+((x>>2)&(one1));
  x = (x&(one2))+((x>>4)&(one2));
  x = (x&(one3))+((x>>8)&(one3));
  x = (x&(one4))+((x>>16)&(one4));
  return x;
}

int main(){
    int n;
    scanf("%d",&n);

    printf("%d", countOneBits(n));

}
