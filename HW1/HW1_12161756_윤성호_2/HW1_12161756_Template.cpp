#include <iostream>
using namespace std;
template <typename T>
class vectorOfInt{
public:

	T *Array1;
	int ini_size = 0;

	vectorOfInt(){
		ini_size = 32;
		Array1 = new T[ini_size];

		for (int i = 0; i < ini_size; i++){
			Array1[i] = NULL;
		}
	}

	vectorOfInt(int s){
		ini_size = s;
		Array1 = new T[ini_size];

		for (int i = 0; i < ini_size; i++){
			Array1[i] = NULL;
		}
	}

	vectorOfInt(vectorOfInt &c){
		ini_size = c.ini_size;
		Array1 = new T[ini_size];

		for (int i = 0; i < ini_size; i++){
			Array1[i] = c.Array1[i];
		}
	}

	T getMethod(int ind){
		cout << "getMethod ¸®ÅÏ°ª : ";
		return Array1[ind];
	}

	void setMethod(int ind, T val){
		Array1[ind] = val;
		cout << "setMethod ½ÇÇàµÊ" << endl;
	}

	void pushback(T val){
		int full_ind = 0;
		for (int i = ini_size - 1; i >= 0; i--){
			if (Array1[i] != NULL){
				full_ind = i;
				break;
			}
		}

		if (full_ind == ini_size - 1)
		{

			int *Array2 = new int[ini_size + 1];
			for (int i = 0; i <= full_ind; i++){
				Array2[i] = Array1[i];
			}

			delete[] Array1;
			Array2[full_ind + 1] = val;

			Array1 = new int[ini_size + 1];

			for (int i = 0; i <= ini_size; i++){
				Array1[i] = Array2[i];
			}
			delete[] Array2;
		}

		else{
			Array1[full_ind + 1] = val;
		}

		cout << "pushback ½ÇÇàµÊ" << endl;
	}

	void pushfront(T val){
		int *Array2 = new int[ini_size + 1];
		for (int i = 0; i <= ini_size - 1; i++){
			Array2[i + 1] = Array1[i];
		}
		delete[] Array1;

		Array1 = new int[ini_size + 1];

		for (int i = 0; i <= ini_size; i++){
			Array1[i] = Array2[i];
		}

		delete[] Array2;
		Array1[0] = val;
		cout << "pushfront ½ÇÇàµÊ" << endl;
	}

	vectorOfInt operator=(vectorOfInt &k){
		ini_size = k.ini_size;
		delete[] Array1;
		Array1 = new int[ini_size];

		for (int i = 0; i < ini_size; i++){
			Array1[i] = k.Array1[i];
		}
		return *this;
	}

	T sum(){
		T val1 = 0;

		for (int i = 0; i < ini_size; i++){
			val1 += Array1[i];
		}
		return val1;
	}

	~vectorOfInt(){
		delete[] Array1;
	}
};

int main(){
	
	cout << "004ºÐ¹Ý 12161756 À±¼ºÈ£" << endl;
	vectorOfInt <float> ex5(5);
	ex5.setMethod(1, 1.3f);
	ex5.setMethod(2, 2.5f);
	ex5.setMethod(3, 3.1f);
	cout << ex5.sum() << endl;

	vectorOfInt <int> ex6(6);
	ex6.setMethod(0, 1.1);
	ex6.setMethod(5, 2.1);
	cout << ex6.sum() << endl;
}