#include"Blockchain.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)

using namespace std;
using namespace std::chrono;

Student_info sv;
vector <Block> Chain;
vector <string> hashChain;
vector <string> codeChain;
string getName;
string getCode;

string createRandomString(int n)
{
   const char alphanum[] = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   int stringLength = sizeof(alphanum) - 1;
   string Str = "";
   for (unsigned int i = 0; i < n; ++i)
   {
       Str += alphanum[rand() % stringLength];
   }
   return Str;
}

Student_info getInfor()
{
    Student_info student;

    string Code = createRandomString(50);
    student.code = Code;
    codeChain.push_back(Code);

    string Name = createRandomString(50);
    student.name = Name;

    string Subject = createRandomString(50);
    student.subject = Subject;

    double Score = rand() % 10;
    student.score = Score;
    return student;
}

Student_info getInforOld()
{
    Student_info student;

    string Code = "20110190";
    student.code = Code;
    codeChain.push_back(Code);

    string Name = "Vo Nguyen Minh Thu";
    student.name = Name;

    string Subject = createRandomString(50);
    student.subject = Subject;

    double Score = rand() % 10;
    student.score = Score;
    return student;
}

#pragma region Time Complexity Of SHA256
void TimeComplexitySHA256(int n)
{
    const char* name = "TimeComplexitySHA256.txt";
    ofstream output;
    output.open(name, ios::out);
    srand(time(0));
    for (int i = 50; i <= n; i += 50)
    {
        int Max = NULL;
        int Min = NULL;
        int Sum = 0;
        for (int j = 0; j < 1000; j++)
        {
            string kq = createRandomString(i);
            auto start = high_resolution_clock::now();
            string output = sha256(kq);
            //cout << output << endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            if (Min == NULL)
            {
                Min = duration.count();
            }
            else if (Min > duration.count())
            {
                Min = duration.count();
            }
            if (Max == NULL)
            {
                Max = duration.count();
            }
            else if (Max < duration.count())
            {
                Max = duration.count();
            }
            Sum += duration.count();
        }
        int Mean = Sum / 1000;
        output << i << "        " << Min << "       " << Mean << "      " << Max << endl;
        std::cout << "n: " << i << endl;
        std::cout << "Min: " << Min << endl;
        std::cout << "Mean: " << Mean << endl;
        std::cout << "Max: " << Max << endl;
        std::cout << "-----------------------------" << endl;
    }
    output.close();
}
#pragma endregion 


#pragma region Time Complexity Of Mine()
string difficult(int level)
{
    string dif = string(level, '0');
    return dif;
}

string generateHash(string message, int &Nonce)
{
    string finalHash;
    finalHash = sha256(message + to_string(Nonce));
    return finalHash;
}

string mine(string message, int n)
{
    int nonce = 0;
    while (message.find(difficult(n), 0) != 0)
    {
        nonce++;
        message = generateHash(message, nonce);
    }
    return message;
}

