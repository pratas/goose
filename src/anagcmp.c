#include <stdio.h>
 
int CheckAnag(char x[], char y[]){
   int first[1024] = {0}, second[1024] = {0}, idx = 0;

   while (x[idx] != '\0'){
     first[x[idx]-'a']++;
     ++idx;
     }

   idx = 0;
   while(y[idx] != '\0'){
     second[y[idx]-'a']++;
     idx++;
     }

  for(idx = 0; idx < 1024; ++idx)
    if(first[idx] != second[idx])
      return 0;

  return 1;
  }

int main(){
  char x[4096], y[4096];
 
  printf("Enter string: ");
  scanf("%s", x);
  printf("Enter string to compare: ");
  scanf("%s", y);
 
  if(CheckAnag(x, y) == 1)
    printf("YES, \"%s\" and \"%s\" are anagrams.\n", x, y);
  else
    printf("NO, \"%s\" and \"%s\" are NOT anagrams.\n", x, y);
  return 0;
  }
