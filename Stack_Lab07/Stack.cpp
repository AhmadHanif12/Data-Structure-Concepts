#include<iostream>

using namespace std;

class plate
{
public:
	plate* next;
	char value;

	plate(int val=' ')
	{
		next = NULL;
		value = val;
	}

	void display()
	{
		cout << "New Top: " << value << endl;
	}
};

class stack
{
private:
	plate* top;
	int numItems;
	int numplates;

public:
	stack()
	{
		top = NULL;
		numplates = 10;
		numItems = 0;
	}

	bool isEmpty()
	{
		if (!top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void push(plate* Value)
	{
		if (isEmpty())
		{
			top = Value;
			numItems++;
		}
		else
		{
			plate* temp = top;
			
			top = Value;
			top->next = temp;
			numItems++;
		}
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "\nStack is Already Empty!\n";
		}
		else
		{
			cout << "Popped value: " << top->value << endl;
			plate* temp = top->next;
			delete top;
			top = temp;
			
		}
	}
	
	bool isFUll()
	{
		if (numItems >= numplates)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void clear()
	{
		plate* temp = top;
		plate* curr = new plate;
		while (temp)
		{
			curr = temp;
			temp = temp->next;
			delete curr;
		}
		cout << "\ncleared!\n";
	}
	void peak()
	{
		cout << "Peak Value is: " << top->value << endl;
	}
	~stack(){

		plate* temp = top;
		plate* curr = new plate;
		while (temp)
		{
			curr = temp;
			temp = temp->next;
			delete curr;
		}
		//cout << "\ncleared!\n";
	}

	void print()
	{
		plate* current = top;
		while (current)
		{
			current->display();
			current = current->next;
		}
	}
	


};

void CheckEqs(string eq)
{
	stack l1;

	int index = 0;

	while (eq[index] != '\0')
	{
		if (eq[index] == '[' || eq[index] == '{' || eq[index] == '(')
		{
			char tem = eq[index];
			plate* temp=new plate(tem);
			//cout << temp->value << endl;

			l1.push(temp);
		}
		else if (eq[index] == ']' || eq[index] == '}' || eq[index] == ')')
		{
			cout << endl;
			l1.pop();
		}
		index++;
	}
	if (l1.isEmpty())
	{
		cout << "\nEquation is Correct!\n";
	}
	else
	{
		cout << "\nEquation is incorrect!\n";
	}

}

int main()
{
	plate *one=new plate('a');
	plate *two = new plate('b');
	plate *three = new plate('c');
	plate *four = new plate('d');

	stack l1;

	l1.push(one);
	l1.push(two);
	l1.push(three);
	l1.push(four);
	l1.print();
	l1.pop();
	cout << "\nAfter Pop!\n\n";
	l1.print();



	string eq1 = "1 + 2 * (3 / 4)";
	string eq2 = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10) - 11 + (12*8)] + 14";
	string eq3 = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10)} - 11 + (12*8) / {13 +13}] + 14";
	CheckEqs(eq1);
	CheckEqs(eq2);
	CheckEqs(eq3);

}