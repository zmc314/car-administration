#include "car.h"
int get_bus_quantity(bus* bus_cur) {
	int count;
	for (count = 0; bus_cur->get_number() != "0"; bus_cur++,count++);
	return count;
}

int get_minibus_quantity(minibus* minibus_cur) {
	int count;
	for (count = 0; minibus_cur->get_number() != "0"; minibus_cur++, count++);
	return count;
}

int get_truck_quantity(truck* truck_cur) {
	int count;
	for (count = 0; truck_cur->get_number() != "0"; truck_cur++, count++);
	return count;
}