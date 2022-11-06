#include<iostream>
#include"Windows.h"
#include <fstream>
using namespace std;

class Game   //класс игры
{
private:
	int count;   //кол-во попыток
	int Count_Word;   // кол-во слов 
	string word;     //загаданое слово
	string wordinput;	//ввод буквы
public:
	Game()    //онструктор по дефолту
	{
		int count = 0; 
		int  Count_Word = 0;
		string Word = nullptr;
		string Word_p = nullptr;
	}
	Game(int b) :Game()
	{
		Count_Word = b;
		fstream in;         //для чтения 
		in.open("Words.txt", ios::app);
		int A = rand() % (1 - Count_Word) + 1;  
		for (int i = 0; i < A; i++)
		{
			const int Size = 200;
			char Buffer[Size] = { };
			in.getline(Buffer, Size);
			word = string(Buffer);
		}
		in.close();
	}
	void Print_Play()
	{
		int attempt = 7; //допустимое кол-во ошибок 
		int win = 0;    //проверка если игрок выиграл 
		for (; ;)          //строение виселицы 
		{
			cout << "Attempt:" << attempt << endl;
			if (attempt < 6)
			{
				cout << "|";
				if (attempt < 5)
				{
					cout << "--------";
				}

			}
			cout << endl;
			if (attempt < 6)
			{
				cout << "|";
				if (attempt < 4)
				{
					cout << "O";
				}
			}
			cout << endl;
			if (attempt < 6)
			{
				cout << "|";
			}
			if (attempt < 7 && attempt != 0)
			{
				cout << "*";
			}
			if (attempt <= 0)
			{
				cout << "Вы проиграли" << endl;
			}
			char Player;
			char Buffer[300];
			strcpy_s(Buffer, word.c_str());
			for (int i = 0; i <= word.size(); i++)
			{
				if (wordinput.find(Buffer[i]) != 0)
				{
					cout << word;
				}
				if (i != word.size() - 1)
				{
					cout << "|";
				}

			}
			cout << endl;
		}
	}

	void SetWord(char a) 
	{
		word += a;
	}
	string GetWord()
	{
		return word;
	}
	void SetCount()
	{
		count++;
	}
	int GetCount()
	{
		return count;
	}
	void SetWord_p(char b)
	{
		wordinput += b;
	}
	string GetWord_p()
	{
		return wordinput;
	}
	void SetCount_w()
	{
		Count_Word++;
	}
	int GetCount_w()
	{
		return Count_Word;
	}
	void Printer()
	{
		cout << "Кол-во попыток: " << GetCount() << endl;
		cout << "В списке " << GetCount_w() <<" cлов" << endl;
		cout << "Загаданое слово: " << GetWord() << endl;
		cout << "Буквы которые ввел игрок: " << GetWord_p() << "\n";
	}
};

void Rules()
{
	cout << "---------Rules------------" << endl;
	cout << "Один из игроков загадывает слово — пишет на бумаге любые две буквы \nслова и отмечает места для остальных букв, например чертами \n(существует также вариант, когда изначально все буквы слова неизвестны). \nТакже рисуется виселица с петлёй. ";
	cout << "Второй игрок предлагает букву, которая может входить в это слово.\n Если такая буква есть в слове, то первый игрок пишет её над соответствующими этой букве чертами — столько раз,\n сколько она встречается в слове. Если такой буквы нет, то к виселице добавляется круг в петле,\n изображающий голову.";
	cout << " Второй игрок продолжает отгадывать буквы до тех пор, пока не отгадает всё слово.\n За каждый неправильный ответ первый игрок добавляет одну часть туловища к виселице ";
}
int count_words()
{
	int c = 0;
	ifstream in;   //открываем для чтения
	in.open("Word.txt", ios::app);   //выводимые ланные добавл. в конец файла
	do
	{
		char buf[150];
		in.getline(buf, 150);
		if (!strstr(buf, " "))
		{
			c++;
		}
	} while (in);
	return c;
	in.close();   //закрываем
}
void Play()
{
	time_t start = time(0);
	Game obj(count_words());
	obj.Print_Play();
	cout << "\n";
	if ((time(0) - start) >= 30)
	{
		cout << (time(0) - start) / 30;
		cout << (time(0) - start) % 30;
		obj.Printer();
	}
}


int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(0));
	int a;
	cout << "\t\tДобро пожаловать в виселицу\n1)Начать игру\n2)Правила игры\n3)Выход\n" << endl;
	cin >> a;
		if (a == 1)
		{
			Play();
		}
		if (a == 2)
		{
			Rules();
		}
		if (a == 3)
		{
			exit(0);
		}
}