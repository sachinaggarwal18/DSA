#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int cse, ece, mech;

    cout << "Enter the number of CSE placements: ";
    cin >> cse;
    cout << "Enter the number of ECE placements: ";
    cin >> ece;
    cout << "Enter the number of MECH placements: ";
    cin >> mech;

    // Check for invalid input
    if (cse < 0 || ece < 0 || mech < 0)
    {
        cout << "Input is Invalid" << endl;
        return 0;
    }

    // Store the departments and their placements in a vector of pairs
    vector<pair<string, int>> placements = {{"CSE", cse}, {"ECE", ece}, {"MECH", mech}};

    // Sort the vector in descending order based on the number of placements
    sort(placements.begin(), placements.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         { return b.second < a.second; });

    // Display the placements in descending order
    for (const auto &p : placements)
    {
        cout << p.first << ": " << p.second << endl;
    }

    // Check for the department with the highest placement
    if (placements[0].second == placements[1].second && placements[1].second == placements[2].second)
    {
        cout << "None of the departments has got the highest placement" << endl;
    }
    else
    {
        cout << placements[0].first << " has got the highest placement" << endl;
    }

    return 0;
}