// Cho difficult cố định bằng 4
// input n là số lượng ký tự của message
void TimeComplexityMine1(int n)
{
    const char* name = "TimeComplexityMine1.txt";
    ofstream output;
    output.open(name, ios::out);
    srand(time(0));
    for (int i = 50; i <= n; i+=50)
    {
        int Max = NULL;
        int Min = NULL;
        int Sum = 0;
        for (int j = 0; j < 100; j++)
        {
            string message = createRandomString(i);
            auto start = high_resolution_clock::now();
            string kq = mine(message, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            if (Min == NULL)
            {
                Min = duration.count();
            }
            else if (Min > duration.count())
            {
                Min = duration.count();
            }
            if (Max == NULL)
            {
                Max = duration.count();
            }
            else if (Max < duration.count())
            {
                Max = duration.count();
            }
            Sum += duration.count();
        }
        int Mean = Sum / 100;
        output << i << "        " << Min << "       " << Mean << "      " << Max << endl;
        std::cout << "So luong ky tu: " << i << endl;
        std::cout << "Min: " << Min << endl;
        std::cout << "Mean: " << Mean << endl;
        std::cout << "Max: " << Max << endl;
        std::cout << "-----------------------------" << endl;
    }
    output.close();
}


// input n là độ khó của thuật toán
// message là một chuỗi ngẫu nhiên
void TimeComplexityMine2(int n)
{
    const char* name = "TimeComplexityMine2.txt";
    ofstream output;
    output.open(name, ios::out);
    srand(time(0));
    for (int i = 1; i <= n; i++)
    {
        int Max = NULL;
        int Min = NULL;
        int Sum = 0;
        for (int j = 0; j < 10; j++)
        {
            int sizeStr = rand();
            string message = createRandomString(sizeStr);
            auto start = high_resolution_clock::now();
            string kq = mine(message, i);
            //cout << kq << endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            if (Min == NULL)
            {
                Min = duration.count();
            }
            else if (Min > duration.count())
            {
                Min = duration.count();
            }
            if (Max == NULL)
            {
                Max = duration.count();
            }
            else if (Max < duration.count())
            {
                Max = duration.count();
            }
            Sum += duration.count();
        }
        int Mean = Sum / 10;
        output << i << "        " << Min << "       " << Mean << "      " << Max << endl;
        std::cout << "Do kho: " << i << endl;
        std::cout << "Min: " << Min << endl;
        std::cout << "Mean: " << Mean << endl;
        std::cout << "Max: " << Max << endl;
        std::cout << "-----------------------------" << endl;
    }
    output.close();
}
#pragma endregion


#pragma region Time Complexity Of INSERTNEWSTUDENT
int insertNewStudent(const char* s1, const char* s2, const char* s3, const char* s4, Student_info student)
{
    const char* s[4] = { s1, s2, s3, s4 };
    sqlite3* DB;
    char* messageError;
    blockChain bc(student);

    string sql("INSERT INTO SinhVien (\"Code\", \"Name\") VALUES('" + student.code + "', '" + student.name + "'); "
        "INSERT INTO Diem (\"Index\", \"Code\", \"Subject\", \"Score\", \"Hash\", \"PreHash\") VALUES( 0, '" + student.code + "', '" + student.subject + "', '" + to_string(student.score) + "', '" + bc.hash + "', '0'); ");
    int i;
    for (i = 0; i < 4; i++)
    {
        int exit = sqlite3_open(s[i], &DB);

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            cerr << "Da xay ra loi khi them thong tin sinh vien!" << endl;
            sqlite3_free(messageError);
            return 0;
        }
    }
    return 1;
}


void TimeComplexityINSERTNEWSTUDENT()
{
    const char* dir1 = R"(.\DataBase\QuanLyDiemSinhVien_PHONGDAOTAO.db)";
    const char* dir2 = R"(.\DataBase\QuanLyDiemSinhVien_GIANGVIEN.db)";
    const char* dir3 = R"(.\DataBase\QuanLyDiemSinhVien_TRUONGKHOA.db)";
    const char* dir4 = R"(.\DataBase\QuanLyDiemSinhVien_BOPHANXULYDIEM.db)";
    const char* name = "TimeComplexityINSERTNEWSTUDENT.txt";
    ofstream output;
    output.open(name, ios::out);
    srand(time(0));
    int Max = NULL;
    int Min = NULL;
    int Sum = 0;
    for (int j = 0; j < 100; j++)
    {
        Student_info sv = getInfor();
        auto start = high_resolution_clock::now();
        insertNewStudent(dir1, dir2, dir3, dir4, sv);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if (Min == NULL)
        {
            Min = duration.count();
        }
        else if (Min > duration.count())
        {
            Min = duration.count();
        }
        if (Max == NULL)
        {
            Max = duration.count();
        }
        else if (Max < duration.count())
        {
            Max = duration.count();
        }
            Sum += duration.count();
    }
        int Mean = Sum / 100;
        output << Min << "       " << Mean << "      " << Max << endl;
        std::cout << "Min: " << Min << endl;
        std::cout << "Mean: " << Mean << endl;
        std::cout << "Max: " << Max << endl;
        std::cout << "-----------------------------" << endl;
        output.close();
}
#pragma endregion

#pragma region Time Complexity Of INSERTOLDSTUDENT
string getHash;
int getIndex;
int nonce;

string generateHash(Student_info student)
{
    string finalHash;
    finalHash = sha256(student.code + student.name + student.subject + to_string(student.score) + getHash + to_string(nonce));
    return finalHash;
}

string mine(Student_info student, string blockHash)
{
    nonce = 0;
    while (blockHash.find(difficult(4), 0) != 0)
    {
        nonce++;
        blockHash = generateHash(student);
    }
    return blockHash;
}

