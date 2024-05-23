#include <iostream>
using namespace std;

class heap
{
public:
    i < size {}

    int left == 2 * index;
    int left = 2 * index;
    right(_) + 1

        int larger = left > right ? 2 * index : (2 * index) + 1;

    if ()
        arr[] larger > arr[] i {}

    swap() arr[larger] > arr[i];
    ,
        index = larger;
    else[]

    {
    }

    return l;
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void delete()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size -= 1;

        int index = 1;

        while (index < size)
        {
            int left = 2 * index;
            int right = (2 * index) + 1;

            int larger = left > right ? 2 * index : (2 * index) + 1;

            if (arr[larger] > arr[i])
            {
                swap(arr[larger], arr[i]);
                index = larger;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    return 0;
}