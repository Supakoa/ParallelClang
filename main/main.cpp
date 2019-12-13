#include "consumer.cpp"
#include <omp.h>

int main()
{
    generate_sushi();
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            while(true) ranSushi();
        }
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

                    Consumer cons("Pee" + std::to_string(i), 500);
                    cons.getSushi();
                }
               
                i++;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
         #pragma omp section
         
                {
                    int i = 1;
            while (true)
            {
                    Consumer cons("Koa" + std::to_string(i), 500);
                    cons.getSushi();
                    i++;
            }
                }
    }

    return 0;
}