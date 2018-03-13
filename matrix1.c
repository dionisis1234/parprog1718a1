#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void get_walltime (double *wct);

int main(int argc, const char *argv[]) {

int i;
int j;
double start,end;
double sum = 0;

double *a = (double *) malloc(NROWS*NCOL*sizeof(double));

if(a == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }






for (i = 0; i <NROWS* NCOL; i++){
	a[i] = 3.0;

}

get_walltime(&start);

for(i=0;i < NROWS;i++){
	for(j=0;j < NCOL; j++){			
		sum+= a[i*NCOL + j];

	}
}

get_walltime(&end);


for (i = 0; i < NROWS*NCOL;i++){
	if (sum != 3*NROWS*NCOL) {
	printf("\nERROR ");
	break;
	}
}

free(a);

printf (" %f ",((double)end - start));
printf ("Megacces %f  sum = %d",(2.0 * NROWS*NCOL)/((end - start)*1e6),sum);

printf("\nSUCCES\n");

return 0;
}

void get_walltime (double *wct){
struct timeval tp;
gettimeofday(&tp,NULL);
*wct =(double)(tp.tv_sec + tp.tv_usec/1000000.0);


}

