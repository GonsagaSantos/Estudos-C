#include "letras.h"

char qualFoiOVetor(int index) {
    if(index >= 0 && index <= 26){
        return 'A' + index;
    }

    return '?';
}
