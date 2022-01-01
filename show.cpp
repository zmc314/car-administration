#include"car.h"

void interface_show()
{
    cout << "************************************************" << endl;
    cout << "*1. 增加车辆                                   *" << endl;
    cout << "*2. 查询车辆                                   *" << endl;
    cout << "*3. 展示车辆信息库                             *" << endl;
    cout << "*4. 编辑车辆                                   *" << endl;
    cout << "*5. 删除车辆                                   *" << endl;
    cout << "*6. 统计车辆信息                               *" << endl;
    cout << "*7. 车辆信息存盘                               *" << endl;
    cout << "*8. 读取车辆信息                               *" << endl;
    cout << "*9. 车辆推荐                                   *" << endl;
    cout << "*10.退出                                       *" << endl;
    cout << "************************************************" << endl;
    cout << "请输入数字选择功能：";
}

void query_show()
{
    cout << "************************************************" << endl;
    cout << "*1. 输入车辆制造公司查询                       *" << endl;
    cout << "*2. 输入编号查询                               *" << endl;
    cout << "*3. 输入类别查询                               *" << endl;
    cout << "************************************************" << endl;
}

void show_bus_data_basement(bus* bus_cur)
{
    if (bus_cur->get_number() == "0")
        return;
    cout << "客车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用" 
        << left << setw(6) << "载客数" << endl;
    while (bus_cur->get_number() != "0")
    {
        //输出表格
        cout << left << setw(10) << bus_cur->get_number()
            << left << setw(12) << bus_cur->get_license_plate() 
            << left << setw(22) << bus_cur->get_Manufacturing_company() 
            << left << setw(14) << bus_cur->get_buy_time() 
            << left << setw(10) << bus_cur->get_total() 
            << left << setw(14) << bus_cur->get_basic_maintenance() 
            << left << setw(16) << bus_cur->get_Fuel_consumption() 
            << left << setw(14) << bus_cur->get_road_maintenance() 
            << left << setw(16) << bus_cur->get_total_rents()
            << left << setw(6) << bus_cur->get_capacity() << endl;
        //指向下一个数据
        bus_cur++;
    }
}
void show_minibus_data_basement(minibus* minibus_cur)
{
    if (minibus_cur->get_number() == "0")
        return;
    cout << "小轿车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(6) << "车箱数" << endl;
    while (minibus_cur->get_number() != "0")
    {
        //输出表格
        cout << left << setw(10) << minibus_cur->get_number()
            << left << setw(12) << minibus_cur->get_license_plate()
            << left << setw(22) << minibus_cur->get_Manufacturing_company()
            << left << setw(14) << minibus_cur->get_buy_time()
            << left << setw(10) << minibus_cur->get_total()
            << left << setw(14) << minibus_cur->get_basic_maintenance()
            << left << setw(16) << minibus_cur->get_Fuel_consumption()
            << left << setw(14) << minibus_cur->get_road_maintenance()
            << left << setw(16) << minibus_cur->get_total_rents()
            << left << setw(6) << minibus_cur->get_car_case() << endl;
        //指向下一个数据
        minibus_cur++;
    }
}
void show_truck_data_basement(truck* truck_cur)
{
    if (truck_cur->get_number() == "0")
        return;
    cout << "卡车数据" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用" 
        << left << setw(8) << "载重数" << left << setw(5) << "自重" << endl;
    while (truck_cur->get_number() != "0")
    {
        //输出表格
        cout << left << setw(10) << truck_cur->get_number()
            << left << setw(12) << truck_cur->get_license_plate()
            << left << setw(22) << truck_cur->get_Manufacturing_company()
            << left << setw(14) << truck_cur->get_buy_time()
            << left << setw(10) << truck_cur->get_total()
            << left << setw(14) << truck_cur->get_basic_maintenance()
            << left << setw(16) << truck_cur->get_Fuel_consumption()
            << left << setw(14) << truck_cur->get_road_maintenance()
            << left << setw(16) << truck_cur->get_total_rents()
            << left << setw(8) << truck_cur->get_load()
            << left << setw(5) << truck_cur->get_deadweight() << endl;
        //指向下一个数据
        truck_cur++;
    }
}

