#include <iostream>
#include <cstdlib>
#include<fstream>
#include<iomanip>
#include "car.h"

#pragma warning(disable:4996)

#define Max_size 10

using namespace std;

void interface_show();
void show_bus_data_basement(bus* bus_cur);
void show_minibus_data_basement(minibus* minibus_cur);
void show_truck_data_basement(truck* truck_cur);
int get_bus_quantity(bus* bus_cur);
int get_minibus_quantity(minibus* minibus_cur);
int get_truck_quantity(truck* bus_cur);
void query_show();
int show_bus_Manufacturing_company_data_basement(bus* bus_cur, string mc);
int show_minibus_Manufacturing_company_data_basement(minibus* minibus_cur, string mc);
int show_truck_Manufacturing_company_data_basement(truck* truck_cur, string mc);
int show_bus_number_data_basement(bus* bus_cur, string n);
int show_minibus_number_data_basement(minibus* minibus_cur, string n);
int show_truck_number_data_basement(truck* truck_cur, string n);
int show_busdata_basement(bus* bus_cur);
int show_minibusdata_basement(minibus* minibus_cur);
int show_truckdata_basement(truck* truck_cur);
void bus_revise_show();
void minibus_revise_show();
void truck_revise_show();

int main()
{
    //登陆界面
    ifstream account_input;
    account_input.open("D:\\account.dat", ios::in);
    string account[Max_size];
    string password[Max_size];
    for (int i = 0; i < Max_size; i++)
    {
        string temp;
        account_input >> temp;
        if (temp == "end");
        {
            break;
        }
        account[i] = temp;
        account_input >> temp;
        password[i] = temp;
    }
    account_input.close();
    while (1)
    {
        system("cls");
        
        string user_account;
        string user_password;
        int mode;
        cout << "请选择模式：" << endl;
        cout << "1. 新用户注册" << endl;
        cout << "2. 用户登录" << endl;
        cout << "请输入数字选择功能：";
        cin >> mode;
        if (mode == 1)
        {
            ofstream account_output;
            account_output.open("D:\\account.dat", ios::out);
            cout << "请输入用户名：";
            cin >> user_account;
            cout << "请输入密码：";
            cin >> user_password;
            int set = 0;
            for (; account[set].size() != 0; set++);
            account[set] = user_account;
            password[set] = user_password;
            cout << set;
            system("pause");
            for (int i = 0; account[i].size() != 0; i++)
            {
                account_output << account[i] << endl;
                account_output << password[i] << endl;
            }
            account_output << "end";
        }
        if (mode == 2)
        {
            cout << "请输入用户名：";
            cin >> user_account;
            cout << "请输入密码：";
            cin >> user_password;
            int flag = 0;
            for (int i = 0; i < Max_size; i++)
            {
                if (user_account == account[i] && user_password == password[i])
                {
                    flag = 1;
                }
            }
            if (flag)
            {
                break;
            }
        }
    }
    bus bus_member[Max_size];           //当成数组类储存方式
    minibus minibus_member[Max_size];
    truck truck_member[Max_size];
    int choice = 0;
    while (1)
    {
        system("cls");
        interface_show();
        cin >> choice;
        if (choice == 1)//添加车辆
        {
            system("cls");
            int choose;
            cout << "请选择添加车辆类型\n"
                "1. 客车\n"
                "2. 小客车\n"
                "3. 卡车\n" << endl;
            cin >> choose;
            if (choose == 1)
            {
                int i = 0;
                while (bus_member[i].get_number() != "0")
                    i++;
                /*用循环检测是否有重复的车辆编号*/
                while (1)
                {
                    int j;
                    bus_member[i].set_bus();
                    for (j = 0; j < Max_size; j++)
                    {
                        if (i == j)
                        {
                            if (minibus_member[j].get_number() == bus_member[i].get_number())
                                break;
                            if (truck_member[j].get_number() == bus_member[i].get_number())
                                break;
                        }
                        else
                        {
                            if (bus_member[j].get_number() == bus_member[i].get_number())
                                break;
                            if (minibus_member[j].get_number() == bus_member[i].get_number())
                                break;
                            if (truck_member[j].get_number() == bus_member[i].get_number())
                                break;
                        }
                    }
                    if (j == Max_size)
                        break;
                    else
                        cout << "车辆编号已存在，请重新输入！" << endl;
                }
            }
            if (choose == 2)
            {
                int i = 0;
                while (minibus_member[i].get_number() != "0")
                    i++;
                while (1)
                {
                    int j;
                    minibus_member[i].set_minibus();
                    for (j = 0; j < Max_size; j++)
                    {
                        if (i == j)
                        {
                            if (bus_member[j].get_number() == minibus_member[i].get_number())
                                break;
                            if (truck_member[j].get_number() == minibus_member[i].get_number())
                                break;
                        }
                        else
                        {
                            if (bus_member[j].get_number() == minibus_member[i].get_number())
                                break;
                            if (minibus_member[j].get_number() == minibus_member[i].get_number())
                                break;
                            if (truck_member[j].get_number() == minibus_member[i].get_number())
                                break;
                        }
                    }
                    if (j == Max_size)
                        break;
                    else
                        cout << "车辆编号已存在，请重新输入！" << endl;
                }
            }
            if (choose == 3)
            {
                int i = 0;
                while (truck_member[i].get_number() != "0")
                    i++;
                while (1)
                {
                    int j;
                    truck_member[i].set_truck();
                    for (j = 0; j < Max_size; j++)
                    {
                        if (i == j)
                        {
                            if (minibus_member[j].get_number() == truck_member[i].get_number())
                                break;
                            if (bus_member[j].get_number() == truck_member[i].get_number())
                                break;
                        }
                        else
                        {
                            if (bus_member[j].get_number() == truck_member[i].get_number())
                                break;
                            if (minibus_member[j].get_number() == truck_member[i].get_number())
                                break;
                            if (truck_member[j].get_number() == truck_member[i].get_number())
                                break;
                        }
                    }
                    if (j == Max_size)
                        break;
                    else
                        cout << "车辆编号已存在，请重新输入！" << endl;
                }
            }
            else
            {
                cout << "请输入正确的编号！" << endl;
            }
        }
        else if (choice == 2)//查询车辆
        {
            system("cls");
            int chose;
            query_show();
            cin >> chose;
            /*按车辆制造公司查询*/
            if (chose == 1)
            {
                cout << "请输入公司名称：";
                string company;
                cin >> company;
                int quantity=0;
                bus* bus_cp;
                bus_cp = bus_member;
                minibus* minibus_cp;
                minibus_cp = minibus_member;
                truck* truck_cp;
                truck_cp = truck_member;
                quantity += show_bus_Manufacturing_company_data_basement(bus_cp, company);
                quantity += show_minibus_Manufacturing_company_data_basement(minibus_cp, company);
                quantity += show_truck_Manufacturing_company_data_basement(truck_cp, company);
                if (quantity == 0)
                    cout << "该车辆制造公司不存在！" << endl;
                cout << "Please enter any keys to continue..." << endl;
                system("pause");
                system("cls");
            }
            /*按编号查询*/
            if (chose == 2) 
            {
                cout << "请输入车辆编号：";
                string car_number;
                cin >> car_number;
                int quantity = 0;
                bus* bus_cp;
                bus_cp = bus_member;
                minibus* minibus_cp;
                minibus_cp = minibus_member;
                truck* truck_cp;
                truck_cp = truck_member;
                quantity += show_bus_number_data_basement(bus_cp, car_number);
                quantity += show_minibus_number_data_basement(minibus_cp, car_number);
                quantity += show_truck_number_data_basement(truck_cp, car_number);
                if (quantity == 0)
                    cout << "该编号不存在！" << endl;
                cout << "Please enter any keys to continue..." << endl;
                system("pause");
                system("cls");
            }
            /*按类别查询*/
            if (chose == 3)
            {
                int nothing = 0;
                system("cls");
                int choose;
                cout << "请选择车辆种类:\n"
                    "1. 客车\n"
                    "2. 小客车\n"
                    "3. 卡车\n" << endl;
                cin >> choose;
                if (choose == 1)
                {
                    bus* bus_cp;
                    bus_cp = bus_member;
                    nothing = show_busdata_basement(bus_cp);
                    cout << "Please enter any keys to continue..." << endl;
                    system("pause");
                    system("cls");
                }
                else if (choose == 2)
                {
                    minibus* minibus_cp;
                    minibus_cp = minibus_member;
                    nothing = show_minibusdata_basement(minibus_cp);
                    cout << "Please enter any keys to continue..." << endl;
                    system("pause");
                    system("cls");
                }
                else if (choose == 3)
                {
                    truck* truck_cp;
                    truck_cp = truck_member;
                    nothing = show_truckdata_basement(truck_cp);
                    cout << "Please enter any keys to continue..." << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (choice == 3)//显示车辆信息库
        {
            system("cls");
            int number = 0;
            for (int i = 0; bus_member[i].get_number() != "0"; i++, number++);
            for (int i = 0; minibus_member[i].get_number() != "0"; i++, number++);
            for (int i = 0; minibus_member[i].get_number() != "0"; i++, number++);
            if (number != 0)
            {
                bus* bus_cp;
                bus_cp = bus_member;
                show_bus_data_basement(bus_cp);
                minibus* minibus_cp;
                minibus_cp = minibus_member;
                show_minibus_data_basement(minibus_cp);
                truck* truck_cp;
                truck_cp = truck_member;
                show_truck_data_basement(truck_cp);
            }
            else
            {
                cout << "车辆信息库为空！" << endl;
            }
            cout << "Please enter any keys to continue..." << endl;
            system("pause");
            system("cls");
        }
        else if (choice == 4)//编辑功能
        {
            /*因为只有编号具有唯一性*/
            string n;
            cout << "请输入编号：";
            cin >> n;
            int i;
            for (i = 0; i < Max_size; i++)
            {
                
                if (bus_member[i].get_number() == n)
                {
                    system("cls");
                    bus_revise_show();
                    int choose;
                    cin >> choose;
                    if (choose == 1)
                    {
                        while (1)
                        {
                            string n;
                            cout << "请输入车辆编号：";
                            cin >> n;
                            bus_member[i].set_number(n);
                            int j;
                            for (j = 0; j < Max_size; j++)
                            {
                                if (i == j)
                                {
                                    if (minibus_member[j].get_number() == bus_member[i].get_number())
                                        break;
                                    if (truck_member[j].get_number() == bus_member[i].get_number())
                                        break;
                                }
                                else
                                {
                                    if (bus_member[j].get_number() == bus_member[i].get_number())
                                        break;
                                    if (minibus_member[j].get_number() == bus_member[i].get_number())
                                        break;
                                    if (truck_member[j].get_number() == bus_member[i].get_number())
                                        break;
                                }
                            }
                            if (j == Max_size)
                                break;
                            else
                                cout << "车辆编号已存在，请重新输入！" << endl;
                        }
                        break;
                    }
                    else if (choose == 2)
                    {
                        string lp;
                        cout << "请输入车牌号：";
                        cin >> lp;
                        bus_member[i].set_license_plate(lp);
                        break;
                    }
                    else if (choose == 3)
                    {
                        string mc;
                        cout << "请输入车辆制造公司：";
                        cin >> mc;
                        bus_member[i].set_Manufacturing_company(mc);
                        break;
                    }
                    else if (choose == 4)
                    {
                        string bt;
                        cout << "请输入购买时间：";
                        cin >> bt;
                        bus_member[i].set_buy_time(bt);
                        break;
                    }
                    else if (choose == 5)
                    {
                        double total;
                        cout << "请输入总公里数：";
                        cin >> total;
                        bus_member[i].set_total(total);
                        break;
                    }
                    else if (choose == 6)
                    {
                        double fc;
                        cout << "请输入每百公里耗油量：";
                        cin >> fc;
                        bus_member[i].set_Fuel_consumption(fc);
                        bus_member[i].set_total_rents(bus_member[i].Calculate_Money());
                        break;
                    }
                    else if (choose == 7)
                    {
                        double rm;
                        cout << "请输入道路维修费用：";
                        cin >> rm;
                        bus_member[i].set_road_maintenance(rm);
                        break;
                    }
                    else if (choose == 8)
                    {
                        int c;
                        cout << "请输入载客数：";
                        cin >> c;
                        bus_member[i].set_capacity(c);
                        break;
                    }
                    else
                    {
                        cout << "请输入正确的编号！" << endl;
                        cout << "Please enter any keys to continue..." << endl;
                        system("pause");
                        system("cls");
                    }
                }
                else if (minibus_member[i].get_number() == n)
                {
                    system("cls");
                    minibus_revise_show();
                    int choose;
                    cin >> choose;
                    if (choose == 1)
                    {
                        while (1)
                        {
                            string n;
                            cout << "请输入车辆编号：";
                            cin >> n;
                            minibus_member[i].set_number(n);
                            int j;
                            for (j = 0; j < Max_size; j++)
                            {
                                if (i == j)
                                {
                                    if (bus_member[j].get_number() == minibus_member[i].get_number())
                                        break;
                                    if (truck_member[j].get_number() == minibus_member[i].get_number())
                                        break;
                                }
                                else
                                {
                                    if (bus_member[j].get_number() == minibus_member[i].get_number())
                                        break;
                                    if (minibus_member[j].get_number() == minibus_member[i].get_number())
                                        break;
                                    if (truck_member[j].get_number() == minibus_member[i].get_number())
                                        break;
                                }
                            }
                            if (j == Max_size)
                                break;
                            else
                                cout << "车辆编号已存在，请重新输入！" << endl;
                        }
                        break;
                    }
                    else if (choose == 2)
                    {
                        string lp;
                        cout << "请输入车牌号：";
                        cin >> lp;
                        minibus_member[i].set_license_plate(lp);
                        break;
                    }
                    else if (choose == 3)
                    {
                        string mc;
                        cout << "请输入车辆制造公司：";
                        cin >> mc;
                        minibus_member[i].set_Manufacturing_company(mc);
                        break;
                    }
                    else if (choose == 4)
                    {
                        string bt;
                        cout << "请输入购买时间：";
                        cin >> bt;
                        minibus_member[i].set_buy_time(bt);
                        break;
                    }
                    else if (choose == 5)
                    {
                        double total;
                        cout << "请输入总公里数：";
                        cin >> total;
                        minibus_member[i].set_total(total);
                        break;
                    }
                    else if (choose == 6)
                    {
                        double fc;
                        cout << "请输入每百公里耗油量：";
                        cin >> fc;
                        minibus_member[i].set_Fuel_consumption(fc);
                        minibus_member[i].set_total_rents(minibus_member[i].Calculate_Money());
                        break;
                    }
                    else if (choose == 7)
                    {
                        double rm;
                        cout << "请输入道路维修费用：";
                        cin >> rm;
                        minibus_member[i].set_road_maintenance(rm);
                        break;
                    }
                    else if (choose == 8)
                    {
                        int cc;
                        cout << "请输入车箱数：";
                        cin >> cc;
                        minibus_member[i].set_car_case(cc);
                        break;
                    }
                    else
                    {
                        cout << "请输入正确的编号！" << endl;
                        cout << "Please enter any keys to continue..." << endl;
                        system("pause");
                        system("cls");
                    }
                }
                else if (truck_member[i].get_number() == n)
                {
                    system("cls");
                    truck_revise_show();
                    int choose;
                    cin >> choose;
                    if (choose == 1)
                    {
                        while (1)
                        {
                            string n;
                            cout << "请输入车辆编号：";
                            cin >> n;
                            truck_member[i].set_number(n);
                            int j;
                            for (j = 0; j < Max_size; j++)
                            {
                                if (i == j)
                                {
                                    if (minibus_member[j].get_number() == truck_member[i].get_number())
                                        break;
                                    if (bus_member[j].get_number() == truck_member[i].get_number())
                                        break;
                                }
                                else
                                {
                                    if (bus_member[j].get_number() == truck_member[i].get_number())
                                        break;
                                    if (minibus_member[j].get_number() == truck_member[i].get_number())
                                        break;
                                    if (truck_member[j].get_number() == truck_member[i].get_number())
                                        break;
                                }
                            }
                            if (j == Max_size)
                                break;
                            else
                                cout << "车辆编号已存在，请重新输入！" << endl;
                        }
                        break;
                    }
                    else if (choose == 2)
                    {
                        string lp;
                        cout << "请输入车牌号：";
                        cin >> lp;
                        truck_member[i].set_license_plate(lp);
                        break;
                    }
                    else if (choose == 3)
                    {
                        string mc;
                        cout << "请输入车辆制造公司：";
                        cin >> mc;
                        truck_member[i].set_Manufacturing_company(mc);
                        break;
                    }
                    else if (choose == 4)
                    {
                        string bt;
                        cout << "请输入购买时间：";
                        cin >> bt;
                        truck_member[i].set_buy_time(bt);
                        break;
                    }
                    else if (choose == 5)
                    {
                        double total;
                        cout << "请输入总公里数：";
                        cin >> total;
                        truck_member[i].set_total(total);
                        break;
                    }
                    else if (choose == 6)
                    {
                        double fc;
                        cout << "请输入每百公里耗油量：";
                        cin >> fc;
                        truck_member[i].set_Fuel_consumption(fc);
                        truck_member[i].set_total_rents(truck_member[i].Calculate_Money());
                        break;
                    }
                    else if (choose == 7)
                    {
                        double rm;
                        cout << "请输入道路维修费用：";
                        cin >> rm;
                        truck_member[i].set_road_maintenance(rm);
                        break;
                    }
                    else if (choose == 8)
                    {
                        int ld;
                        cout << "请输入载重量：";
                        cin >> ld;
                        truck_member[i].set_load(ld);
                        break;
                    }
                    else if (choose == 9)
                    {
                        int dw;
                        cout << "请输入自重：";
                        cin >> dw;
                        truck_member[i].set_deadweight(dw);
                        break;
                    }
                    else
                    {
                        cout << "请输入正确的编号！" << endl;
                        cout << "Please enter any keys to continue..." << endl;
                        system("pause");
                        system("cls");
                    }
                }
            }
            if (i == Max_size)
                cout << "此编号没有对应的车辆！" << endl;
            else
                cout << "修改成功！" << endl;
            cout << "Please enter any keys to continue..." << endl;
            system("pause");
            system("cls");
        }
        else if (choice == 5)//删除车辆
        {
            system("cls");
            int bus_quantity;
            bus* bus_cp;
            bus_cp = bus_member;
            bus_quantity = get_bus_quantity(bus_cp);
            int minibus_quantity;
            minibus* minibus_cp;
            minibus_cp = minibus_member;
            minibus_quantity = get_minibus_quantity(minibus_cp);
            int truck_quantity;
            truck* truck_cp;
            truck_cp = truck_member;
            truck_quantity = get_truck_quantity(truck_cp);
            int sum = bus_quantity + minibus_quantity + truck_quantity;
            if (sum == 0)
            {
                cout << "车辆信息库为空" << endl;
                cout << "Please enter any keys to continue..." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                string car_number;
                cout << "请输入想要删除的车辆编号：";
                cin >> car_number;
                int i = 0;
                for (; i < Max_size; i++)
                {
                    if (bus_member[i].get_number() == car_number)
                    {
                        for (int j = i; j < Max_size - 1; j++) {
                            bus_member[j] = bus_member[j + 1];
                        }
                        break;
                    }
                    if (minibus_member[i].get_number() == car_number)
                    {
                        for (int j = i; j < Max_size - 1; j++) {
                            minibus_member[j] = minibus_member[j + 1];
                        }
                        break;
                    }
                    if (truck_member[i].get_number() == car_number)
                    {
                        for (int j = i; j < Max_size - 1; j++) {
                            truck_member[j] = truck_member[j + 1];
                        }
                        break;
                    }
                }
                if (i == Max_size)
                {
                    cout << "该编号不存在！" << endl;
                    cout << "Please enter any keys to continue..." << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (choice == 6)//统计信息
        {
            system("cls");
            int bus_quantity;
            bus* bus_cp;
            bus_cp = bus_member;
            bus_quantity = get_bus_quantity(bus_cp);
            int minibus_quantity;
            minibus* minibus_cp;
            minibus_cp = minibus_member;
            minibus_quantity = get_minibus_quantity(minibus_cp);
            int truck_quantity;
            truck* truck_cp;
            truck_cp = truck_member;
            truck_quantity = get_truck_quantity(truck_cp);
            int sum = bus_quantity + minibus_quantity + truck_quantity;
            cout << "车辆总数：" << sum << "辆" << endl;
            cout << "客车总数：" << bus_quantity << "辆" << endl;
            cout << "小轿车总数：" << minibus_quantity << "辆" << endl;
            cout << "卡车总数：" << truck_quantity << "辆" << endl;
            cout << "Please enter any keys to continue..." << endl;
            system("pause");
            system("cls");
        }
        else if (choice == 7)//车辆信息存盘
        {
            ofstream storage;
            storage.open("D:\\storage.dat", ios::out|ios::binary);
            if (!storage)
            {
                cout<<"文件打开失败！"<<endl;
                exit(0);
            }
            bus* bus_cp;
            bus_cp = bus_member;
            minibus* minibus_cp;
            minibus_cp = minibus_member;
            truck* truck_cp;
            truck_cp = truck_member;
            /*先获取每种车有几辆*/
            int bus_AOI = get_bus_quantity(bus_cp);
            int minibus_AOI = get_minibus_quantity(minibus_cp);
            int truck_AOI = get_truck_quantity(truck_cp);
            /*先输出客车信息*/
            storage << "bus:" << endl;
            for (int i = 0; i < bus_AOI; i++)
            {
                storage << bus_member[i].get_number() << endl;
                storage << bus_member[i].get_license_plate() << endl;
                storage << bus_member[i].get_Manufacturing_company() << endl;
                storage << bus_member[i].get_buy_time() << endl;
                storage << bus_member[i].get_total() << endl;
                storage << bus_member[i].get_Fuel_consumption() << endl;
                storage << bus_member[i].get_road_maintenance() << endl;
                storage << bus_member[i].get_capacity() << endl;
            }
            storage << "minibus:" << endl;
            for (int i = 0; i < minibus_AOI; i++)
            {
                storage << minibus_member[i].get_number() << endl;
                storage << minibus_member[i].get_license_plate() << endl;
                storage << minibus_member[i].get_Manufacturing_company() << endl;
                storage << minibus_member[i].get_buy_time() << endl;
                storage << minibus_member[i].get_total() << endl;
                storage << minibus_member[i].get_Fuel_consumption() << endl;
                storage << minibus_member[i].get_road_maintenance() << endl;
                storage << minibus_member[i].get_car_case() << endl;
            }
            storage << "truck:" << endl;
            for (int i = 0; i < truck_AOI; i++)
            {
                storage << truck_member[i].get_number() << endl;
                storage << truck_member[i].get_license_plate() << endl;
                storage << truck_member[i].get_Manufacturing_company() << endl;
                storage << truck_member[i].get_buy_time() << endl;
                storage << truck_member[i].get_total() << endl;
                storage << truck_member[i].get_Fuel_consumption() << endl;
                storage << truck_member[i].get_road_maintenance() << endl;
                storage << truck_member[i].get_load() << endl;
                storage << truck_member[i].get_deadweight() << endl;
            }
            storage << "end" << endl;
            cout << "信息存储成功！" << endl;
            cout << "Please enter any keys to continue..." << endl;
            system("pause");
            system("cls");
        }
        else if (choice == 8)//读出车辆信息
        {
            string in_str;
            int in_int;
            double in_double;
            ifstream input;
            input.open("D:\\storage.dat", ios::in|ios::binary);
            input >> in_str;
            if (in_str == "bus:")
            {
                input >> in_str;
                int i = 0;
                while (in_str != "minibus:")
                {
                    bus_member[i].set_basic_maintenance(2000);
                    bus_member[i].set_number(in_str);
                    input >> in_str;
                    bus_member[i].set_license_plate(in_str);
                    input >> in_str;
                    bus_member[i].set_Manufacturing_company(in_str);
                    input >> in_str;
                    bus_member[i].set_buy_time(in_str);
                    input >> in_double;
                    bus_member[i].set_total(in_double);
                    input >> in_double;
                    bus_member[i].set_Fuel_consumption(in_double);
                    input >> in_double;
                    bus_member[i].set_road_maintenance(in_double);
                    input >> in_int;
                    bus_member[i].set_capacity(in_int);
                    bus_member[i].set_total_rents(bus_member[i].Calculate_Money());
                    i++;
                    input >> in_str;
                }
                input >> in_str;
                i = 0;
                while (in_str != "truck:")
                {
                    minibus_member[i].set_basic_maintenance(1000);
                    minibus_member[i].set_number(in_str);
                    input >> in_str;
                    minibus_member[i].set_license_plate(in_str);
                    input >> in_str;
                    minibus_member[i].set_Manufacturing_company(in_str);
                    input >> in_str;
                    minibus_member[i].set_buy_time(in_str);
                    input >> in_double;
                    minibus_member[i].set_total(in_double);
                    input >> in_double;
                    minibus_member[i].set_Fuel_consumption(in_double);
                    input >> in_double;
                    minibus_member[i].set_road_maintenance(in_double);
                    input >> in_int;
                    minibus_member[i].set_car_case(in_int);
                    minibus_member[i].set_total_rents(minibus_member[i].Calculate_Money());
                    i++;
                    input >> in_str;
                }
                input >> in_str;
                i = 0;
                while (in_str != "end")
                {
                    truck_member[i].set_basic_maintenance(1500);
                    truck_member[i].set_number(in_str);
                    input >> in_str;
                    truck_member[i].set_license_plate(in_str);
                    input >> in_str;
                    truck_member[i].set_Manufacturing_company(in_str);
                    input >> in_str;
                    truck_member[i].set_buy_time(in_str);
                    input >> in_double;
                    truck_member[i].set_total(in_double);
                    input >> in_double;
                    truck_member[i].set_Fuel_consumption(in_double);
                    input >> in_double;
                    truck_member[i].set_road_maintenance(in_double);
                    input >> in_int;
                    truck_member[i].set_load(in_int);
                    input >> in_int;
                    truck_member[i].set_deadweight(in_int);
                    truck_member[i].set_total_rents(truck_member[i].Calculate_Money());
                    i++;
                    input >> in_str;
                }
            }
            else
            {
                cout << "此文件中没有存储车辆！" << endl;
            }
            cout << "Please enter any keys to continue..." << endl;
            system("pause");
            system("cls");
        }
        else if (choice == 9) /*计算车辆性价比——推荐高性价比车辆*/
        {
        double bus_price[Max_size];
        double minibus_price[Max_size];
        double truck_price[Max_size];
        int days;
        time_t nowtime;
        struct tm* p;
        time(&nowtime);
        p = localtime(&nowtime);
        days = (p->tm_year - 1) * 365 + (p->tm_mon - 1) * 30 + p->tm_mday;
        for (int i = 0; bus_member[i].get_number() != "0"; i++)
        {
            bus_price[i] = (bus_member[i].get_total() + bus_member[i].get_capacity()) / ((bus_member[i].get_Fuel_consumption() + (bus_member[i].get_road_maintenance()/100))*(log(days-bus_member[i].get_buy_time_day()/100000)));
        }
        for (int i = 0; minibus_member[i].get_number() != "0"; i++)
        {
            minibus_price[i] = (minibus_member[i].get_total() + minibus_member[i].get_car_case()) / ((minibus_member[i].get_Fuel_consumption() + (minibus_member[i].get_road_maintenance() / 100)) * (log(days - minibus_member[i].get_buy_time_day()/100000)));
        }
        for (int i = 0; truck_member[i].get_number() != "0"; i++)
        {
            truck_price[i] = (truck_member[i].get_total() + (truck_member[i].get_load()/1000)) / ((truck_member[i].get_Fuel_consumption() + (truck_member[i].get_deadweight()/1000) + (truck_member[i].get_road_maintenance() / 100))*(log(days - truck_member[i].get_buy_time_day()/100000)));
        }
        for (int i = 0; bus_member[i].get_number() != "0"; i++)
        {
            int max = i;
            double temp_price;
            bus temp;
            for (int j = i + 1; bus_member[j].get_number() != "0"; j++)
            {
                if (bus_price[j] > bus_price[i])
                {
                    max = j;
                }
            }
            if (max != i)
            {
                temp = bus_member[max];
                bus_member[max] = bus_member[i];
                bus_member[i] = temp;
                temp_price = bus_price[max];
                bus_price[max] = bus_price[i];
                bus_price[i] = temp_price;
            }
        }
        for (int i = 0; minibus_member[i].get_number() != "0"; i++)
        {
            int max = i;
            double temp_price;
            minibus temp;
            for (int j = i + 1; minibus_member[j].get_number() != "0"; j++)
            {
                if (minibus_price[j] > minibus_price[i])
                {
                    max = j;
                }
            }
            if (max != i)
            {
                temp = minibus_member[max];
                minibus_member[max] = minibus_member[i];
                minibus_member[i] = temp;
                temp_price = minibus_price[max];
                minibus_price[max] = minibus_price[i];
                minibus_price[i] = temp_price;
            }
        }
        for (int i = 0; truck_member[i].get_number() != "0"; i++)
        {
            int max = i;
            double temp_price;
            truck temp;
            for (int j = i + 1; truck_member[j].get_number() != "0"; j++)
            {
                if (truck_price[j] > truck_price[i])
                {
                    max = j;
                }
            }
            if (max != i)
            {
                temp = truck_member[max];
                truck_member[max] = truck_member[i];
                truck_member[i] = temp;
                temp_price = truck_price[max];
                truck_price[max] = truck_price[i];
                truck_price[i] = temp_price;
            }
        }
        cout << "车辆性价比已分析完成！\n";
        cout << "Please enter any keys to continue..." << endl;
        system("pause");
        system("cls");
        int number = 0;
        for (int i = 0; bus_member[i].get_number() != "0"; i++, number++);
        for (int i = 0; minibus_member[i].get_number() != "0"; i++, number++);
        for (int i = 0; minibus_member[i].get_number() != "0"; i++, number++);
        if (number != 0)
        {
            bus* bus_cp;
            bus_cp = bus_member;
            show_bus_data_basement(bus_cp);
            minibus* minibus_cp;
            minibus_cp = minibus_member;
            show_minibus_data_basement(minibus_cp);
            truck* truck_cp;
            truck_cp = truck_member;
            show_truck_data_basement(truck_cp);
        }
        else
        {
            cout << "车辆信息库为空！" << endl;
        }
        cout << "Please enter any keys to continue..." << endl;
        system("pause");
        system("cls");
        }
        else if (choice == 10)//退出
        {
            system("cls");
            cout << "Please enter any keys to continue..." << endl;
            break;
        }
        else
        {
            cout << "请输入正确的编号！" << endl;
            cout << "Please enter any keys to continue..." << endl;
            system("pause");
            system("cls");
        }
    }

    return 0;
}