int insertOldStudent(const char* s1, const char* s2, const char* s3, const char* s4, Student_info student)
{
    const char* s[4] = { s1, s2, s3, s4 };
    sqlite3* DB;
    char* messageError;
    string hashTemp, finalHash;
    hashTemp = generateHash(student);
    finalHash = mine(student, hashTemp);
    string sql = "INSERT INTO Diem (\"Index\", \"Code\", \"Subject\", \"Score\", \"Hash\", \"PreHash\") VALUES( " + to_string(getIndex) + ", '" + student.code + "', '" + student.subject + "', '" + to_string(student.score) + "', '" + finalHash + "', '" + getHash + "'); ";
    int i;
    for (i = 0; i < 4; i++)
    {

        int exit = sqlite3_open(s[i], &DB);
        exit = sqlite3_exec(DB, sql.c_str(), NULL, NULL, &messageError);

        if (exit != SQLITE_OK) {
            cerr << "Da xay ra loi khi them diem!" << endl;
            sqlite3_free(messageError);
            return 0;
        }
    }
    return 1;
}

int selectInfor(const char* s, Student_info student)
{
    sv.code = "";
    sqlite3* DB;
    char* messageError;
    string sql = "SELECT * FROM Diem WHERE Code = '" + student.code + "' ORDER BY ID DESC LIMIT 1; ";

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callInfor, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Da xay ra loi khi kiem tra ma so sinh vien!" << endl;
        sqlite3_free(messageError);
    }
    return 0;
}

int callInfor(void* data, int argc, char** argv, char** azColName)
{
    char* numstr = argv[1];
    getIndex = atoi(numstr);
    getIndex++;
    getHash = argv[5];
    return 0;
}

void TimeComplexityINSERTOLDSTUDENT()
{
    const char* dir1 = R"(.\DataBase\QuanLyDiemSinhVien_PHONGDAOTAO.db)";
    const char* dir2 = R"(.\DataBase\QuanLyDiemSinhVien_GIANGVIEN.db)";
    const char* dir3 = R"(.\DataBase\QuanLyDiemSinhVien_TRUONGKHOA.db)";
    const char* dir4 = R"(.\DataBase\QuanLyDiemSinhVien_BOPHANXULYDIEM.db)";
    const char* name = "TimeComplexityINSERTOLDSTUDENT.txt";
    ofstream output;
    output.open(name, ios::out);
    srand(time(0));
    int Max = NULL;
    int Min = NULL;
    int Sum = 0;
    for (int j = 0; j < 1; j++)
    {
        Student_info old = getInforOld();
        auto start = high_resolution_clock::now();
        selectInfor(dir1, old);
        insertOldStudent(dir1, dir2, dir3, dir4, old);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if (Min == NULL)
        {
            Min = duration.count();
        }
        else if (Min > duration.count())
        {
            Min = duration.count();
        }
        if (Max == NULL)
        {
            Max = duration.count();
        }
        else if (Max < duration.count())
        {
            Max = duration.count();
        }
        Sum += duration.count();
    }
    int Mean = Sum / 1;
    output << Min << "       " << Mean << "      " << Max << endl;
    std::cout << "Min: " << Min << endl;
    std::cout << "Mean: " << Mean << endl;
    std::cout << "Max: " << Max << endl;
    std::cout << "-----------------------------" << endl;
    output.close();
}
#pragma endregion

#pragma region Time Complexity Of Check Blockchain Valid
int getGenesisFromDataBase(const char* s, Student_info student)
{
    sv.code = "";
    sqlite3* DB;
    char* messageError;

    string sql = "SELECT * FROM SinhVien WHERE Code = '" + student.code + "'";

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callGenesis, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Da xay ra loi khi in thong tin sinh vien!" << endl;
        sqlite3_free(messageError);
    }
    else
    {
        if (sv.code == "")
        {
            cout << "Sinh vien chua co thong tin" << endl;
        }
    }
    return 0;
}

int callGenesis(void* NotUsed, int argc, char** argv, char** azColName)
{
    sv.code = argv[1];
    getCode = argv[1];
    getName = argv[2];
    return 0;
}

