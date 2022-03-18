#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<string> FileReader(const string& fileName1,const string& fileName2)
{
    cout << fileName1 << endl << fileName2 << endl;
    vector <string> fileTexts;
    string countstr,filename1,filename2,line1,line2,falseLine;
    cout << "Enter your file name: ";
    // cin >> filename1;
    cout << endl << "Enter your instructor's file name: ";
    // cin >> filename2;
    cout << endl;
    ifstream file1,file2;
    int count = 1,trueVal=0,falseVal=0,lines = 0;
    file1.open(fileName1);
    file2.open(fileName2);
    if (file2.fail() || file1.fail()){
        cout << "One or two file can not openned at the moment." << endl;
        exit(1) ;
    }else{
        cout << "Both files opened successfully." <<endl;
    }
/* kelime kelime okuyor */
    while (!file1.eof() || !file2.eof()) {
        lines++;
        // alttaki ise cümle cümle alıyor.
        getline(file1,line1);
        getline(file2,line2);
        // alttaki kelime kelime alıyor inputu.
        //file1 >> line1;
        //file2 >> line2;
        countstr = to_string(count);
        falseLine = countstr +". line\n------------------------------\n"+ line1+"\n|- -|\n"+line2+"\n------------------------------\n\n";
        if (line1==line2) {
            cout << "true" << endl;
            trueVal++;
        }
        else{
            cout << falseLine << endl;
            fileTexts.push_back(falseLine);
            falseVal++;
        }count++;
        if (file1.eof() && !file2.eof()){
            cout << "The shortest file is " << filename1 << endl;
            break;
        }else if (!file1.eof() && file2.eof()){
            cout << "The shortest file is " << filename2 << endl;
            break;
        } else if (!file1.eof() && !file2.eof()){
            continue;
        } else{
            cout << "Both files have equal lines. " << endl;
            break;
        }

    }
    file1.close();
    file2.close();
    cout << endl << "%"<< (trueVal / (lines))*100 << " your code is true" << endl;
    return fileTexts;
}

void AnotherFunc(const string& fn1, const string& fn2,const string& df1){
    ofstream outputFile;
    string deneme,line1;
    vector<string> lists;
    cout << "If your files at another location you must give the file way too." << endl ;
    lists = FileReader(fn1,fn2);
    outputFile.open(df1);
    int size = lists.size();
    for (unsigned int i=0; i < size;i++)
    {
        deneme = lists[i];
        outputFile << deneme << endl;
    }
    outputFile.close();
    cout << endl << "Press any key and press enter: ";
    cin >> line1;
}

// Driver Code
int main()
{
    AnotherFunc(R"(D:\desktop\bbm104-As4-1.2\output1.txt)",R"(D:\desktop\bbm104-As4-1.2\outputIns1.txt)",R"(D:\desktop\bbm104-As4-1.2\diff1.txt)");
    AnotherFunc(R"(D:\desktop\bbm104-As4-1.2\output2.txt)",R"(D:\desktop\bbm104-As4-1.2\outputIns2.txt)",R"(D:\desktop\bbm104-As4-1.2\diff2.txt)");
    AnotherFunc(R"(D:\desktop\bbm104-As4-1.2\output3.txt)",R"(D:\desktop\bbm104-As4-1.2\outputIns3.txt)",R"(D:\desktop\bbm104-As4-1.2\diff3.txt)");
    AnotherFunc(R"(D:\desktop\bbm104-As4-1.2\output4.txt)",R"(D:\desktop\bbm104-As4-1.2\outputIns4.txt)",R"(D:\desktop\bbm104-As4-1.2\diff4.txt)");
    AnotherFunc(R"(D:\desktop\bbm104-As4-1.2\output5.txt)",R"(D:\desktop\bbm104-As4-1.2\outputIns5.txt)",R"(D:\desktop\bbm104-As4-1.2\diff5.txt)");
}
