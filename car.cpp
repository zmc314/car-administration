#include "car.h"

void car::set_car(string n, string l, string m, string b, double t, double f, double rm, int bm)
{
    basic_maintenance = bm;                 //根据每种不同的车型设置不同的金额
    cout << "请输入车辆编号：";
    cin >> n;
    number = n;
    cout << "请输入车牌号：";
    cin >> l;
    license_plate = l;
    cout << "请输入车辆制造公司：";
    cin >> m;
    Manufacturing_company = m;
    while (1)
    {
        cout << "请输入购买日期(YYYY-MM-DD)：";
        cin >> b;
        /*检测日期格式*/
        if (b.size() == 10)
        {
            int year,month,day;
            year = (b[0]-'0') * 1000 + (b[1] - '0') * 100 + (b[2] - '0') * 10 + (b[3] - '0');
            month = (b[5] - '0') * 10 + (b[6] - '0');
            day = (b[8] - '0') * 10 + (b[9] - '0');
            b[4] = b[7] = '-';
            if (year >= 1886&&year<=2021)
            {
                if (month > 0 && month <= 12)
                {
                    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                    {
                        if (day > 0 && day <= 31)
                        {
                            break;
                        }
                    }
                    if (month == 4 || month == 6 || month == 9 || month == 11)
                    {
                        if (day > 0 && day <= 30)
                        {
                            break;
                        }
                    }
                    if (month == 2 && (year % 4 == 0 && year % 400 != 0))
                    {
                        if (day > 0 && day <= 29)
                        {
                            break;
                        }
                    }
                    else
                    {
                        if (day > 0 && day <= 29)
                        {
                            break;
                        }
                    }
                }
            }
            cout << "请输入正确的日期！"<<endl;
        }
        
    }
    
    buy_time = b;
    cout << "请输入总公里数：";
    cin >> t;
    total = t;
    cout << "请输入百公里耗油量（升）：";
    cin >> f;
    Fuel_consumption = f;
    cout << "请输入道路维护费用：";
    cin >> rm;
    road_maintenance = rm;
}

int car::get_buy_time_day() {
    int year, month, day;
    year = (buy_time[0] - '0') * 1000 + (buy_time[1] - '0') * 100 + (buy_time[2] - '0') * 10 + (buy_time[3] - '0');
    month = (buy_time[5] - '0') * 10 + (buy_time[6] - '0');
    day = (buy_time[8] - '0') * 10 + (buy_time[9] - '0');
    return (year - 1) * 365 + (month - 1) * 30 + day;
}

double bus::Calculate_Money() {
    return 7.79 * get_Fuel_consumption() + get_basic_maintenance();
}

double minibus::Calculate_Money() {
    return 7.79 * get_Fuel_consumption() + get_basic_maintenance();
}

double truck::Calculate_Money() {
    return 7.79 * get_Fuel_consumption() + get_basic_maintenance();
}

minibus::minibus()
{
    car_case = 0;
}
