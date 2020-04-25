#include<iostream>
#include <string.h>  // for strlen
using namespace std;

char my_pop_back(char *str){
	int len = strlen(str);

	if(len == 0){
		return '\0';
	}
	char ret = *(str + len - 1);
	*(str + len -1) = '\0';
	return ret;
}

char my_pop_front(char *str){
	int len = strlen(str);

	char c = *str;
	if(c != '\0'){
		cout << "##char c=" << c << endl;
		while( (*str = *(str+1)) != '\0'){
			cout << "####test *str=" << *str << " *(str+1)=" << *(str+1) <<endl;
			str++;
		}

	}
	return c;
}

void my_strcpy(char *dst, const char *src){
	while((*dst++ = *src++) != '\0'){}
}

void my_strcpy2(char *dst, const char *src){
	while(*src != '\0'){
		*dst = *src;
		dst++;
		src++;
	}
}


void my_erase_head(char *str, int n){
	const int len = strlen(str);
	if(n>=len){
		*str = '\0';
		return;
	}

	char* src = str + n;
	// 備忘、どうしても上の行を　char* src = *str +n と書いてしまうのは反省。

	while( (*str++ = *src++) != '\0'){}

}

void my_erase_tail(char* str, int n){
	//演習8、模範解答のほうが優れているという印象
	const int len = strlen(str);

	if(n>=len){
		*str = '\0';
		return;
	}
	*(str + len -n) = '\0';
	return;

}

void my_strrev(char *str){
	//演習27
	int len = strlen(str);

	for (int i=0; i<len/2; i++){
		char c = *(str+i);
		*(str + i) = *(str + len -1 - i);
		*(str + len -1 - i) = c;
	}
}

void my_str_rot_left(char *str){
	//演習28
	int len = strlen(str);

	if(len <= 1){
		return;
	}
	char c = *str;
	while((*str = *(str+1)) != '\0'){
		str++;
	}
	*str = c;
}

void my_str_rot_right(char *str){
	//演習29
	int len = strlen(str);

	if(len <=1){
		
	}else{
		char c = *(str+len-1);
		for(int i=len-1; i>0; i--){
			str[i] = str[i-1];
		}
		*str = c;
	}
}

const char *my_strrchr(const char *str, char c){
	int len = strlen(str);

	for (int i=len-1; i>0; i--){
		if(str[i] == c){
			return &str[i];
		}
	}
	cout << "NG" << endl;
	return str;
}

int main(){

/*
	//演習30
	//ダメ、実行方法がわからない。関数が正しいことはtestcodeで確認している。
	cout << "**4 " << (const char *)my_strrchr("abcccc",'c') << endl;
	cout << "**1 " << my_strrchr("",'x') << " **" << endl;
	cout << "**2 " << my_strrchr("abc",'x') << endl;
	cout << "**3 " << my_strrchr("abc",'a') << endl;
	cout << "**4 " << my_strrchr("abcccc",'c') << endl;
*/	


	//演習29
	char v1[] = "12345";
	my_str_rot_right(v1);
	cout << v1 << endl;
	char v2[] = "abc";
	my_str_rot_right(v2);
	cout << v2 << endl;
	char v3[] = "";
	my_str_rot_right(v3);
	cout << v3 << endl;

/*
	//演習28
	char v1[] = "a1234567";
	my_str_rot_left(v1);
	cout << v1 << endl;
*/

/*
	//演習27
	char v1[] = "xyz123";
	my_strrev(v1);
	cout << v1 << endl;
	char v2[] = "1234567890";
	my_strrev(v2);
	cout << v2 << endl;
*/	

/*
	//演習8
	char v1[] = "abcxyz";
	my_erase_tail(v1,3);
	cout << v1 << endl;
	char v3[] = "abcxyz";
	my_erase_tail(v3,0);
	cout << v3 << endl;
	char v4[] = "abc";
	my_erase_tail(v4,6);
	cout << v4 << endl;
*/

/*
	char v1[] = "abcxyz";
	my_erase_head(v1,3);
	cout << v1 << endl;
	char v3[] = "abcxyz";
	my_erase_head(v3,0);
	cout << v3 << endl;

*/


/*
	char v[10] = {0};
	char *ptr = &v[0];
	for(int i=0; i<10; i++){cout << "{" << (int)v[i] << "}" ;}
	cout << endl;
	*ptr++ = 1;
	for(int i=0; i<10; i++){cout << "{" << (int)v[i] << "}" ;}
	cout <<  endl;
	*ptr = 2;
	for(int i=0; i<10; i++){cout << "{" << (int)v[i] << "}" ;}
	cout <<  endl;
	ptr = &v[5];
	*++ptr = 3;
	for(int i=0; i<10; i++){cout << "{" << (int)v[i] << "}" ;}
	cout <<  endl;	
	*ptr = 4;
	for(int i=0; i<10; i++){cout << "{" << (int)v[i] << "}" ;}
	cout <<  endl;
*/



/*
	char dst[10];
	const char *src = "abc123";
	my_strcpy2(dst, src);
	cout << dst ;
*/

/*
	char buf[] = "abcd";
	cout << " pop=" << my_pop_front(buf) << " buf=" << buf << endl;
	cout << " pop=" << my_pop_front(buf) << " buf=" << buf << endl;
	cout << " pop=" << my_pop_front(buf) << " buf=" << buf << endl;
	cout << " pop=" << my_pop_front(buf) << " buf=" << buf << endl;
	cout << " pop=" << my_pop_front(buf) << " buf=" << buf << endl;
*/

/*
	char buf[] = "abcd";
	cout << " pop=" << my_pop_back(buf) << " buf=" << buf << endl;
	cout << " pop=" << my_pop_back(buf) << " buf=" << buf << endl;
	cout << " pop=" << my_pop_back(buf) << " buf=" << buf << endl;
	cout << " pop=" << my_pop_back(buf) << " buf=" << buf << endl;
	cout << " pop=" << my_pop_back(buf) << " buf=" << buf << endl;
*/	


}