int show_bus_Manufacturing_company_data_basement(bus* bus_cur,string mc)
{
    if (bus_cur->get_number() == "0")
        return 0;
    bus* bus_cp = bus_cur;
    int count = 0;
    while (bus_cp->get_number() != "0")
    {
        if (bus_cp->get_Manufacturing_company() == mc)
        {
            count++;
        }
        bus_cp++;
    }
    if (count == 0)
        return 0;
    cout << "客车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(6) << "载客数" << endl;
    while (bus_cur->get_number() != "0")
    {
        if(bus_cur->get_Manufacturing_company() == mc)
        //在特定情况下输出表格
            cout << left << setw(10) << bus_cur->get_number()
            << left << setw(12) << bus_cur->get_license_plate()
            << left << setw(22) << bus_cur->get_Manufacturing_company()
            << left << setw(14) << bus_cur->get_buy_time()
            << left << setw(10) << bus_cur->get_total()
            << left << setw(14) << bus_cur->get_basic_maintenance()
            << left << setw(16) << bus_cur->get_Fuel_consumption()
            << left << setw(14) << bus_cur->get_road_maintenance()
            << left << setw(16) << bus_cur->get_total_rents()
            << left << setw(6) << bus_cur->get_capacity() << endl;
        //指向下一个数据
        bus_cur++;
    }
    return count;
}

int show_minibus_Manufacturing_company_data_basement(minibus* minibus_cur,string mc)
{
    if (minibus_cur->get_number() == "0")
        return 0;
    minibus* minibus_cp = minibus_cur;
    int count = 0;
    while (minibus_cp->get_number() != "0")
    {
        if (minibus_cp->get_Manufacturing_company() == mc)
        {
            count++;
        }
        minibus_cp++;
    }
    if (count == 0)
        return 0;
    cout << "小轿车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(6) << "车箱数" << endl;
    while (minibus_cur->get_number() != "0")
    {
        if (minibus_cur->get_Manufacturing_company() == mc)
        //输出表格
            cout << left << setw(10) << minibus_cur->get_number()
            << left << setw(12) << minibus_cur->get_license_plate()
            << left << setw(22) << minibus_cur->get_Manufacturing_company()
            << left << setw(14) << minibus_cur->get_buy_time()
            << left << setw(10) << minibus_cur->get_total()
            << left << setw(14) << minibus_cur->get_basic_maintenance()
            << left << setw(16) << minibus_cur->get_Fuel_consumption()
            << left << setw(14) << minibus_cur->get_road_maintenance()
            << left << setw(16) << minibus_cur->get_total_rents()
            << left << setw(6) << minibus_cur->get_car_case() << endl;
        //指向下一个数据
        minibus_cur++;
    }
    return count;
}

int show_truck_Manufacturing_company_data_basement(truck* truck_cur,string mc)
{
    if (truck_cur->get_number() == "0")
        return 0;
    truck* truck_cp = truck_cur;
    int count = 0;
    while (truck_cp->get_number() != "0")
    {
        if (truck_cp->get_Manufacturing_company() == mc)
        {
            count++;
        }
        truck_cp++;
    }
    if (count == 0)
        return 0;
    cout << "卡车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(8) << "载重数" << left << setw(5) << "自重" << endl;
    while (truck_cur->get_number() != "0")
    {
        if (truck_cur->get_Manufacturing_company() == mc)
            //输出表格
            cout << left << setw(10) << truck_cur->get_number()
            << left << setw(12) << truck_cur->get_license_plate()
            << left << setw(22) << truck_cur->get_Manufacturing_company()
            << left << setw(14) << truck_cur->get_buy_time()
            << left << setw(10) << truck_cur->get_total()
            << left << setw(14) << truck_cur->get_basic_maintenance()
            << left << setw(16) << truck_cur->get_Fuel_consumption()
            << left << setw(14) << truck_cur->get_road_maintenance()
            << left << setw(16) << truck_cur->get_total_rents()
            << left << setw(8) << truck_cur->get_load()
            << left << setw(5) << truck_cur->get_deadweight() << endl;
        //指向下一个数据
        truck_cur++;
    }
    return count;
}

int show_bus_number_data_basement(bus* bus_cur, string n)
{
    if (bus_cur->get_number() == "0")
        return 0;
    bus* bus_cp = bus_cur;
    int count = 0;
    while (bus_cp->get_number() != "0")
    {
        if (bus_cp->get_Manufacturing_company() == n)
        {
            count++;
        }
        bus_cp++;
    }
    if (count == 0)
        return 0;
    cout << "客车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(6) << "载客数" << endl;
    while (bus_cur->get_number() != "0")
    {
        if (bus_cur->get_number() == n)
            //在特定情况下输出表格
            cout << left << setw(10) << bus_cur->get_number()
            << left << setw(12) << bus_cur->get_license_plate()
            << left << setw(22) << bus_cur->get_Manufacturing_company()
            << left << setw(14) << bus_cur->get_buy_time()
            << left << setw(10) << bus_cur->get_total()
            << left << setw(14) << bus_cur->get_basic_maintenance()
            << left << setw(16) << bus_cur->get_Fuel_consumption()
            << left << setw(14) << bus_cur->get_road_maintenance()
            << left << setw(16) << bus_cur->get_total_rents()
            << left << setw(6) << bus_cur->get_capacity() << endl;
        //指向下一个数据
        bus_cur++;
    }
    return count;
}

