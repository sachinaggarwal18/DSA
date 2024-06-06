#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

void convertNumbersToCharacters()
{
    int n;
    cout << "Enter the total no. of numbers: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter numbers-" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];

        if (num[i] < 0 || num[i] > 127)
        {
            cout << "Entered number is Invalid!! ";
            return;
        }
    }

    cout << "Numbers to Characters-" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << ": " << static_cast<char>(num[i]) << endl;
    }
}

void convertCharactersToNumbers()
{

    int n;
    cout << "Enter the total no. of characters: ";
    cin >> n;

    vector<char> characters(n);
    cout << "Enter characters-" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> characters[i];

        if (!isprint(characters[i]))
        {
            cout << "Invalid Character!!: ";
            return;
        }
    }

    cout << "Characters to Numbers-" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << characters[i] << ": " << static_cast<int>(characters[i]) << endl;
    }
}

int main()
{
    int choice;
    cout << "1:To convert number to character: " << endl;
    cout << "2:To convert character to number: " << endl;
    cin >> choice;

    if (choice == 1)
    {
        convertNumbersToCharacters();
    }
    else if (choice == 2)
    {
        convertCharactersToNumbers();
    }
    else
    {
        cout << "Invalid choice!!";
    }

    return 0;
}
