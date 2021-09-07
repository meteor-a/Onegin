#include "Onegin.h"

int main() {
    int result = RandGenStr();
    if (result == 1) {
        return OK_RESULT;
    }
    else {
        return CODE_ERROR;
    }
}
