#include <iostream>

class my_str {
private:
	int length;
	char* string;
public:
	my_str() {
		my_str::length = 0;
		my_str::string = 0;
	}

	my_str(const char str[]) {
		int l;
		for (l = 0; str[l]; l++);
		my_str::length = l;
		my_str::string = new char[l];
		for (int i = 0; i < l; i++) {
			my_str::string[i] = str[i];
		}
	}

	my_str(const my_str& str) {
		my_str::length = str.length;
		my_str::string = new char[my_str::length];
		for (int i = 0; i < my_str::length; i++) {
			my_str::string[i] = str.string[i];
		}
	}

	char& operator[](size_t i) {
		return my_str::string[i];
	}

	friend my_str& operator!(my_str& s);
	friend std::ostream& operator<<(std::ostream& out, my_str str);
	friend std::istream& operator>>(std::istream& in, my_str& str);

	friend my_str operator+(my_str s1, my_str s2) {
		my_str res;
		res.length = s1.length + s2.length;
		res.string = new char[res.length];
		for (unsigned int i = 0; i < s1.length; i++) {
			res[i] = s1[i];
		}
		for (unsigned int i = s1.length; i < res.length; i++) {
			res[i] = s2[i - s1.length];
		}
		return res;
	}

	friend my_str operator*(my_str str, unsigned int n) {
		my_str res;
		res.length = str.length * n;
		res.string = new char[res.length];
		for (int i = 0, j = 0; i < res.length; i++, j++) {
			if (j == str.length)
				j = 0;
			res[i] = str[j];
		}
		return res;
	}


	my_str& operator=(const char str[]) {
		int l;
		for (l = 0; str[l]; l++);
		my_str::length = l;
		my_str::string = new char[l];
		for (int i = 0; i < l; i++) {
			my_str::string[i] = str[i];
		}
		return *this;
	}

	my_str& operator=(my_str str) {
		my_str::length = str.length;
		my_str::string = new char[my_str::length];
		for (int i = 0; i < my_str::length; i++) {
			string[i] = str[i];
		}
		return *this;
	}

	friend my_str& operator+=(my_str& str, char ch) {
		my_str res;
		res.length = str.length + 1;
		res.string = new char[res.length];
		for (int i = 0; i < str.length; i++) {
			res[i] = str[i];
		}
		res[res.length - 1] = ch;
		str = res;
		return str;
	}
	friend my_str& operator+=(my_str& s1, my_str& s2) {
		my_str res;
		res.length = s1.length + s2.length;
		res.string = new char[res.length];
		for (unsigned int i = 0; i < s1.length; i++) {
			res[i] = s1[i];
		}
		for (unsigned int i = s1.length; i < res.length; i++) {
			res[i] = s2[i - s1.length];
		}
		s1 = res;
		return s1;
	}

	friend bool operator==(const my_str s1, const my_str s2) {
		if (s1.length != s2.length)
			return false;
		else {
			for (int i = 0; i < s1.length; i++) {
				if (s1.string[i] != s2.string[i])
					return false;
			}
			return true;
		}
	}

	unsigned int size() {
		return my_str::length;
	}
	void reverse() {
		for (unsigned int i = 0; i < my_str::length / 2; i++) {
			char temp = my_str::string[i];
			my_str::string[i] = my_str::string[my_str::length - i - 1];
			my_str::string[my_str::length - i - 1] = temp;
		}
		return;
	}

	unsigned int find_i(char& c) {
		for (unsigned int i = 0; i < my_str::length; i++) {
			if (my_str::string[i] == c)
				return i;
		}
		return my_str::length;
	}

	unsigned int count(char& c) {
		unsigned int counter = 0;
		for (unsigned i = 0; i < my_str::length; i++) {
			if (my_str::string[i] == c)
				++counter;
		}
		return counter;
	}

	bool isExist(char c) {
		for (unsigned i = 0; i < my_str::length; i++) {
			if (my_str::string[i] == c)
				return true;
		}
		return false;
	}

	my_str change(/*my_str& str, */char a, char b) {
		for (int i = 0; i < my_str::length; i++) {
			if (string[i] == a)
				string[i] = b;
		}
		return string;
	}

	my_str substr(unsigned int pos, unsigned int length) {
		my_str res = "";
		for (int i = pos; i < length; i++) {
			res += my_str::string[i];
		}
		return res;
	}

	bool empty() {
		if (my_str::length == 0)
			return true;
		return false;
	}

	int ctoi(char a) {
		int res = (char)(a - 48);
		return res;
	}
	~my_str() {
		delete string;
		string = nullptr;
		length = 0;
	}
};

std::ostream& operator<<(std::ostream& out, my_str str) {
	for (int i = 0; i < str.size(); i++) {
		out << str[i];
	}
	return out;
}
std::istream& operator>>(std::istream& in, my_str& str) {
	size_t maxLength = 2;
	char* s = (char*)malloc(maxLength * sizeof(char));
	size_t length;
	for (length = 0; '\n' - (s[length] = std::cin.get()); ++length) {
		if (length == maxLength - 1) {
			s = (char*)realloc(s, (maxLength *= 2) * sizeof(char));
		}
	}
	s = (char*)realloc(s, (length + 1) * sizeof(char));
	s[length] = '\0';
	str = s;
	free(s);
	s = nullptr;
	return in;
}

//int main() {
//	my_str s = "dgdgh";
//	std::cout << s.empty();
//
//	return 0;
//}