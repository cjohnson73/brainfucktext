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
      if(j<text.length()-1 && text.at(j)==text.at(j+1))
        continue;
      char c = text.at(j);
      output += ">";
      int tens = (int)round(((float)c)/10);
      for(int i = 0; i<tens; i++)
        output += "+";
  }
  output += "[<]>-]";
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
      if(j<text.length()-1 && text.at(j)==text.at(j+1))
      {
          output += ".>";
          j++;
      }
  }
  cout << output << endl;
  return 0;
}
