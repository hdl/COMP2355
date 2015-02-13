//
//  Lab11 COMP2355 Winter 2015
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <thread>
#include <vector>
#include "Timer.h"
using namespace std;
// InitValues - set array values.  Array items are
//   set to the sqrt of their index in the array.
//
// a - pointer to first item to set
// first - index of first array item to set
// count - number of items to set
void InitValues(double *a, int first, int count) {
    // cout << "init thread begin" << endl;
    int limit = first + count;
    for (int i = first; i < limit; ++i) {
        a[i] = sqrt((double) i);
    }
    // cout << "init thread end" << endl;
}

// SumValues - sum array values.
//
// a - array to be summed
// sum - return value, the sum of all items in the range
// first - index of first array item to be summed
// count - number of items to sum
void SumValues(const double *a, double *sum, int first, int count) {
    // cout << "sum thread begin" << endl;
    double sumTmp = 0.0;
    int limit = first + count;
    for (int i = first; i < limit; ++i) {
        sumTmp += a[i];
    }
    *sum = sumTmp;
    // cout << "sum thread end" << endl;
}

// ThreadedSum - initialize and sum a large array using
//   multiple threads.
//
// numThreads - number of threads to use
// arraySize - size of array to use
double ThreadedSum(int numThreads, size_t arraySize) {
    double sum = 0.0;
    static double *a = NULL;
    static bool init=false;
    std::thread initThread;
    vector<std::thread> sumThreadsVector;

    if(init == false){
        //do init
        a = new double[arraySize];
        cout << "initialize array, total size " << arraySize << endl;
        for(int i=0; i<numThreads; i++){
            initThread = std::thread(InitValues, a, 0, arraySize);
        }
        initThread.join();
        init = true;
        return 0;

    }else{
        int i;
        double sumI[numThreads];
        // for example we have 4 threads
        // first 3 threads
        int perThreadcount=arraySize/numThreads;
        for(i=0; i<numThreads-1; i++){
            sumThreadsVector.push_back(std::thread(SumValues, a, &sumI[i], i * perThreadcount, perThreadcount));
        }
        //last Thread
        int lastThreadcout=arraySize - (numThreads-1)*perThreadcount;
        i=numThreads-1;
        sumThreadsVector.push_back(std::thread(SumValues, a, &sumI[i], i * perThreadcount, lastThreadcout));
        
        for(auto &th: sumThreadsVector){
            th.join(); 
        }
        for(i=0; i<numThreads; i++){
            sum+=sumI[i]; 
        } 
        // undo init
        delete a;
        init = false;
        return sum;
    }

    // ********************
    // Write your code here
    // ********************

    //return sum;
}

int main(int argc, const char * argv[])
{
    // Use the number of hardware threads provided by the CPU(s).
    // If only one hardware thread, use two threads.
    int numThreads = std::thread::hardware_concurrency();
    std::cout << "Hardware threads available: " << numThreads << std::endl;
    if (numThreads < 2) numThreads = 2;  // use at least 2 threads

    // Create a Timer object
    Timer t;

    // Run for each power of 2 from 20 to 26 (You may want to start
    // with 10 to 15 for testing)
    for (int power = 20; power <= 26; power++)
    {
        t.StartTimer();
        double sum1 = ThreadedSum(1, 1<<power);
        t.EndTimer();
        std::cout << "Elapsed time: " << t.GetElapsedTime() << ", "
            << "arraySize " << (1<<power) << ", numThreads = 1, sum = "
            << std::setprecision(15) << sum1 << std::endl;

        t.StartTimer();
        double sumN = ThreadedSum(numThreads, 1<<power);
        t.EndTimer();
        std::cout << "Elapsed time: " << t.GetElapsedTime() << ", "
            << "arraySize " <<(1<<power)<< ", numThreads = "
            << numThreads << ", sum = "
            << std::setprecision(15) << sumN << std::endl;
    }
}
