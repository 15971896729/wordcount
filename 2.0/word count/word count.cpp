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
	printf("相关用法：\n");
	printf_s("word count.exe -c filename.txt //统计字符 \n");
	printf_s("word count.exe -w filename.txt //统计词数 \n");
	printf_s("word count.exe -l filename.txt //统计行数 \n");
	printf_s("word count.exe -m filename.txt //统计代码行、空行、注释行 \n");
	printf_s("Exit							 //退出程序 \n");
			while (1)
			{
				gets_s(input);
				int x = strlen(input);
				if (x > 18)
				{
					strncpy_s(path, input + 18, x - 18);
					//cout << path << endl;				//输出以对比路径，判断错误
					path[x - 17] = '\0';
					int i = 15;
					if ((input[i] == '-') && (input[i + 1] == 'c'))
					{
						CharCount(path);
						continue;
					}
					if ((input[i] == '-') && (input[i + 1] == 'w'))
					{
						WordCount(path);
						continue;
					}
					if ((input[i] == '-') && (input[i + 1] == 'l'))
					{
						LineCount(path);
						continue;
					}
					if ((input[i] == '-') && (input[i + 1] == 'm'))
					{
						Multiple(path);
						continue;
					}
					else
					{
						cout << "输入格式错误" << endl;
						continue;
					}
				}							//获取文件名及路径      “-”作为第一标识符，“c、w、l、m”对应相应功能
				else
				{
					break;					//当输入不足18位时，退出程序
				}
			} 
	system("pause");
	return 0;
}

void CharCount(char path[])
{
	FILE*fp = NULL;
	int c = 0,space=0;
	char C;
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
	C = fgetc(fp);
	while (C != EOF)
	{
		if (C ==' ')
		{
			space++;
		}
		c++;
		C = fgetc(fp);
	} 
	cout << "总字符为：" << c << endl;			//总字符包含空格、标点符号等
	cout << "总字数为：" << c - space<< endl;		//总字数不包括空格
	fclose(fp);
}

void WordCount(char path[])
{
	FILE*fp;
	int w = 0;
	char C;
	char*path2 = path;
	//cout << path2 << endl;					//添加以对比路径，判断错误
	int k = strlen(path);
	*(path2 + k) = '\0';
	errno_t err;
	if ((err = fopen_s(&fp, path2, "r")) != 0)
	{
		cout << "文件读取失败！" << endl;
		exit(0);								//读取失败则强行退出
	}
	C = fgetc(fp);
	while (C != EOF)
	{
		if ((C >= 'a'&&C <= 'z') || (C >= 'A'&&C <= 'Z') || (C >= '0'&&C <= '9'))
		{
			while ((C >= 'a'&&C <= 'z') || (C >= 'A'&&C <= 'Z') || (C >= '0'&&C <= '9'))
			{
				C = fgetc(fp);
			}
			w++;
			C = fgetc(fp);
		}
		else
		{
			C = fgetc(fp);
		}
	}										//遇到英文字母与数字便获取下一字符，直到为非英文、非数字，词数加1
	cout << "总英文词数为：" << w << endl;
	fclose(fp);
}

void LineCount(char path[])
{
	FILE*fp;
	int L = 1;
	char C;
	char*path3 = path;
	int k = strlen(path);
	*(path3 + k) = '\0';
	//cout << path3 << endl;					//添加以对比路径，判断错误
	errno_t err;
	if ((err = fopen_s(&fp, path3, "r")) != 0)
	{
		cout << "文件读取失败！" << endl;
		exit(0);									//读取失败则强行退出
	}
	C = fgetc(fp);
	while (C != EOF)
	{
		if (C == '\n')
		{
			L++;
			C = fgetc(fp);
		}
		else
		{
			C = fgetc(fp);
		}
	}
	cout << "行数为：" << L << endl;
	fclose(fp);
}

void Multiple(char path[])
{
	FILE*fp = NULL;
	char C;
	char*path4 = path;
	int k = strlen(path);
	*(path4 + k) = '\0';
	//cout << path4 << endl;					//添加以对比路径，判断错误
	int c = 0, e = 0, n = 0;
	errno_t err;
	if ((err = fopen_s(&fp, path4, "r")) != 0)
	{
		cout << "文件读取失败！" << endl;
		exit(0);									//读取失败则强行退出
	}
	C = fgetc(fp);
	while (C != EOF)
	{
		if (C == '{' || C == '}')
		{
			e++;
			C = fgetc(fp);
		}
		else if (C == '\n'||C==' ')
		{
			C = fgetc(fp);
			if (C==' ')
			{
				C = fgetc(fp);
			}
			while (C == '\n')
			{
				e++;
				C = fgetc(fp);
			}
		}
		else if (C == '/')
		{
			C = fgetc(fp);
			if (C == '/')
			{
				while (C != '\n')
				{
					C = fgetc(fp);
				}
			}
			n++;
		}
		else
		{
			c++;
			while (C != '{'&&C != '}'&&C != '\n'&&C != '/'&&C != EOF)
			{
				C = fgetc(fp);
			}
		}
	}
	cout << "代码行数为：" << c << endl;
	cout << "空行数为：" << e << endl;
	cout << "注释行数为：" << n << endl;
	fclose(fp);
}
