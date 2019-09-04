// shopping advisory.....
#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>

using namespace std;
double ab,b=233445, abc=10;
	string a;					
void confirmation()                              
   {
	cout<<"Enter mobile no.\n";
	cin>>a;
	if(a.length()!=abc)
	{
		cout<<"Please enter a valid mobile no.";
		exit(1);
	}
	else
	cout<<"Enter one time password\n";
	cin>>ab;
    if(b==ab)
	   {
        cout<<"\t\t\t\t\t\t\t\tAccess Granted\n";
		return;
	   }
	else
	cout<<"Sorry! Your have entered wrong otp\n";
	exit(1);
   }
   						
						
	class shop
	{
	char name[26];
	char code[10];
	float cost;
	int quantity;
	public:
	void ip();
	void display();		 		
    int checkproduct_code(char product_code[])          
    {
	 return strcmp(code,product_code);
	}
		void modify();
	}s,sh;
						
	 void shop::ip()
	{
	
	cout<<"Enter the name of product: "<<endl;
	cin>>name;
	cout<<"Enter the product code: "<<endl;
	cin>>code;
	cout<<"Enter the product cost: "<<endl;
    cin>>cost;     
	cout<<"Enter the product quantity: "<<endl;
	cin>>quantity;	 
    }
									 
	void shop::display()
	{
     cout<<"Name of the product:-"<<name<<endl;
    cout<<"Product code of product:-"<<code<<endl;
	cout<<"Cost of the product:-"<<cost<<endl;
    cout<<"Product Quantity in stock:-"<<quantity<<endl;
	}
						
	void shop::modify()
   {
cout<<"Product Name: "<<name<<endl;
cout<<"Product Code: "<<code<<endl;
cout<<"Product Cost: "<<cost<<endl;
cout<<"Product Quantity: "<<quantity<<endl;
							  	
char mod_prod[2],mod_code[2];
float mod_cost; int mod_quantity;
							  	
cout<<"Product Name:";
 cin>>mod_prod;
cout<<"Product code:";
  cin>>mod_code;
cout<<"Product cost:";
cin>>mod_cost;
cout<<"Product quantity:";
cin>>mod_quantity;
								
if(strcmp(mod_prod,".")!=0)
strcpy(name,mod_prod);
if(strcmp(mod_code,".")!=0)
 strcpy(code,mod_code);          
 if(mod_cost!=0)
 cost=mod_cost;
if(mod_quantity!=0)
quantity=mod_quantity;
						 	
  }
						
void add()
{
ofstream fo;
fo.open("items.txt",ios::app|ios::binary);
char ans='y';
while((ans=='y')||(ans=='Y'))
{ 
s.ip();
fo.write((char*)&s,sizeof(s));
cout<<"Item Succesfully added to file\n";
cout<<"Want to Add more items(y/n):- ";
cin>>ans;
}
							
fo.close();
						 	
 }
						 
						 
void modddd()
 {
						 	
 fstream fio;
 fio.open("items.txt",ios::in|ios::out|ios::binary);
char mpc[10];
long pos; char found='f';
cout<<"\nEnter the Product code to be modified:-";
cin>>mpc;
while(!fio.eof())
{	pos=fio.tellg();
fio.read((char*)&s,sizeof(s));
if(s.checkproduct_code(mpc)==0)
{
s.modify();
fio.seekg(pos);
fio.write((char*)&s,sizeof(s));
found='t';
break;
}
}  
if(found=='f')
cout<<"\nRecord not found!!\n";
fio.close();						 	
}
 void delet()
{
ifstream fio("items.txt",ios::binary);
ofstream file("temp.txt",ios::out|ios::binary);
char mpc1[10];
char found='f',confirm='n';
cout<<"\nEnter the Product code to delete it:-";
cin>>mpc1;
while(!fio.eof())
{
fio.read((char*)&s,sizeof(s));
if(s.checkproduct_code(mpc1)==0)
{
s.display();
found='t';
cout<<"Are you sure , you want to delete this record permanently(y/n):.. ";
cin>>confirm;
if(confirm=='n')
file.write((char*)&s,sizeof(s));  
}
else
file.write((char*)&s,sizeof(s));
} 
if(found=='f')
cout<<"\nRecord not found!!\n";
fio.close();
file.close();
remove("items.txt");
rename("temp.txt","items.txt");  
}
void dis()
{
cout<<"\nThe Inventory Contain:\n";
ifstream fio("items.txt");
while(!fio.eof())
{
fio.read((char*)&sh,sizeof(sh));
if(fio.eof())
break;
sh.display();		
}
fio.close();
}

int main()
{
cout<<"*************************************************************************************************\n";
cout<<"            **************************Welcome To Shop**********************\n";
cout<<"*************************************************************************************************\n";
confirmation();
int opt;
							
while(opt!=6)
{
								
cout<<"\n******Enter Your Choice *********\n";	
								
cout<<"\t\t\t1. Add product"<<endl;
cout<<"\t\t\t2. Modify the product"<<endl;
cout<<"\t\t\t3. Show product:"<<endl;
cout<<"\t\t\t4. Delete product"<<endl;
cout<<"\t\t\t5. Exit"<<endl;
cin>>opt;
							    
 switch(opt)
	{
	case 1:  add();
	 break;
	 
	case 2:  modddd();
	break;
	
	case 3:  dis();
    break;
    
	case 4:  delet();
	break;
	
    case 5: 
	  cout<<"*************************\nThank you\n**************************";
	  cout<<"*************************\nVisit Again\n************************";
	   exit(1);
	break;
	
	default: cout<<"\nSorry! Wrong input!!";
	}
}
}
