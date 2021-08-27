// SML.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;


struct stackNode
{
	char data;
	stackNode* nextPTR;
};
struct stackNodeint
{
	double data;
	stackNodeint* nextPTR;
};
typedef struct stackNode STACKNODE;
typedef STACKNODE  *STACKNODEPTR;
typedef struct stackNodeint STACKNODEINT;
typedef STACKNODEINT* STACKNODEINTPTR;
void push(STACKNODEPTR *topPtr, char info)
{
	//topPtr - указатель на указатель на бывший головной элемент стека
	//*topPtr - указатель на бывший головной элемент стека
	//выделяется память под новый элемент типа структуры STACKNODE и создаётся указатель на эту область памяти:
	STACKNODEPTR newPtr;
	newPtr = new STACKNODE;
	//только что созданному элементу присваивается значение info в поле data
	newPtr->data = info;
	//теперь этот элемент будет головным в стеке, поэтому он должен указывать на следующий (тот, что 
	// раньше был головным). Поэтому:
	newPtr->nextPTR = *topPtr;
	//меняется указатель на головной элемент стека, так как теперь головным является newPtr:
	*topPtr = newPtr;
}
void pop(STACKNODEPTR* topPtr)
{
	*topPtr = (*topPtr)->nextPTR;
}
void pushINT(STACKNODEINTPTR* topPtr, double info)
{
	//topPtr - указатель на указатель на бывший головной элемент стека
	//*topPtr - указатель на бывший головной элемент стека
	//выделяется память под новый элемент типа структуры STACKNODE и создаётся указатель на эту область памяти:
	STACKNODEINTPTR newPtr;
	newPtr = new STACKNODEINT;
	//только что созданному элементу присваивается значение info в поле data
	newPtr->data = info;
	//теперь этот элемент будет головным в стеке, поэтому он должен указывать на следующий (тот, что 
	// раньше был головным). Поэтому:
	newPtr->nextPTR = *topPtr;
	//меняется указатель на головной элемент стека, так как теперь головным является newPtr:
	*topPtr = newPtr;
}
void popINT(STACKNODEINTPTR* topPtr)
{
	*topPtr = (*topPtr)->nextPTR;
}
void printStack(STACKNODEPTR currentPtr)
{
	if (currentPtr == NULL)
	{
		cout << "The stack is empty!\n\n";

	}
	else {
		cout << "The stack is: \n";
		while (currentPtr != NULL)
		{
			cout  << currentPtr->data << " -> ";
			currentPtr = currentPtr->nextPTR;
		}
		cout << "NULL\n\n";
	}
}
void printStackINT(STACKNODEINTPTR currentPtr)
{
	if (currentPtr == NULL)
	{
		cout << "The stack is empty!\n\n";

	}
	else {
		cout << "The stack is: \n";
		while (currentPtr != NULL)
		{
			cout << currentPtr->data << " -> ";
			currentPtr = currentPtr->nextPTR;
		}
		cout << "NULL\n\n";
	}
}
int WhatIsIt2(char a)
{
	if (a == '+')
	{
		return 2;
	}
	if (a == '-')
	{
		return 3;
	}
	if ( a == '*')
	{
		return 4;
	}
	if ( a == '/')
	{
		return 5;
	}
	else
	{
		return 1;
	}
}
int WhatIsIt(char a)
{
	if (a == '+' || a == '-')
	{
		return 31;
	}
	if (a == '*' || a == '/')
	{
		return 32;
	}
	if (a == '(')
	{
		return 2;
	}
	if (a == ')')
	{
		return 4;
	}
	else
	{
		return 1;
	}
}
int main()
{


	// Работа со стеками:
	stackNode* stkPtr;
	stkPtr = new stackNode;
	stkPtr = NULL;
	/*stkPtr2 = new stackNode;
	stkPtr->data = "A";
	stkPtr->nextPTR = stkPtr2;
	stkPtr2->data = "B";
	stkPtr2->nextPTR = NULL;*/
	/*printStack(stkPtr);
	push(&stkPtr, "A");
	printStack(stkPtr);
	push(&stkPtr, "B");
	printStack(stkPtr);
	pop(&stkPtr);
	printStack(stkPtr);*/




	//=================================================
	//преобразоване инфиксного выражения в постфиксное
	string infix;// = "(6+2)*5-8/4";
	cin >> infix;
	char *l = &infix[0];

	int N = 0; // в этой переменной будеи количество введённых символов
	while (*l) // для определения длины введённой строки
	{
		cout << *l << endl;
		l++;
		N++;
	}
	char* Infix = new char[N + 1];
	char* l1 = &Infix[0];
	l = &infix[0];
	while (*l)// считывание введённой строки в массив символов
	{
		*l1 = *l;
		l++;
		l1++;
	}
	Infix[N] = ')';
	char* postfix = new char[N];
	stackNode* stackPtr;
	stackPtr = new stackNode;
	stackPtr = NULL;

	push(&stackPtr, '(');


	int k = 0;
	char s;
	int q = 0;
	int o = 0;
	while (stackPtr != NULL)
	{
		if (k == N+1)
		{
			break;
		}
		s = Infix[k];
		k++;

		switch (WhatIsIt(s))
		{
		case 1:
			postfix[q] = s;
			q++;
			continue;
		case 2:
			push(&stackPtr, s);
			continue;
		case 31:
			while (stackPtr->data == '+' || stackPtr->data == '-' || stackPtr->data == '/' || stackPtr->data == '*')
			{
				o = 1;
				postfix[q] = stackPtr->data;
				q++;
				pop(&stackPtr);
			}
			if (stackPtr->data == '(' && o == 1 && stackPtr->nextPTR != NULL)
			{
				pop(&stackPtr);
			}
			o = 0;
			push(&stackPtr, s);
			continue;
		case 32:
			while (stackPtr->data == '/' || stackPtr->data == '*')
			{
				o = 1;
				postfix[q] = stackPtr->data;
				q++;
				pop(&stackPtr);
			}
			if (stackPtr->data == '('&&o == 1&& stackPtr->nextPTR != NULL)
			{
				pop(&stackPtr);
			}
			o = 0;
			push(&stackPtr, s);
			continue;
		case 4:
			while (stackPtr->data != '(')
			{
				postfix[q] = stackPtr->data;
				q++;
				pop(&stackPtr);
			}
			pop(&stackPtr);
			continue;
		default:
			break;
		}
	}
	postfix[q] = '\0';
	cout << "prefix form: " << endl;
	for (int n = 0; n <= q; n++)
	{
		cout << postfix[n];
	}
	cout << endl;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//оценка постфиксного выражения
	stackNodeint* stackPtr2;
	stackPtr2 = new stackNodeint;
	stackPtr2 = NULL;
	char* Postfix;
	Postfix = new char[q+1]; // создание массива под ппостфиксное выражение (оно будет сюда перенесено)
	for (int i = 0; i < q; i++)// перенос постфиксного выражения в массив
	{
		Postfix[i] = postfix[i];
	}
	Postfix[q] = '\0';
	char ch = Postfix[0];
	k = 0;
	double x, y;
	cout << "=================================================================\n";
	while (ch != '\0') // цикл оценки постфиксного выражения
	{
		k++;
		switch (WhatIsIt2(ch))
		{
		case 1:
			pushINT(&stackPtr2, (int(ch)-int('0')));
			ch = Postfix[k];
			continue;
		case 2: 
			//+
			x = stackPtr2->data;
			popINT(&stackPtr2);
			y = stackPtr2->data;
			popINT(&stackPtr2);
			pushINT(&stackPtr2, y+x);
			ch = Postfix[k];
			continue;
		case 3:
			//-
			x = stackPtr2->data;
			popINT(&stackPtr2);
			y = stackPtr2->data;
			popINT(&stackPtr2);
			pushINT(&stackPtr2, y - x);
			ch = Postfix[k];
			continue;
		case 4:
			//*
			x = stackPtr2->data;
			popINT(&stackPtr2);
			y = stackPtr2->data;
			popINT(&stackPtr2);
			pushINT(&stackPtr2, y * x);
			ch = Postfix[k];
			continue;
		case 5:
			// /
			x = stackPtr2->data;
			popINT(&stackPtr2);
			y = stackPtr2->data;
			popINT(&stackPtr2);
			pushINT(&stackPtr2, y / x);
			ch = Postfix[k];
			continue;
		}

	}
	if (ch == '\0')
	{
		cout <<"Result = "<< (stackPtr2->data) << endl;
	}
	//////////////////////////////////////////////////////////










	// SML
  int* memory = new int[100];
  int accumulator = 0;
  int instructionCounter = 0;
  int operationCode = 0;
  int operand = 0;
  int instructionRegister = 0;
  int code = 0;
  int code1 = 0;
  int a;

  cout << "Hello! I am SML\n Input your program below.\n To stop the input process enter -99999.\n";

  for (int i = 0; i < 100; i++)
  {
	  if (i < 10)
	  {
		  cout << 0 << i << "?  ";
		  cin >> a;
		  if (a == -99999)
		  {
			  memory[i] = 4301;
			  break;
		  }
		  else
		  {
			  memory[i] = a;
		  }
		  //cout << endl;
	  }
	  else
	  {
		  cout <<  i << "?  ";
		  cin >> a;
		  if (a == -99999)
		  {
			  memory[i] = 4301;
			  break;
		  }
		  else
		  {
			  memory[i] = a;
		  }
		  //cout << endl;
	  }
  }
  cout << "\n entering completed! \n\n";

  for (int i = 1; i <= 100; i++)
  {
	  instructionRegister = memory[instructionCounter];
	  instructionCounter++;
	  operationCode = instructionRegister / 100;
	  operand = abs(instructionRegister % 100);
	  cout << "operationCode = " << operationCode << "operand = " << operand << endl;
	  switch (operationCode)
	  {
	  case 10:
		  cout << "\n";
		  cin >> a;
		  memory[operand] = a;
		  break;
	  case 11:
		  cout << memory[operand] <<endl;
		  break;
	  case 20:
		  accumulator = memory[operand];
		  break;
	  case 21:
		  memory[operand] = accumulator;
		  break;
	  case 30:
		  accumulator += memory[operand];
		  break;
	  case 31:
		  accumulator -= memory[operand];
		  break;
	  case 32:
		  if (memory[operand] == 0)
		  {
			  code = 1;
			  break;
		  }
		  accumulator /= memory[operand];
		  break;
	  case 33:
		  accumulator *= memory[operand];
		  break;
	  case 40:
		  instructionCounter = memory[operand];
		  break;
	  case 41:
		  if (accumulator < 0)
		  {
			  instructionCounter = memory[operand];
		  }
		  break;
	  case 42:
		  if (accumulator == 0)
		  {
			  instructionCounter = memory[operand];
		  }
		  break;
	  case 43:
		  code1 = 1;
		  break;
	  default:
		  code = 1;
		  code1 = 1;
		  break;
	  }
	  if (code1 == 1)
	  {
		  break;
	  }
  }

   cout << "\nThe programm has performed with code "<< code;// "Hello World!\n";
   return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
