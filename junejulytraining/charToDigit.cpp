// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {

//     char ch;
//     cout << "Enter a character: ";
//     cin >> ch;

//     int ans = ch - 'a';
//     cout << ch << ": " << ans;
// }

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

void convertNumbersToCharacters()
{
    vector<int> numbers(4);

    cout << "Enter 4 numbers: ";
    for (int i = 0; i < 4; i++)
    {
        cin >> numbers[i];

        // Check if the input is within the valid ASCII range
        if (numbers[i] < 0 || numbers[i] > 127)
        {
            cout << "Input is Invalid" << endl;
            return;
        }
    }

    cout << "Corresponding characters:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << numbers[i] << "-" << static_cast<char>(numbers[i]) << endl;
    }
}

void convertCharactersToNumbers()
{
    vector<char> characters(4);

    cout << "Enter 4 characters: ";
    for (int i = 0; i < 4; i++)
    {
        cin >> characters[i];

        // Check if the input is a valid ASCII character
        if (!isprint(characters[i]))
        {
            cout << "Input is Invalid" << endl;
            return;
        }
    }

    cout << "Corresponding ASCII values:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << static_cast<int>(characters[i]) << "-" << characters[i] << endl;
    }
}

int main()
{
    int choice;

    cout << "Choose an option:" << endl;
    cout << "1. Convert numbers to characters" << endl;
    cout << "2. Convert characters to numbers" << endl;
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
        cout << "Invalid choice" << endl;
    }

    return 0;
}
