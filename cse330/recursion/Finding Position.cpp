long long int nthPosition(long long int n)

{

          for(int i=1;i<30;i++)

          {

               if(n>=pow(2,i))

                {

                  po=i;   

                }

         }

         return pow(2,po);

    }