#include <iostream>
#pragma warning(disable:4996)

using namespace std;

class People {
private:
	const char* m_id;
	const char* m_pw;

	char *selDiet; // ���̾�Ʈ ��� ����(� ��¿�)
	char* m_sex;
	int m_weight = 80;
	int m_height = 175;
	int m_age = 20;

	int m_BMI = 0; // ǥ��ü��
	int m_muscle = 0; //������
	int m_bodyFat = 0; // ü����
	int m_metabolism = 0; //���ʴ�緮

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


	//void showPeople(); // �� ����� ������ �����ִ� �Լ�
	//void showResult(); // �Ϸ��Ϸ��� ����� �����ִ� show �Լ�
	//void showSchedule(); // ������¸� ������
	//void matching(); // ģ���� ��Ī�����ִ� �Լ�
	//void chooseMeal(); //�Ϸ��ѳ� ���� �Լ� -> 0-1 knapsack���� ������ ���� �Է�
	void chooseDiet(); // ���ϴ� �Ĵ� ����
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
//////////////////////////////////////////////////////People get �Լ�
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
//////////////////////////////////////////////////////People set �Լ�
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
	int m_fat;		//����
	int m_protein;	//�ܹ���
	int m_carbo;
public:

	int getFat();
	int getProtein();
	int getCarbo();

	void setFat(int fat);
	void setProtein(int protain);
	void setCarbo(int carbo);


};

//////////////////////////////////////////////////////Food get �Լ�
int Food::getFat() {
	return m_fat;
}
int Food::getProtein() {
	return m_protein;
}
int Food::getCarbo() {
	return m_carbo;
}

//////////////////////////////////////////////////////Food set �Լ�
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
	int consumeCal;	//�Һ�Į�θ�
	int time;		//�ð�
public:


};

void People::start() {
	cout << "test" << endl;
	while (1) {
		cout << "�Ĵܰ��� �ý���" << endl;
		cout << "1) ���������Է� 2)�Ĵܼ��� 3)��Īģ�� ã�� 4)������ �ѳ����� 5) �����ٷ����� 6) ����" << endl;
		cout << "�޴��� �����ϼ��� : ";

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
			return; // �� �Լ��� ������ �� ��

		default:
			break;

		}

	}

}

void People::chooseDiet() {
	// ���ϴ� �Ĵ�/��õ���̾�Ʈ ����
	int input1 = 0;

	cout << "1) ����� �Ĵ� / 2)���ø����̼� ��õ �Ĵ�" << endl;
	cin >> input1;

	if (input1 == 1) {
		int input2 = 0;

		cout << "���ϴ� ���̾�Ʈ ����� �����ϼ���" << endl;
		cout << "1)��������ź�� 2)��ܹ� 3)������ 4)��Į�θ� 5) �Ŀ��" << endl;
		cin >> input2;

		if (input2 == 1) {
			selDiet = "��������ź��";
		}
		else if (input2 == 2) {
			selDiet = "��ܹ�";
		}
		else if (input2 == 3) {
			selDiet = "������";
		}
		else if (input2 == 4) {
			selDiet = "��Į�θ�";
		}
		else if (input2 == 5) {
			selDiet = "�Ŀ��";
		}
		else {
			cout << "���⿡ ����� ����ּ���" << endl;
		}

	}
	else if (input1 == 2) {
		//bmi����
		//ü���� = ü��-������
		//������ = (1.07*ü��) - (128*ü��^2/Ű^2)
		m_BMI = getWeight() / (getHeight()*getHeight());
		m_muscle = (1.07*getWeight()) - (128 * (getWeight()*getWeight()) / (getHeight()*getHeight()));
		m_bodyFat = getWeight() - m_muscle;

		cout << "BMI ���� : " << m_BMI << endl;
		cout << "ü���� ���� : " << m_bodyFat << endl;
		cout << "������ ���� : " << m_muscle << endl;

	}
}
int main() {
	People jungbin("jeon", "1234"); //ID�� ��й�ȣ �Է�

	jungbin.start();


	return 0;
}