int show_minibus_number_data_basement(minibus* minibus_cur, string n)
{
    if (minibus_cur->get_number() == "0")
        return 0;
    minibus* minibus_cp = minibus_cur;
    int count = 0;
    while (minibus_cp->get_number() != "0")
    {
        if (minibus_cp->get_Manufacturing_company() == n)
        {
            count++;
        }
        minibus_cp++;
    }
    if (count == 0)
        return 0;
    cout << "小轿车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(6) << "车箱数" << endl;
    while (minibus_cur->get_number() != "0")
    {
        if (minibus_cur->get_number() == n)
            //输出表格
            cout << left << setw(10) << minibus_cur->get_number()
            << left << setw(12) << minibus_cur->get_license_plate()
            << left << setw(22) << minibus_cur->get_Manufacturing_company()
            << left << setw(14) << minibus_cur->get_buy_time()
            << left << setw(10) << minibus_cur->get_total()
            << left << setw(14) << minibus_cur->get_basic_maintenance()
            << left << setw(16) << minibus_cur->get_Fuel_consumption()
            << left << setw(14) << minibus_cur->get_road_maintenance()
            << left << setw(16) << minibus_cur->get_total_rents()
            << left << setw(6) << minibus_cur->get_car_case() << endl;
        //指向下一个数据
        minibus_cur++;
    }
    return count;
}

int show_truck_number_data_basement(truck* truck_cur, string n)
{
    if (truck_cur->get_number() == "0")
        return 0;
    truck* truck_cp = truck_cur;
    int count = 0;
    while (truck_cp->get_number() != "0")
    {
        if (truck_cp->get_Manufacturing_company() == n)
        {
            count++;
        }
        truck_cp++;
    }
    if (count == 0)
        return 0;
    cout << "卡车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(8) << "载重数" << left << setw(5) << "自重" << endl;
    while (truck_cur->get_number() != "0")
    {
        if (truck_cur->get_number() == n)
            //输出表格
            cout << left << setw(10) << truck_cur->get_number()
            << left << setw(12) << truck_cur->get_license_plate()
            << left << setw(22) << truck_cur->get_Manufacturing_company()
            << left << setw(14) << truck_cur->get_buy_time()
            << left << setw(10) << truck_cur->get_total()
            << left << setw(14) << truck_cur->get_basic_maintenance()
            << left << setw(16) << truck_cur->get_Fuel_consumption()
            << left << setw(14) << truck_cur->get_road_maintenance()
            << left << setw(16) << truck_cur->get_total_rents()
            << left << setw(8) << truck_cur->get_load()
            << left << setw(5) << truck_cur->get_deadweight() << endl;
        //指向下一个数据
        truck_cur++;
    }
    return count;
}

