#include <iostream>

int main(void) {
	long long A, B, C;
	long long X1, X2, Y1, Y2;
	std::cin >> A >> B >> C >> X1 >> X2 >> Y1 >> Y2;
	
	long long sub1 = B * Y1 + A * X1 + C ;		// 기울기 음수일 때
	long long sub2 = B * Y2 + A * X2 + C ;
	long long sub3 = B * Y2 + A * X1 + C;		// 기울기 양수일 때
	long long sub4 = B * Y1 + A * X2 + C;
	
	if ((double)A / B < 0) {					// 기울기 양수일 때는 
		if (sub3 * sub4 < 0) {					// sub3,4의 곱이 음수이면 포함
			std::cout << "Poor";
		}
		else
			std::cout << "Lucky";				// 0이상이면 포함 x
	}
	else if (A == 0&&B!=0){
		if((B*Y1+C)*(B*Y2+C)<0)					// 기울기 0일때는
			std::cout << "Poor";		
		else
			std::cout << "Lucky";
	}
			
	else if((double)A / B > 0){					// 기울기 음수일 때는
		if (sub1 * sub2 < 0) {					// sub1,2의 곱이 음수이면 포함
			std::cout << "Poor";
		}
		else
			std::cout << "Lucky";
	}


	return 0;
}

