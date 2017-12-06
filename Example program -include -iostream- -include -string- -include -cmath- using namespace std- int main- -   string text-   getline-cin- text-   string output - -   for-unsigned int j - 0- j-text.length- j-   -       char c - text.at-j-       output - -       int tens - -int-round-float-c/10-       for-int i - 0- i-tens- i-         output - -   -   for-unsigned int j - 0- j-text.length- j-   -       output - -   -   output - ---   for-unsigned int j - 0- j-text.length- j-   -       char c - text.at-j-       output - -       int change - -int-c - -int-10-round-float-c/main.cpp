// Example program
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  string text;
  getline(cin, text);
  string output = "++++++++++[";
  for(unsigned int j = 0; j<text.length(); j++)
  {
      char c = text.at(j);
      output += ">";
      int tens = (int)round(((float)c)/10);
      for(int i = 0; i<tens; i++)
        output += "+";
  }
  for(unsigned int j = 0; j<text.length(); j++)
  {
      output += "<";
  }
  output += "-]";
  for(unsigned int j = 0; j<text.length(); j++)
  {
      char c = text.at(j);
      output += ">";
      int change = (int)c - (int)(10*round(((float)c)/10));
      for(int i = 0; i< abs(change); i++)
      {
          output += (change > 0 ? "+" : "-");
      }
      output += ".";
  }
  cout << output << endl;
  return 0;
}
