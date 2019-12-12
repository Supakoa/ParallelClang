#include "../koa/consumer.cpp"
#include <omp.h>

int main()
{

    #pragma omp parallel sections
    {
        #pragma omp section
        {
          
                    Producer prod("singha");
                    // cout<< prod.name;
                    prod.makeOrder();
                
              
        }
        #pragma omp section
        {
            int i = 1;
            while (true)
            {
                #pragma omp critical
                {

                    Consumer cons("Pee" + std::to_string(i), 500+i);
                    cons.getSushi();
                }
                #pragma omp critical
                {
                    Consumer cons("Koa" + std::to_string(i), 500+i);
                    cons.getSushi();
                }
                i++;
            }
        }
    }

    return 0;
}