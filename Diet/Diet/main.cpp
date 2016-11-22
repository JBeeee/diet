#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

using namespace std;

class People {
private:
	char* m_ID;
	char* m_PW;
	char* m_name;

	char* selDiet; // ���̾�Ʈ ��� ����(� ��¿�)
	int m_sex;
	double m_original_weight;
	double m_changed_weight;
	double m_height;
	int m_age;

	double m_BMI; // ǥ��ü��
	double m_muscle; //������
	double m_bodyFat; // ü����
	double m_metabolism; //���ʴ�緮

	double m_goalWeight;
	int m_start;
	int m_end;

public:
	People(const char* _name, const char* _ID, const char* _PW, double _weight, double _height, int _start, int _end, int _goal_weight, int _sex);

	int getSex();
	int getWeight();
	int getHeight();
	int getAge();

	void setSex(int sex);
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

	//void start();

};

People::People(const char* _name, const char* _ID, const char* _PW, double _weight, double _height, int _start, int _end, int _goal_weight, int _sex)
:m_original_weight(_weight), m_height(_height), m_changed_weight(0), m_start(_start), m_end(_end), m_BMI(0), m_goalWeight(_goal_weight)
{
	int len = strlen(_name);
	m_name = new char[len + 1];
	strcpy(m_name, _name);

	len = strlen(_ID);
	m_ID = new char[len + 1];
	strcpy(m_ID, _ID);

	len = strlen(_PW);
	m_PW = new char[len + 1];
	strcpy(m_PW, _PW);

	m_BMI = 0;    /// ��� 
	m_muscle = 0;
	m_bodyFat = 0;
	m_metabolism = 0;

	ofstream userin("userinfo.txt", ios::app);
	userin << m_name << " " << m_ID << " " << m_PW << " " << m_original_weight << " " << m_height << " ";
};

//////////////////////////////////////////////////////People get �Լ�
int People::getSex() {
	return m_sex;
}
int People::getWeight() {
	return m_original_weight;
}
int People::getHeight() {
	return m_height;
}
int People::getAge() {
	return m_age;
}
//////////////////////////////////////////////////////People set �Լ�

void People::setSex(int sex) {

	m_sex = sex;
}
void People::setWeight(int weight) {
	m_original_weight = weight;
}
void People::setHeight(int height) {
	m_height = height;
}
void People::setAge(int age) {
	m_age = age;
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class People_handler
{
private:
	People* people_Arr[50];
	int peopleNum;

public:
	People_handler() :peopleNum(0) {};
	void make_user();     // ȸ������
	void show_main();
	void start();
	void login();         // login
};

void People_handler::make_user()
{
	char t_name[20];
	char t_ID[20];
	char t_PW[20];

	double t_original_weight;
	double t_height;
	int t_sex;

	double t_BMI;

	int t_goal_weight;

	int t_start;
	int t_end;

	cout << " ���̵� : ";
	cin >> t_ID;
	cout << " ��й�ȣ : ";
	cin >> t_PW;
	cout << " �̸� : ";
	cin >> t_name;
	cout << " ������ : ";
	cin >> t_original_weight;
	cout << " Ű : ";
	cin >> t_height;
	cout << " ��ǥ ü�� : ";
	cin >> t_goal_weight;

	cout << " ���� : (1.����, 2.����)";
	cin >> t_sex;

	cout << " ��ǥ �Ⱓ " << endl;

	cout << "���� ��¥ : ";
	cin >> t_start;
	cout << "������ ��¥ : ";
	cin >> t_end;

	t_BMI = 50;

	cout << endl;

	people_Arr[peopleNum++] = new People(t_name, t_ID, t_PW, t_original_weight, t_height, t_start, t_end, t_goal_weight, t_sex);
}

void People_handler::start() {
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
			//chooseDiet();
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
int main()
{




	return 0;
}