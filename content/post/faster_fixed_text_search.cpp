#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
bool ffts(CharacterVector target, CharacterVector srch) {
    String x = target[0];
    String y = srch[0];
    const char* X = x.get_cstring();
    const char* Y = y.get_cstring();
    int N_x = std::char_traits<char>::length(X);
    int N_y = std::char_traits<char>::length(Y);
    
    if (N_x < N_y) {
        return false;
    }
    
    if (N_x == N_y) {
        if (x == y) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        char c = Y[0];
        int c_i = 0;
        
        for(int j = 0; j < N_x; j++) {
            char rchar = X[j];
            if (c == rchar) {
                c_i += 1;
                if (c_i == N_y) {
                    return true;
                }
                c = Y[c_i];
            }
            else {
                c = Y[0];
                c_i = 0;
            }
        }
    }
    
    return false;
}