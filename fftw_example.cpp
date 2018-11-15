#include <vector>
#include <stdio.h>
#include <cmath>
#include <string>
#include <fstream>
// #include <fftw3.h>
#include "fftw3.h"

const double PI = 3.14 ;

using namespace std;

void write_complex_to_csv(const char * file_name, fftw_complex * arr, int size) {
    ofstream f;
  	f.open(file_name);
    for (int i=0; i<size; i++) {
        f << to_string(arr[i][0]);
        f << ",";
        f << to_string(arr[i][1]);
        f << "\n";
    }
    f.close();
}

int main () {
    int N = 256;
    double freq = 5.0;
    // double freq1 = static_cast<double>(N / 2);
    double freq1 = 200;
    printf("freq: %f, freq1: %f\n", freq, freq1);
    // vector<double> freq_range(2);
    // freq_range[0] = 0;
    // freq_range[1] = PI;
    double delta = 2.0*PI - 0.0;
    // double delta = 1.0;
    fftw_complex *in, *out;
    fftw_plan p;

    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    double k ;
    for (int i=0; i<N; i++){
        k = static_cast<double>(i) * (delta / N) ;
        in[i][0] = sin(freq * k) + sin(freq1 * k);
        in[i][1] = 0.0;
    }
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(p);

    write_complex_to_csv("in.csv", in, N);
    write_complex_to_csv("out.csv", out, N);

    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    return 0;
}
