#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct weather
{
  int t;
  int temp;
  double pres;
  int hum;
} weather;

weather *findForecast(weather *wptr, int days)
{
  int i;
  if(days > 0)
  {
    if((wptr = malloc(sizeof(weather) * days)) != NULL)
    {
      for(i = 0; i < days; i++)
      {
        wptr[i].t = i + 1;
        wptr[i].temp = rand()%35 + 50;
        wptr[i].pres = rand()%20;
        (wptr[i].pres /= 10);
        wptr[i].pres += 29;
        wptr[i].hum = rand()%101;
      }
    }
  }
  return wptr;
}

void printForecast(weather *wptr, int days)
{
  int i;
  printf("Day    Temp    Pres    Hum\n");
  for(i = 0; i < days; i++)
  {
    printf("%03d     %03d    %2.1lf    %03d%%", wptr[i].t, wptr[i].temp, wptr[i].pres, wptr[i].hum);
    if(wptr[i].temp <=65)
      printf(" -Wear a jacket !");
    printf("\n");
  }

}
int main(void)
{
  srand(time(NULL));
  weather *wptr = NULL;
  int i, days = 0;
  printf("This is the weather forecast for the next few days.\n");
  printf("How many days ahead would you like to see weather for?\n");
  scanf("%d", &days);
  if((wptr = findForecast(wptr, days)) == NULL)
  {
    printf("Failed to find forecast :(.\n");
    return 0;
  }
  printForecast(wptr, days);
  return 0;
}
