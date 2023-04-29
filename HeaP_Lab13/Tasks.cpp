#include <iostream>

using namespace std;

class Heap
{
private:
    int size;
    int *array;
    int capacity;

public:
    Heap(int Capacity = 0)
    {
        size = 0;
        capacity = Capacity;

        array = new int[capacity];
    }

    bool isHeap()
    {
        // cout<<capacity<<endl;
        bool flag = true;
        for (int i = size - 1; i > 0; i--)
        {
            int temp = array[i];
            int temp2 = array[i / 2];
            if (i % 2 == 0)
            {
                if (array[i / 2-1] < array[i])
                {
                    flag = false;
                    break;
                }
            }
            else if (array[i / 2] < array[i])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }

    void insert(int data)
    {
        if (size >= capacity)
        {
            int tempSize = size + 1;

            int *temparray = new int[tempSize];
            for (int i = 0; i < size; i++)
            {
                temparray[i] = array[i];
            }

            temparray[size] = data;

            delete[] array;

            array = new int[tempSize];

            for (int i = 0; i < tempSize; i++)
            {
                array[i] = temparray[i];
            }

            size++;
            capacity++;
            delete temparray;
        }
        else
        {
            array[size] = data;
            size++;
        }

        if (!isHeap())
        {

            for (int i = size - 1; i > 0; i = i / 2)
            {

                if (array[i / 2] < array[i])
                {
                    int temp = array[i / 2];

                    array[i / 2] = array[i];

                    array[i] = temp;
                }
            }
        }
    }
    int max(int n1, int n2)
    {
        if (n1 > n2)
        {
            return n1;
        }
        else
            return n2;
    }

    void remove()
    {
        int temp = array[0];
        array[0] = array[size - 1];
        array[size - 1] = temp;

        size--;
        if (!isHeap())
        {
            for (int i = 0; i < size;)
            {
                if (i * 2 + 2 < size && i * 2 + 1 < size)
                {
                    int temp = array[i];
                    if (array[i] < max(array[i * 2 + 1], array[i * 2 + 2]))
                    {

                        if (array[i * 2 + 1] < array[i * 2 + 2])
                        {
                            int temp = array[i];
                            array[i] = array[i * 2 + 2];
                            array[i * 2 + 2] = temp;
                            i = i * 2 + 2;
                        }
                        else
                        {
                            int temp = array[i];
                            array[i] = array[i * 2 + 1];
                            array[i * 2 + 1] = temp;
                            i = i * 2 + 1;
                        }
                    }
                    else
                        break;
                }
                else
                    i++;
            }
        }
    }
    void returnsize()
    {
        cout << "Size is: " << size << endl;
    }
    void display()
    {
        if (size <= 0)
        {
            cout << "\nHeap is Empty !\n";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
    }

    void clear()
    {

        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
        }
        size = 0;
    }

    ~Heap()
    {
        delete[] array;
    }
};

int main()
{
    Heap H1(10);

    H1.insert(10);
    H1.insert(11);
    H1.insert(12);
    H1.insert(20);
    H1.insert(50);
    H1.insert(35);
    H1.insert(100);
    H1.display();
    cout << endl;
    H1.remove();
    H1.display();
    cout << endl;
    H1.remove();
    H1.display();
    cout << endl;
    H1.returnsize();

    if (H1.isHeap())
    {
        cout << "\nArray is Heap!\n";
    }
    else
    {
        cout << "\nArray isn't Heap!\n";
    }
}