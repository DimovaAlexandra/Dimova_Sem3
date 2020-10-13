#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct  pipe{
    int id;
    double lenght;
    double diameter;
    bool repair_status;

};

struct CS {
    int id;
    string name;
    int workshop_number;
    int working_workshop_number;
    double efficiency;
};

vector <pipe> vector_PIPE;
vector <CS> vector_CS;

int Check(int min, int max) {
    int buf = 0;
    while (!(cin >> buf) || buf > max || buf < min) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "enter a number" << endl;
    }
    return buf;

}

string fileCheck(int X)
{
    string name_of_file;
    int i = 0;
    while (i != 1)
    {
        cout << "write name_of_file" << endl;
        cin >> name_of_file;
        name_of_file = name_of_file + ".txt";
        ifstream file_for_check(name_of_file);
        if (!file_for_check)

            cout << "Указанный файл не найден, введите корректное название." << endl;
        else
        {
            cout << "Указанный файл успешно открыт." << endl;
            if (file_for_check.peek() == EOF && X == 1)
            {
                cout << "Указанный файл пуст, выбирете другой файл " << endl;
            }
            else
            {
                i = 1;
            }
        }
    }
    return name_of_file;
};

void Save() {
    int choose;
    string file_name;
    cout << "1.Save database of pipe" << endl
        << "2.Save database of CS" << endl;
    choose = Check(1, 2);
   /* file_name=fileCheck(2);*/
    file_name = "save.txt";
    ifstream input_file(file_name);
    switch (choose) {
    case 1: {
        for (int i = 0; i <= vector_PIPE.size() - 1; i++)
        {
            input_file >> vector_PIPE[i].id;
            input_file >> vector_PIPE[i].diameter;
            input_file >> vector_PIPE[i].lenght;
            input_file >> vector_PIPE[i].repair_status;
        }
        break; }
    case 2: {
        for (int i = 0; i <= vector_CS.size() - 1; i++)
        {
            input_file >> vector_CS[i].id;
            input_file >> vector_CS[i].name;
            input_file >> vector_CS[i].workshop_number;
            input_file >> vector_CS[i].working_workshop_number;
            input_file >> vector_CS[i].efficiency;
           
        }
        break;

    }
    }
   
}

void Load(int x)
{


}



void Add_Pipe()
{
    pipe P;
    
    cout << "Add pipe's id:" << endl;
    P.id=Check(0,9999);
    cout << "Add pipe's diameter:" << endl;
    P.diameter = Check(0, 9999);
    cout << "Add pipe's lenght:" << endl;
   P.lenght = Check(0, 9999);
    cout << "Add pipe's repair status 1 or 0:" << endl;
 P.repair_status = Check(0, 9999);
    vector_PIPE.push_back(P);
}
void Add_CS()
{
    CS C;
    cout << "Add CS's id:" << endl;
   C.id = Check(0, 9999);
    cout << "Add CS' name:" << endl;
    cin >> C.name;
    cout << "Add CS's workshop number:" << endl;
    C.workshop_number = Check(0, 9999);
    cout << "Add CS's working workshop number:" << endl;
    C.working_workshop_number = Check(0, 9999);
    cout << "Add CS's efficiency:" << endl;
  C.efficiency = Check(0, 9999);

    vector_CS.push_back(C);
   

}
void View_all_objects()
{
    int i=0;
    int j=0;
    if (vector_PIPE.size() != 0) {
        for (i; i <= vector_PIPE.size() - 1; i++)
        {
            cout << "ID" << endl;
            cout << vector_PIPE[i].id << endl;
            cout << "DIAMETER" << endl;
            cout << vector_PIPE[i].diameter << endl;
            cout << "LENGHT" << endl;
            cout << vector_PIPE[i].lenght << endl;
            cout << "REPAIR STATUS" << endl;
            cout << vector_PIPE[i].repair_status << endl;
        }
    }
    if (vector_CS.size() != 0)
    {
        for (j; j <= vector_CS.size() - 1; j++)
        {
            cout << "ID" << endl;
            cout << vector_CS[j].id << endl;
            cout << "NAME" << endl;
            cout << vector_CS[j].name << endl;
            cout << "WORKSHOP NUMBER" << endl;
            cout << vector_CS[j].workshop_number << endl;
            cout << "WORKING WORKSHOP NUMBER" << endl;
            cout << vector_CS[j].working_workshop_number << endl;
            cout << "EFFICIENCY" << endl;
            cout << vector_CS[j].efficiency << endl;
        }
    }
}
void Edit_Pipe()
{
    int id;
    cout << "Add pipe's id which you want to change" << endl;
    cin >> id;
    pipe b;
    b.id = id;
    for (int i = 0; i <= vector_PIPE.size() - 1;i++) {
        if (vector_PIPE[i].id = id)
             id = i;
    }
    cout << "Add new pipe's id:" << endl;
    b.id = Check(0, 9999);
    cout << "Add new pipe's diameter:" << endl;
   b.diameter = Check(0, 9999);
    cout << "Add new pipe's lenght:" << endl;
    b.lenght = Check(0, 9999);
    cout << "Add new pipe's repair status 0 or 1:" << endl;
    b.repair_status = Check(0, 9999);
    vector_PIPE[id] = b;

}

void Edit_CS()
{
    int id;
    cout << "Add CS's id which you want to change" << endl;
    cin >> id;
   CS e;
    e.id = id;
    for (int j = 0; j <= vector_CS.size() - 1; j++) {
        if (vector_CS[j].id = id)
            id = j;
    }
    cout << "Add new CS's id:" << endl;
    e.id = Check(0, 9999);
    cout << "Add new CS's name:" << endl;
    cin >> e.name;
    cout << "Add new CS's workshop number:" << endl;
  e.workshop_number = Check(0, 9999);
    cout << "Add new CS's working workshop number:" << endl;
e.working_workshop_number = Check(0, 9999);
    cout << "Add new CS's efficiency:" << endl;
    e.efficiency = Check(0, 9999);
    vector_CS[id] = e;

}

void menu()
{
    setlocale(LC_ALL, "rus");
    while (1) {
        cout << "1. Add pipe" << endl
            << "2. Add CS" << endl
            << "3. View all objects" << endl
            << "4. Edit pipe" << endl
            << "5. Edit CS " << endl
            << "6. Save" << endl
            << "7. Load " << endl
            << "0. Exit" << endl;

        int x;

        cin >> x;

        switch (x) {
        case 1: {Add_Pipe(); break;}
        case 2: {Add_CS(); break; }
        case 3: {View_all_objects(); break; }
        case 4: {Edit_Pipe(); break; }
        case 5: {Edit_CS(); break;  }
        case 6: {Save(); break; }
        };
    };
}

int main()
{
    menu();

}
