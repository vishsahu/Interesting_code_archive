#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

#include "string_process.hpp"

using namespace std;

void string_to_upper(string& s) {
	boost::to_upper(s);
}
