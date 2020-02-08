// All the functions operate on C arrays with a stride parameter specifying the spacing between elements.
#include<stdio.h>
#include<gsl/gsl_statistics.h>
#include<gsl/gsl_sort.h>

int main(){
    double data[5] = {17.2, 18.1, 16.5, 18.3, 12.6};
    double mean, variance, largest, smallest;

    mean     = gsl_stats_mean(data, 4, 2);
    variance = gsl_stats_variance(data, 1, 5);
    largest  = gsl_stats_max(data, 1, 5);
    smallest = gsl_stats_min(data, 1, 5);

    printf ("The dataset is %g, %g, %g, %g, %g\n",
        data[0], data[1], data[2], data[3], data[4]);

    printf ("The sample mean is %g\n", mean);
    printf ("The estimated variance is %g\n", variance);
    printf ("The largest value is %g\n", largest);
    printf ("The smallest value is %g\n", smallest);

    gsl_sort (data, 1, 5);
    printf ("The dataset after sort is %g, %g, %g, %g, %g\n",
        data[0], data[1], data[2], data[3], data[4]);
    return 0;
}