int getBlockchainFromDataBase(const char* s, Student_info student)
{
    sv.code = "";
    sqlite3* DB;
    char* messageError;

    string sql = "SELECT * FROM Diem WHERE Code = '" + student.code + "'";

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callBlockChain, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Da xay ra loi khi in thong tin sinh vien!" << endl;
        sqlite3_free(messageError);
    }
    else
    {
        if (sv.code == "")
        {
            cout << "Sinh vien chua co thong tin" << endl;
        }
    }
    return 0;
}

int callBlockChain(void* NotUsed, int argc, char** argv, char** azColName)
{
    sv.code = argv[2];
    Student_info data;
    data.name = getName;
    data.code = getCode;
    data.subject = argv[3];
    data.score = stod(argv[4]);

    int index = stod(argv[1]);
    string Hash = argv[5];
    string PrevHash = argv[6];
    Block newBlock(index, data, PrevHash);

    Chain.push_back(newBlock);
    hashChain.push_back(Hash);
    return 0;
}

void isBlockChainValid(const char* s, Student_info student)
{
    getGenesisFromDataBase(s, student);
    getBlockchainFromDataBase(s, student);
    int size = Chain.size() == hashChain.size() ? Chain.size() : -1;
    if (size != -1)
    {
        for (int i = 0; i < size; i++)
        {
            if (hashChain[i] != Chain[i].getHash())
            {
                cout << "BlockChain khong bao toan!" << endl;
                Chain.clear();
                hashChain.clear();
                return;
            }
            if (i != 0)
            {
                Block previousBlock = Chain[i - 1];
                if (previousBlock.getHash() != Chain[i].getPreviousHash())
                {
                    cout << "BlockChain khong bao toan!" << endl;
                    Chain.clear();
                    hashChain.clear();
                    return;
                }
            }
        }
        cout << "BlockChain bao toan!" << endl;
    }
    Chain.clear();
    hashChain.clear();
}


void TimeComplexityIsBlockChainValid()
{
    const char* dir1 = R"(.\DataBase\QuanLyDiemSinhVien_PHONGDAOTAO.db)";
    const char* name = "TimeComplexityIsBlockChainValid.txt";
    ofstream output;
    output.open(name, ios::out);
    srand(time(0));
    int Max = NULL;
    int Min = NULL;
    int Sum = 0;
    for (int j = 0; j < 100; j++)
    {
        int n = rand() % 100;
        Student_info sv;
        sv.code = codeChain[n];
        auto start = high_resolution_clock::now();
        isBlockChainValid(dir1, sv);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if (Min == NULL)
        {
            Min = duration.count();
        }
        else if (Min > duration.count())
        {
            Min = duration.count();
        }
        if (Max == NULL)
        {
            Max = duration.count();
        }
        else if (Max < duration.count())
        {
            Max = duration.count();
        }
        Sum += duration.count();
    }
    int Mean = Sum / 100;
    output << Min << "       " << Mean << "      " << Max << endl;
    std::cout << "Min: " << Min << endl;
    std::cout << "Mean: " << Mean << endl;
    std::cout << "Max: " << Max << endl;
    std::cout << "-----------------------------" << endl;
    output.close();
}
#pragma endregion


#pragma region Time Complexity Of Compare 2 File Txt


bool compareFile(const char* fname1, const char* fname2)
{
    FILE* fp1, * fp2;
    int ch1, ch2;
    fp1 = fopen(fname1, "r");
    fp2 = fopen(fname2, "r");
    if (fp1 == NULL)
    {
        printf("Khong the mo file %s.", fname1);
        exit(1);
    }
    else if (fp2 == NULL)
    {
        printf("Khong the mo file %s.", fname2);
        exit(1);
    }
    else
    {
        ch1 = getc(fp1);
        ch2 = getc(fp2);
        while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
            ch1 = getc(fp1);
            ch2 = getc(fp2);
        }
        if (ch1 == ch2)
        {
            return 1;
        }
        else if (ch1 != ch2)
        {
            return 0;
        }
    }
    return 0;
}

