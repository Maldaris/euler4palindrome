#include <iostream>
#include <string>
#include <sstream>

/*
	Compile with flag "-D OPTIMIZED=<value>" for the optimized 
	unoptimized binary.
*/

using namespace std;
bool is_palindrome(string);
string to_string(int);
int main(){
	int max = 0;
	int iterationCount = 0;
	for(int i = 999; i > 100; i--){
#if OPTIMIZED
		for(int j = 999; j >= i; j--){
#elif !OPTIMIZED
		for(int j = 999; j >= 100; j--){
#endif
			string s = to_string(i * j);
			iterationCount++;
			if(is_palindrome(s)){
				//cout << "found: " << i * j << endl;
				if(max < i * j)
					max = i * j;
			}
		}
	}
	cout << "Final: " << max << endl;
	cout << "Reached at: " << iterationCount << endl;
#if _WIN32 || _WIN64
	cout << "Press any key to exit" << endl;
	cin.get();
	return 0;
#else
	return 0;
#endif
}
string to_string(int a){
	stringstream ss;
	ss << a;
	return ss.str();
}
bool is_palindrome(string s){
	bool pal = true;
	for(int i = 0; i < s.length(); i++){
		int j = s.length() - i - 1;
		if(s[i] != s[j]){
			pal = false;
		}
	}
	return pal;
}
