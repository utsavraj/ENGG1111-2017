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

using namespace std;

int main() {
	int occurrences = 0;

	Dynarray<char> ore;

	while (1) {
		char c;
		cin.get(c);
		if (c == '\n')
			break;
		ore.add(c);
	}

	int lenpass = 0; // actual length of password
	while (ore[lenpass] != '\0' && lenpass < ore.size())
		lenpass++;
	int occurrencesA = 0;
	int occurrencesH = 0;
	int occurrencesZ = 0;

	for (int i = 0; i < lenpass; i++) {
		occurrencesA = 0;
		occurrencesH = 0;
		occurrencesZ = 0;
		for (int j = i; j <= i + 4; j++) {
			if (ore[j] == 'A')
				occurrencesA++;

			if (ore[j] == 'H')
				occurrencesH++;

			if (ore[j] == 'Z')
				occurrencesZ++;

			if (occurrencesA == 2 && occurrencesH == 2 && occurrencesZ == 1) {
				occurrences++;
				i += 4;
				break;
			}
		}
	}
	cout << occurrences << endl;
	return 0;
}