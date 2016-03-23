#include <iostream>
#include <new>
#include <string>
using namespace std;

class Card
{
public:
	int card[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	string col;
	void shuff(int num)
	{
		for (int i = 0; i < 20; i++)
		{
			card[i] = num;
		}//Loop
	}//Constructor 

	string colour(int val)
	{

		if (val<10)
		{
			col = "Black";
		}//IfStatement
		else
		{
			col = "Red";
		}//ElseCondition(val>=10)
		return col;
	}//Colour

	int number()
	{
		int v;
		cout << "Enter card number you wish to get value off: " << endl;
		cin >> v;
		if ((v<0) || (v >= 20))
		{
			cout << "Value entered is out of bounds. Please try again." << endl;
		}
		return card[v];
	}//Number

	void print()
	{
		for (int j = 0; j < 20; j++)
		{
			if (j < 10)
			{
				cout << " " << j << " " << "Black" << endl;
			}
			else
			{
				cout << " " << j << " " << "Red" << endl;
			}
		}//Loop
	}//Print

};//Class Card

class DeckOfCards
{
public:
	int * poi = new int[20];
	Card obj;
	Card * pointer;

	void pointerCheck()
	{
		if (poi == nullptr)
		{
			cout << "Error: memory could not be allocated";
		}
		else
		{
			for (int n = 0; n < 20; n++)
			{
				poi[n] = obj.card[n];
			}
		}//IfStatement
	}
	void reset()
	{
		for (int j = 0; j < 20; j++)
		{
			if (j < 10)
			{
				cout << " " << j << " " << "Black" << endl;
			}
			else
			{
				cout << " " << j << " " << "Red" << endl;
			}
		}//Loop
	}//Reset

	void shuffle()
	{
		int val1, val2;
		for (int i = 0; i < 20; i++)
		{
			val1 = rand() % 20 + 1;
			obj.shuff(val1);
		}
		obj.print();
	}//Shuffle

	void draw()
	{
		cout << "Card: " << poi[20] << endl;
		for (int i = 0; i < 20; i++)
		{
			obj.card[i] = obj.card[(i + 1)];
		}
		delete[20] poi;
	}//Draw

	void peek()
	{
		cout << "Last card in deck is: " << poi[20] << endl;
	}//Peek

	void NumberOfCards()
	{
		cout << "Number of cards: " << poi.length() << endl;
	}//NumCards

};//ClassDeckOfCards

void main()
{
	Card obj;
	DeckOfCards obi1;
	obi1.pointerCheck();
	int val;
	cout << "Please choose an option:\nEnter 0 to exit\n1. Print all cards\n2. Get colour of card\n3. Reset\n4. Shuffle\n5. Number of cards left " << endl;
	cin >> val;
	bool flag = true;
	while (flag = true)
	{
		switch (val)
		{
		case 0:
			exit(0);
			break;
		case 1:
			obj.print();
			break; case 2:
				int val;
				cout << "Please enter number of card: " << endl;
				cin >> val;
				cout << "Colour of card is: " << obj.colour(val) << endl;
				break; case 3:
					obi1.reset();
					break; case 4:
						obi1.shuffle();
						break; case 5:
							obi1.NumberOfCards();
							break; default:
								break;
		}
	}//While
}//Main Method