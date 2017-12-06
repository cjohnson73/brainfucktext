#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  string text;
  getline(cin, text);
  string output = "++++++++++[";
  int uniqs = 0;
  int tensArr[text.length()][2];
  for(unsigned int j = 0; j<text.length(); j++)
  {
      char c = text.at(j);
      int tens = (int)round(((float)c)/10);
      bool uni = true;
      for(unsigned int i = 0; i<uniqs; i++)
      {
        if(tensArr[i]==tens)
        {
          uni = false;
          break;
        }
      }
      if(!uni)
        continue;
      tensArr[uniqs++][0] = tens;
      tensArr[uniqs][1] = uniqs;
      output += ">";
      for(int i = 0; i<tens; i++)
        output += "+";
  }
  output += "[<]>-]";//stopping here for now   currnet state won't work
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
