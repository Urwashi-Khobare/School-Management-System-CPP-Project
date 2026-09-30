#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int id,cls,ch5;
    string name,surname,fname,pass;

    int internal[5];
    int onPaper[5];

    Student()
    {
        id = 0;
        cls = 0;

        for(int i = 0; i < 5; i++)
        {
            internal[i] = 0;
            onPaper[i] = 0;
        }
    }
};

class Teacher
{
public:
    int id;
    string name,lname,fname,username,pass,cls,subject;
    float salary;

    Teacher()
    {
        id = 0;
        salary = 0;
        subject = "NOT SET";
    }
};

class Result
{
public:

};

class Admin
{
public:

    Teacher t[50];
    int teacherCount = 0;

    Student s[50];
    int studentCount = 0;

    int choice,ch,ch1,ch2,ch3,emp_id,stu_id,cls;
    float salary;
    string name,uname,username,pass,password,lname,fname;

    void admin_section()
    {
        do{
        cout<<"<Admin Portal"<<endl;
        cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTRATION"<<endl;
        cout<<"0.BACK MENU"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"--LOGIN--"<<endl;
            cout<<"Username:"<<endl;
            cin>>username;
            cout<<"Password:"<<endl;
            cin>>password;

            if(uname==username && pass==password)
            {
                do{
                    cout<<"WELCOME"<<uname<<endl;
                    cout<<"<Admin Portal>"<<endl;
                    cout<<"1.Teacher Account"<<endl;
                    cout<<"2.Student Account"<<endl;
                    cout<<"3.Result"<<endl;
                    cout<<"0.Logout"<<endl;

                    cout<<"Enter your choice:"<<endl;
                    cin>>ch;

                    switch(ch)
                    {
                    case 1:
                         do
                         {
                            cout << "\n<Admin Portal>" << endl;
                            cout << "Teacher SECTION" << endl;
                            cout << "1. ADD" << endl;
                            cout << "2. UPDATE" << endl;
                            cout << "3. DELETE" << endl;
                            cout << "4. SHOW" << endl;
                            cout << "5. SALARY" << endl;
                            cout << "6. SHOW All teacher" << endl;
                            cout << "0. BACK MENU" << endl;

                            cout << "\nCHOICE: ";
                            cin >> ch1;

                            switch(ch1)
                            {
                            case 1:
                                cout << "\n>> ADD TEACHER" << endl;

                                int newId;
                                bool idExists;

                                do
                                {
                                    idExists = false;

                                    cout << "Teacher ID : ";
                                    cin >> newId;

                                    for(int i = 0; i < teacherCount; i++)
                                    {
                                       if(t[i].id == newId)
                                       {
                                          idExists = true;

                                          cout << "\nTeacher ID already exists!" << endl;
                                          cout << "Please enter a different ID.\n" << endl;

                                          break;
                                       }
                                    }

                                }while(idExists == true);

                                t[teacherCount].id = newId;

                                cout << "Enter Name : ";
                                cin >> t[teacherCount].name;

                                cout << "Enter Surname : ";
                                cin >> t[teacherCount].lname;

                                cout << "Enter Father Name : ";
                                cin >> t[teacherCount].fname;

                                cout << "Enter Class : ";
                                cin >> t[teacherCount].cls;

                                cout << "Enter Password : ";
                                cin >> t[teacherCount].pass;

                                t[teacherCount].salary = 0;
                                t[teacherCount].subject = "NOT SET";

                                teacherCount++;

                                cout << "\nTeacher Added Successfully...." << endl;

                                break;

                            case 2:
                            {
                               int searchId;
                               int updateChoice;
                               bool found = false;

                               cout << "\nEnter Emp ID to Update : ";
                               cin >> searchId;

                               for(int i = 0; i < teacherCount; i++)
                               {
                                  if(t[i].id == searchId)
                                  {
                                     found = true;

                                     cout << "\nEMPLOYEE DETAILS" << endl;
                                     cout << "EMP ID : " << t[i].id << endl;
                                     cout << "NAME : " << t[i].name << endl;

                                     cout << "\nWhat do you want to update?" << endl;
                                     cout << "1. ID" << endl;
                                     cout << "2. NAME" << endl;
                                     cout << "3. SURNAME" << endl;
                                     cout << "4. FATHER NAME" << endl;
                                     cout << "5. CLASS" << endl;
                                     cout << "6. PASSWORD" << endl;
                                     cout << "0. BACK" << endl;

                                     cout << "CHOICE : ";
                                     cin >> updateChoice;

                                     switch(updateChoice)
                                     {
                                     case 1:
                                         cout << "Enter New ID : ";
                                         cin >> t[i].id;
                                         cout << "ID Updated Successfully!" << endl;
                                         break;

                                     case 2:
                                         cout << "Enter New Name : ";
                                         cin >> t[i].name;
                                         cout << "Name Updated Successfully!" << endl;
                                         break;

                                     case 3:
                                         cout << "Enter New Surname : ";
                                         cin >> t[i].lname;
                                         cout << "Surname Updated Successfully!" << endl;
                                         break;

                                     case 4:
                                         cout << "Enter New Father Name : ";
                                         cin >> t[i].fname;
                                         cout << "Father Name Updated Successfully!" << endl;
                                         break;

                                     case 5:
                                         cout << "Enter New Class : ";
                                         cin >> t[i].cls;
                                         cout << "Class Updated Successfully!" << endl;
                                         break;

                                     case 6:
                                         cout << "Enter New Password : ";
                                         cin >> t[i].pass;
                                         cout << "Password Updated Successfully!" << endl;
                                         break;

                                     case 0:
                                         break;

                                     default:
                                         cout << "Invalid Choice!" << endl;
                                    }

                                    break;
                                  }
                                }

                                if(found == false)
                                {
                                  cout << "\nTeacher not found!" << endl;
                                }

                                break;
                            }

                            case 3:
                            {
                               int deleteId;
                               bool found = false;

                               cout << "\nEnter Emp ID to Delete : ";
                               cin >> deleteId;

                               for(int i = 0; i < teacherCount; i++)
                               {
                                  if(t[i].id == deleteId)
                                  {
                                     found = true;

                                     for(int j = i; j < teacherCount - 1; j++)
                                     {
                                        t[j] = t[j + 1];
                                     }

                                     teacherCount--;

                                     cout << "\nTeacher Deleted Successfully!" << endl;
                                     break;
                                  }
                               }

                               if(found == false)
                               {
                                  cout << "\nTeacher not found!" << endl;
                               }

                               break;
                            }

                            case 4:
                            {
                                int searchId;

                                cout << "\nEnter Emp ID : ";
                                cin >> searchId;

                                bool found = false;

                                for(int i = 0; i < teacherCount; i++)
                                {
                                   if(t[i].id == searchId)
                                   {
                                      cout << "\nEMPLOYEE DETAILS" << endl;
                                      cout << "EMP ID  : " << t[i].id << endl;
                                      cout << "NAME    : " << t[i].name << " "
                                           << t[i].lname << endl;
                                      cout << "FATHER NAME : " << t[i].fname << endl;
                                      cout << "CLASS   : " << t[i].cls << endl;
                                      cout << "SUBJECT : " << t[i].subject << endl;
                                      cout << "SALARY  : " << t[i].salary << endl;

                                      found = true;
                                      break;
                                    }
                                }

                                if(found == false)
                                {
                                    cout << "\nTeacher not found!" << endl;
                                }

                                break;
                            }
                            case 5:
                            {
                               int searchId;
                               float newSalary;
                               bool found = false;

                               cout << "\nEnter Emp ID : ";
                               cin >> searchId;

                               for(int i = 0; i < teacherCount; i++)
                               {
                                  if(t[i].id == searchId)
                                  {
                                     found = true;

                                     cout << "\nEMPLOYEE DETAILS" << endl;
                                     cout << "EMP ID  : " << t[i].id << endl;
                                     cout << "NAME    : " << t[i].name << " "
                                          << t[i].lname << endl;
                                     cout << "SUBJECT : " << t[i].subject << endl;
                                     cout << "SALARY  : " << t[i].salary << endl;

                                     cout << "\nEnter Salary : ";
                                     cin >> newSalary;

                                     t[i].salary = newSalary;

                                     cout << "\nOK..Task Complete!" << endl;

                                     break;
                                  }
                               }

                               if(found == false)
                               {
                                  cout << "\nTeacher not found!" << endl;
                               }

                               break;
                            }

                            case 6:
                                if(teacherCount == 0)
                                {
                                   cout << "\nNo teacher available!" << endl;
                                   break;
                                }

                                cout << "\n================ ALL TEACHERS ================\n";

                                cout << "ID\tNAME\t\tSUBJECT\t\tSALARY" << endl;

                                cout << "------------------------------------------------\n";

                                for(int i = 0; i < teacherCount; i++)
                                {
                                   cout << t[i].id << "\t"
                                        << t[i].name << " " << t[i].lname << "\t"
                                        << t[i].subject << "\t\t"
                                        << t[i].salary << endl;
                                }
                                break;

                            case 0:
                                break;

                            default:
                                cout << "Invalid Choice" << endl;
                            }

                         } while(ch1 != 0);
                        break;
                    case 2:
                        do{
                        cout<<"<Admin Portal>"<<endl;
                        cout<<"Student Section"<<endl;
                        cout<<"1.ADD"<<endl;
                        cout<<"2.UPDATE"<<endl;
                        cout<<"3.DELETE"<<endl;
                        cout<<"4.SHOW"<<endl;
                        cout<<"0.BACK MENU"<<endl;

                        cout<<"Enter your choice:"<<endl;
                        cin>>ch2;

                            switch(ch2)
                            {
                            case 1:
                            {
                               cout << "\n>> ADD STUDENT" << endl;

                               int newId;
                               bool idExists;

                               do
                               {
                                  idExists = false;

                                  cout << "Enter Student ID : ";
                                  cin >> newId;

                                  for(int i = 0; i < studentCount; i++)
                                  {
                                     if(s[i].id == newId)
                                     {
                                        idExists = true;
                                        cout << "\nStudent ID already exists!" << endl;
                                        cout << "Please enter a different ID.\n" << endl;
                                        break;
                                     }
                                  }

                               }while(idExists == true);

                               s[studentCount].id = newId;

                               cout << "Enter Name : ";
                               cin >> s[studentCount].name;

                               cout << "Enter Surname : ";
                               cin >> s[studentCount].surname;

                               cout << "Enter Father Name : ";
                               cin >> s[studentCount].fname;

                               cout << "Enter Class : ";
                               cin >> s[studentCount].cls;

                               cout << "Enter Password : ";
                               cin >> s[studentCount].pass;

                               studentCount++;

                               cout << "\nStudent Added Successfully...." << endl;

                               break;
                            }
                            case 2:
                            {
                                int searchId;
                                int updateChoice;
                                bool found = false;

                                cout << "\n>> UPDATE STUDENT" << endl;

                                cout << "\nEnter Student ID : ";
                                cin >> searchId;

                                for(int i = 0; i < studentCount; i++)
                                {
                                   if(s[i].id == searchId)
                                   {
                                      found = true;

                                      cout << "\n========== STUDENT FOUND ==========" << endl;
                                      cout << "Student ID  : " << s[i].id << endl;
                                      cout << "Name        : " << s[i].name << " "
                                           << s[i].surname << endl;
                                      cout << "Father Name : " << s[i].fname << endl;
                                      cout << "Class       : " << s[i].cls << endl;

                                      cout << "\nWhat do you want to update?" << endl;
                                      cout << "1. UPDATE ID" << endl;
                                      cout << "2. UPDATE NAME" << endl;
                                      cout << "3. UPDATE SURNAME" << endl;
                                      cout << "4. UPDATE FATHER NAME" << endl;
                                      cout << "5. UPDATE CLASS" << endl;
                                      cout << "6. UPDATE PASSWORD" << endl;
                                      cout << "0. BACK" << endl;

                                      cout << "CHOICE : ";
                                      cin >> updateChoice;

                                      switch(updateChoice)
                                      {
                                      case 1:
                                          cout << "Old ID : " << s[i].id << endl;
                                          cout << "New ID : ";
                                          cin >> s[i].id;
                                          cout << "ID Updated Successfully!" << endl;
                                          break;

                                      case 2:
                                          cout << "Old Name : " << s[i].name << endl;
                                          cout << "New Name : ";
                                          cin >> s[i].name;
                                          cout << "Name Updated Successfully!" << endl;
                                          break;

                                      case 3:
                                          cout << "Old Surname : " << s[i].surname << endl;
                                          cout << "New Surname : ";
                                          cin >> s[i].surname;
                                          cout << "Surname Updated Successfully!" << endl;
                                          break;

                                      case 4:
                                          cout << "Old Father Name : " << s[i].fname << endl;
                                          cout << "New Father Name : ";
                                          cin >> s[i].fname;
                                          cout << "Father Name Updated Successfully!" << endl;
                                          break;

                                      case 5:
                                          cout << "Old Class : " << s[i].cls << endl;
                                          cout << "New Class : ";
                                          cin >> s[i].cls;
                                          cout << "Class Updated Successfully!" << endl;
                                          break;

                                      case 6:
                                          cout << "Enter New Password : ";
                                          cin >> s[i].pass;
                                          cout << "Password Updated Successfully!" << endl;
                                          break;

                                      case 0:
                                          break;

                                     default:
                                          cout << "Invalid Choice!" << endl;
                                     }

                                     break;
                                   }
                                }

                                if(found == false)
                                {
                                   cout << "\nStudent not found!" << endl;
                                }

                                break;
                            }
                            case 3:
                            {
                                int deleteId;
                                bool found = false;

                                cout << "\n>> DELETE STUDENT" << endl;

                                cout << "\nEnter Student ID: ";
                                cin >> deleteId;

                                for(int i = 0; i < studentCount; i++)
                                {
                                   if(s[i].id == deleteId)
                                   {
                                      found = true;

                                      for(int j = i; j < studentCount - 1; j++)
                                      {
                                         s[j] = s[j + 1];
                                      }

                                      studentCount--;

                                      cout << "\nStudent Deleted Successfully!" << endl;

                                      break;
                                   }
                                }

                                if(found == false)
                                {
                                    cout << "\nStudent not found!" << endl;
                                }

                                break;
                            }
                            case 4:
                            {
                               int searchId;
                               bool found = false;

                               cout << "\nEnter Student ID : ";
                               cin >> searchId;

                               for(int i = 0; i < studentCount; i++)
                               {
                                  if(s[i].id == searchId)
                                  {
                                     cout << "\n========== STUDENT DETAILS ==========" << endl;

                                     cout << "Student ID   : " << s[i].id << endl;
                                     cout << "Name         : " << s[i].name << " "
                                          << s[i].surname << endl;
                                     cout << "Father Name  : " << s[i].fname << endl;
                                     cout << "Class        : " << s[i].cls << endl;

                                     found = true;
                                     break;
                                  }
                               }

                               if(found == false)
                               {
                                  cout << "\nStudent not found!" << endl;
                               }

                               break;
                            }
                            case 0:
                                break;
                            default:
                                break;
                            }
                        }while(ch2!=0);
                        break;
                    case 3:
                        do{
                        cout<<"<Admin Portal>"<<endl;
                        cout<<"Result Section"<<endl;
                        cout<<"1.SEARCH"<<endl;
                        cout<<"2.SHOW"<<endl;
                        cout<<"3.EDIT"<<endl;
                        cout<<"0.BACK MENU"<<endl;

                        cout<<"Enter your choice:"<<endl;
                        cin>>ch3;

                        switch(ch3)
                        {
                        case 1:
                        {
                            int searchId;
                            bool found = false;

                            cout << "\n>> SEARCH RESULT" << endl;

                            cout << "\nENTER STUDENT ID : ";
                            cin >> searchId;

                            for(int i = 0; i < studentCount; i++)
                            {
                               if(s[i].id == searchId)
                               {
                                   found = true;

                                   int totalMarks = 0;

                                   cout << "\n";
                                   cout << "**************************************************" << endl;
                                   cout << "                    RESULT                       " << endl;
                                   cout << "**************************************************" << endl;

                                   cout << "COLLEGE : Priyadarshini College of Engineering, Nagpur"
                                        << endl;

                                   cout << "NAME : "
                                        << s[i].name << " "
                                        << s[i].surname << endl;

                                   cout << "FATHER NAME : "
                                        << s[i].fname << endl;

                                   cout << "ROLL NUMBER : AST"
                                        << s[i].id << endl;

                                   cout << "--------------------------------------------------"
                                        << endl;

                                   cout << "SUBJECT\t\tINTERNAL\tON PAPER\tTOTAL"
                                        << endl;

                                   cout << "--------------------------------------------------"
                                        << endl;

                                   string subjects[5] =
                                   {
                                       "MA-102",
                                       "EN-102",
                                       "CS-111",
                                       "HS-107",
                                       "MT-101"
                                   };


                                   for(int j = 0; j < 5; j++)
                                   {
                                       int total;

                                       total = s[i].internal[j]
                                             + s[i].onPaper[j];

                                       cout << subjects[j] << "\t\t"
                                            << s[i].internal[j] << "\t\t"
                                            << s[i].onPaper[j] << "\t\t"
                                            << total << endl;

                                       totalMarks = totalMarks + total;
                                   }

                                   cout << "--------------------------------------------------"
                                        << endl;

                                   cout << "TOTAL MARKS : "
                                        << totalMarks << endl;

                                   if(totalMarks >= 200)
                                   {
                                       cout << "RESULT : PASS" << endl;
                                   }
                                   else
                                   {
                                       cout << "RESULT : FAIL" << endl;
                                   }

                                   cout << "**************************************************"
                                        << endl;

                                   break;
                               }
                            }

                            if(found == false)
                            {
                                cout << "\nStudent not found!" << endl;
                            }

                            break;
                        }

                        case 2:
                        {
                            if(studentCount == 0)
                            {
                                cout << "\nNo student result available!" << endl;
                                break;
                            }

                            string subjects[5] =
                            {
                                "MA-102",
                                "EN-102",
                                "CS-111",
                                "HS-107",
                                "MT-101"
                            };

                            cout << "\n";
                            cout << "============================================================="
                                 << endl;

                            cout << "                 ALL STUDENT RESULTS"
                                 << endl;

                            cout << "============================================================="
                                 << endl;

                            cout << "\n";

                            cout << "ID\tNAME\t\t"
                                 << "MA-102\t"
                                 << "EN-102\t"
                                 << "CS-111\t"
                                 << "HS-107\t"
                                 << "MT-101\t"
                                 << "TOTAL\tRESULT"
                                 << endl;

                            cout << "--------------------------------------------------------------------------------"
                                 << endl;

                            for(int i = 0; i < studentCount; i++)
                            {
                               int totalMarks = 0;

                               int subjectTotal[5];

                               for(int j = 0; j < 5; j++)
                               {
                                   subjectTotal[j] =
                                     s[i].internal[j] +
                                     s[i].onPaper[j];

                                   totalMarks = totalMarks +
                                     subjectTotal[j];
                               }

                               string result;

                               if(totalMarks >= 200)
                               {
                                  result = "PASS";
                               }
                               else
                               {
                                  result = "FAIL";
                               }

                               cout << s[i].id << "\t";

                               cout << s[i].name << " "
                                    << s[i].surname << "\t";

                               for(int j = 0; j < 5; j++)
                               {
                                  cout << subjectTotal[j] << "\t";
                               }

                                  cout << totalMarks << "\t"
                                       << result << endl;
                            }

                            cout << "--------------------------------------------------------------------------------"
                                 << endl;

                            break;
                        }

                        case 3:
                        {
                            int searchId;
                            int subjectChoice;
                            int markChoice;
                            int newMarks;
                            bool found = false;

                            cout << "\n==================================" << endl;
                            cout << "          EDIT RESULT" << endl;
                            cout << "==================================" << endl;

                            cout << "\nEnter Student ID : ";
                            cin >> searchId;

                            for(int i = 0; i < studentCount; i++)
                            {
                               if(s[i].id == searchId)
                               {
                                  found = true;

                                  cout << "\nStudent Found!" << endl;

                                  cout << "Student ID : " << s[i].id << endl;
                                  cout << "Name       : "
                                       << s[i].name << " "
                                       << s[i].surname << endl;

                                  cout << "\nSELECT SUBJECT" << endl;
                                  cout << "1. MA-102" << endl;
                                  cout << "2. EN-102" << endl;
                                  cout << "3. CS-111" << endl;
                                  cout << "4. HS-107" << endl;
                                  cout << "5. MT-101" << endl;

                                  cout << "\nCHOICE : ";
                                  cin >> subjectChoice;

                                  int subjectIndex = -1;

                                  switch(subjectChoice)
                                  {
                                  case 1:
                                     subjectIndex = 0;
                                     break;

                                 case 2:
                                     subjectIndex = 1;
                                     break;

                                 case 3:
                                     subjectIndex = 2;
                                     break;

                                 case 4:
                                     subjectIndex = 3;
                                     break;

                                 case 5:
                                     subjectIndex = 4;
                                     break;

                                 default:
                                     cout << "\nInvalid Subject Choice!" << endl;
                                 }

                                 if(subjectIndex == -1)
                                 {
                                    break;
                                 }

                                 cout << "\nEDIT MARKS" << endl;
                                 cout << "1. INTERNAL (20)" << endl;
                                 cout << "2. ON PAPER (80)" << endl;

                                 cout << "\nCHOICE : ";
                                 cin >> markChoice;

                                 if(markChoice == 1)
                                 {
                                     cout << "\nOld Internal Marks : "
                                          << s[i].internal[subjectIndex]
                                          << endl;

                                     cout << "Enter New Internal Marks : ";
                                     cin >> newMarks;

                                     while(newMarks < 0 || newMarks > 20)
                                     {
                                        cout << "Invalid marks!" << endl;
                                        cout << "Enter marks between 0 and 20 : ";
                                        cin >> newMarks;
                                     }

                                     s[i].internal[subjectIndex] = newMarks;

                                     cout << "\nInternal Marks Updated Successfully!" << endl;
                                 }
                                 else if(markChoice == 2)
                                 {
                                     cout << "\nOld On Paper Marks : "
                                          << s[i].onPaper[subjectIndex]
                                          << endl;

                                     cout << "Enter New On Paper Marks : ";
                                     cin >> newMarks;

                                     while(newMarks < 0 || newMarks > 80)
                                     {
                                         cout << "Invalid marks!" << endl;
                                         cout << "Enter marks between 0 and 80 : ";
                                         cin >> newMarks;
                                     }

                                     s[i].onPaper[subjectIndex] = newMarks;

                                     cout << "\nOn Paper Marks Updated Successfully!" << endl;
                                 }
                                 else
                                 {
                                     cout << "\nInvalid Choice!" << endl;
                                 }

                                 break;
                               }
                            }

                            if(found == false)
                            {
                                cout << "\nStudent not found!" << endl;
                            }

                            break;
                        }

                        case 0:
                            cout<<"--BACK MENU--"<<endl;
                            break;
                        default:
                            cout<<"Invalid Choice"<<endl;
                            break;
                        }
                        }while(ch3!=0);
                        break;

                    case 0:
                        cout<<"ACCOUNT LOGOUT SUCCESSFULLY"<<endl;
                        break;
                    default:
                        cout<<"Invalid Choice"<<endl;
                        break;
                    }
                }while(ch!=0);
            }
            break;
        case 2:
            cout<<"--REGISTRATION--"<<endl;
            cout<<"Enter Details:"<<endl;
            cout<<"Name:"<<endl;
            cin>>name;
            cout<<"Username:"<<endl;
            cin>>uname;
            cout<<"Password:"<<endl;
            cin>>pass;
            cout<<"ACCOUNT CREATED SUCCESSFULLY!"<<endl;
            break;
        case 0:
            cout<<"--BACK MENU--"<<endl;
            break;
        default:
            cout<<"--INVALID CHOICE--"<<endl;
            break;
        }
    }while(choice!=0);
    }

    void teacher_portal()
    {
       int teacherChoice;

       do
       {
          cout << "\n==================================" << endl;
          cout << "        <Teacher Portal>" << endl;
          cout << "==================================" << endl;

          cout << "1. LOGIN" << endl;
          cout << "2. REGISTRATION" << endl;
          cout << "0. BACK MENU" << endl;

          cout << "\nCHOICE: ";
          cin >> teacherChoice;

          switch(teacherChoice)
          {
          case 1:
          {
             string loginUsername;
             string loginPassword;
             bool found = false;

             cout << "\n>> TEACHER LOGIN" << endl;

             cout << "USERNAME : ";
             cin >> loginUsername;

             cout << "PASSWORD : ";
             cin >> loginPassword;

             for(int i = 0; i < teacherCount; i++)
             {
                 if(t[i].username == loginUsername &&
                    t[i].pass == loginPassword)
                 {
                    found = true;

                    int teacherChoice;

                    do
                    {
                        cout << "\n==================================" << endl;
                        cout << "       >> WELCOME TEACHER!" << endl;
                        cout << "==================================" << endl;

                        cout << "NAME : "
                             << t[i].name << " "
                             << t[i].lname << endl;

                        cout << "SUBJECT : "
                             << t[i].subject << endl;

                        cout << "\n<Teacher Portal>" << endl;
                        cout << "1. Select Subject" << endl;
                        cout << "2. Add Marks" << endl;
                        cout << "3. Result" << endl;
                        cout << "0. Logout" << endl;

                        cout << "\nCHOICE : ";
                        cin >> teacherChoice;

                        switch(teacherChoice)
                        {
                        case 1:
                        {
                            int subjectChoice;

                            cout << "\n<SELECT SUBJECT>" << endl;
                            cout << "1) MA-102" << endl;
                            cout << "2) EN-102" << endl;
                            cout << "3) CS-111" << endl;
                            cout << "4) HS-107" << endl;
                            cout << "5) MT-101" << endl;

                            cout << "\nCHOICE : ";
                            cin >> subjectChoice;

                            switch(subjectChoice)
                            {
                            case 1:
                               t[i].subject = "MA-102";
                               break;

                            case 2:
                               t[i].subject = "EN-102";
                               break;

                            case 3:
                               t[i].subject = "CS-111";
                               break;

                            case 4:
                               t[i].subject = "HS-107";
                               break;

                            case 5:
                               t[i].subject = "MT-101";
                               break;

                            default:
                               cout << "Invalid Subject Choice!" << endl;
                            }

                            if(subjectChoice >= 1 && subjectChoice <= 5)
                            {
                              cout << "\nOK.. Subject Selected Successfully!" << endl;
                            }

                            break;
                        }

                        case 2:
                        {
                           int marksChoice;

                           do
                           {
                              cout << "\n<Teacher Portal>" << endl;
                              cout << "ADD MARKS SECTION" << endl;
                              cout << "1. Add" << endl;
                              cout << "2. Update" << endl;
                              cout << "0. BACK MENU" << endl;

                              cout << "\nCHOICE : ";
                              cin >> marksChoice;

                              switch(marksChoice)
                              {
                              case 1:
                              {
                                  if(t[i].subject == "NOT SET")
                                  {
                                      cout << "\nPlease select a subject first!" << endl;
                                      break;
                                  }

                                  if(studentCount == 0)
                                  {
                                      cout << "\nNo students available!" << endl;
                                      break;
                                  }

                                  int subjectIndex = -1;

                                  if(t[i].subject == "MA-102")
                                      subjectIndex = 0;
                                  else if(t[i].subject == "EN-102")
                                      subjectIndex = 1;
                                  else if(t[i].subject == "CS-111")
                                      subjectIndex = 2;
                                  else if(t[i].subject == "HS-107")
                                      subjectIndex = 3;
                                  else if(t[i].subject == "MT-101")
                                      subjectIndex = 4;

                                  cout << "\nSUBJECT : " << t[i].subject << endl;
                                  cout << ":: ADD MARKS ::" << endl;

                                  for(int j = 0; j < studentCount; j++)
                                  {
                                      cout << "\nRoll No. : " << s[j].id << endl;
                                      cout << "Name : "
                                           << s[j].name << " "
                                           << s[j].surname << endl;

                                      cout << "Internal 20 out of : ";
                                      cin >> s[j].internal[subjectIndex];

                                      while(s[j].internal[subjectIndex] < 0 ||
                                            s[j].internal[subjectIndex] > 20)
                                      {
                                           cout << "Invalid marks! Enter between 0 and 20 : ";
                                           cin >> s[j].internal[subjectIndex];
                                      }

                                      cout << "On Paper 80 out of : ";
                                      cin >> s[j].onPaper[subjectIndex];

                                      while(s[j].onPaper[subjectIndex] < 0 ||
                                            s[j].onPaper[subjectIndex] > 80)
                                      {
                                          cout << "Invalid marks! Enter between 0 and 80 : ";
                                          cin >> s[j].onPaper[subjectIndex];
                                      }

                                      cout << "Next..." << endl;
                                  }

                                  cout << "\nOK. Done! All Students Marks Added." << endl;

                                  break;
                              }

                              case 2:
                              {
                                  if(t[i].subject == "NOT SET")
                                  {
                                      cout << "\nPlease select a subject first!" << endl;
                                      break;
                                  }

                                  int rollNo;
                                  int markChoice;
                                  bool found = false;

                                  int subjectIndex = -1;

                                  if(t[i].subject == "MA-102")
                                      subjectIndex = 0;
                                  else if(t[i].subject == "EN-102")
                                      subjectIndex = 1;
                                  else if(t[i].subject == "CS-111")
                                      subjectIndex = 2;
                                  else if(t[i].subject == "HS-107")
                                      subjectIndex = 3;
                                  else if(t[i].subject == "MT-101")
                                      subjectIndex = 4;

                                  cout << "\n:: UPDATE MARKS ::" << endl;

                                  cout << "Enter Roll No : ";
                                  cin >> rollNo;

                                  for(int j = 0; j < studentCount; j++)
                                  {
                                      if(s[j].id == rollNo)
                                      {
                                          found = true;

                                          cout << "\nStudent Name : "
                                               << s[j].name << " "
                                               << s[j].surname << endl;

                                          cout << "\n1. Internal" << endl;
                                          cout << "2. On Paper" << endl;

                                          cout << "CHOICE : ";
                                          cin >> markChoice;

                                          if(markChoice == 1)
                                          {
                                              cout << "Old marks : "
                                                   << s[j].internal[subjectIndex]
                                                   << endl;

                                              cout << "New Marks : ";
                                              cin >> s[j].internal[subjectIndex];

                                              while(s[j].internal[subjectIndex] < 0 ||
                                                    s[j].internal[subjectIndex] > 20)
                                              {
                                                  cout << "Invalid marks! Enter between 0 and 20 : ";
                                                  cin >> s[j].internal[subjectIndex];
                                              }

                                              cout << "\nInternal Marks Updated!" << endl;
                                          }
                                          else if(markChoice == 2)
                                          {
                                              cout << "Old marks : "
                                                   << s[j].onPaper[subjectIndex]
                                                   << endl;

                                              cout << "New Marks : ";
                                              cin >> s[j].onPaper[subjectIndex];

                                              while(s[j].onPaper[subjectIndex] < 0 ||
                                                    s[j].onPaper[subjectIndex] > 80)
                                              {
                                                   cout << "Invalid marks! Enter between 0 and 80 : ";
                                                   cin >> s[j].onPaper[subjectIndex];
                                              }

                                              cout << "\nOn Paper Marks Updated!" << endl;
                                          }
                                          else
                                          {
                                              cout << "\nInvalid Choice!" << endl;
                                          }

                                         break;
                                      }
                                  }

                                  if(found == false)
                                  {
                                      cout << "\nStudent not found!" << endl;
                                  }

                                  break;
                              }

                              case 0:
                                  break;

                              default:
                                  cout << "\nInvalid Choice!" << endl;
                              }

                           } while(marksChoice != 0);

                           break;
                        }

                        case 3:
                        {
                            if(t[i].subject == "NOT SET")
                            {
                                cout << "\nPlease select a subject first!" << endl;
                                break;
                            }

                            if(studentCount == 0)
                            {
                                cout << "\nNo students available!" << endl;
                                break;
                            }

                            int subjectIndex = -1;

                            if(t[i].subject == "MA-102")
                                subjectIndex = 0;
                            else if(t[i].subject == "EN-102")
                                subjectIndex = 1;
                            else if(t[i].subject == "CS-111")
                                subjectIndex = 2;
                            else if(t[i].subject == "HS-107")
                                subjectIndex = 3;
                            else if(t[i].subject == "MT-101")
                                subjectIndex = 4;

                            int pass = 0;
                            int fail = 0;

                            cout << "\n==============================================" << endl;
                            cout << "             TEACHER RESULT" << endl;
                            cout << "==============================================" << endl;

                            cout << "SUBJECT : " << t[i].subject << endl;

                            cout << "\nTotal Student : " << studentCount << endl;

                            cout << "----------------------------------------------------------" << endl;

                            cout << "ROLL\tNAME\t\tINTERNAL\tON PAPER\tTOTAL" << endl;

                            cout << "----------------------------------------------------------" << endl;

                            for(int j = 0; j < studentCount; j++)
                            {
                               int total;

                               total = s[j].internal[subjectIndex]
                                     + s[j].onPaper[subjectIndex];

                               cout << s[j].id << "\t"
                                    << s[j].name << "\t\t"
                                    << s[j].internal[subjectIndex] << "\t\t"
                                    << s[j].onPaper[subjectIndex] << "\t\t"
                                    << total << endl;

                               if(total >= 40)
                               {
                                   pass++;
                               }
                               else
                               {
                                   fail++;
                               }
                            }

                            cout << "----------------------------------------------------------" << endl;

                            cout << "Pass : " << pass << endl;
                            cout << "Fail : " << fail << endl;

                            cout << "==============================================" << endl;

                            break;
                        }

                        case 0:
                            cout << "\nTEACHER LOGOUT SUCCESSFULLY!" << endl;
                            break;

                       default:
                            cout << "\nInvalid Choice!" << endl;
                       }

                    } while(teacherChoice != 0);

                    break;
                 }
             }

             if(found == false)
             {
                cout << "\nINVALID USERNAME OR PASSWORD!" << endl;
             }

             break;
          }

          case 2:
          {
             cout << "\n>> REGISTRATION" << endl;

             if(teacherCount >= 50)
             {
                cout << "Teacher limit reached!" << endl;
                break;
             }

             // Auto generated ID
             t[teacherCount].id = 111 + teacherCount;

             cout << "ID : "
                  << t[teacherCount].id
                  << " (auto gen)" << endl;

             cout << "NAME : ";
             cin >> t[teacherCount].name;

             cout << "SURNAME : ";
             cin >> t[teacherCount].lname;

             cout << "USERNAME : ";
             cin >> t[teacherCount].username;

             cout << "PASSWORD : ";
             cin >> t[teacherCount].pass;

             t[teacherCount].salary = 0;
             t[teacherCount].subject = "NOT SET";

             teacherCount++;

             cout << "\nACCOUNT CREATED SUCCESSFULLY!" << endl;

             break;
          }

          case 0:
             cout << "\n-- BACK MENU --" << endl;
             break;

          default:
             cout << "\nINVALID CHOICE!" << endl;
          }

       } while(teacherChoice != 0);
    }

    void student_portal()
    {
       int studentChoice;

       do
       {
          cout << "\n==================================" << endl;
          cout << "        <Student Portal>" << endl;
          cout << "==================================" << endl;

          cout << "1. LOGIN" << endl;
          cout << "0. BACK MENU" << endl;

          cout << "\nCHOICE : ";
          cin >> studentChoice;

          switch(studentChoice)
          {
          case 1:
          {
            int loginId;
            string loginPassword;
            bool found = false;

            cout << "\n>> STUDENT LOGIN" << endl;

            cout << "STUDENT ID : ";
            cin >> loginId;

            cout << "PASSWORD : ";
            cin >> loginPassword;

            for(int i = 0; i < studentCount; i++)
            {
                if(s[i].id == loginId &&
                   s[i].pass == loginPassword)
                {
                    found = true;

                    int choice;

                    do
                    {
                        cout << "\n==================================" << endl;
                        cout << "       >> WELCOME STUDENT!" << endl;
                        cout << "==================================" << endl;

                        cout << "NAME  : "
                             << s[i].name << " "
                             << s[i].surname << endl;

                        cout << "CLASS : "
                             << s[i].cls << endl;

                        cout << "\n<Student Portal>" << endl;
                        cout << "1. VIEW RESULT" << endl;
                        cout << "2. CHANGE PASSWORD" << endl;
                        cout << "0. LOGOUT" << endl;

                        cout << "\nCHOICE : ";
                        cin >> choice;

                        switch(choice)
                        {
                        case 1:
                        {
                            cout << "\n================ RESULT ================" << endl;

                            cout << "STUDENT ID : " << s[i].id << endl;
                            cout << "NAME       : "
                                 << s[i].name << " "
                                 << s[i].surname << endl;

                            cout << "FATHER NAME: "
                                 << s[i].fname << endl;

                            cout << "CLASS      : "
                                 << s[i].cls << endl;

                            cout << "\n------------------------------------------" << endl;

                            cout << "SUBJECT\t\tINTERNAL\tON PAPER\tTOTAL" << endl;

                            cout << "------------------------------------------" << endl;

                            string subjects[5] =
                            {
                                "MA-102",
                                "EN-102",
                                "CS-111",
                                "HS-107",
                                "MT-101"
                            };

                            int totalMarks = 0;

                            for(int j = 0; j < 5; j++)
                            {
                                int total;

                                total = s[i].internal[j]
                                      + s[i].onPaper[j];

                                cout << subjects[j] << "\t\t"
                                     << s[i].internal[j] << "\t\t"
                                     << s[i].onPaper[j] << "\t\t"
                                     << total << endl;

                                totalMarks = totalMarks + total;
                            }

                            cout << "------------------------------------------" << endl;

                            cout << "TOTAL MARKS : "
                                 << totalMarks << endl;

                            if(totalMarks >= 200)
                            {
                                cout << "RESULT      : PASS" << endl;
                            }
                            else
                            {
                                cout << "RESULT      : FAIL" << endl;
                            }

                            cout << "==========================================" << endl;

                            break;
                        }

                        case 2:
                        {
                            string oldPassword;
                            string newPassword;

                            cout << "\nEnter Old Password : ";
                            cin >> oldPassword;

                            if(oldPassword == s[i].pass)
                            {
                                cout << "Enter New Password : ";
                                cin >> newPassword;

                                s[i].pass = newPassword;

                                cout << "\nPassword Changed Successfully!" << endl;
                            }
                            else
                            {
                                cout << "\nWrong Old Password!" << endl;
                            }

                            break;
                        }

                        case 0:
                            cout << "\nSTUDENT LOGOUT SUCCESSFULLY!" << endl;
                            break;

                        default:
                            cout << "\nInvalid Choice!" << endl;
                        }

                    } while(choice != 0);

                    break;
                }
            }

            if(found == false)
            {
                cout << "\nINVALID STUDENT ID OR PASSWORD!" << endl;
            }

            break;
          }

          case 0:
             cout << "\n-- BACK MENU --" << endl;
             break;

          default:
             cout << "\nINVALID CHOICE!" << endl;
          }

       } while(studentChoice != 0);
    }

    void result_portal()
    {
        int resultChoice;

        do
        {
            cout << "\n==================================" << endl;
            cout << "          <Result Portal>" << endl;
            cout << "==================================" << endl;

            cout << "1. SEARCH RESULT" << endl;
            cout << "2. SHOW ALL RESULT" << endl;
            cout << "3. EDIT RESULT" << endl;
            cout << "0. BACK MENU" << endl;

            cout << "\nCHOICE : ";
            cin >> resultChoice;

            switch(resultChoice)
            {
            case 1:
            {
                int searchId;
                bool found = false;

                cout << "\n>> SEARCH RESULT" << endl;

                cout << "Enter Student ID : ";
                cin >> searchId;

                for(int i = 0; i < studentCount; i++)
                {
                    if(s[i].id == searchId)
                    {
                        found = true;

                        cout << "\n==================================" << endl;
                        cout << "          STUDENT RESULT" << endl;
                        cout << "==================================" << endl;

                        cout << "Student ID : "
                             << s[i].id << endl;

                        cout << "Name : "
                             << s[i].name << " "
                             << s[i].surname << endl;

                        cout << "\nSUBJECT\t\tINTERNAL\tON PAPER\tTOTAL"
                             << endl;

                        cout << "------------------------------------------------"
                             << endl;

                        string subjects[5] =
                        {
                            "MA-102",
                            "EN-102",
                            "CS-111",
                            "HS-107",
                            "MT-101"
                        };

                        int grandTotal = 0;
                        bool pass = true;

                        for(int j = 0; j < 5; j++)
                        {
                            int total;

                            total = s[i].internal[j]
                                  + s[i].onPaper[j];

                            cout << subjects[j] << "\t\t"
                                 << s[i].internal[j] << "\t\t"
                                 << s[i].onPaper[j] << "\t\t"
                                 << total << endl;

                            grandTotal = grandTotal + total;

                            if(total < 40)
                            {
                                pass = false;
                            }
                        }

                        cout << "------------------------------------------------"
                             << endl;

                        cout << "TOTAL : "
                             << grandTotal << " / 500"
                             << endl;

                        if(pass == true)
                        {
                            cout << "RESULT : PASS" << endl;
                        }
                        else
                        {
                            cout << "RESULT : FAIL" << endl;
                        }

                        cout << "==================================" << endl;

                        break;
                    }
                }

                if(found == false)
                {
                    cout << "\nStudent not found!" << endl;
                }

                break;
            }


            case 2:
            {
                if(studentCount == 0)
                {
                    cout << "\nNo student result available!" << endl;
                    break;
                }

                string subjects[5] =
                {
                    "MA-102",
                    "EN-102",
                    "CS-111",
                    "HS-107",
                    "MT-101"
                };

                cout << "\n========================================================"
                     << endl;

                cout << "                 ALL STUDENT RESULTS"
                     << endl;

                cout << "========================================================"
                     << endl;

                for(int i = 0; i < studentCount; i++)
                {
                    int grandTotal = 0;
                    bool pass = true;

                    cout << "\nStudent ID : "
                         << s[i].id << endl;

                    cout << "Name : "
                         << s[i].name << " "
                         << s[i].surname << endl;

                    cout << "\nSUBJECT\t\tTOTAL" << endl;
                    cout << "-----------------------------" << endl;

                    for(int j = 0; j < 5; j++)
                    {
                        int total;

                        total = s[i].internal[j]
                              + s[i].onPaper[j];

                        cout << subjects[j]
                             << "\t\t"
                             << total << endl;

                        grandTotal = grandTotal + total;

                        if(total < 40)
                        {
                            pass = false;
                        }
                    }

                    cout << "-----------------------------" << endl;

                    cout << "TOTAL : "
                         << grandTotal
                         << " / 500" << endl;

                    if(pass == true)
                    {
                        cout << "RESULT : PASS" << endl;
                    }
                    else
                    {
                        cout << "RESULT : FAIL" << endl;
                    }

                    cout << "========================================================"
                         << endl;
                }

                break;
            }


            case 3:
            {
                int searchId;
                int subjectChoice;
                int markChoice;
                int newMarks;
                bool found = false;

                cout << "\n>> EDIT RESULT" << endl;

                cout << "Enter Student ID : ";
                cin >> searchId;

                for(int i = 0; i < studentCount; i++)
                {
                    if(s[i].id == searchId)
                    {
                        found = true;

                        cout << "\nStudent Found!" << endl;

                        cout << "Name : "
                             << s[i].name << " "
                             << s[i].surname << endl;

                        cout << "\nSELECT SUBJECT" << endl;
                        cout << "1. MA-102" << endl;
                        cout << "2. EN-102" << endl;
                        cout << "3. CS-111" << endl;
                        cout << "4. HS-107" << endl;
                        cout << "5. MT-101" << endl;

                        cout << "\nCHOICE : ";
                        cin >> subjectChoice;

                        int subjectIndex = -1;

                        if(subjectChoice >= 1 &&
                           subjectChoice <= 5)
                        {
                            subjectIndex = subjectChoice - 1;
                        }
                        else
                        {
                            cout << "\nInvalid Subject Choice!" << endl;
                            break;
                        }

                        cout << "\nEDIT MARKS" << endl;
                        cout << "1. INTERNAL (20)" << endl;
                        cout << "2. ON PAPER (80)" << endl;

                        cout << "\nCHOICE : ";
                        cin >> markChoice;

                        if(markChoice == 1)
                        {
                            cout << "\nOld Internal Marks : "
                                 << s[i].internal[subjectIndex]
                                 << endl;

                            cout << "Enter New Internal Marks : ";
                            cin >> newMarks;

                            while(newMarks < 0 || newMarks > 20)
                            {
                                cout << "Enter marks between 0 and 20 : ";
                                cin >> newMarks;
                            }

                            s[i].internal[subjectIndex] = newMarks;

                            cout << "\nInternal Marks Updated Successfully!"
                                 << endl;
                        }
                        else if(markChoice == 2)
                        {
                            cout << "\nOld On Paper Marks : "
                                 << s[i].onPaper[subjectIndex]
                                 << endl;

                            cout << "Enter New On Paper Marks : ";
                            cin >> newMarks;

                            while(newMarks < 0 || newMarks > 80)
                            {
                                cout << "Enter marks between 0 and 80 : ";
                                cin >> newMarks;
                            }

                            s[i].onPaper[subjectIndex] = newMarks;

                            cout << "\nOn Paper Marks Updated Successfully!"
                                 << endl;
                        }
                        else
                        {
                            cout << "\nInvalid Choice!" << endl;
                        }

                        break;
                    }
                }

                if(found == false)
                {
                    cout << "\nStudent not found!" << endl;
                }

                break;
            }


            case 0:
                cout << "\n-- BACK MENU --" << endl;
                break;


            default:
                cout << "\nINVALID CHOICE!" << endl;
            }

        } while(resultChoice != 0);
    }
};

int main()
{
    int choice;
    Admin a;

    do
    {
        cout << "\n==================================" << endl;
        cout << "       WELCOME BACK TO SCHOOL" << endl;
        cout << "==================================" << endl;

        cout << "\nMENU:" << endl;
        cout << "1. ADMIN PORTAL" << endl;
        cout << "2. TEACHER PORTAL" << endl;
        cout << "3. STUDENT PORTAL" << endl;
        cout << "4. RESULT PORTAL" << endl;
        cout << "0. EXIT" << endl;

        cout << "\nCHOICE: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            a.admin_section();
            break;

        case 2:
            a.teacher_portal();
            break;

        case 3:
            a.student_portal();
            break;

        case 4:
            a.result_portal();
            break;

        case 0:
            cout << "\nTHANK YOU!" << endl;
            break;

        default:
            cout << "\nINVALID CHOICE!" << endl;
        }

    }while(choice != 0);

    return 0;
}
