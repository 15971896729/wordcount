
a.项目简介及其相关用法 

本项目名为“word count”，是一个命令行文本计数统计程序，能正确统计导入的txt文本中的字符数、单词数、代码行、空行、注释行数。

以下为快捷测试代码,test.txt已经放在了word count.exe同层文件夹：

word count.exe -c test.txt //统计字符

word count.exe -w test.txt //统计词数

word count.exe -l test.txt //统计行数

word count.exe -m test.txt //统计代码行、空行、注释行


b.文件列表及其相关说明

本项目文件包含3个版本：
版本0.0：
		空项目
版本1.0：
		程序初级版本，可完成基本功能
版本2.0：
			版本2.0为1.0的修改版，在1.0基础上升级了以下内容：
			(1)多组输入，运行一次可查询文件的各项指标；
			(2)增加了运行提示；
			(3)修改了程序崩溃的bug；

<<<<<<< HEAD
			版本1.0和2.0中包含:
					源文件;
					程序文件（在debug文件夹）;
					运行结果（截图保存在result文件夹）;
					性能测试结果截图及报告（在performance test文件夹）;
			版本2.0中:
					“Wctest1”文件夹为未完成的单元测试文件
					
=======
			版本中包含源文件、程序文件（在debug文件夹）、运行结果（截图保存在result文件夹）、性能测试结果截图及报告（在performance test文件夹）
>>>>>>> parent of 439bd04... Revert "Revert "3.1""

c.例程运行及其相关结果
	各版本运行不同，详见各版本及其result文件夹