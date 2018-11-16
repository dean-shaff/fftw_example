#include <vector>
#include <stdio.h>
#include <cmath>
#include <string>
#include <fstream>
#include "fftw3.h"
#include "csv.hpp"

const double PI = 3.14 ;

using namespace std;


int main () {
    int N = 256;
    double freq = 5.0;
    double freq1 = 200;
    printf("freq: %f, freq1: %f\n", freq, freq1);
    double delta = 2.0*PI - 0.0;

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

	ofstream fin; fin.open("in.csv");
	ofstream fout; fout.open("out.csv");

	for (int i=0; i<N; i++) {
		csv::write_row<double>(fin, in[i], 2);
		csv::write_row<double>(fout, out[i], 2);
	}
	fin.close();
	fout.close();

    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    return 0;
}
