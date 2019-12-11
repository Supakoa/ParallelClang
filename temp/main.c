#include <stdio.h>

// openmp
#include <omp.h>

int main()
{
#pragma omp parallel
   {
      int threadNum, numThread;
      threadNum = omp_get_thread_num();
      numThread = omp_get_num_threads();
      printf("tn: %d, nt: %d\n", threadNum, numThread);
   }

   return 0;
}
