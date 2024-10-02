#include <iostream>

using namespace std;

int validation(int lowBound, int highBound, string prompt, string error)
{
  int input{};

  cout << prompt << endl;

  while (true)
  {
    cin >> input;

    if (input < lowBound || input > highBound)
      cout << error;
    else
      return input;
  }
}

int main()
{
  int lowBound{0};
  int highBound{100};
  string prompt{"Hello! Please enter a number: "};
  string error{"This number is out of range, please enter a number within the valid range: "};

  validation(lowBound, highBound, prompt, error);
  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  validation(0, 45, "foo", "bar");
  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  validation(-40, -10, prompt, error);
  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  validation(-1000, 1000, prompt, error);
}
