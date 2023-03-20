#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	
	ifstream fin("batch.inp");
	ofstream fout("batch.out");

	int num = 0;
	fin >> num;

	int io = 0; //유휴시간
	int sum = 0; // 총 작동시간

	int a = 0;
	int b = 0;
	for (int i = 0; i < num; i++) {
		while (a != -1) {// -1을 만날때까지 반복
			fin >> a;
			sum += a;

			// 각 줄의 짝수 번째 숫자만 더함 == I/O 시간.
			if (b == 0) {
				b++;
			}
			else if (b == 1 && a != -1) {
				io += a;
				b = 0;
			}
		}
		a = 0;
		b = 0;
	}
	fout << io << " " << sum + num;
	fin.close();
	fout.close();
}