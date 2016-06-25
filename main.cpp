#include<iostream>  
#include<io.h>
#include<Windows.h>
#include<string>
#include<stdio.h>
#include<direct.h>


using namespace std;

int main()
{

	char pBuf[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, pBuf);
	cout << "now you are in :"<<pBuf<<endl;



	cout << "************************************************************" << endl;
	cout << "*                                                          *"<<endl;
	cout << "*       creat by mark! used to produce .pri for QT         *"<<endl;
	cout << "*                                                          *" << endl;
	cout << "************************************************************" << endl;
	cout << endl << endl;
	_finddata_t file;
	long numOfFiles[4] = {0};
	//输入文件夹路径  
	cout << "please input the INCLUDEPATH ,like \"Library/cml\"" << endl;

	string path=pBuf,incpath,filepath[4];                         //path_cpp,path_h,path_dll,path_lib;
	cin >> incpath;
	
	filepath[0] = path + "\\*.cpp";
	filepath[1] = path + "\\*.h";
	filepath[2] = path + "\\*.lib";
	filepath[3] = path + "\\*.dll";
	for (int i = 0; i < 4; i++)
	{
		cout << endl;
		cout << "******************************************************************" << endl;
		cout << "*                                                                *" << endl;
		cout << "*                                                                *" << endl;
		switch (i)
		{
		case 0:
			cout << " cpp files:" << endl;
			cout << endl;
			cout << "INCLUDEPATH += "<<incpath<<endl;
			cout << endl;
			cout << "SOURCES += \\" << endl;
			break;

		case 1:
			cout << " h files:" << endl; 
			cout << endl;
			cout << "INCLUDEPATH += " << incpath << endl;
			cout << endl;
			cout << "HEADERS += \\" << endl;
			break;
		case 2:
			cout << " lib files:" << endl; break;
		case 3:
			cout << " dll files:" << endl; break;
		default:
			break;
		}
		//cout << "******************************************************************" << endl;
		cout << endl;

		long lf;
		if ((lf = _findfirst(filepath[i].c_str(), &file)) == -1)
		{
			cout << "Not Found!" << endl;
		}

			
		else
		{
			//输出文件名  


			do			
			{
				numOfFiles[i]++;
				cout << "	"<<incpath<<'/'<<file.name <<" \\"<< endl;

			} while (_findnext(lf, &file) == 0);
			
		}
		_findclose(lf);

			cout << endl;
			//cout << "******************************************************************" << endl;
			switch (i)
			{ 
			case 0:
				cout << "num of cpp files:" << numOfFiles[i] << endl; break;
			case 1:
				cout << "num of h files:" << numOfFiles[i] << endl; break;
			case 2:
				cout << "num of lib files:" << numOfFiles[i] << endl; break;
			case 3:
				cout << "num of dll files:" << numOfFiles[i] << endl; break;
			default:
				break;
			}
			cout << "*                                                                *" << endl;
			cout << "*                                                                *" << endl;
			cout << "******************************************************************" << endl;
			cout << endl;

		
		
	}
	cout << numOfFiles[0] + numOfFiles[1] + numOfFiles[2] + numOfFiles[3] << "files at all!" << endl;





	system("pause");
	return 0;


}