int show_busdata_basement(bus* bus_cur)
{
    if (bus_cur->get_number() == "0")
    { 
        cout << "该类别没有车辆" << endl;
        return 0;
    }
    cout << "客车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(6) << "载客数" << endl;
    while (bus_cur->get_number() != "0")
    {
        //输出表格
        cout << left << setw(10) << bus_cur->get_number()
            << left << setw(12) << bus_cur->get_license_plate()
            << left << setw(22) << bus_cur->get_Manufacturing_company()
            << left << setw(14) << bus_cur->get_buy_time()
            << left << setw(10) << bus_cur->get_total()
            << left << setw(14) << bus_cur->get_basic_maintenance()
            << left << setw(16) << bus_cur->get_Fuel_consumption()
            << left << setw(14) << bus_cur->get_road_maintenance()
            << left << setw(16) << bus_cur->get_total_rents()
            << left << setw(6) << bus_cur->get_capacity() << endl;
        //指向下一个数据
        bus_cur++;
    }
    return 0;
}
int show_minibusdata_basement(minibus* minibus_cur)
{
    if (minibus_cur->get_number() == "0")
    {
        cout << "该类别没有车辆" << endl;
        return 0;
    }
    cout << "小轿车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(6) << "车箱数" << endl;
    while (minibus_cur->get_number() != "0")
    {
        //输出表格
        cout << left << setw(10) << minibus_cur->get_number()
            << left << setw(12) << minibus_cur->get_license_plate()
            << left << setw(22) << minibus_cur->get_Manufacturing_company()
            << left << setw(14) << minibus_cur->get_buy_time()
            << left << setw(10) << minibus_cur->get_total()
            << left << setw(14) << minibus_cur->get_basic_maintenance()
            << left << setw(16) << minibus_cur->get_Fuel_consumption()
            << left << setw(14) << minibus_cur->get_road_maintenance()
            << left << setw(16) << minibus_cur->get_total_rents()
            << left << setw(6) << minibus_cur->get_car_case() << endl;
        //指向下一个数据
        minibus_cur++;
    }
    return 0;
}
int show_truckdata_basement(truck* truck_cur)
{
    if (truck_cur->get_number() == "0")
    {
        cout << "该类别没有车辆" << endl;
        return 0;
    }
    cout << "卡车数据：" << endl;
    cout << left << setw(10) << "车辆编号" << left << setw(12) << "车牌号" << left << setw(22) << "车辆制造公司"
        << left << setw(14) << "车辆购买时间" << left << setw(10) << "总公里数" << left << setw(14) << "基础维护费用"
        << left << setw(16) << "每百公里耗油量" << left << setw(14) << "道路维护费用" << left << setw(16) << "道路维修总费用"
        << left << setw(8) << "载重数" << left << setw(5) << "自重" << endl;
    while (truck_cur->get_number() != "0")
    {
        //输出表格
        cout << left << setw(10) << truck_cur->get_number()
            << left << setw(12) << truck_cur->get_license_plate()
            << left << setw(22) << truck_cur->get_Manufacturing_company()
            << left << setw(14) << truck_cur->get_buy_time()
            << left << setw(10) << truck_cur->get_total()
            << left << setw(14) << truck_cur->get_basic_maintenance()
            << left << setw(16) << truck_cur->get_Fuel_consumption()
            << left << setw(14) << truck_cur->get_road_maintenance()
            << left << setw(16) << truck_cur->get_total_rents()
            << left << setw(8) << truck_cur->get_load()
            << left << setw(5) << truck_cur->get_deadweight() << endl;
        //指向下一个数据
        truck_cur++;
    }
    return 0;
}

void bus_revise_show()
{
    cout << "************************************************" << endl;
    cout << "*1. 更改车辆编号                               *" << endl;
    cout << "*2. 更改车牌号                                 *" << endl;
    cout << "*3. 更改车辆制造公司                           *" << endl;
    cout << "*4. 更改购买时间                               *" << endl;
    cout << "*5. 更改总公里数                               *" << endl;
    cout << "*6. 更改每百公里耗油量                         *" << endl;
    cout << "*7. 更改道路维护费用                           *" << endl;
    cout << "*8. 更改载客数                                 *" << endl;
    cout << "************************************************" << endl;
    cout << "请输入数字选择功能：";
}

void minibus_revise_show()
{
    cout << "************************************************" << endl;
    cout << "*1. 更改车辆编号                               *" << endl;
    cout << "*2. 更改车牌号                                 *" << endl;
    cout << "*3. 更改车辆制造公司                           *" << endl;
    cout << "*4. 更改购买时间                               *" << endl;
    cout << "*5. 更改总公里数                               *" << endl;
    cout << "*6. 更改每百公里耗油量                         *" << endl;
    cout << "*7. 更改道路维护费用                           *" << endl;
    cout << "*8. 更改车箱数                                 *" << endl;
    cout << "************************************************" << endl;
    cout << "请输入数字选择功能：";
}

void truck_revise_show()
{
    cout << "************************************************" << endl;
    cout << "*1. 更改车辆编号                               *" << endl;
    cout << "*2. 更改车牌号                                 *" << endl;
    cout << "*3. 更改车辆制造公司                           *" << endl;
    cout << "*4. 更改购买时间                               *" << endl;
    cout << "*5. 更改总公里数                               *" << endl;
    cout << "*6. 更改每百公里耗油量                         *" << endl;
    cout << "*7. 更改道路维护费用                           *" << endl;
    cout << "*8. 更改载重量                                 *" << endl;
    cout << "*9. 更改自重                                   *" << endl;
    cout << "************************************************" << endl;
    cout << "请输入数字选择功能：";
}
