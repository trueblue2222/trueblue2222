// ������û �����ڵ� ���� ġ�� ������ ���α׷�

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
	cout << "������û ������ 1000 ~ 9999 ������ ������ �����ϰڽ��ϴ�.\n";
	bool flag = false;
	while (!flag) {
		cout << "5�� �� ������ �����˴ϴ�." << endl;
		for (int i = 5; i > 0; i--) {
			cout << i << " " << flush;
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << endl;
		int num = (rand() % 9000) + 1000;
		int num_;
		cout << num << endl;

		// �Է� �ð� ���� ����
		auto start_time = high_resolution_clock::now();

		cout << "�Է��ϼ���! ";
		cin >> num_;

		// �Է� �ð� ���� ����
		auto end_time = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end_time - start_time);

		// �� ������ ��ȯ (�Ҽ��� 2�ڸ�����)
		double seconds = duration.count() / 1000.0;
		cout << "�Է� �ð�: " << fixed << setprecision(2) << seconds << "��" << endl;

		if (num == num_) {
			char yes_or_no = ' ';
			cout << "���ϼ̽��ϴ�. �� �Ͻðڽ��ϱ�? y or n : ";
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
			cout << "Ʋ�Ƚ��ϴ�. �� �Ͻðڽ��ϱ�? y or n : ";
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
	cout << "���α׷��� ����Ǿ����ϴ�.";
}