void TimeComplexityCompareFile(int n)
{
    const char* name = "TimeComplexityCompareFile.txt";
    ofstream output;
    output.open(name, ios::out);
    fstream file1;
    fstream file2;
    srand(time(0));
    for (int i = 50; i <= n; i += 50)
    {
        int Max = NULL;
        int Min = NULL;
        int Sum = 0;
        for (int j = 0; j < 10; j++)
        {
            file1.open("file1.txt", ios::out);
            file2.open("file2.txt", ios::out);
            string message = createRandomString(i);
            cout << message << endl;
            file1 << message;
            file2 << message;
            auto start = high_resolution_clock::now();
            compareFile("file1.txt", "file2.txt");
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            if (Min == NULL)
            {
                Min = duration.count();
            }
            else if (Min > duration.count())
            {
                Min = duration.count();
            }
            if (Max == NULL)
            {
                Max = duration.count();
            }
            else if (Max < duration.count())
            {
                Max = duration.count();
            }
            Sum += duration.count();
            file1.close();
            file2.close();
        }
        int Mean = Sum / 10;
        output << i << "        " << Min << "       " << Mean << "      " << Max << endl;
        std::cout << "So luong ky tu: " << i << endl;
        std::cout << "Min: " << Min << endl;
        std::cout << "Mean: " << Mean << endl;
        std::cout << "Max: " << Max << endl;
        std::cout << "-----------------------------" << endl;
    }
    output.close();
}
#pragma endregion


#pragma region Time Complexity Of Check Security (4 Database)
void file2compare1(const char* s1)
{
    const char* name = "GiangVien.txt";
    ofstream output;
    output.open(name, ios::out);
    output.close();
    sqlite3* DB;
    char* messageError;
    string sql("SELECT * FROM SinhVien;" "SELECT * FROM Diem;");
    int exit = sqlite3_open(s1, &DB);
    exit = sqlite3_exec(DB, sql.c_str(), call2compare1, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Da xay ra loi khi xuat file du lieu!" << endl;
        sqlite3_free(messageError);
    }
}

int call2compare1(void* NotUsed, int argc, char** argv, char** azColName)
{
    const char* name = "GiangVien.txt";
    ofstream output;
    output.open(name, ios::app);
    if (output.is_open())
    {
        int i;
        for (i = 1; i < argc; i++)
        {
            string colName = azColName[i];
            string Argv = argv[i] ? argv[i] : "NULL";
            output << colName + ": " + Argv << endl;
        }
        output << endl;
        output.close();
    }
    else
        cout << "\nMo file " << name << " that bai" << endl;
    return 0;
}

void file2compare2(const char* s2)
{
    const char* name = "PhongDaoTao.txt";
    ofstream output;
    output.open(name, ios::out);
    output.close();
    sqlite3* DB;
    char* messageError;
    string sql("SELECT * FROM SinhVien;" "SELECT * FROM Diem;");
    int exit = sqlite3_open(s2, &DB);
    exit = sqlite3_exec(DB, sql.c_str(), call2compare2, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Da xay ra loi khi xuat file du lieu!" << endl;
        sqlite3_free(messageError);
    }
}

int call2compare2(void* NotUsed, int argc, char** argv, char** azColName)
{
    const char* name = "PhongDaoTao.txt";
    ofstream output;
    output.open(name, ios::app);
    if (output.is_open())
    {
        int i;
        for (i = 1; i < argc; i++)
        {
            string colName = azColName[i];
            string Argv = argv[i] ? argv[i] : "NULL";
            output << colName + ": " + Argv << endl;
        }
        output << endl;
        output.close();
    }
    else
        cout << "\nMo file " << name << " that bai" << endl;
    return 0;
}

void file2compare3(const char* s3)
{
    const char* name = "TruongBoMon.txt";
    ofstream output;
    output.open(name, ios::out);
    output.close();
    sqlite3* DB;
    char* messageError;
    string sql("SELECT * FROM SinhVien;" "SELECT * FROM Diem;");
    int exit = sqlite3_open(s3, &DB);
    exit = sqlite3_exec(DB, sql.c_str(), call2compare3, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Da xay ra loi khi xuat file du lieu!" << endl;
        sqlite3_free(messageError);
    }
}

int call2compare3(void* NotUsed, int argc, char** argv, char** azColName)
{
    const char* name = "TruongBoMon.txt";
    ofstream output;
    output.open(name, ios::app);
    if (output.is_open())
    {
        int i;
        for (i = 1; i < argc; i++)
        {
            string colName = azColName[i];
            string Argv = argv[i] ? argv[i] : "NULL";
            output << colName + ": " + Argv << endl;
        }
        output << endl;
        output.close();
    }
    else
        cout << "\nMo file " << name << " that bai" << endl;
    return 0;
}

