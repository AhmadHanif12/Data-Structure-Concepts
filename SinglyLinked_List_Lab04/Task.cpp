#include<iostream>

using namespace std;


class Student
{
public:
    int EmpID;
    string Student_ID;
    string Student_Name;
    double Salary;
    double CGPA;

    Student(int ID = 0, string Name = " ", string nic = " ", double salary = 0, double Bonus = 0)
    {
        EmpID = ID;
        Student_ID = Name;
        Student_Name = nic;
        Salary = salary;
        this->CGPA = Bonus;
    }

    Student(Student& temp)
    {
        EmpID = temp.EmpID;
        Student_ID = temp.Student_ID;
        Student_Name = temp.Student_Name;
        Salary = temp.Salary;
        CGPA = temp.CGPA;
    }

    void display()
    {
        cout << "ID of the Employee  :           " << EmpID << endl;
        cout << "Name of the Employee:           " << Student_ID << endl;
        cout << "NIC of the Employee :           " << Student_Name << endl;
        cout << "Current Salary of the Employee: " << Salary << endl;
        cout << "Bonus recieved by the Employee: " << CGPA << endl;
    }

};

class node
{
public:
    Student value;
    node* next;

    node()
    {
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
public:
    Queue()
    {
        rear = NULL;
        front = NULL;
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
    bool Enqueue(const Student& emp)
    {
        if (isEmpty())
        {
            front = new node;
            front->value = emp;
            rear = front;
            return true;
        }
        else
        {
            node* temp = new node(emp);
            rear->next = temp;
            rear = temp;
            return true;
        }

    }

    void remove(int id)
    {
        if (isEmpty())
        {
            cout << "No Record Found !" << endl;
        }
        
        node* current;
        current = front;
       
        
        node* temp=new node;
        while (current)
        {
            if (current->value.EmpID == id)
            {
                if (current->value.EmpID == rear->value.EmpID)
                {
                    rear = temp;
                }
                temp->next = current->next;
                    
            }
            
            
            temp = current;
            current = current->next;
        }

    
        

    }








    void display()
    {

        node* current = front;

        while (current)
        {
            current->value.display();
            cout << "---------------------------------------------------\n";
            current = current->next;
        }
    }

    void UpdateSalary(const int& salary, int id)
    {
        node* current = front;

        while (current)
        {
            if (current->value.EmpID == id)
            {
                current->value.Salary = salary;
            }
            current = current->next;
        }
    }
    void UpdateBonus(const int& bonus, int id)
    {
        node* current = front;

        while (current)
        {
            if (current->value.EmpID == id)
            {
                current->value.CGPA = bonus;
            }
            current = current->next;
        }
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


    void sort()
    {
        node* previous = NULL;
        node* now = front;
        node* second = now->next;

          while (now)
        {
            
            node* temp = NULL;
            node* temp1 = front;
            node* temp2 = second;
            node* helper = second->next;
            while (second)
            {
                if (temp == NULL && temp1->value.Salary > helper->value.Salary)
                {
                    
                    temp1->next = helper->next;
                    helper->next = temp1;
                    front = helper;
                }
                else if (second->next == NULL)
                {
                   /* cout<< temp1->value.Salary <<endl << temp2->value.Salary;*/

                    if (temp1->value.Salary > temp2->value.Salary)
                    {

                        temp->next = temp1->next;
                        temp1->next = temp2->next;
                        temp2->next = temp1;
                       
                        rear = temp1;
                    }

                    break;
                }
                 else if (temp1->value.Salary > temp2->value.Salary)
                {
                    temp->next = temp1->next;
                    temp1->next = temp2->next;
                    temp2->next = temp1;
                    
                    
                }
                 
             
                
                
                temp = temp1;
                temp1 = temp2;
                temp2 = temp2->next;
                second = second->next;
                
            }

           /* cout << "lun;";*/
            now = now->next;
            second = front;
         }
       
    }

    void display_salary()
    {
        node* current = front;

        while (current)
        {
          cout<<endl<<current->value.Salary<<" ";
            
            current = current->next;
        }
        cout << endl;
    }
};



int main()
{
    Student emp1(1, "Khagga", "3130377447474", 550, 2000);
    Student emp2(2, "Ahmad Hanif", "3132424424242", 755774, 2000);
    Student emp3(3, "Ahmad Hanif", "3132424424242", 5000, 2000);
    Student emp4(4, "Ahmad Hanif", "3132424424242",1, 2000);

    Student emp5(1000, "Ahmad Khagga", "3132424424242", 89, 2000);
    Queue l1;
    l1.Enqueue(emp1);
    l1.Enqueue(emp2);
    l1.Enqueue(emp3);
    l1.Enqueue(emp4);
    l1.display();
    cout << endl << endl;
    /*l1.remove(10);*/
    
    /*cout << "Removing id 19: " << endl << endl;
    l1.remove(19);*/

    cout << "After Sorting: \n\n";
    l1.sort();
    /*l1.insert(emp5);*/
    l1.display();



}