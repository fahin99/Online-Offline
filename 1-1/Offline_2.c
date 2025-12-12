#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "utils.c"

#define MAX_SIZE 1000000
#define MAX_BINS 1000
#define MAX_STARS 50
double a[MAX_SIZE];
int n;

void cmd();
void set();
void hist(double arr[], int size, int bins);
double min(double arr[], int size);
double max(double arr[], int size);
double mean(double arr[], int size);
double stddev(double arr[], int size);
int compare(const void *a, const void *b);

int main()
{
    int c=0;
    char s[7];
    cmd();
    while(1)
    {
        printf("Enter command: ");
        scanf("%s", s);
        if (strcmp(s, "set") == 0)
        {
            c++;
            set();
        }
        else if (strcmp(s, "min") == 0)
        {
            if (c==0)
            {
                printf("Error: Array not initialized. Use 'set' command first.\n");
                continue;
            }
            printf("Min: %.4lf\n", min(a, n));
        }
        else if (strcmp(s, "max") == 0)
        {
            if (c==0)
            {
                printf("Error: Array not initialized. Use 'set' command first.\n");
                continue;
            }
            printf("Max: %.4lf\n", max(a, n));
        }
        else if (strcmp(s, "mean") == 0)
        {
            if (c==0)
            {
                printf("Error: Array not initialized. Use 'set' command first.\n");
                continue;
            }
            printf("Mean: %.4lf\n", mean(a, n));
        }
        else if (strcmp(s, "stddev") == 0)
        {   
            if (c==0)
            {
                printf("Error: Array not initialized. Use 'set' command first.\n");
                continue;
            }
            printf("Std Dev: %.4lf\n", stddev(a, n));
        }
        else if (strcmp(s, "summary") == 0)
        {
            if (c==0)
            {
                printf("Error: Array not initialized. Use 'set' command first.\n");
                continue;
            }
            printf("Summary:\n");
            printf("Min: %.4lf\nMax: %.4lf\nMean: %.4lf\nStddev: %.4lf\n", min(a,n), max(a,n), mean(a,n), stddev(a,n));
        }
        else if (strcmp(s, "hist") == 0)
        {
            if (c==0)
            {
                printf("Error: Array not initialized. Use 'set' command first.\n");
                continue;
            }
            int bins;
            printf("Enter number of bins: ");
            scanf("%d", &bins);
            if (bins>1000||bins<1)
            {
                printf("Error: Number of bins meanst be between 1 and 1000.\n");
                continue;
            }
            hist(a,n,bins);
        }
        else if (strcmp(s, "help") == 0)
        {
            cmd();
        }
        else if (strcmp(s, "exit") == 0)
        {
            printf("Exiting program.\n");
            break;
        }
        else if (strcmp(s, "median") == 0)
        {
            if (c==0)
            {
                printf("Error: Array not initialized. Use 'set' command first.\n");
                continue;
            }
            qsort(a,n,sizeof(double),compare);
            double median;
            if (n%2==0) {
                median =(a[n/2 -1]+a[n/2])/2.0;
            } else {
                median =a[n/2+1];
            }
            printf("Median: %.4lf\n", median);
        }
        else
        {
            printf("Error: Invalid command.\n");
        }
    }
    return 0;
}

void cmd()
{
    printf("\t\tList of available commands:\n");
    printf("set - Ask user for number of elements, seed, and distribution type (uniform or gaussian), then populate the array.\n");
    printf("min - Print the minimum value.\n");
    printf("max - Print the maximum value.\n");
    printf("mean - Print the average of the elements.\n");
    printf("stddev - Print the standard deviation.\n");
    printf("summary - Print min, max, mean, stddev.\n");
    printf("hist - Ask user for number of bins, and then plot a bin_counts.\n");
    printf("help - Print the list of all available commands.\n");
    printf("exit - Exit the program.\n");
}

void set()
{
    printf("Enter number of elements(<=100000): ");
    scanf("%d", &n);
    if (n > MAX_SIZE)
    {
        printf("Error: Number of elements exceeds maximum size.\n");
        return;
    }
    unsigned int seed;
    char type[10];
    printf("Enter seed: ");
    scanf("%d", &seed);
    
    while(1){
    printf("Enter distribution type (uniform or gaussian): ");
    scanf("%s", type);
    double mean, stddev, min, max;
    if (strcmp(type, "gaussian") == 0)
    {
        printf("Enter mean and stddev: ");
        scanf("%lf %lf", &mean,  &stddev);
        populate_array_gaussian(a, n, mean, stddev, seed);
        printf("Array successfully populated with gaussian distribution.\n");
        break;
    }
    else if (strcmp(type, "uniform") == 0)
    {
        printf("Enter min and max values: ");
        scanf("%lf %lf", &min, &max);
        populate_array_uniform(a, n, min, max, seed);
        printf("Array successfully populated with uniform distribution.\n");
        break;
    }
    else
    {
        printf("Error: Invalid distribution.\n");
        continue;
    }
}
}

double min(double arr[], int n) {
    double min =arr[0];
    for (int i =1;i<n;i++) {
        if (arr[i]<min) {
            min =arr[i];
        }
    }
    return min;
}

double max(double arr[], int n) {
    double max =arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]>max) {
            max =arr[i];
        }
    }
    return max;
}

double mean(double arr[], int n) {
    double sum =0.0;
    for (int i =0;i<n;i++) {
        sum +=arr[i];
    }
    return sum/n;
}

double stddev(double arr[], int n) {
    double Mean =mean(arr,n);
    double sum =0.0;
    for (int i=0;i<n;i++) {
        sum +=(arr[i]-Mean)*(arr[i]-Mean);
    }
    return sqrt(sum/n);
}

void hist(double *arr, int size, int bins) {
    double b_min =min(arr, size);
    double b_max =max(arr, size);
    if (b_min==b_max) {
        printf("All values are the same. No histogram to display.\n");
        return;
    }
    double bin_width =(b_max-b_min)/bins;
    int bin_counts[MAX_BINS] ={0};
    for (int i=0;i<size;i++){
        int bin_index =(int)((arr[i]-b_min)/bin_width);
        if (bin_index>=bins){
            bin_index =bins-1;
        }
        bin_counts[bin_index]++;
    }
    int max_count =0;
    for (int i=0;i<bins;i++){
        if (bin_counts[i]>max_count)
            max_count=bin_counts[i];
    }

    for (int i=0;i<bins;i++){
        double bin_start =b_min+ i*bin_width;
        double bin_end =bin_start+bin_width;
        double stars =0;
        if (max_count>0) {
            stars =(bin_counts[i]*MAX_STARS)/max_count;
        }
        printf("[%06.2lf - %06.2lf]: ", bin_start, bin_end);
        for (int s=0;s<stars;s++){
            printf("*");
        }
        printf("\n");
    }   
}

int compare(const void *a, const void *b){
    const double a1 = *(const double*)a;
    const double b1 = *(const double*)b;
    if (a1<b1) return -1;
    if (a1>b1) return 1;
    return 0;
}