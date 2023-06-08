#include<iostream>
#include<fstream>
#include <cstdlib>
#include<windows.h>
#include<iomanip>
using namespace std;
const int rows = 9, columns = 9;
int arr3[35], arr4[35];
void CoutCentered()
{
	cout << setw(36);
}
void coutCentered()
{
	cout << setw(39);
}

void size2()
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 400;
	fontex.dwFontSize.X = 40;
	fontex.dwFontSize.Y = 40;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

}
void size()
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 400;
	fontex.dwFontSize.X = 28;
	fontex.dwFontSize.Y = 28;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

}
bool checkrows(int arr[][columns]);
bool checkcolumns(int arr[][columns]);
bool checksquare(int arr[][columns]);
bool checkrows1(int arr[][columns]);
bool checkcolumns1(int arr[][columns]);
bool checksquare1(int arr[][columns]);
void printsuduko(int arr[][columns]);
void getdata(int arr[][columns]);
void storepositions(int arr[][columns]);
bool checkprevious(int x, int y, int arr1[], int arr2[]);
int main()
{
	size();
	system("Color CF");
	string ch, ch1;
	int arr[rows][columns] = { 0 }, x, y, z, temp = 0;
	do
	{
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			cout << endl;
		}
		for (int i = 0; i < 5; i++)
		{
			cout << "\t";
		}
		cout << "1->New game\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "\t";
		}
		cout << "2->Saved game\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "\t";
		}
		cout << "Your choice : ";
		cin >> ch;
		Beep(323, 300);

		if (ch == "1")
		{
			system("Color F0");
			srand(time(0));
			for (int i = 0; i < 22; i++)
			{
				do
				{
					do {
						x = rand();
					} while (x < 0 || x > 8);


					do {
						y = rand();
					} while (y < 0 || y > 8);
				} while ((!checkprevious(x, y, arr3, arr4)));
				arr3[i] = x + 1, arr4[i] = y + 1;
				do {
					z = rand();
					arr[x][y] = z;
				} while (z < 1 || z>9 || (!checksquare(arr)) || !(checkrows(arr)) || (!checkcolumns(arr)));


			}

		}
		else if (ch == "2")
		{
			do {
				system("cls");
				for (int i = 0; i < 10; i++)
				{
					cout << endl;
				}
				for (int i = 0; i < 5; i++)
				{
					cout << "\t";
				}
				cout << "1->Saved game1\n";
				for (int i = 0; i < 5; i++)
				{
					cout << "\t";
				}
				cout << "2->Saved game2\n";
				for (int i = 0; i < 5; i++)
				{
					cout << "\t";
				}
				cout << "3->Saved game3\n";
				for (int i = 0; i < 5; i++)
				{
					cout << "\t";
				}
				cout << "Your choice : ";
				cin >> ch1;
				Beep(323, 300);

				if (ch1 == "1")
				{
					system("Color C0");
					ifstream fr;
					fr.open("f1.text");
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							fr >> arr[i][j];
						}

					}
					fr.close();
					for (int i = 0; i < rows; i++)
					{
						for (int j = 0; j < columns; j++)
						{
							if (arr[i][j] != 0)
								temp++;

						}

					}
					if (temp == 0)
					{
						system("cls");
						for (int i = 0; i < 10; i++)
						{
							cout << endl;
						}
						for (int i = 0; i < 5; i++)
						{
							cout << "\t";
						}
						cout << "No saved file found!!!\n";
						Sleep(1800);
						Beep(623, 600);
						ch = " - 1";
					}
					fr.close();
					fr.open("f1a.txt");
					for (int j = 0; j < 9; j++)
					{
						fr >> arr3[j];
					}
					fr.close();
					fr.open("f1b.txt");
					for (int j = 0; j < 9; j++)
					{
						fr >> arr4[j];
					}
					fr.close();
				}

				else if (ch1 == "2")
				{
					system("Color E2");
					ifstream fr;
					fr.open("f2.text");
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							fr >> arr[i][j];
						}

					}
					fr.close();
					for (int i = 0; i < rows; i++)
					{
						for (int j = 0; j < columns; j++)
						{
							if (arr[i][j] != 0)
								temp++;

						}

					}
					if (temp == 0)
					{
						system("cls");
						for (int i = 0; i < 10; i++)
						{
							cout << endl;
						}
						for (int i = 0; i < 5; i++)
						{
							cout << "\t";
						}
						cout << "No saved file found\n";
						Sleep(2000);
						Beep(623, 600);
						ch = " - 1";
					}
					fr.close();
					fr.open("f2a.txt");
					for (int j = 0; j < 9; j++)
					{
						fr >> arr3[j];
					}
					fr.close();
					fr.open("f2b.txt");
					for (int j = 0; j < 9; j++)
					{
						fr >> arr4[j];
					}
					fr.close();
				}

				else if (ch1 == "3")
				{
					system("Color 7D");
					ifstream fr;
					fr.open("f3.text");
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							fr >> arr[i][j];
						}

					}
					fr.close();
					for (int i = 0; i < rows; i++)
					{
						for (int j = 0; j < columns; j++)
						{
							if (arr[i][j] != 0)
								temp++;

						}

					}
					if (temp == 0)
					{
						system("cls");
						for (int i = 0; i < 10; i++)
						{
							cout << endl;
						}
						for (int i = 0; i < 5; i++)
						{
							cout << "\t";
						}

						cout << "No saved file found\n";
						Sleep(2000);
						Beep(623, 600);
						ch = " - 1";
					}
					fr.close();
					fr.open("f3a.txt");
					for (int j = 0; j < 9; j++)
					{
						fr >> arr3[j];
					}
					fr.close();
					fr.open("f3b.txt");
					for (int j = 0; j < 9; j++)
					{
						fr >> arr4[j];
					}
					fr.close();
				}

			} while (ch1 != "1" && ch1 != "2" && ch1 != "3");
		}
	} while (ch != "1" && ch != "2");
	system("cls");
	printsuduko(arr);
	getdata(arr);
}
bool checkrows(int arr[][columns])
{

	for (int k = 0; k < rows; k++)
	{
		for (int i = 0; i < columns; i++)
		{
			int temp = 0;
			for (int j = 0; j < columns; j++)
			{
				if (arr[k][i] == 0)
					break;
				if (arr[k][i] == arr[k][j])
					temp++;

			}
			if (temp != 1 && arr[k][i] != 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool checkcolumns(int arr[][columns])
{

	for (int k = 0; k < columns; k++)
	{
		for (int i = 0; i < rows; i++)
		{
			int temp = 0;
			for (int j = 0; j < rows; j++)
			{

				if (arr[i][k] == 0)
					break;
				if (arr[i][k] == arr[j][k])
					temp++;
			}
			if (temp != 1 && arr[i][k] != 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool checksquare(int arr[][columns])
{
	int temp;
	for (int x = 0; x < rows; x = x + 3)
	{
		for (int i = 0; i < columns; i = i + 3)
		{
			for (int j = x; j < x + 3; j++)
			{
				for (int l = i; l < i + 3; l++)
				{
					temp = 0;
					for (int k = x; k < x + 3; k++)
					{
						for (int m = i; m < i + 3; m++)
						{

							if (arr[j][l] == 0)
								break;
							if (arr[j][l] == arr[k][m])
								temp++;
						}
					}
					if (arr[j][l] == 0)
						continue;

					if (temp != 1)
					{
						return false;
					}
				}
			}

		}
	}
	return true;
}
bool checkrows1(int arr[][columns])
{
	int temp;
	for (int k = 0; k < rows; k++)
	{
		for (int i = 0; i < columns; i++)
		{
			temp = 0;
			for (int j = 0; j < columns; j++)
			{
				if (arr[k][i] == arr[k][j])
					temp++;
			}
			if (temp != 1)
			{
				return false;
			}

		}

	}
	return true;
}
bool checkcolumns1(int arr[][columns])
{

	for (int k = 0; k < columns; k++)
	{
		for (int i = 0; i < rows; i++)
		{
			int temp = 0;
			for (int j = 0; j < rows; j++)
			{
				if (arr[i][k] == arr[j][k])
					temp++;
			}
			if (temp != 1)
			{
				return false;
			}
		}
	}
	return true;
}
bool checksquare1(int arr[][columns])
{
	int temp;
	for (int x = 0; x < rows; x = x + 3)
	{
		for (int i = 0; i < columns; i = i + 3)
		{
			for (int j = x; j < x + 3; j++)
			{
				for (int l = i; l < i + 3; l++)
				{
					temp = 0;
					for (int k = x; k < x + 3; k++)
					{
						for (int m = i; m < i + 3; m++)
						{

							if (arr[j][l] == 0)
								break;
							if (arr[j][l] == arr[k][m])
								temp++;
						}
					}


					if (temp != 1)
					{
						return false;
					}
				}
			}

		}
	}
	return true;

}
void printsuduko(int arr[][columns])
{
	/*cout << "   ";*/
	coutCentered();
	for (int i = 0; i < 9; i++)
	{
		cout << " " << i + 1;
		if ((i + 1) % 3 == 0)
			cout << "  ";
	}
	/*cout << endl << "  ";*/
	cout << endl;
	coutCentered();
	for (int i = 0; i < 12; i++)
	{
		cout << " -";

	}
	cout << endl;

	for (int i = 0; i < 9; i++)
	{
		CoutCentered();
		cout << i + 1 << " ";
		cout << "| ";
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j] << " ";
			if ((j + 1) % 3 == 0)
			{
				cout << "| ";
			}
		}

		cout << endl;
		if ((i + 1) % 3 == 0)
		{
			/*cout << "  ";*/
			coutCentered();
			for (int i = 0; i < 12; i++)
				cout << " -";
			cout << endl;
		}

	}
}
void getdata(int arr[][columns])
{
	int x, y, z, temp1, t = 0, t1; string ch;
	do
	{

		do
		{


			cout << "\nEnter the row in which you want to enter: ";
			do
			{
				do {

					cin >> x;
					Beep(332, 300);
					if (cin.fail())
					{
						Beep(623, 600);
						cin.clear();
						cin.ignore(1000, '\n');

						cout << "Invalid input. Enter agin" << endl;
					}
				} while (cin.fail());
				if (x < 1 || x>9)
				{
					system("cls");
					printsuduko(arr);
					Beep(623, 600);
					cout << "\nInvalid input for rows\nEnter again: ";
				}
			} while (x < 1 || x>9);
			cout << "\nEnter the column in which you want to enter: ";

			do
			{

				do {

					cin >> y;
					Beep(332, 300);
					if (cin.fail())
					{
						Beep(623, 600);
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Invalid input. Enter agin" << endl;
					}
				} while (cin.fail());


				if (y < 1 || y>9)
				{
					system("cls");
					printsuduko(arr);
					cout << "You have entered " << x << " for rows\n";
					Beep(623, 600);
					cout << "\nInvalid input for columns \nEnter again: ";
				}
			} while (y < 1 || y>9);
			if ((!checkprevious(x, y, arr3, arr4)))
			{
				system("cls");
				printsuduko(arr);
				Beep(623, 600);
				cout << "\nCannot input in row " << x << " and column " << y;
			}

		} while ((!checkprevious(x, y, arr3, arr4)));
		cout << "\nEnter the number from 1 to 9 for input: ";

		do {

			cin >> t;
			Beep(332, 300);
			if (cin.fail())
			{
				Beep(623, 600);
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input. Enter agin" << endl;
			}
		} while (cin.fail());

		t1 = arr[x - 1][y - 1];
		arr[x - 1][y - 1] = t;
		do
		{
			arr[x - 1][y - 1] = t;
			if (t < 1 || t>9)
				do {
					system("cls");
					printsuduko(arr);
					cout << "You have entered " << x << " for rows and " << y << " for columns\n";
					Beep(623, 600);
					cout << "\nInvalid input\nEnter again: ";
					do {

						cin >> t;
						Beep(332, 300);
						if (cin.fail())
						{
							Beep(623, 600);
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Invalid input. Enter agin" << endl;
						}
					} while (cin.fail());


				} while (t < 1 || t>9);


				if (!checkrows(arr))
				{
					do
					{

						system("cls");
						printsuduko(arr);
						cout << "You have entered " << x << " for rows and " << y << " for columns\n";
						Beep(623, 600);
						cout << "\nInput Number already exists in rows\nEnter again or enter -1 to change the rows or columns: ";
						do {

							cin >> t;
							Beep(332, 300);
							if (cin.fail())
							{
								Beep(623, 600);
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Invalid input. Enter agin" << endl;
							}
						} while (cin.fail());

						if (t == -1)
						{

							break;
						}
						arr[x - 1][y - 1] = t;
						if (checkrows(arr))
							z = t;
					} while (!checkrows(arr));
				}

				if (t != -1)
				{
					if (!checkcolumns(arr))
					{
						do {

							system("cls");
							printsuduko(arr);
							cout << "You have entered " << x << " for rows and " << y << " for columns\n";
							Beep(623, 600);
							cout << "\nInput Number already exists in columns\nEnter again or enter -1 to change the rows or columns: ";

							do {

								cin >> t;
								Beep(332, 300);
								if (cin.fail())
								{
									Beep(623, 600);
									cin.clear();
									cin.ignore(1000, '\n');
									cout << "Invalid input. Enter agin" << endl;
								}
							} while (cin.fail());

							if (t == -1)
							{

								break;
							}
							arr[x - 1][y - 1] = t;
							if (checkcolumns(arr))
							{
								z = t;
							}
						} while (!checkcolumns(arr));
					}
				}


				if (t != -1)
				{
					if (!checksquare(arr))
					{
						do
						{

							system("cls");
							printsuduko(arr);
							cout << "You have entered " << x << " for rows and " << y << " for columns\n";
							Beep(623, 600);
							cout << "\nInput Number already exists in 3x3 square\nEnter again or enter -1 to change the rows or columns: ";

							do {

								cin >> t;
								Beep(332, 300);
								if (cin.fail())
								{
									Beep(623, 600);
									cin.clear();
									cin.ignore(1000, '\n');
									cout << "Invalid input. Enter agin" << endl;
								}
							} while (cin.fail());

							if (t == -1)
							{

								break;
							}
							arr[x - 1][y - 1] = t;
							if (checksquare(arr))
							{
								z = t;
							}
						} while (!checksquare(arr));
					}
				}

				if (t == -1)
				{

					arr[x - 1][y - 1] = t1;

					system("cls");

					printsuduko(arr);
					do
					{

						cout << "\nEnter the row in which you want to enter: ";
						do
						{
							do {

								cin >> x;
								Beep(332, 300);
								if (cin.fail())
								{
									Beep(623, 600);
									cin.clear();
									cin.ignore(1000, '\n');
									cout << "Invalid input. Enter agin" << endl;
								}
							} while (cin.fail());


							if (x < 1 || x>9)
							{
								system("cls");
								printsuduko(arr);
								Beep(623, 600);
								cout << "\nInvalid input for rows\nEnter again: ";
							}
						} while (x < 1 || x>9);
						cout << "\nEnter the column in which you want to enter: ";

						do
						{
							do {

								cin >> y;
								Beep(332, 300);
								if (cin.fail())
								{
									Beep(623, 600);
									cin.clear();
									cin.ignore(1000, '\n');
									cout << "Invalid input. Enter agin" << endl;
								}
							} while (cin.fail());

							if (y < 1 || y>9)
							{
								system("cls");
								printsuduko(arr);
								cout << "You have entered " << x << " for rows\n";
								Beep(623, 600);
								cout << "\nInvalid input for columns \nEnter again: ";
							}
						} while (y < 1 || y>9);
						if ((!checkprevious(x, y, arr3, arr4)))
						{
							system("cls");
							printsuduko(arr);
							cout << "\nCannot input in row " << x << " and column " << y;
						}

					} while ((!checkprevious(x, y, arr3, arr4)));

					do
					{
						cout << "\nEnter the number from 1 to 9 for input: ";

						do {

							cin >> t;
							Beep(332, 300);
							if (cin.fail())
							{
								Beep(623, 600);

								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Invalid input. Enter agin" << endl;
							}
						} while (cin.fail());

						if (t < 1 || t>9)

						{
							Beep(623, 600);
							cout << "\nInvalid input\nEnter again: ";
							cin >> t;
						}
						arr[x - 1][y - 1] = t;
					} while (t < 1 || t>9);
					arr[x - 1][y - 1] = t;
				}
				if ((checksquare(arr)) && (checkrows(arr)) && (checkcolumns(arr)))
				{
					z = t;
					arr[x - 1][y - 1] = z;
				}
		} while (t < 1 || t>9 || (!checksquare(arr)) || !(checkrows(arr)) || (!checkcolumns(arr)));
		system("cls");
		printsuduko(arr);
		temp1 = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (arr[i][j] == 0)
					temp1++;
			}
		}
		if ((checksquare1(arr)) || (checkrows1(arr)) || (checkcolumns1(arr)) || (temp1 == 0))
		{
			continue;
		}
		else
		{
			cout << "\nEnter -1 to save game or press any key to continue: ";
			cin >> ch;
			Beep(332, 300);
			if (ch == "-1")
				break;
		}

	} while ((!checksquare1(arr)) || (!checkrows1(arr)) || (!checkcolumns1(arr)) || (temp1 != 0));
	if (ch == "-1")
	{
		cout << "\nEnter your choice to save:\n1->Saved game1\n2->Saved game2\n3->Saved game3\n\Your choice: ";
		cin >> ch;
		Beep(323, 300);
		ofstream fw;
		if (ch == "1")
		{
			fw.open("f1.text");
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					fw << arr[i][j] << " ";
				}
				fw << endl;
			}
			fw.close();
			fw.open("f1a.txt");
			for (int j = 0; j < 9; j++)
			{
				fw << arr3[j] << " ";
			}
			fw.close();
			fw.open("f1b.txt");
			for (int j = 0; j < 9; j++)
			{
				fw << arr4[j] << " ";
			}
			fw.close();

		}
		else if (ch == "2")
		{
			fw.open("f2.text");
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					fw << arr[i][j] << " ";
				}
				fw << endl;
			}
			fw.close();
			fw.open("f2a.txt");
			for (int j = 0; j < 9; j++)
			{
				fw << arr3[j] << " ";
			}
			fw.close();
			fw.open("f2b.txt");
			for (int j = 0; j < 9; j++)
			{
				fw << arr4[j] << " ";
			}
			fw.close();

		}
		else if (ch == "3")
		{
			fw.open("f3.text");
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					fw << arr[i][j] << " ";
				}
				fw << endl;
			}
			fw.open("f3a.txt");
			for (int j = 0; j < 9; j++)
			{
				fw << arr3[j] << " ";
			}
			fw.close();
			fw.open("f3b.txt");
			for (int j = 0; j < 9; j++)
			{
				fw << arr4[j] << " ";
			}
			fw.close();

		}

		fw.close();
	}
	else
	{
		system("cls");
		for (int i = 0; i < 8; i++)
			cout << endl;
		size2();
		CoutCentered();
		system("Color 1F");
		Beep(623, 600);
		Beep(623, 600);
		Beep(623, 600);

		cout << "\t         Congratulations. You won!!";
		Sleep(20000);
		Beep(623, 600);

	}
}
bool checkprevious(int x, int y, int arr1[], int arr2[])
{
	for (int i = 0; i < 35; i++)
	{
		if (arr1[i] == x)
		{
			if (arr2[i] == y)
			{
				return false;
			}
		}
	}
	return true;
}
void storepositions(int arr[][columns])
{
	int a = 0, b = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (arr[i][j] != 0)
			{
				arr3[a] = i + 1, arr4[b] = j + 1;
				a++;
				b++;
			}
		}
	}
}
