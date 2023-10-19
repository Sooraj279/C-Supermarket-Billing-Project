#include<iostream>
#include<fstream>

using namespace std;

//We will create a class and declare some variables

class shopping{
	private:
		int pcode;
		float price;
		float dis;
		string pname; //p stands for product
		
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

void shopping :: menu() // :: is the  scope resolution operator used to access members of a class.
{
    m:
    int choice;
    string email;
    string password;
	
    cout<<"\t\t\t\t______________________________________\n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t        Supermarket Main Menu         \n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t______________________________________\n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t|   1) Administrator   |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|   2) Buyer           |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|   3) Exit            |\n";
    
    cout<<"\n\t\t\t Please select : ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		cout<<"\t\t\t Please Login \n";
    		cout<<"\t\t\t Enter Email : ";
    		cin>>email;
    		cout<<"\t\t\t Password  : ";
    		cin>>password;
    		
    		if(email=="sooraj20@gmail.com" && password=="12345")
    		{
    			administrator();
			}
			else
			{
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
			cout<< "Please select from the given options";
	}	
	goto m;
}

void shopping:: administrator()
{
	m:
	int choice;
	
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|____1) Add the product____|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|____2) Modify the product_|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|____3) Delete the product_|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|____4) Back to main menu__|";
	
	cout<<"\n\n\t Please enter your choice : ";
	cin>>choice;
	
	
	switch(choice)
	{
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
		
		default:
			cout<<"Invalid choice!";
	}
	goto m;
}

void shopping:: buyer()
{
	m:
	int choice;
	
	cout<<"\n\n\n\t\t\t Buyer menu";
	cout<<"\n\t\t\t|--------------------------|";
	cout<<"\n\t\t\t|____1) Buy the product____|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|____2) Go back____________|";
	
	cout<<"\n\n\t Please enter your choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			break;
		
		default:
			cout<<"Invalid choice!";
	}
	goto m;
}

void shopping::add()
{
	m:
	fstream data; //Creating an object of an fstream class
	int c;
	int token = 0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product : ";
	cin>>pcode;
	cout<<"\n\n\t Name of the product : ";
	cin>>pname;
	cout<<"\n\n\t Price of the product : ";
	cin>>price;
	cout<<"\n\n\t Discount on the product : ";
	cin>>dis;
	
	//File Handle
	data.open("database.txt", ios::in); //ios::in open the file in reading mode
	
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out); // app stand for append and out for writing mode
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		//Read from the file
		data>>c>>n>>p>>d;
		
		while(!data.eof()) //eof is end of file
		{
			if(c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
		if(token==1)
			goto m;
		else{
			data.open("database.txt", ios::app|ios::out); // app stand for append and out for writing mode
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			data.close();
		}
    }
    
    cout<<"\n\n\t\t Record inserted !";
		
}

void shopping::edit()
{
	fstream data, data1;
	int pkey;
	int token;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code:";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist";
	}
	else{
		data1.open("database1.txt", ios::app|ios::out);		
		data>>pcode>>pname>>price>>dis;
		
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t\t Record edited";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
	
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\t\t Delete Product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"File doesnt exist";
	}
	
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\t\t Product deleted successfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n________________________________________\n";
	cout<<"ProNo.\t\tName\t\tPrice\n";
	cout<<"\n\n________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100]; // Product code
    int arrq[100]; // Product quantity
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty Database";
        data.close();
        return; // Exit the function as there's no data to process
    }

    list();
    cout << "\n_________________________________\n";
    cout << "\n|                                \n";
    cout << "\n      Please place the order     \n";
    cout << "\n|                                \n";
    cout << "\n_________________________________\n";

    do
    {
        m:
        cout << "\n\nEnter Product code : ";
        cin >> arrc[c];
        cout << "\n\nEnter the product quantity : ";
        cin >> arrq[c];
        for (int i = 0; i < c; i++)
        {
            if (arrc[c] == arrc[i])
            {
                cout << "\n\n Duplicate product code. Please try again!";
                goto m;
            }
        }
        c++;
        cout << "\n\n Do you want to buy another product? if yes then press y else no : ";
        cin >> choice;
    }
    while (choice == 'y');

    cout << "\n\n\t\t\t________________________RECEIPT__________________________\n";
    cout << "\nProduct No\t Product quantity\tprice\tAmount\tAmount with discount\n";

    // You should read the product information once before entering the loop
    data.seekg(0, ios::beg);
    while (data >> pcode >> pname >> price >> dis)
    {
        for (int i = 0; i < c; i++)
        {
            if (pcode == arrc[i])
            {
                amount = price * arrq[i];
                dis = amount - (amount * dis / 100);
                total += dis;
                cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis << endl;
            }
        }
    }

    data.close();

    cout << "\n\n_______________________________________________________________________";
    cout << "\n Total Amount: " << total;
}


int main()
{
	shopping s;
	s.menu();	
}


