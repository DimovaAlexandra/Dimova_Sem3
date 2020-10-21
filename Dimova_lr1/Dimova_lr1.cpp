#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct pipe{
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

double Check(double min, double max) {
   double buf = 0;
    while (!(cin >> buf) || buf > max || buf < min) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "enter a correct number" << endl;
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

            cout << "The specified file was not found, please enter the correct name." << endl;
        else
        {
            cout << "The specified file was successfully opened." << endl;
            if (file_for_check.peek() == EOF && X == 1)
            {
                cout << "The specified file is empty, please select another file " << endl;
            }
            else
            {
                i = 1;
            }
        }
    }
    return name_of_file;
};





void Save()
{
    string filename;
    fstream inputfile;
    cout << "1. Save pipe" << "\n"
        << "2.Save CS" << "\n";
    int x = Check(1, 2);
    cout << "Enter file name:" << endl;
   filename=fileCheck(2);
    inputfile.open(filename, fstream::in | fstream::app);
   if (!inputfile.is_open()) {
       cout << "File not found"<<endl;
   }
   else { if (x=1)
       for (pipe pipe : vector_PIPE) {
           inputfile << pipe.id<< "\n" << pipe.diameter <<"\n"<< pipe.lenght<<"\n" << pipe.repair_status << "\n" ;
       }
   else { for (CS CS : vector_CS) { inputfile << CS.id << "\n" << CS.name << "\n" << CS.workshop_number << "\n" << CS.working_workshop_number << "\n" << CS.efficiency << "\n"; } }

   }
   }

void Load()
{
    string filename;
    fstream inputfile;
    cout << "1. Load pipe" << "\n"
        << "2.Load CS" << "\n";
    int x = Check(1, 2);
    cout << "Enter file name:" << endl;
    filename=fileCheck(1);
    inputfile.open(filename, fstream::in| fstream::out | fstream::app);
   
    if (!inputfile.is_open()) {
        cout << "File not found" << endl;
    }
    else {
        if (x = 1)
            while (!inputfile.eof()) {
                pipe pipe;
                inputfile >> pipe.id >> pipe.diameter >> pipe.lenght >> pipe.repair_status;
                vector_PIPE.push_back(pipe);
            }
        else {
            while (!inputfile.eof()) {
                CS CS;
                inputfile >> CS.id >> CS.name >> CS.workshop_number >> CS.working_workshop_number >> CS.efficiency;
                vector_CS.push_back(CS);
            }
        }

    }
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
 P.repair_status = Check(0, 1);
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
    C.working_workshop_number = Check(0, C.workshop_number);
    cout << "Add CS's efficiency (in percents):" << endl;
  C.efficiency = Check(0, 100);

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
            cout << vector_CS[j].efficiency << "%" << endl;
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
    b.repair_status = Check(0, 1);
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
    cout << "Add new CS's efficiency (in percents):" << endl;
    e.efficiency = Check(0, 100);
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

  

        int x = Check(0, 7);

        switch (x) {
        case 0: {exit(0); break; }
        case 1: {Add_Pipe(); break;}
        case 2: {Add_CS(); break; }
        case 3: {View_all_objects(); break; }
        case 4: {Edit_Pipe(); break; }
        case 5: {Edit_CS(); break;  }
        case 6: {Save(); break; }
        case 7: {Load(); break; }
        };
    };
}

int main()
{
    menu();

}
