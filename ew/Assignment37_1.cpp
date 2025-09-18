#include<iostream>
using namespace std;
class Array
{
    protected:
    int *Arr;
    int size = 0;

    public:
    Array(int Value)
    {
       cout<<"Inside Array Constructor\n";
       this->size = Value;
        this->Arr = new int[size];
    }
    Array(const Array &ref)
    {
        cout<<"Inside Array Copy Constructor\n";
        this->size = ref.size;
        this->Arr = new int[this->size];
        for(int i = 0; i < size; i++)
        {
            this->Arr[i] = ref.Arr[i];
        }
    }
    ~Array()
    {
        cout<<"Inside Array Destructor\n";
        delete[] Arr;
    }
    inline void Accept();
    inline void Display();
};
void Array::Accept()
{
    cout<<"Enter the elements of the array:\n";
    for(int i = 0; i < size; i++)
    {
        cin >> Arr[i];
    }
}
void Array::Display()
{
    cout<<"Elements of the array are:\n";
    for(int i = 0; i < size; i++)
    {               
        cout << Arr[i] << " ";
    }
    cout << endl;
}       
class ArrSearch: public Array
{
    public:
    ArrSearch(int no = 10): Array(10)
    {
        cout<<"Inside ArrSearch Default Constructor\n";
        this->size = no;
        this->Arr = new int[size];
    }
    int Frequency(int );
    int SearchFirst(int);
    int SearchLast(int);
    int EvenOdd(int);
    int OddCount(int);
    
};
int ArrSearch::Frequency(int iNo)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(Arr[i] == iNo)
        {
            count++;
        }
    }
    return count;
}
int ArrSearch::SearchFirst(int iNo)
{
    for(int i = 0; i < size; i++)
    {
        if(Arr[i] == iNo)
        {
            return i; // Return index of first occurrence
        }
    }
    return -1; // Not found
}
int ArrSearch::SearchLast(int iNo)
{
    for(int i = size - 1; i >= 0; i--)
    {
        if(Arr[i] == iNo)
        {
            return i; // Return index of last occurrence
        }
    }
    return -1; // Not found
}
int ArrSearch::EvenOdd(int iNo)
{

    int evenCount = 0, oddCount = 0;
    for(int i = 0; i < size; i++)
    {
        if(Arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
    return (iNo == 1) ? evenCount : oddCount; // Return count based on input
}

int ArrSearch::OddCount(int iNo)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(Arr[i] % 2 != 0)
        {
            count++;
        }
    }
    return count; // Return count of odd numbers
}
int main()
{
    int size = 0,iNo = 0;
    cout << "Enter the size of the array: ";
    cin >> size;
    ArrSearch arr(size);
    arr.Accept();
    arr.Display();
    
    cout << "Enter the number to search for frequency: ";   
    cin >> iNo;
    int frequency = arr.Frequency(iNo);
    if(frequency != -1)
    {
        cout << "Frequency of " << iNo << " is: " << frequency << endl
        << "First occurrence at index: " << arr.SearchFirst(iNo) << endl
        << "Last occurrence at index: " << arr.SearchLast(iNo) << endl; 
    }
    else    

    {
        cout << iNo << " not found in the array." << endl;
    }
    cout << "Even count: " << arr.EvenOdd(1) << endl;
    cout << "Odd count: " << arr.EvenOdd(0) << endl;
    cout << "Total odd numbers: " << arr.OddCount(0) << endl
    << "Total even numbers: " << arr.EvenOdd(1) << endl;
    cout << "Program completed successfully." << endl;

   
    return 0;
}