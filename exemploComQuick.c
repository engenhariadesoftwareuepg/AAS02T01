#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

FILE *gnuplot;


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void bubble(int a[], int N)
{
  int i, j;
  for (i=N; i >= 0; i--)
    for (j = 1; j <= i; j++)
      if (a[j-1] > a[j]) swap(&a[j-1], &a[j]); 
}

void leia( char *nome )
{
  int *a, *ptr;
  struct timeb tempoInicial, tempoFinal;
  int i, tamanho;
  FILE   *arquivo;
  arquivo = fopen(nome, "r");
  fscanf(arquivo, "%d", &tamanho);
  a = malloc(tamanho * sizeof(int));
  printf("%d\t\t", tamanho);
  fprintf( gnuplot, "%d\t\t", tamanho);
  for (i=1; i <= tamanho; i++)
    {
      fscanf(arquivo, "%d", &a[i-1]);
    }
  /*-------------------*/
  ftime( &tempoInicial );
  quickSort(a, 0, tamanho - 1);
  ftime( &tempoFinal );
  /*-------------------*/
  free(a);
  int tempo = (int) (1000.0 *(tempoFinal.time - tempoInicial.time)+(tempoFinal.millitm - tempoInicial.millitm));
  fprintf( gnuplot," %d \n", tempo );
  printf(" %d \n", tempo );
  fclose(arquivo);
}
int main()
{

  system("clear");

  gnuplot = fopen(".resultados/bubb-rnd.dat", "w");
  printf("RANDOMICOS\nTamanho \t Tempo\n");
  fprintf(gnuplot, "#RANDOMICOS\n#Tamanho \t Tempo\n");
  leia ("amostra/rnd10.dat");
  leia ("amostra/rnd50.dat");
  leia ("amostra/rnd100.dat");
  leia ("amostra/rnd500.dat");
  leia ("amostra/rnd1000.dat");
  leia ("amostra/rnd2000.dat");
  leia ("amostra/rnd5000.dat");
  leia ("amostra/rnd10000.dat");
  leia ("amostra/rnd20000.dat");
  leia ("amostra/rnd50000.dat");
  leia ("amostra/rnd100000.dat");
  fclose(gnuplot); 

  gnuplot = fopen(".resultados/bubb-ord.dat", "w");
  printf("\nORDENADOS\nTamanho \t Tempo\n");
  fprintf(gnuplot, "#ORDENADOS\n#Tamanho \t Tempo\n");
  leia ("amostra/ord10.dat");
  leia ("amostra/ord50.dat");
  leia ("amostra/ord100.dat");
  leia ("amostra/ord500.dat");
  leia ("amostra/ord1000.dat");
  leia ("amostra/ord2000.dat");
  leia ("amostra/ord5000.dat");
  leia ("amostra/ord10000.dat");
  leia ("amostra/ord20000.dat");
  leia ("amostra/ord50000.dat");
  leia ("amostra/ord100000.dat");
  fclose(gnuplot); 

  gnuplot = fopen(".resultados/bubb-inv.dat", "w");
  printf("\nINVERSAMENTE ORDENADOS\nTamanho \t Tempo\n");
  fprintf(gnuplot, "#INVERSAMENTE ORDENADOS\n#Tamanho \t Tempo\n");
  leia ("amostra/inv10.dat");
  leia ("amostra/inv50.dat");
  leia ("amostra/inv100.dat");
  leia ("amostra/inv500.dat");
  leia ("amostra/inv1000.dat");
  leia ("amostra/inv2000.dat");
  leia ("amostra/inv5000.dat");
  leia ("amostra/inv10000.dat");
  leia ("amostra/inv20000.dat");
  leia ("amostra/inv50000.dat");
  leia ("amostra/inv100000.dat");
  
  fclose(gnuplot); 
  system("gnuplot -bg gray90 plota.gnu");
}