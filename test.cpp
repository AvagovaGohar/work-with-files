#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main()
{
    string path = "C:\\Users\\ERNA\\OneDrive\\Рабочий стол\\test.txt";
    bool condition = true;
    do {
        cout << "who are you?\tteacher or student\n(for exit enter E):\t";
        string who;
        cin >> who;
        if (who == "teacher")
        {
            int count;
            std::ofstream input;
            input.open(path);
            if (input.is_open())
            {
                cout << "wich subject do you coose?\t(math, programming or english):\t";
                cin >> who;

                if (who == "math")
                {
                    input << "Math exam\n\n";
                    cout << "you should create 5 questions\n";
                    for (int i = 1; i < 6; i++)
                    {
                        string who2;
                        cout << "input question N" << i << std::endl;
                        input << "Question " << i << ":\n";
                        cin >> who;
                        std::getline(cin, who2);
                        who += who2;
                        who += "\n";
                        input << who;
                        cout << "how many answers?\t(2-4)\t";
                        cin >> count;
                        if (count >= 2 && count <= 4)
                        {
                            for (int j = 65; j < count + 65; j++)
                            {
                                cout << "answer " << (char)j << "\n";
                                input << (char)j << ") ";
                                cin >> who;
                                std::getline(cin, who2);
                                who += who2;
                                input << who;
                                input << "\n";
                            }char count2;
                            cout << "\nwich one is right?";
                            cin >> count2;
                            if ((char)count2 >= 65 && (char)count2 <= count + 65)
                            {
                                input << "N ";
                                input << (char)count2;
                                input << "\n";
                            }
                            else
                            {
                                condition = false;
                                cout << "there is no answer like that\n\n";
                                break;
                            }
                        }
                        else
                        {
                            cout << "not enough count of answers\n";
                            condition = false;
                        }
                    }
                    
                }
                else if (who == "programming")
                {
                    input << "Programming exam\n\n";
                    cout << "you should create 6 questions\n";
                    for (int i = 1; i < 7; i++)
                    {
                        string who2;
                        cout << "input question N" << i << std::endl;
                        input << "Question " << i << ":\n";
                        cin >> who;
                        std::getline(cin, who2);
                        who += who2;
                        who += "\n";
                        input << who;
                        cout << "how many answers?\t(2-4)\t";
                        cin >> count;

                        if (count >= 2 && count <= 4)
                        {
                            for (int j = 65; j < count + 65; j++)
                            {
                                cout << "answer " << (char)j << "\n";
                                input << (char)j << ") ";
                                cin >> who;
                                std::getline(cin, who2);
                                who += who2;
                                input << who;
                                input << "\n";
                            }
                            char count2;
                            cout << "\nwich one is right?";
                            cin >> count2;
                            if ((char)count2 >= 65 && (char)count2 <= count + 65)
                            {
                                input << "N ";
                                input << (char)count2;
                                input << "\n";
                            }
                            else
                            {
                                condition = false;
                                cout << "there is no answer like that\n\n";
                                break;
                            }
                        }
                        else
                        {
                            cout << "not enough count of answers\n";
                            condition = false;
                        }

                    }
                    
                }
                else if (who == "english")
                {
                    input << "English exam\n\n";
                    cout << "you should create 4 questions\n";
                    for (int i = 1; i < 5; i++)
                    {
                        string who2;
                        cout << "input question N" << i << std::endl;
                        input << "Question " << i << ":\n";
                        cin >> who;
                        std::getline(cin, who2);
                        who += who2;
                        who += "\n";
                        input << who;
                        cout << "how many answers?\t(2-4)\t";
                        cin >> count;
                        if (count >= 2 && count <= 4)
                        {
                            for (int j = 65; j < count + 65; j++)
                            {
                                cout << "answer " << (char)j << "\n";
                                input << (char)j << ") ";
                                cin >> who;
                                std::getline(cin, who2);
                                who += who2;
                                input << who;
                                input << "\n";
                            }char count2;
                            cout << "\nwich one is right?";
                            cin >> count2;
                            if ((char)count2 >= 65 && (char)count2 <= count + 65)
                            {
                                input << "N ";
                                input << (char)count2;
                                input << "\n";
                            }
                            else
                            {
                                condition = false;
                                cout << "there is no answer like that\n\n";
                                break;
                            }
                        }
                        else
                        {
                            cout << "not enough count of answers\n";
                            condition = false;
                        }
                    }
                    
                }
                else {
                    cout << "wrong answer\n";
                    condition = false;
                }
            }
            input.close();
        }
        else if (who == "student")
        {
            int allQuest;
            std::ifstream output;
            output.open(path);
            if (output.is_open())
            {
                std::getline(output, who);
                if (who == "English exam")
                {
                    allQuest = 4;
                }
                else if (who == "Math exam")
                {
                    allQuest = 5;
                }
                else if (who == "Programming exam")
                {
                    allQuest = 6;
                }
                std::getline(output, who);
                string all = "";
                int correctAnsw = 0;
                int y = 0;
                while (!output.eof())
                {
                    char tmp;
                    while (!output.eof())
                    {
                        output.get(tmp);
                        if (tmp !='N')
                        {
                            all += tmp;
                        }
                        else
                        {
                            output >> tmp;
                            cout << all << "Which is one correct?\n";
                            all = "";
                            char tm;
                            cin >> tm;
                            if (tm == tmp)
                            {
                                correctAnsw++;
                            }
                            y++;
                            break;
                        }
                        
                    }
                }if (y == allQuest)
                {
                    allQuest = correctAnsw * 10 / allQuest;
                    cout << "\n\nYOUR GRADE:  " << allQuest << "/10 \n\n";
                }
                else
                {
                    cout << "teacher wrote smt wrong\n\n";
                }
                

            }
            output.close();
        }
        else if (who == "E")
        {
            condition = false;
        }
        else
        {
            cout << "wrong order\n";
            condition = false;

        }
    } while (condition);
}
