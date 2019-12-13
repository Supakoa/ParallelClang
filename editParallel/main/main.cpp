#include "consumer.cpp"
#include <iostream>
#include <omp.h>

int main()
{
    generate_sushi();

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                while (true) {
                    ranSushi();
                }
            }
            #pragma omp section
            {
                Producer prod("singha");
                while (true)
                {
                    prod.makeOrder(omp_get_thread_num());
                }
            }
            // #pragma omp section
            // {
            //     Producer prod("American");
            //     while (true)
            //     {
            //         prod.makeOrder(omp_get_thread_num());
            //     }
            // }
            #pragma omp section
            {
                string consumer_name[] = {"Pee", "Koa", "First "};
                while (true)
                {
                    Consumer cons(consumer_name[rand()%1], rand() % 500);
                    cons.getSushi();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            #pragma omp section
            {
                string consumer_name[] = {"Koa", "First "};
                while (true)
                {
                    Consumer cons(consumer_name[rand()%1], rand() % 500);
                    cons.getSushi();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
    }

    return 0;
}