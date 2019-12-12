#include "../koa/consumer.cpp"
#include <omp.h>


int main()
{

   
    #pragma omp parallel sections
    {
        int td = omp_get_num_threads();

            #pragma omp section
            {
                Producer prod("singha");
                prod.makeOrder();
            }
             #pragma omp section
            {
                cout<< td<< "::" <<"COSSS\n";
                Consumer cons("Pee",500);
                if (cons.getSushi())
                {
                   Consumer cons("PP", 500);
                cons.getSushi();
                }

                cout << "you back\n\n";
                // if (cons.money <=  50){
                // Consumer cons("PP", 500);
                // cons.getSushi();
                // } 
                
            }
            // #pragma omp section
            // {
            //     cout<< td<< "::" <<"COSSS\n";
            //     Consumer cons("koa",500);
            //     cons.getSushi();
            // }
            
    }
    
    // Sushi a("name", 50);



    return 0;
}