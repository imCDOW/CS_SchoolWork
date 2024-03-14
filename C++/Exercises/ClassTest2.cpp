#include<iostream>
using namespace std;

class Player
{
public:
    string PlayerName;
    string Height;
    string Weight;

    Player() : PlayerName("None"), Weight("None"), Height("None"){}

    Player(string playerName, string height, string weight)
        : PlayerName(playerName), Height(height), Weight(weight) {}

    void PrintInfo()
    {
        cout << PlayerName << " " << Height << " + " << Weight;
    }
};

int main()
{
    Player Player1;
    Player1.PlayerName = "Player1";
    Player1.Weight = "100Lb";
    Player1.Height = "6Ft";

    Player Player2("Player2", "5Ft", "150Lb"); // Initialize Player2 with specific values

    Player Player3("Hero", "6Ft", "200Lb"); // Initialize Player3 with specific values

    // Print Player1's info using PrintInfo method
    Player1.PrintInfo();
    cout << endl;

    // Print Player2's info using PrintInfo method
    Player2.PrintInfo();
    cout << endl;

    // Print Player3's info using PrintInfo method
    Player3.PrintInfo();
    cout << endl;

    return 0;
}
