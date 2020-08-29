#include <iostream>
using namespace std;

class vectorOfInt{
public:

	int *Array1;
	int ini_size = 0;

	vectorOfInt(){
		ini_size = 32;
		Array1 = new int[ini_size];

		for (int i = 0; i < ini_size; i++){
			Array1[i] = NULL;
		}
	}

	vectorOfInt(int s){
		ini_size = s;
		Array1 = new int[ini_size];

		for (int i = 0; i < ini_size; i++){
			Array1[i] = NULL;
		}
	}

	vectorOfInt(vectorOfInt &c){
		ini_size = c.ini_size;
		Array1 = new int[ini_size];

		for (int i = 0; i < ini_size; i++){
			Array1[i] = c.Array1[i];
		}
	}

	int getMethod(int ind){
		cout << "getMethod 리턴값 : ";
		return Array1[ind];
	}

	void setMethod(int ind, int val){
		Array1[ind] = val;
		cout << "setMethod 실행됨" << endl;
	}

	void pushback(int val){
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

		cout << "pushback 실행됨" << endl;
	}

	void pushfront(int val){
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
		cout << "pushfront 실행됨" << endl;
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

	~vectorOfInt(){
		delete[] Array1;
	}
};

int main(){
	cout << "004분반 12161756 윤성호" << endl;
	cout << "====== ex1 영역 ======" << endl;
	vectorOfInt ex1; //32개	요소를 할당하는 인수없는 생성자
	ex1.setMethod(31, 10); //31인덱스에 10값을 set
	cout << ex1.getMethod(31) <<endl; //31인덱스 값을 불러옴

	ex1.pushback(20); //20의 값을 pushback
	cout << ex1.getMethod(32) << endl; //pushback한 값을 불러옴

	ex1.pushfront(30); //30의 값을 pushfront
	cout << ex1.getMethod(0) << endl; //pushfront한 값을 불러옴


	cout << endl << "====== ex2 영역 ======" << endl;
	vectorOfInt ex2(7); //크기(7)을 인수로 받는 생성자
	ex2.setMethod(6, 5); //6인덱스에 5값을 set
	cout << ex2.getMethod(6) << endl; //6인덱스 값을 불러옴
	

	cout << endl << "====== ex3 영역 ======" << endl;
	vectorOfInt ex3 = ex2; //복사 생성자 실행
	cout << ex3.getMethod(6) << endl;
	

	cout << endl << "====== ex4 영역 ======" << endl;;
	ex1 = ex2; //대입 연산자 실행
	cout << ex1.getMethod(6) << endl;
}