#include <iostream>

template <class T> class Dynarray {
private:
	T *pa;
	int length;
	int nextIndex;

public:
	Dynarray();
	~Dynarray();
	T &operator[](int index);
	void add(int val);
	int size();
};
template <class T> Dynarray<T>::Dynarray() {
	pa = new T[10];
	for (int i = 0; i < 10; i++)
		pa[i] = 0;
	length = 10;
	nextIndex = 0;
}
template <class T> Dynarray<T>::~Dynarray() {
	delete[] pa;
}
template <class T> T &Dynarray<T>::operator[](int index) {
	T *pnewa;
	if (index >= length) {
		pnewa = new T[index + 10];
		for (int i = 0; i < nextIndex; i++)
			pnewa[i] = pa[i];
		for (int j = nextIndex; j < index + 10; j++)
			pnewa[j] = 0;
		length = index + 10;
		delete[] pa;
		pa = pnewa;
	}
	if (index > nextIndex)
		nextIndex = index + 1;
	return *(pa + index);
}
template <class T> void Dynarray<T>::add(int val) {
	T *pnewa;
	if (nextIndex == length) {
		length = length + 10;
		pnewa = new T[length];
		for (int i = 0; i < nextIndex; i++)
			pnewa[i] = pa[i];
		for (int j = nextIndex; j < length; j++)
			pnewa[j] = 0;
		delete[] pa;
		pa = pnewa;
	}
	pa[nextIndex++] = val;
}
template <class T> int Dynarray<T>::size() {
	return length;
}

void swap(char *xp, char *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

using namespace std;

int main() {
	Dynarray<char> mess;
	cin >> noskipws;

	while (1) {
		char c;
		cin >> c;
		if (!cin || c == '\n')
			break;
		mess.add(c);
	}

	Dynarray<char> pass;
	while (1) {
		char c;
		cin >> c;
		if (!cin || c == '\n')
			break;
		pass.add(c);
	}

	for (int w = 0; w < 50; w++) // lowercasing for mess
	{
		if (int(mess[w]) >= 65 && int(mess[w]) <= 90) {
			int st = 0;
			st = int(mess[w]) + 32;
			mess[w] = char(st);
		}
	}

	for (int w = 0; w < 50; w++) // lowercasing for pass
	{
		if (int(pass[w]) >= 65 && int(pass[w]) <= 90) {
			int st = 0;
			st = int(pass[w]) + 32;
			pass[w] = char(st);
		}
	}

	for (int i = 0; i < mess.size(); i++) // Deleting punctiation
	{
		if ('a' <= mess[i] && 'z' >= mess[i])
			;
		else {
			mess[i] = '\0';
			for (int z = 0; z < mess.size() - i - 1; z++) {
				swap(&mess[z], &mess[z + 1]);
			}
		}
	}

	// Sorting
	for (int i = 0; i < mess.size() - 1; i++)
		for (int j = 0; j < mess.size() - i - 1; j++)
			if (mess[j] > mess[j + 1])
				swap(&mess[j], &mess[j + 1]);

	int ini = 0; // start
	while (mess[ini] == '\0' && ini < mess.size()) {
		ini++;
	}
	int p = 0;
	int end = ini; // fin
	while (mess[end] != '\0' && end < mess.size()) {
		swap(&mess[end], &mess[p]);
		p++;
		end++;
	}
	ini = 0;
	end = p;

	int lenpass = 0; // actual length of password
	while (pass[lenpass] != '\0' && lenpass < pass.size())
		lenpass++;

	// i
	int refer = end - ini - 1;
	int referp = ini + (refer / 2 + 1);
	char referpoint = mess[referp];
  //cout<<refer<<endl<<referpoint<<endl;
  //for (int i1 = 0; i1 < mess.size(); i1++)
	//	cout << mess[i1];
  //cout<<endl;
  
	for (int i = ini; i < end - 1;) {
		int j = i + 1;
		for (; j < end; j++) {
			if (mess[j] == mess[i]) {
				mess[j] = '\0';

			} else {
				break;
			}
		}
		i = j;
	}

	// Sorting
	for (int i = 0; i < mess.size() - 1; i++)
		for (int j = 0; j < mess.size() - i - 1; j++)
			if (mess[j] > mess[j + 1])
				swap(&mess[j], &mess[j + 1]);

	//for (int i1 = 0; i1 < mess.size(); i1++)
	//	cout << mess[i1];
  //cout<<endl;
	//cout << endl << ini << " " << end;

	ini = 0; // start
	while (mess[ini] == '\0' && ini < mess.size()) {
		ini++;
	}
	p = 0;
	end = ini; // fin
	while (mess[end] != '\0' && end < mess.size()) {
		swap(&mess[end], &mess[p]);
		p++;
		end++;
	}
	ini = 0;
	end = p;

	//cout << endl << ini << " " << end << endl;
	int ind = 0;
	for (; ind < end; ind++)
		if (mess[ind] == referpoint)
			break;

	Dynarray<int> lst; //*list DELETE*
	int a = 0;

	for (int i = 0; i < lenpass; i++) // subset of pass
	{
		int j = ini;
		for (; j < end; j++) {
			if (pass[i] == mess[j]) {
				lst[a] = j; //*list DELETE*
				a++;		//*List DELETE*
				break;
			}
		}

		if (j == end||j==ind) {
			cout << "Invalid code: Don't break it!";
			return 0;
		}
	}
	for (int i=0;i<lenpass;i++){
	    if (lst[i]<ind)
	      cout <<"acw:"<< ind-lst[i]<<endl;
	    else
	      cout<<"cw:"<<lst[i]-ind<<endl;
	}
}