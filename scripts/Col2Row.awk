BEGIN {FS=" "}

{
for (i=1;i<=NF;i++)
{
 arr[NR,i]=$i;
 if(big <= NF)
  big=NF;
 }
}
 
END {
  for(i=1;i<=big;i++)
   {
    for(j=1;j<=NR;j++)
    {
     printf("%s\t",arr[j,i]);
    }
    printf("\n");
   }
}
