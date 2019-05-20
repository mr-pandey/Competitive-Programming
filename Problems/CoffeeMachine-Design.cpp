#include<bits/stdc++.h>
#include<string>
using namespace std;

class Machine
{
private:
	int coffee, sugar, cream;
    map<string, pair<int, pair<int, int>>> Ingredients;
    map<int, string> Menu;
public:
	int NoOfDrinks;
	void Restock()
	{
		coffee=30;
		sugar=cream=10;
	}
	void GetDrink(int sno)
    {
        if(sno>NoOfDrinks)
        {
            cout<<"Invalid choice!\n";
            return;
        }
        string Drink=Menu[sno];
        int x=Ingredients[Drink].first, y=Ingredients[Drink].second.first, z=Ingredients[Drink].second.second;
        if((coffee>=x)&&(sugar>=y)&&(cream>=z))
        {
            cout<<"Dispensing:\n";
            cout<<"Please pay USD "<<x*0.75+y*0.25+z*0.25<<endl;
            coffee-=x;
            sugar-=y;
            cream-=z;
        }
        else
            cout<<"The ingredients need to be refilled!\n";
    }
	void AddDrink()
	{
        int Coffee, Sugar, Cream;
        cout<<"Enter the name of the drink : ";
        string NewDrink;
        cin>>NewDrink;
        cout<<"Enter the units of the following ingredents required for the drink : \n";
        cout<<"Coffee : ";
        cin>>Coffee;
        cout<<"Sugar : ";
        cin>>Sugar;
        cout<<"Cream : ";
        cin>>Cream;
        Ingredients[NewDrink]={Coffee, {Sugar, Cream}};
        ++NoOfDrinks;
	}
    void AddDrink(string NewDrink, int Coffee, int Sugar, int Cream)
    {
        Ingredients[NewDrink]={Coffee, {Sugar, Cream}};
        ++NoOfDrinks;
    }
	void Display()
	{
        cout<<endl<<endl<<"******* WELCOME TO THE COFFEE SHOP *******"<<endl;
		cout<<endl<<"Remaining Stock: \n";
		cout<<"Coffee -> "<<coffee<<" "<<endl;
		cout<<"Sugar  -> "<<sugar<<"  "<<endl;
		cout<<"Cream  -> "<<cream<<"  "<<endl;
		cout<<endl<<endl<<"Our menu offers: \n";
        cout<<"S.NO.\tDRINK\t\tPRICE\n";
		map<string, pair<int, pair<int, int>>> :: iterator it=Ingredients.begin();
        int c=0;
        for( ; it!=Ingredients.end(); it++)
        {
            cout<<++c<<".\t"<<it->first<<"\t\tUSD "<<(it->second).first*0.75+(it->second).second.first*0.25+(it->second).second.second*0.25<<endl;
            Menu[c]=it->first;
        }
        cout<<endl<<endl;
	}
	Machine()
	{
		NoOfDrinks=0;
	}
};

int main()
{
	// #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r", stdin);
    // 	freopen("output.txt", "w", stdout);
	// #endif
	Machine CoffeeMachine;
	CoffeeMachine.Restock();
	CoffeeMachine.AddDrink("Frappe", 4, 1, 1);
	CoffeeMachine.AddDrink("Latte", 4, 1, 2);
	CoffeeMachine.AddDrink("Mojito", 4, 1, 3);
    while(true)
    {
        CoffeeMachine.Display();
        cout<<"Input:\n'a' or 'A' : Add a new drink to our menu\n";
        cout<<"'b' or 'B' : Choose a drink from our menu\n";
        cout<<"'r' or 'R' : Refill the ingredients into the machine\n";
        cout<<"'q' or 'Q' : Shut down\n";
        char Input;
        cin>>Input;
        if((Input=='q')||(Input=='Q'))
            break;
        else if((Input=='r')||(Input=='R'))
            CoffeeMachine.Restock();
        else if((Input=='a')||(Input=='A'))
            CoffeeMachine.AddDrink();
        else if((Input=='b')||(Input=='B'))
        {
            cout<<"Enter the S.No. of the desired drink : ";
            int sno;
            cin>>sno;
            CoffeeMachine.GetDrink(sno);
        }
        else
            cout<<"Invalid Choice!\n";
    }
	return 0;
}