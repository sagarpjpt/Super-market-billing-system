#include<iostream>
#include<fstream>
using namespace std;
 
 class Shopping{
    private: 
        int p_code;//product code 
        float price;
        float dis;//discount
        string p_name;// p is for product
    public: 
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void Shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t____________________________________\n\n";
    cout<<"\t\t\t                                    \n\n";
    cout<<"\t\t\t          SuperMarket Main Menu     \n\n";
    cout<<"\t\t\t                                    \n\n";
    cout<<"\t\t\t____________________________________\n\n";
    cout<<"\t\t\t|  1) Administrator       |\n";
    cout<<"\t\t\t|                         |\n";
    cout<<"\t\t\t|  2) Buyer               |\n";
    cout<<"\t\t\t|                         |\n";
    cout<<"\t\t\t|  3) Exit                |\n";
    cout<<"\n\t\t\t Please select : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t Enter Email \n\t\t";
            cin>>email;
            cout<<"\t Password \n\t\t";
            cin>>password;

            if(email=="xyz" && password=="123"){
                administrator();
            }
            else{
                cout<<"Invalid email/password";
            }
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"Please Select from given option\n";
    }
    goto m;
 }

void Shopping :: administrator(){
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t|  1)Add the product      |";
    cout<<"\n\t\t\t|                         |";
    cout<<"\n\t\t\t|  2)Modify the product   |";
    cout<<"\n\t\t\t|                         |";
    cout<<"\n\t\t\t|  3)Delete the product   |";
    cout<<"\n\t\t\t|                         |";
    cout<<"\n\t\t\t|  4)Back to main menu    |";
    cout<<"\n\n\t Please enter your choice : ";
    cin>>choice;

    switch(choice){
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                rem();
                break;
            case 4:
                menu();
                break;
            default :
                cout<<"Invalid choice !";
    }
    administrator();
 } 

 void Shopping :: buyer()
 {
    int choice;
    cout<<"\n\t\t\t    Buyer ";
    cout<<"\n\t\t\t|  1)buy product          |";
    cout<<"\n\t\t\t|                         |";
    cout<<"\n\t\t\t|  2)Go Back              |";
    cout<<"\n\n\t Please enter your choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default :
            cout<<"invalid choice";
    }
    buyer();
 }
 void Shopping :: add(){
    m:
    fstream data;
    int c,token=0;
    float p,d;
    string n;

    cout<<"\n\n\t\t\t Add the product ";
    cout<<"\n\n\t Product code of the product : ";
    cin>>p_code;
    cout<<"\n\n Name of the product : ";
    cin>>p_name;
    cout<<"\n\n\t Price of the product : ";
    cin>>price;
    cout<<"\n\n\t Discount on product : ";
    cin>>dis;
    //adding above data in a file(database) as inputted by administrator

    data.open("database.txt",ios::in);//in means opening in reading mode file is opened
    if(!data){  // not data means if file dosent exist
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<p_code<<" "<<p_name<<" "<<price<<" "<<dis<<endl;
        data.close();
    }
    else{
        //data>>c>>n>>p>>d;
        while(data.good()){
            data>>c>>n>>p>>d;
            if(c==p_code){ //checking duplicacy of product code 
                token++;
            }
            
        }
        data.close();
    
        if(token==1){ //if there is duplicacy p_code
            goto m; 
        }
        else{
            data.open("database.txt",ios::app | ios::out);
            data<<" "<<p_code<<" "<<p_name<<" "<<price<<" "<<dis<<endl;
            data.close();
        }
    }
    cout<<"\n\n\t\t\t record inserted !";
    
 }

 void Shopping :: edit(){
    fstream data,data1;
    int p_key,token=0,c;
    float p,d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code : ";
    cin>>p_key;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n File dosent exist !";
    }
    else{
        data1.open("database1.txt",ios::app | ios::out);
        //data>>p_code>>p_name>>price>>dis;
        while(!data.eof()){
            data>>p_code>>p_name>>price>>dis;
            if(p_key==p_code)
            {
                cout<<"\n\t\t Product's new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Dsicount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                cout<<"\n\n\t\t record edtied ";
                token++;
            }
            else{
                data1<<" "<<p_code<<" "<<p_name<<" "<<price<<" "<<dis<<"\n";
            }
            //data>>p_code>>p_name>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry !";
        }
    }
 }

 void Shopping :: rem()
 {
    fstream data,data1;
    int p_key;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product code : ";
    cin>>p_key;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File dosent exist";
    }
    else{
        data1.open("database1.txt",ios::app | ios::out);
        data>>p_code>>p_name>>price>>dis;
        while(data.good()){
            if(p_code==p_key){
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else{
                data1<<" "<<p_code<<" "<<p_name<<" "<<price<<" "<<dis<<"\n";
            }
            data>>p_code>>p_name>>price>>dis;   
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n\t Record not found";
        }
    }
 }

 void Shopping :: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_____________________________\n";
    cout<<"Pro_Code\t\t\tName\t\t\tPrice\n";
    cout<<"\n\n______________________________\n";
    data>>p_code>>p_name>>price>>dis;
    while(!data.eof()){
        cout<<p_code<<"\t\t\t"<<p_name<<"\t\t\t"<<price<<"\n";
        data>>p_code>>p_name>>price>>dis;
    }
    data.close();
 }

void Shopping :: receipt(){
    fstream data;
    int arr_c[100];//to get product code 
    int arr_q[100];//to get product quantity
    char choice;
    int c=0;
    float amount=0,dis=0,total=0;

    cout<<"\n\n\t\t\t RECEIPT";
    data.open("database.txt",ios::in);
    if(!data)//database exist or not
    {
        cout<<"\n\n\tEmpty data base \n";
    }
    else{
        data.close();//very importatnt to close the file 
        list();
        cout<<"\n_______________________________________\n";
        cout<<"\n                                       \n";
        cout<<"\n        Please place the order         \n";
        cout<<"\n                                       \n";
        cout<<"\n_______________________________________\n";
        do
        {
            m:
            cout<<"\n\nEnter Product code : ";
            cin>>arr_c[c];
            cout<<"\n\nEnter the product quantity : ";
            cin>>arr_q[c];
            for(int i=0;i<c;i++){
                if(arr_c[c]==arr_c[i]){
                    cout<<"\n\n Duplicate product code . please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product ? if yes then press y : ";
            cin>>choice;
        } while (choice=='y'||choice=='Y');
        
        cout<<"\n\n\t\t\t_________________RECEIPT_______________________\n";
        cout<<"\n PRoduct NO\t PRoduct Name\t\t PRoduct quantity\t Price\tAmount\tAmont with discount\n";

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            //data>>p_code>>p_name>>price>>dis;
            while(!data.eof()){
                data>>p_code>>p_name>>price>>dis;
                if(p_code==arr_c[i]){
                    amount=price*arr_q[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<p_code<<"\t\t"<<p_name<<"\t\t"<<arr_q[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t" <<dis;
                }
            }
            data.close();
        }
    }
    cout<<"\n\n____________________________________________\n";
    cout<<"\n Total Amount : "<<total;
}

int main(){
    Shopping obj;
    obj.menu();
}