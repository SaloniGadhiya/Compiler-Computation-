#include <iostream>
using namespace std;

void validatestring(string input, int n, char symbols[], int state, int i_state, int accept, int accept_state[], int transition_table[][100])
{
    int current = i_state;

    for (char ch : input)
    {
        bool valid = false;
        for (int j = 0; j < n; j++)
        {
            if (ch == symbols[j])
            {
                valid = true;
                current = transition_table[current][j];
                break;
            }
        }
        if (!valid)
        {
            cout << "Invalid String" << endl;
            return;
        }
    }

    for (int i = 0; i < accept; i++)
    {
        if (current == accept_state[i])
        {
            cout << "Valid String" << endl;
            return;
        }
    }

    cout << "Invalid String" << endl;
}

int main()
{
    int n;
    cout << "Number of input symbols : ";
    cin >> n;

    char symbols[n];
    cout << "Input symbols : ";
    for (int i = 0; i < n; i++)
    {
        cin >> symbols[i];
    }

    int state;
    cout << "Enter number of states : ";
    cin >> state;

    int i_state;
    cout << "Initial state : ";
    cin >> i_state;

    int accept;
    cout << "Number of accepting states : ";
    cin >> accept;

    int accept_state[accept];
    cout << "Accepting states : ";
    for (int i = 0; i < accept; i++)
    {
        cin >> accept_state[i];
    }

    int transition_table[state + 1][100];
    cout << "Transition table : " << endl;
    for (int i = 1; i <= state; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << i << " to " << symbols[j] << " -> ";
            cin >> transition_table[i][j];
        }
    }

    while (true)
    {
        string input;
        cout << "Input String (type 'exit' to stop): ";
        cin >> input;

        if (input == "exit")
        {
            cout << "Exiting program." << endl;
            break;
        }

        validatestring(input, n, symbols, state, i_state, accept, accept_state, transition_table);
    }

    return 0;
}
