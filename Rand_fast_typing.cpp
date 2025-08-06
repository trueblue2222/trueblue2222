// 수강신청 보안코드 빨리 치는 연습용 프로그램

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

int main(void) {
	srand(time(NULL));
	cout << "수강신청 연습용 1000 ~ 9999 사이의 난수를 생성하겠습니다.\n";
	bool flag = false;
	while (!flag) {
		cout << "5초 후 난수가 생성됩니다." << endl;
		for (int i = 5; i > 0; i--) {
			cout << i << " " << flush;
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << endl;
		int num = (rand() % 9000) + 1000;
		int num_;
		cout << num << endl;

		// 입력 시간 측정 시작
		auto start_time = high_resolution_clock::now();

		cout << "입력하세요! ";
		cin >> num_;

		// 입력 시간 측정 종료
		auto end_time = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end_time - start_time);

		// 초 단위로 변환 (소수점 2자리까지)
		double seconds = duration.count() / 1000.0;
		cout << "입력 시간: " << fixed << setprecision(2) << seconds << "초" << endl;

		if (num == num_) {
			char yes_or_no = ' ';
			cout << "잘하셨습니다. 더 하시겠습니까? y or n : ";
			cin >> yes_or_no;
			if (yes_or_no == 'y') {
				continue;
			}
			else if (yes_or_no == 'n') {
				flag = true;
				continue;
			}
		}
		else {
			char yes_or_no = ' ';
			cout << "틀렸습니다. 더 하시겠습니까? y or n : ";
			cin >> yes_or_no;
			if (yes_or_no == 'y') {
				continue;
			}
			else if (yes_or_no == 'n') {
				flag = true;
				continue;
			}
		}
	}
	cout << "프로그램이 종료되었습니다.";
}