#include <iostream>
#include <string>
#include "UserInterface.h"

using namespace std;

int main(int argc, char** argv){
    UserInterface SE(argv[1]);
        SE.runSearchEngine();
        return 0;
}


