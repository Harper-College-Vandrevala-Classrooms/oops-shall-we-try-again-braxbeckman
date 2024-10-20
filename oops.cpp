#include <iostream>

using namespace std;

std::string validation(int lowBound, int highBound, string prompt, string error)
{
  bool isString{false};
  std::string input{};
 

  cout << prompt << endl;

  while (true)
  {
    cin >> input;
     int inputLength{input.length()};
    if (input == "exit")
    {
      return "aborted";
    }
    else if (input == "default")
    {
      return "100";
    }


    for (int i = 0; i < inputLength; i++)
    {
      if (isdigit(input[i]))
      {
        continue;
      }
      else
      {
        isString = true;
        break;
      }
    }
    if (isString == false)
    {
      if (stoi(input) < lowBound || stoi(input) > highBound)
        cout << error;
      else
        return input;
    }
    if (isString == true)
    {
      if (inputLength > 0)
      {
        return input;
      }
    }
  }
}

int main()
{
  int lowBound{0};
  int highBound{100};
  string prompt{"Hello! Please enter a value. Enter \"default\" for the default value of 100, or \"exit\" to exit: "};
  string error{"This number is out of range, please enter a number within the valid range: "};

  std::string value1{validation(lowBound, highBound, prompt, error)};

  cout << "Your chosen value is: " << value1;
  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  std::string value2{validation(0, 45, "Enter a number between 0 and 45: ", "Custom Error")}; //example of custom arguments
  cout << "Your chosen value is: " << value2;
  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  std::string value3{validation(-40, -10, prompt, error)};
  cout << "Your chosen value is: " << value3;
  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


  std::string value4{validation(-1000, 1000, prompt, error)};
  cout << "Your chosen value is: " << value4;
  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}
