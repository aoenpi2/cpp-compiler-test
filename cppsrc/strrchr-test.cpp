#include <iostream>
#include <algorithm>
#include <string.h>  // for strlen

using std::cout;

const char *my_strrchr(const char *str, char c)
{
	//	ToDo: write your code, here
		int len = strlen(str);

	for (int i=len-1; i>0; i--){
		if(str[i] == c){
			return &str[i];
		}
	}
	return 0;
}

int	g_n_tested = 0;
int	g_n_failed = 0;

void check(int line, bool exp, bool act)
{
	++g_n_tested;
	if( exp == act )
		cout << "OK: ";
	else {
		cout << "*** NG: ";
		++g_n_failed;
	}
	cout << "(" << line << ") ";
	cout << "expected: " << exp << ", actual: " << act << "\n";
}
void check(int line, int exp, int act)
{
	++g_n_tested;
	if( exp == act )
		cout << "OK: ";
	else {
		cout << "*** NG: ";
		++g_n_failed;
	}
	cout << "(" << line << ") ";
	cout << "expected: " << exp << ", actual: " << act << "\n";
}
void check(int line, const int *exp, const int *act)
{
	++g_n_tested;
	if( exp == act )
		cout << "OK: ";
	else {
		cout << "*** NG: ";
		++g_n_failed;
	}
	cout << "(" << line << ") ";
	cout << "expected: " << (void *)exp << ", actual: " << (void *)act << "\n";
}
void check(int line, const char *exp, const char *act)
{
	++g_n_tested;
	if( exp == act )
		cout << "OK: ";
	else {
		cout << "*** NG: ";
		++g_n_failed;
	}
	cout << "(" << line << ") ";
	cout << "expected: " << (void *)exp << ", actual: " << (void *)act << "\n";
}
void check_str(int line, const char *exp, const char *act)
{
	++g_n_tested;
	if( !strcmp(exp, act) )
		cout << "OK: ";
	else {
		cout << "*** NG: ";
		++g_n_failed;
	}
	cout << "(" << line << ") ";
	cout << "expected: '" << exp << "', actual: '" << act << "'\n";
}
bool is_equal(const int *exp, const int *act, int sz)
{
	for(int i = 0; i < sz; ++i) {
		if( *exp++ != *act++ )
			return false;
	}
	return true;
}
void print(const int *ptr, int sz)
{
	for(int i = 0; i < sz; ++i) {
		cout << *ptr++ << ", ";
	}
}
void check_data(int line, const int *exp, const int *act, int sz)
{
	++g_n_tested;
	if( is_equal(exp, act, sz) )
		cout << "OK: ";
	else {
		cout << "*** NG: ";
		++g_n_failed;
	}
	cout << "(" << line << ") ";
	//cout << "expected: " << (void *)exp << ", actual: " << (void *)act << "\n";
	cout << "expected: ";
	print(exp, sz);
	cout << ", actual: ";
	print(act, sz);
	cout << "\n";
}
void check(int line, char exp, char act)
{
	++g_n_tested;
	if( exp == act )
		cout << "OK: ";
	else {
		cout << "*** NG: ";
		++g_n_failed;
	}
	cout << "(" << line << ") ";
	cout << "expected: '" << exp << "', actual: '" << act << "'\n";
}
//----------------------------------------------------------------------------------
int main()
{
	cout << "strrchr():\n";
	const char *s1 = "";
	check(__LINE__, (const char *)0, my_strrchr(s1, 'x'));
	const char *s2 = "abc";
	check(__LINE__, (const char *)0, my_strrchr(s2, 'x'));
	const char *s3 = "abcabc";
	check(__LINE__, (const char *)s3+3, my_strrchr(s3, 'a'));
	const char *s4 = "abcccc";
	check(__LINE__, (const char *)s4+5, my_strrchr(s4, 'c'));
	
	cout << "\n";
	cout << g_n_failed << " failed / " << g_n_tested << " testted.\n";
	getchar();
	return 0;
}
