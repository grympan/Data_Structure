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
		cout << "getMethod ���ϰ� : ";
		return Array1[ind];
	}

	void setMethod(int ind, int val){
		Array1[ind] = val;
		cout << "setMethod �����" << endl;
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

		cout << "pushback �����" << endl;
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
		cout << "pushfront �����" << endl;
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
	cout << "004�й� 12161756 ����ȣ" << endl;
	cout << "====== ex1 ���� ======" << endl;
	vectorOfInt ex1; //32��	��Ҹ� �Ҵ��ϴ� �μ����� ������
	ex1.setMethod(31, 10); //31�ε����� 10���� set
	cout << ex1.getMethod(31) <<endl; //31�ε��� ���� �ҷ���

	ex1.pushback(20); //20�� ���� pushback
	cout << ex1.getMethod(32) << endl; //pushback�� ���� �ҷ���

	ex1.pushfront(30); //30�� ���� pushfront
	cout << ex1.getMethod(0) << endl; //pushfront�� ���� �ҷ���


	cout << endl << "====== ex2 ���� ======" << endl;
	vectorOfInt ex2(7); //ũ��(7)�� �μ��� �޴� ������
	ex2.setMethod(6, 5); //6�ε����� 5���� set
	cout << ex2.getMethod(6) << endl; //6�ε��� ���� �ҷ���
	

	cout << endl << "====== ex3 ���� ======" << endl;
	vectorOfInt ex3 = ex2; //���� ������ ����
	cout << ex3.getMethod(6) << endl;
	

	cout << endl << "====== ex4 ���� ======" << endl;;
	ex1 = ex2; //���� ������ ����
	cout << ex1.getMethod(6) << endl;
}