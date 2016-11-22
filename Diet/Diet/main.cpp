#include <iostream>
#pragma warning(disable:4996)

using namespace std;

class People {
private:
	const char* m_id;
	const char* m_pw;

	char *selDiet; // 다이어트 방식 저장(쇼에 출력용)
	char* m_sex;
	int m_weight = 80;
	int m_height = 175;
	int m_age = 20;

	int m_BMI = 0; // 표준체중
	int m_muscle = 0; //근육량
	int m_bodyFat = 0; // 체지방
	int m_metabolism = 0; //기초대사량

	int m_goalWeight;
	int m_dietPeriod;

public:
	People(const char* id, const char* pw);
	~People();

	char* getSex();
	int getWeight();
	int getHeight();
	int getAge();

	void setSex(char* sex);
	void setWeight(int weight);
	void setHeight(int height);
	void setAge(int age);


	//void showPeople(); // 한 사람의 정보를 보여주는 함수
	//void showResult(); // 하루하루의 결과를 보여주는 show 함수
	//void showSchedule(); // 진행상태를 보여줌
	//void matching(); // 친구와 매칭시켜주는 함수
	//void chooseMeal(); //하루한끼 고르는 함수 -> 0-1 knapsack으로 나머지 끼니 입력
	void chooseDiet(); // 원하는 식단 고르기
					   //bool login();

	void start();

};


People::People(const char* id, const char* pw)
	:m_id(id), m_pw(pw)
{

}

People::~People() {
	delete[] m_id;
	delete[] m_pw;
}
//////////////////////////////////////////////////////People get 함수
char* People::getSex() {
	return m_sex;
}
int People::getWeight() {
	return m_weight;
}
int People::getHeight() {
	return m_height;
}
int People::getAge() {
	return m_age;
}
//////////////////////////////////////////////////////People set 함수
void People::setSex(char* sex) {
	delete[] m_sex;
	int len = strlen(sex);
	m_sex = new char[len + 1];
	strcpy(m_sex, sex);
}
void People::setWeight(int weight) {
	m_weight = weight;
}
void People::setHeight(int height) {
	m_height = height;
}
void People::setAge(int age) {
	m_age = age;
}


class Food {
private:
	int m_fat;		//지방
	int m_protein;	//단백질
	int m_carbo;
public:

	int getFat();
	int getProtein();
	int getCarbo();

	void setFat(int fat);
	void setProtein(int protain);
	void setCarbo(int carbo);


};

//////////////////////////////////////////////////////Food get 함수
int Food::getFat() {
	return m_fat;
}
int Food::getProtein() {
	return m_protein;
}
int Food::getCarbo() {
	return m_carbo;
}

//////////////////////////////////////////////////////Food set 함수
void Food::setFat(int fat) {
	m_fat = fat;
}
void Food::setProtein(int protein) {
	m_protein = protein;
}
void Food::setCarbo(int carbo) {
	m_carbo = carbo;
}


class Exercise {
private:
	int consumeCal;	//소비칼로리
	int time;		//시간
public:


};

void People::start() {
	cout << "test" << endl;
	while (1) {
		cout << "식단관리 시스템" << endl;
		cout << "1) 개인정보입력 2)식단선택 3)매칭친구 찾기 4)오늘의 한끼고르기 5) 스케줄러보기 6) 종료" << endl;
		cout << "메뉴를 선택하세요 : ";

		int menu;
		cin >> menu;

		switch (menu) {
		case 1:
			/*
			if (login()) {

			}*/
			break;
		case 2:
			chooseDiet();
			break;
		case 3:
			//matching();
			break;
		case 4:
			//chooseMeal();
			break;
		case 5:
			//showSchedule();
			break;
		case 6:
			return; // 이 함수를 종료할 때 씀

		default:
			break;

		}

	}

}

void People::chooseDiet() {
	// 원하는 식단/추천다이어트 선택
	int input1 = 0;

	cout << "1) 사용자 식단 / 2)어플리케이션 추천 식단" << endl;
	cin >> input1;

	if (input1 == 1) {
		int input2 = 0;

		cout << "원하는 다이어트 방식을 선택하세요" << endl;
		cout << "1)고지방저탄수 2)고단백 3)저지방 4)저칼로리 5) 파워운동" << endl;
		cin >> input2;

		if (input2 == 1) {
			selDiet = "고지방저탄수";
		}
		else if (input2 == 2) {
			selDiet = "고단백";
		}
		else if (input2 == 3) {
			selDiet = "저지방";
		}
		else if (input2 == 4) {
			selDiet = "저칼로리";
		}
		else if (input2 == 5) {
			selDiet = "파워운동";
		}
		else {
			cout << "보기에 방식을 골라주세요" << endl;
		}

	}
	else if (input1 == 2) {
		//bmi지수
		//체지방 = 체중-제지방
		//제지방 = (1.07*체중) - (128*체중^2/키^2)
		m_BMI = getWeight() / (getHeight()*getHeight());
		m_muscle = (1.07*getWeight()) - (128 * (getWeight()*getWeight()) / (getHeight()*getHeight()));
		m_bodyFat = getWeight() - m_muscle;

		cout << "BMI 지수 : " << m_BMI << endl;
		cout << "체지방 지수 : " << m_bodyFat << endl;
		cout << "근육량 지수 : " << m_muscle << endl;

	}
}
int main() {
	People jungbin("jeon", "1234"); //ID와 비밀번호 입력

	jungbin.start();


	return 0;
}