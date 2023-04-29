#include<iostream>

using namespace std;

//static int priority;

class Student
{
public:
    string Student_ID;
    string Student_Name;
    double Salary;
    int age;
    double CGPA;

    Student(string Name = " ", string nic = " ", double salary = 0, int AGE = 0, double CGPA = 0)
    {
        Student_ID = Name;
        Student_Name = nic;
        Salary = salary;
        age = AGE;
        this->CGPA = CGPA;
    }

    Student(Student& temp)
    {
        Student_ID = temp.Student_ID;
        Student_Name = temp.Student_Name;
        Salary = temp.Salary;
        CGPA = temp.CGPA;
        age = temp.age;
    }

    void display()
    {
        cout << "ID of the Student:              " << Student_ID << endl;
        cout << "Name of the Student:            " << Student_Name << endl;
        cout << "Age of the Student:             " << age << endl;
        cout << "CGPA of the student:            " << CGPA << endl;
    }

};

class node
{
public:
    Student value;
    node* next;
    int Priority;

    node()
    {
        Priority = 0;
        next = NULL;
    }
    node(const Student& temp)
    {
        value = temp;
    }

};



class Queue
{
private:
    node* front;
    node* rear;
    int numItems;
public:
    Queue()
    {
        rear = NULL;
        front = NULL;
        numItems = 0;
    }

    bool isEmpty()
    {
        if (!rear && !front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Enqueue(const Student& std, int priority)
    {
        if (isEmpty())
        {
            numItems++;
            front = new node;
            front->value = std;
            front->Priority = priority;
            rear = front;

            return true;
        }
        else
        {
            numItems++;
            node* temp = new node(std);
            rear->next = temp;
            rear = temp;
            rear->Priority = priority;
            return true;
        }

    }

    bool Dequeue()
    {
        if (isEmpty())
        {
            cout << "No Record Found !" << endl;
            return 0;
        }
        else
        {
            if (!front->next)
            {
                numItems=0;

                front = NULL;
                rear = NULL;
            }
            else
            {
                numItems--;

                node* temp = front;
                front = temp->next;
                delete temp;
            }
           

            
        }



    }
    bool PriorityBasedDequeue()
    {
        if (isEmpty())
        {
            cout << "No Record Found !" << endl;
            return 0;
        }
        int max = 0;

        node* current;
        current = front;

        while (current)
        {
            if (max < current->Priority)
            {
                max = current->Priority;
            }

            current = current->next;

        }
        current = front;
        node* temp1 = new node;

        node* temp = new node;
        while (current)
        {
            if (current->Priority == max)
            {
                numItems--;
                if (current->value.Student_ID == front->value.Student_ID)
                {
                    temp = front->next;
                    front = temp;

                    delete current;
                    return 1;
                }
                else if (current->next == NULL)
                {

                    rear = NULL;
                    rear = temp1;
                    rear->next = NULL;
                    return 1;
                }
                else
                {
                    temp1->next = current->next;
                    delete current;
                    return 1;
                }
            }
            temp1 = current;
            current = current->next;
        }
        cout << "\nRecord not found!\n";
        return 0;
    }







    bool display()
    {
        if (isEmpty())
        {
            return 0;
        }

        node* current = front;

        while (current)
        {
            current->value.display();
            cout << "---------------------------------------------------\n";
            current = current->next;
        }
        return 1;
    }

    void FRONT()
    {
        if (!front)
        {
            cout << "\nList is Empty!\n";
            return;
        }
        else
        front->value.display();

    }
    void REAR()
    {
        if (!front)
        {
            cout << "\nList is Empty!\n";

        }
        else
        rear->value.display();
    }

    void clear()
    {
        Student decoy;
        node* current = new node;
        current = front;

        while (current)
        {
            current->value = decoy;
            current = current->next;
        }
    }

    ~Queue()
    {
        node* temp = front;
        node* curr = new node;
        while (temp)
        {
            curr = temp;
            temp = temp->next;
            delete curr;
        }
    }
};



int main()
{
    Student emp1("1", "Khagga", 550, 12, 2000);
    Student emp2("2", "Ahmad Hanif", 755774, 25, 2000);
    Student emp3("3", "Ahmad Hanif", 5000, 29, 2000);
    Student emp4("4", "Ahmad Hanif", 1, 32, 2000);

    Student emp5("5", "Ahmad Hanif", 89, 19, 2000);
    Queue l1;
    l1.Enqueue(emp1, 1);
     l1.Enqueue(emp2, 2);
     l1.Enqueue(emp3, 5);
     l1.Enqueue(emp4, 10);

    l1.display();
    l1.Dequeue();
    cout << "\nRemoving using priority: \n\n";
    l1.PriorityBasedDequeue();
    l1.display();

    cout << "\nFront: \n\n";
    l1.FRONT();

    cout << "\nRear:  \n\n";
    l1.REAR();
    //l1.display();

}