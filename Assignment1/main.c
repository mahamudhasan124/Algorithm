#include <stdio.h>
int main()
{

    int i,d,t1,t2,n,start[100],finish[100],count=0,a=0,b=0,a1[50],a2[50],m,first,last;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&start[i]);
        scanf("%d",&finish[i]);
    }
   scanf("%d",&first);
   scanf("%d",&last);

    for (i = 1 ; i <= n - 1; i++) {
    d = i;

    while ( d > 0 && start[d-1] > start[d])
    {
       t1= start[d];
       t2=finish[d];
      start[d]   = start[d-1];
      finish[d] =finish[d-1];
      start[d-1] = t1;
      finish[d-1] =t2;
      d--;
    }
  }

a1[a]=start[0];
a2[b]=finish[0];

for(i=1;i<n;i++)
  {
   if(a1[a]==start[i])
    {
        if(a2[b]<finish[i])
        {
            a2[b]=finish[i];
        }

    }
    else if(a1[a]!=start[i])
    {
        if(start[i]<a2[b] && finish[i]>a2[b])
        {
            m=a-1;
            while(m>-1)
            {
                if(start[i]<a2[m])
                {
                    a1[a]=start[i];
                   a2[b]=finish[i];
                }
                m--;
            }

                a++;b++;
                a1[a]=start[i];
                a2[b]=finish[i];
               count++;
            }

        }

    }

  printf("%d",count);

}
