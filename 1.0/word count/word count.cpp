#include"stdafx.h"
#include <iostream>
#include"stdlib.h"
using namespace std;
void CharCount(char path[]);  //字符统计函数
void WordCount(char path[]);  //单词统计函数
void LineCount(char path[]);  //行数统计函数
void Multiple(char path[]);  //综合统计函数，包括代码行，空行，注释行
int main()
{
	char input[100], path[50];
	gets_s(input);
	int x = strlen(input);
	strncpy_s(path, input + 18, x - 18);
	//cout << path << endl;				//添加以对比路径，判断错误
	path[x - 17] = '\0';
		while (1)
		{
			{
				int i = 15;
				if ((input[i] == '-') && (input[i + 1] == 'c'))
				{
					CharCount(path);
					break;
				}
				if ((input[i] == '-') && (input[i + 1] == 'w'))
				{
					WordCount(path);
					break;
				}
				if ((input[i] == '-') && (input[i + 1] == 'l'))
				{
					LineCount(path);
					break;
				}
				if ((input[i] == '-') && (input[i + 1] == 'm'))
				{
					Multiple(path);
					break;
				}
				else
				{
					cout << "输入格式错误" << endl;
					break;
				}
			}							//获取文件名及路径      “-”作为第一标识符，“c、w、l、m”对应相应功能
		}
	system("pause");
	return 0;
}

void CharCount(char path[])
{
	FILE*fp = NULL;
	int c = 0,space=0;
	char ch;
	char *path1 = path;
	int k = strlen(path);
	*(path1 + k) = '\0';
	//cout << path1 << endl;			//添加以对比路径，判断错误
	errno_t err=0;
	if ((err= fopen_s(&fp,path1, "r")) !=0)
	{
		cout << "文件读取失败！" << endl;
		exit(0);						//读取失败则强行退出
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch ==' ')
		{
			space++;
		}
		c++;
		ch = fgetc(fp);
	} 
	cout << "总字符为：" << c << endl;			//总字符包含空格、标点符号等
	cout << "总字数为：" << c - space<< endl;		//总字数不包括空格
	fclose(fp);
}

void WordCount(char path[])
{
	FILE*fp;
	int w = 0;
	char ch;
	char*path2 = path;
	cout << path2 << endl;
	int k = strlen(path);
	*(path2 + k) = '\0';
	errno_t err;
	if ((err = fopen_s(&fp, path2, "r")) != 0)
	{
		cout << "文件读取失败！" << endl;
		exit(0);								//读取失败则强行退出
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
		{
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
			{
				ch = fgetc(fp);
			}
			w++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}										//遇到英文字母与数字便获取下一字符，直到为非英文、非数字，词数加1
	cout << "总英文词数为：" << w << endl;
	fclose(fp);
}

void LineCount(char path[])
{
	FILE*fp;
	int l = 1;
	char ch;
	char*path3 = path;
	int k = strlen(path);
	*(path3 + k) = '\0';
	cout << path3 << endl;
	errno_t err;
	if ((err = fopen_s(&fp, path3, "r")) != 0)
	{
		cout << "文件读取失败！" << endl;
		exit(0);									//读取失败则强行退出
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '\n')
		{
			l++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	cout << "行数为：" << l << endl;
	fclose(fp);
}

void Multiple(char path[])
{
	FILE*fp = NULL;
	char ch;
	char*path4 = path;
	int k = strlen(path);
	*(path4 + k) = '\0';
	cout << path4 << endl;
	int c = 0, e = 0, n = 0;
	errno_t err;
	if ((err = fopen_s(&fp, path4, "r")) != 0)
	{
		cout << "文件读取失败！" << endl;
		exit(0);									//读取失败则强行退出
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '{' || ch == '}')
		{
			e++;
			ch = fgetc(fp);
		}
		else if (ch == '\n'||ch==' ')
		{
			ch = fgetc(fp);
			if (ch==' ')
			{
				ch = fgetc(fp);
			}
			while (ch == '\n')
			{
				e++;
				ch = fgetc(fp);
			}
		}
		else if (ch == '/')
		{
			ch = fgetc(fp);
			if (ch == '/')
			{
				while (ch != '\n')
				{
					ch = fgetc(fp);
				}
			}
			n++;
		}
		else
		{
			c++;
			while (ch != '{'&&ch != '}'&&ch != '\n'&&ch != '/'&&ch != EOF)
			{
				ch = fgetc(fp);
			}
		}
	}
	cout << "代码行数为：" << c << endl;
	cout << "空行数为：" << e << endl;
	cout << "注释行数为：" << n << endl;
	fclose(fp);
}
