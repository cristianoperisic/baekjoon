#include <iostream>

int main(void) {
	long long A, B, C;
	long long X1, X2, Y1, Y2;
	std::cin >> A >> B >> C >> X1 >> X2 >> Y1 >> Y2;
	
	long long sub1 = B * Y1 + A * X1 + C ;		// ���� ������ ��
	long long sub2 = B * Y2 + A * X2 + C ;
	long long sub3 = B * Y2 + A * X1 + C;		// ���� ����� ��
	long long sub4 = B * Y1 + A * X2 + C;
	
	if ((double)A / B < 0) {					// ���� ����� ���� 
		if (sub3 * sub4 < 0) {					// sub3,4�� ���� �����̸� ����
			std::cout << "Poor";
		}
		else
			std::cout << "Lucky";				// 0�̻��̸� ���� x
	}
	else if (A == 0&&B!=0){
		if((B*Y1+C)*(B*Y2+C)<0)					// ���� 0�϶���
			std::cout << "Poor";		
		else
			std::cout << "Lucky";
	}
			
	else if((double)A / B > 0){					// ���� ������ ����
		if (sub1 * sub2 < 0) {					// sub1,2�� ���� �����̸� ����
			std::cout << "Poor";
		}
		else
			std::cout << "Lucky";
	}


	return 0;
}

