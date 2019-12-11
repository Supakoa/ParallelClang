#include "../koa/consumer.cpp"

int main()
{

   
    #pragma omp parallel sections
    {
            #pragma omp section
            {
                Producer prod("singha");
                prod.makeOrder();
            }
             #pragma omp section
            {
               std:: cout<<"COSSS\n";
                Consumer cons("Pee",500);
                cons.getSushi();
            }
            
    }
    
    Sushi a("name", 50);



    return 0;
}