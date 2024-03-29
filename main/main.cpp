#include "consumer.cpp"
#include <omp.h>

int main()
{
    cout << "---------------- generate section -------------- \n" << endl;
    generate_sushi();
    cout << "---------------------- end --------------------- \n" << endl;
    #pragma omp parallel sections num_threads(8)
    {
        
        #pragma omp section
        {
            while(true) ranSushi();
        }
        #pragma omp section
        {
        cout << "\n------------- PRODUCER up to BUFFER ---------- \n" << endl;
           Producer prod("singha");
            prod.makeOrder(); 
        cout << "---------------- end PRODUCER ------------------\n" << endl;
        }
        #pragma omp section 
        {
            int i = 1;
           int num_td = omp_get_thread_num();  

            while (true)
            {

                #pragma omp critical
                {
                    Consumer cons("Pee[" + std::to_string(i)+"]", 500, num_td);
                    cons.getSushi();
                }
               
                i++;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
         #pragma omp section
         
                {
           int num_td = omp_get_thread_num();  

                    int i = 1;
            while (true)
            {
                    Consumer cons("Koa" + std::to_string(i), 500,num_td);
                    cons.getSushi();
                    i++;
            }
                }
    }

    return 0;
}