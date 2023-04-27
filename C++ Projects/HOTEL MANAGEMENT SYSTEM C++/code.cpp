//HOTEL MANAGEMENT SYSTEM
#include<bits/stdc++.h>
using namespace std;

//LETS GO 
int main(){
    int  quant ;

    int choice;

    //quantities of rooms and food items in hotel
    int Qrooms = 0 , Qnoodles = 0 , Qpasta = 0 , Qburger = 0 , Qdrinks = 0;


    //numbers of rooms and food items that already sold.
    int Srooms = 0 , Snoodles = 0 , Spasta = 0 , Sburger = 0 , Sdrinks = 0;


    //price of these rooms and food items
    int Prooms = 0 , Pnoodles = 0 , Ppasta = 0 , Pburger = 0 , Pdrinks = 0; 


    //Total quantity of rooms/food items
    cout<<endl<<"\t QUANTITIES OF ROOMS/FOOD ITEMS WE HAVE "<<endl<<endl<<endl;
    cout<<"Quantity of Rooms --> ";
    cin>>Qrooms;
    cout<<"Quantity of Noodles --> ";
    cin>>Qnoodles;
    cout<<"Quantity of Pasta --> ";
    cin>>Qpasta;
    cout<<"Quantity of Burgers --> ";
    cin>>Qburger;
    cout<<"Quantity of Cold Drinks --> ";
    cin>>Qdrinks;

    //Menu for selection for whats customer wants
    cout<<endl<<endl<<endl<<"\t PLEASE SELECT THE GIVEN OPTIONS WE HAVE :) "<<endl<<endl;
    cout<<"1) Rooms in RS 1000 "<<endl;
    cout<<"2) Noodles in RS 100"<<endl;
    cout<<"3) Pasta in RS 50 "<<endl;
    cout<<"4) Burgers in RS 30 "<<endl;
    cout<<"5) Cold Drinks in RS 40 "<<endl;
    cout<<"6) Info regarding sales and collections "<<endl;
    cout<<"7) Exit "<<endl;  
    

    //label m as goto statement
    m:

    
    //choices 
    cout<<endl<<endl<<"\t Please Enter Your Choice --> ";
    cin>>choice;

    

    //where customer/owner make their choices
    switch(choice){


            case 1:
            cout<<endl<<"\t Enter the number of rooms you want -- ";
            cin>>quant;
            if(Qrooms - Srooms >= quant){
                Srooms = Srooms - quant;
                Prooms = Prooms + quant * 1000;
                cout<<endl<<quant<<" rooms alloted to you :)"<<endl;
            }
            else{
                cout<<endl<<Qrooms-Srooms<<" are rooms available only :|"<<endl;
            }
            break;



            case 2:
            cout<<endl<<"\t Enter the number of Noodles you want -- ";
            cin>>quant;
            if(Qnoodles - Snoodles >= quant){
                Snoodles -= quant;
                Pnoodles += quant * 100;
                cout<<endl<<quant<<" noodles alloted to you :)"<<endl;
            }
            else{
                cout<<endl<<Qnoodles-Snoodles<<" noodles available only :|"<<endl;
            }
            break;



            case 3:
            cout<<endl<<"\t Enter the number of Pasta you want -- ";
            cin>>quant;
            if(Qpasta - Spasta >= quant){
                Spasta -= quant;
                Ppasta += quant * 50;
                cout<<endl<<quant<<" Pasta alloted to you :)"<<endl;
            }
            else{
                cout<<endl<<Qpasta-Spasta<<" are pasta available only :|"<<endl;
            }
            break;



            case 4:
            cout<<endl<<"\t Enter the number of Burgers you want -- ";
            cin>>quant;
            if(Qburger - Sburger >= quant){
                Sburger -= quant;
                Pburger += quant * 30;
                cout<<endl<<quant<<" Burger alloted to you :)"<<endl;
            }
            else{
                cout<<endl<<Qburger-Sburger<<" are Burgers available only :|"<<endl;
            }
            break;



            case 5:
            cout<<endl<<"\t Enter the number of Cold Drinks you want -- ";
            cin>>quant;
            if(Qdrinks - Sdrinks >= quant){
                Sdrinks -= quant;
                Sdrinks += quant * 40;
                cout<<endl<<quant<<" Cold Drinks alloted to you :)"<<endl;
            }
            else{
                cout<<endl<<Qdrinks-Sdrinks<<" are Cold Drinks available only :|"<<endl;
            }
            break;



            case 6:
            cout<<endl<<"\t Details of Sales and Collections "<<endl;
            cout<<endl<<" Total No. of Rooms we have -- "<<Qrooms;
            cout<<endl<<" No. of Rooms are in Rent -- "<<Srooms;
            cout<<endl<<" No. of Rooms available Now -- "<<Qrooms-Srooms;
            cout<<endl<<" Amount of Money We make By Renting Rooms -- "<<Prooms<<endl;


            cout<<endl<<" Total No. of Noodles we have -- "<<Qnoodles;
            cout<<endl<<" No. of Noodles are Sold -- "<<Snoodles;
            cout<<endl<<" No. of Noodles available Now -- "<<Qnoodles-Snoodles;
            cout<<endl<<" Amount of Money We make By Selling Noodles -- "<<Pnoodles<<endl;


            cout<<endl<<" Total No. of Pasta we have -- "<<Qpasta;
            cout<<endl<<" No. of Pasta are Sold -- "<<Spasta;
            cout<<endl<<" No. of Pasta available Now -- "<<Qpasta-Spasta;
            cout<<endl<<" Amount of Money We make By Selling Pasta -- "<<Ppasta<<endl;


            cout<<endl<<" Total No. of Burgers we have -- "<<Qburger;
            cout<<endl<<" No. of Burgers are Sold -- "<<Sburger;
            cout<<endl<<" No. of Burgers available Now -- "<<Qburger-Sburger;
            cout<<endl<<" Amount of Money We make By Selling Burgers -- "<<Pburger<<endl;


            cout<<endl<<" Total No. of Cold Drinks we have -- "<<Qdrinks;
            cout<<endl<<" No. of Cold Drinks are Sold  -- "<<Sdrinks;
            cout<<endl<<" No. of Cold Drinks available Now -- "<<Qdrinks-Sdrinks;
            cout<<endl<<" Amount of Money We make By Selling Cold Drinks -- "<<Pdrinks<<endl;
            cout<<endl<<endl;


            cout<<"\t TOTAL REVENUE WE GOT IS  --> "<<Prooms + Pnoodles + Pburger + Ppasta + Pdrinks;
            cout<<endl<<endl<<endl;

            break;



            case 7:
            exit(0);
        



            default :
            cout<<endl<<"\t Please choose the available choice "<<endl;
            
    }



    goto m;


    return 0;
}