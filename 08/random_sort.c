/*
Compile: make random_sort
Run: ./random_sort
make random_sort && ./random_sort
*/

#include "base.h"
#include <math.h>

//template code

char* brands[] = {"VW", "BMW", "Mercedes", "Fiat", "Ford", "Dacia", "Audi", "Citroen"};
int brand_count = sizeof(brands) / sizeof(char*);
int min_year = 1950;
int max_year = 2017;
int max_km = 250000;


struct Car{
	char* brand;
	int year;
	int km;
	double price;
};

typedef struct Car Car;

//print car information
void print_car(Car* car){
	printf("Caryear: %4d\tbrand: %8s\tKM: %6dkm\tPrice: %8.2lfEuro\n", car->year, car->brand, car->km, car->price);	
}

//print carArray
void print_car_array(Car* car_park, int car_count){
	for(int i = 0; i < car_count; i++){
		print_car(car_park + i);
	}
}


// Creates an array with random cars. Returns a pointer to the array.
Car* create_car_park(int car_count){
	//next statement is part of the following lectures. Don't worry.
	Car* car = (Car*) xmalloc(sizeof(Car) * car_count);
	
	//fill the array with random cars
	for(int i = 0; i < car_count; i++){
		int random_brand_index = i_rnd(brand_count); // car brand index in interval: [0,7]

		car[i].brand = brands[random_brand_index];
		int random_year = i_rnd(max_year - min_year) + min_year; //years between min and max year
		car[i].year = random_year;
		
		int random_km = 0;
		// On MinGW: max random number is 32767. To overcome this two 16 bit random numbers are glued together.
		if(RAND_MAX == 32767){
			random_km = (i_rnd(max_km >> 16) << 16 ) | i_rnd(max_km); //dirty hack
		}else{
			random_km = i_rnd(max_km); 
		}
		car[i].km = random_km; //max 250.000km
		
		car[i].price = 30000.00 * pow(0.85, (random_year - min_year)) + 20000.00 * pow(0.75, random_km / 10000.0)  ; // car price max 50.000 Euro
	}
	return car;
}

// Deletes a car array. Call the function, when you don't need the array anymore.
void delete_car_park(Car* cars){
	free(cars);
}

//end of template code

// (a) TODO: implement compare function
int compare(Car car1, Car car2){
	printf("---------------------------------------------------------\n");
	printf("car1 brand: %s, car2 brand: %s\n", car1.brand, car2.brand);
	// return 1 wenn car1 jünger als car2 ist
	if(car1.year > car2.year) {
		return 1;
	}
	// return -1 wenn car1 älter als car2 ist
	else if(car1.year < car2.year) {
		return -1;
	}
	// wenn car1 und car2 gleich alt sind, dann Marke überprüfen mit int strcmp(char* str1, char* str2)
	else if(car1.year == car2.year) {
		int result = strcmp(car1.brand, car2.brand);
		return result > 0 ? 1 :
			   result < 0 ? -1 : 
			   result == 0 ? 0 :
			   0;
	}
	return 0;
}

// (b) TODO: write compare test function
void compare_test(void){
	Car car1 = {
		car1.brand = brands[0],
		car1.year = 1950,
		car1.km = 100000,
		car1.price = 10000.00,
	};

	Car car2 = {
		car2.brand = brands[1],
		car2.year = 1960,
		car2.km = 100000,
		car2.price = 10000.00,
	};

	Car car3 = {
		car1.brand = brands[2],
		car1.year = 1970,
		car1.km = 100000,
		car1.price = 10000.00,
	};

	Car car4 = {
		car2.brand = brands[3],
		car2.year = 1980,
		car2.km = 100000,
		car2.price = 10000.00,
	};

	Car car5= {
		car1.brand = brands[4],
		car1.year = 1990,
		car1.km = 100000,
		car1.price = 10000.00,
	};

	Car car6 = {
		car2.brand = brands[5],
		car2.year = 1990,
		car2.km = 100000,
		car2.price = 10000.00,
	};

	test_equal_i(compare(car1, car2), 1);
	test_equal_i(compare(car4, car3), 1);
	test_equal_i(compare(car5, car6), 1);
}

// (c) TODO: implement sorted function
bool sorted(Car* a, int length){
	return false;
}

// (d,e) TODO: implement random_sort function
int random_sort(Car* a, int length){
	return 0;
}


int main(void) {
	
	// (b) TODO: test compare function
	
	
	
	//some output
	// int number_of_random_cars = 10;
	// Car* car_park = create_car_park(number_of_random_cars);
	// print_car_array(car_park, number_of_random_cars);
	
	// printf("Sorting...\n");
	
	//TODO: sort the car_park array.
	
	
	// print_car_array(car_park, number_of_random_cars);
	
	// delete_car_park(car_park);

	compare_test();

    return 0;
}
