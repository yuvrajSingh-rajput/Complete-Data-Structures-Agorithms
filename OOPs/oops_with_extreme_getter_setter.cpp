//? In summary, constructors and destructors play a crucial role in managing object initialization and cleanup, especially when dealing with dynamic memory allocation or other resource management tasks.

#include <iostream>
#include <string>
using namespace std;

class carRacing
{
private:
    string player_name;
    string car;
    int age, size, *arr, key;
    int binarySearch(int *arr, int size, int key);

public:
    carRacing();  // Constructor
    ~carRacing(); // Destructor
    void setname(void);
    void setcar(void);
    void setage(void);
    void setSize();
    void setKey(int k);
    void InputArray(void);
    void searching(void);
    void printing_data_of_player(void);
};

//! Private Function of Binary Search;
int carRacing ::binarySearch(int *arr, int size, int key)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (*(arr + mid) == key)
        {
            return mid;
        }
        else if (*(arr + mid) > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

carRacing::carRacing()
{

    arr = nullptr; //*It firstly initialize our pointer to a NULL pointer;
}

carRacing::~carRacing()
{
    delete[] arr;
}

//! Setting the player name;
void carRacing::setname()
{
    string s1;
    cout << "Enter the name of the player: ";
    getline(cin, s1);
    player_name = s1;
}

//! Setting the car name;
void carRacing::setcar(void)
{
    string s2;
    cout << "Enter the name of car: ";
    getline(cin, s2);
    car = s2;
}

//! Setting the age;
void carRacing::setage()
{
    int a;
    cout << "Enter the age of the player: ";
    cin >> a;
    age = a;
}

//! Setting the array size;
void carRacing::setSize(void)
{
    int arrSize;
    cout << "Enter the size of the array: ";
    cin >> arrSize;
    size = arrSize;
    arr = new int[size];
}

//! Taking elements as an input of array;
void carRacing::InputArray(void)
{
    cout << "Enter the " << size << " elements in the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }
}

//! Seting the key value;
void carRacing::setKey(int k)
{

    key = k;
}

//! Searching the number
void carRacing::searching(void)
{
    //* Nesting of Member function;

    int k = binarySearch(arr, size, key);

    if (k == -1)
    {
        cout << "Key you are searching is not present is the dynamic array!" << endl;
    }
    else
    {
        cout << "Key you are searching is present in array at index: " << k << endl;
    }
}
void carRacing::printing_data_of_player(void)
{
    cout << "player's Name: " << player_name << endl;
    if (age >= 18)
    {
        cout << "Your selected car name is: " << car << endl;
        cout << "All the best for your Race!" << endl;
    }
    else
    {
        cout << "You can not participace in the car race, As you are below 18." << endl;
    }
}
int main()
{
    carRacing player1;
    player1.setname();
    player1.setcar();
    player1.setage();
    player1.setSize();
    player1.InputArray();
    int key;
    cout << "Enter the key to be searched inside array: ";
    cin >> key;
    player1.setKey(key);
    player1.searching();
    player1.printing_data_of_player();
    return 0;
}