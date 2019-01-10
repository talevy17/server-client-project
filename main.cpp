#include <iostream>
#include <ctime>

using namespace std;

void f() {
    using namespace std;
    clock_t begin = clock();
    int k=0;
    for (int i=0; i<50000000; i++){
        k++;

    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    if (elapsed_secs == 60){

    }
    cout << elapsed_secs << endl;

}
int main() {
    f();
    return 0;
}

