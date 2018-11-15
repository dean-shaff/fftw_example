#include <vector>
#include <stdio.h>
#include <cmath>
#include <string>
#include <fstream>
#include <fftw3.h>

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
    int N = 512;
    double freq = 1.0;
    // vector<double> freq_range(2);
    // freq_range[0] = 0;
    // freq_range[1] = PI;
    double delta = PI - 0.0;
    // double delta = 1.0;
    fftw_complex *in, *out;
    fftw_plan p;

    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    double k ;
    for (int i=0; i<N; i++){
        k = static_cast<double>(i) / delta ;
        in[i][0] = sin(freq * k);
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