void file2compare4(const char* s4)
{
    const char* name = "BoPhanXuLyDiem.txt";
    ofstream output;
    output.open(name, ios::out);
    output.close();
    sqlite3* DB;
    char* messageError;
    string sql("SELECT * FROM SinhVien;" "SELECT * FROM Diem;");
    int exit = sqlite3_open(s4, &DB);
    exit = sqlite3_exec(DB, sql.c_str(), call2compare4, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Da xay ra loi khi xuat file du lieu!" << endl;
        sqlite3_free(messageError);
    }
}

int call2compare4(void* NotUsed, int argc, char** argv, char** azColName)
{
    const char* name = "BoPhanXuLyDiem.txt";
    ofstream output;
    output.open(name, ios::app);
    if (output.is_open())
    {
        int i;
        for (i = 1; i < argc; i++)
        {
            string colName = azColName[i];
            string Argv = argv[i] ? argv[i] : "NULL";
            output << colName + ": " + Argv << endl;
        }
        output << endl;
        output.close();
    }
    else
        cout << "\nMo file " << name << " that bai" << endl;
    return 0;
}

int checkSecurity(const char* s1, const char* s2, const char* s3, const char* s4)
{
    file2compare1(s1);
    file2compare2(s2);
    file2compare3(s3);
    file2compare4(s4);

    if (compareFile("GiangVien.txt", "PhongDaoTao.txt"))
    {
        if (compareFile("GiangVien.txt", "TruongBoMon.txt"))
        {
            if (compareFile("GiangVien.txt", "BoPhanXuLyDiem.txt"))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        return 0;
    }
}

void TimeComplexityCheckSecurity()
{
    const char* dir1 = R"(.\DataBase\QuanLyDiemSinhVien_PHONGDAOTAO.db)";
    const char* dir2 = R"(.\DataBase\QuanLyDiemSinhVien_GIANGVIEN.db)";
    const char* dir3 = R"(.\DataBase\QuanLyDiemSinhVien_TRUONGKHOA.db)";
    const char* dir4 = R"(.\DataBase\QuanLyDiemSinhVien_BOPHANXULYDIEM.db)";
    const char* name = "TimeComplexityCheckSecurity.txt";
    ofstream output;
    output.open(name, ios::out);
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int Max = NULL;
        int Min = NULL;
        int Sum = 0;
        Student_info sv = getInfor();
        insertNewStudent(dir1, dir2, dir3, dir4, sv);
        for (int j = 0; j < 10; j++)
        {
            auto start = high_resolution_clock::now();
            int kq = checkSecurity(dir1, dir2, dir3, dir4);
            cout << kq << endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            if (Min == NULL)
            {
                Min = duration.count();
            }
            else if (Min > duration.count())
            {
                Min = duration.count();
            }
            if (Max == NULL)
            {
                Max = duration.count();
            }
            else if (Max < duration.count())
            {
                Max = duration.count();
            }
            Sum += duration.count();
        }
        int Mean = Sum / 10;
        output << i <<"       " << Min << "       " << Mean << "      " << Max << endl;
        std::cout << "Min: " << Min << endl;
        std::cout << "Mean: " << Mean << endl;
        std::cout << "Max: " << Max << endl;
        std::cout << "-----------------------------" << endl;
    }
    output.close();
}
#pragma endregion





int main()
{
   
    //TimeComplexitySHA256(1000);
    //TimeComplexityMine1(1000);
    //TimeComplexityMine2(10);

    //TimeComplexityINSERTNEWSTUDENT();
    //TimeComplexityINSERTOLDSTUDENT();
    //TimeComplexityIsBlockChainValid();

    //TimeComplexityCompareFile(1250);   
    //TimeComplexityCheckSecurity();
    const char* dir1 = R"(.\DataBase\QuanLyDiemSinhVien_PHONGDAOTAO.db)";
    const char* dir2 = R"(.\DataBase\QuanLyDiemSinhVien_GIANGVIEN.db)";
    const char* dir3 = R"(.\DataBase\QuanLyDiemSinhVien_TRUONGKHOA.db)";
    const char* dir4 = R"(.\DataBase\QuanLyDiemSinhVien_BOPHANXULYDIEM.db)";
    Student_info old = getInforOld();
    insertNewStudent(dir1, dir2, dir3, dir4, old);
    

    return 0;
}







