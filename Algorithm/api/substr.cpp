// string::substr
#include <iostream>
#include <string>

int main ()
{
  std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)
	// [start, start+ pos)
  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("thin");      // position of "live" in str
	
 std::cout << pos << std::endl;
  std::string str3 = str.substr (pos);     // get from "live" to the end

  std::cout << str2 << ' ' << str3 << '\n';

  return 0;
}
