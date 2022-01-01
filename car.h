#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

class car
{
public:
    car() :number("0"), license_plate("0"), Manufacturing_company("0"), buy_time("0"), total(0), basic_maintenance(0),
        Fuel_consumption(0), road_maintenance(0), total_rents(0) {};
    ~car() { }             /*纯虚函数*/
    void set_car(string n, string l, string m, string b, double t, double f, double rm, int bm);
    string get_number() {
        return number;
    }//用于获取车辆编号，完成get_length任务,同时还能检查是否存在同名车辆编号
    string get_license_plate() {
        return license_plate;
    }
    string get_Manufacturing_company() {
        return Manufacturing_company;
    }
    string get_buy_time() {
        return buy_time;
    }
    double get_total() {
        return total;
    }
    int get_basic_maintenance() {
        return basic_maintenance;
    }
    double get_Fuel_consumption() {
        return Fuel_consumption;
    }
    double get_road_maintenance() {
        return road_maintenance;
    }
    double get_total_rents(){
        return total_rents;
    }
    void set_number(string num) {
        number = num;
    }
    void set_license_plate(string lp) {
        license_plate = lp;
    }
    void set_Manufacturing_company(string mc) {
        Manufacturing_company = mc;
    }
    void set_buy_time(string bt) {
        buy_time = bt;
    }
    void set_total(double t){
        total = t;
    }
    void set_Fuel_consumption(double fc) {
        Fuel_consumption = fc;
    }
    void set_road_maintenance(double rm) {
        road_maintenance = rm;
    }
    void set_basic_maintenance(int bm) {
        basic_maintenance = bm;
    }
    void set_total_rents(double tr) {
        total_rents = tr;
    }
    int get_buy_time_day();
    virtual double Calculate_Money() = 0;

private:
    string number;					/*车辆编号：具有唯一性*/
    string license_plate;			/*车牌号*/
    string Manufacturing_company;	/*车辆制造公司*/
    string buy_time;				/*车辆购买时间*/
    double total;					/*总公里数*/
    int basic_maintenance;			/*基础维护费用       *
                                     *客车：2000元/月    *
                                     *小轿车：1000元/月  *
                                     *卡车：1500元/月    */
    double Fuel_consumption;		/*每百公里耗油量（单位为升）*/
    double road_maintenance;		/*道路维护费用*/
protected:
    double total_rents;             /*道路维修总费用*/
};

class bus : public car
{
private:
    int capacity;                   /*载客数*/
public:
    bus() :capacity(0) {}
    ~bus() { };
    void set_bus()
    {
        string n = "0";
        string l = "0";
        string m = "0";
        string b = "0";
        double t = 0;
        double f = 0;
        double rm = 0;
        int bm = 2000;
        int c = 0;
        set_car(n, l, m, b, t, f, rm, bm);
        cout << "请输入载客数：";
        cin >> c;
        capacity = c;
        total_rents = Calculate_Money();
    }
    int get_capacity() {
        return capacity;
    }
    void set_capacity(int c) {
        capacity = c;
    }
    double Calculate_Money() override;

};

class minibus : public car
{
private:
    int car_case;                   /*车箱数*/
public:
    minibus();
    ~minibus() { };
    void set_minibus()
    {
        string n = "0";
        string l = "0";
        string m = "0";
        string b = "0";
        double t = 0;
        double f = 0;
        double rm = 0;
        int bm = 1000;
        int cc = 0;
        set_car(n, l, m, b, t, f, rm, bm);
        cout << "请输入车箱数：";
        cin >> cc;
        car_case = cc;
        total_rents = Calculate_Money();
    }
    int get_car_case() {
        return car_case;
    }
    void set_car_case(int cc) {
        car_case = cc;
    }
    double Calculate_Money() override;
};

class truck : public car
{
private:
    int load;                       /*载重量*/
    int deadweight;                 /*自重*/
public:
    truck() :load(0), deadweight(0) {}
    ~truck() { };
    void set_truck()
    {
        string n = "0";
        string l = "0";
        string m = "0";
        string b = "0";
        double t = 0;
        double f = 0;
        double rm = 0;
        int bm = 1500;
        int ld = 0;
        int dw = 0;
        set_car(n, l, m, b, t, f, rm, bm);
        cout << "请输入载重量：";
        cin >> ld;
        load = ld;
        cout << "请输入自重：";
        cin >> dw;
        deadweight = dw;
        total_rents = Calculate_Money();
    }
    int get_load(){
        return load;
    }
    int get_deadweight() {
        return deadweight;
    }
    void set_load(int ld) {
        load = ld;
    }
    void set_deadweight(int dw) {
        deadweight = dw;
    }
    double Calculate_Money() override;
};