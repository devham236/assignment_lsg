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
int compare(const Car* car1, const Car* car2){
	// Wenn car1 jünger ist als car2
	if(car1->year > car2->year){
		return 1;
	}
	// Wenn car1 älter ist als car2
	if(car1->year < car2->year){
		return -1;
	}

	int result = strcmp(car1->brand, car2->brand);
	if(result > 0) return 1;
	if(result < 0) return -1;

	return 0;
	
}

// (b) TODO: write compare test function
void compare_test(void){
	Car car1 = {"VW", 1950};
	Car car2 = {"VW", 2000};
	test_equal_i(compare(&car1, &car2), -1);
	test_equal_i(compare(&car2, &car1), 1);

	Car car3 = {"Audi", 1990};
	Car car4 = {"BMW", 1990};
	test_equal_i(compare(&car3, &car4), -1);
	test_equal_i(compare(&car4, &car3), 1);

	Car car5 = {"Ford", 1960};
	Car car6 = {"Ford", 1960};
	test_equal_i(compare(&car5, &car6), 0);
	test_equal_i(compare(&car6, &car5), 0);
	
	
}

// (c) TODO: implement sorted function
bool sorted(Car* a, int length){	
	// du willst immer paarweise vergleichen (zu Beginn das erste und zweite, dann das zweite und dritte usw.), deswegen gehst du nur bis zum vorletzten Element (i < length - 1)
	for(int i = 0; i < length - 1; i++){
		int result = compare(a+i, a+i+1);

		// Sobald result größer als 1 ist (das vorherige Element ist größer als das nächste => [2000, 1950]) wird abgebrochen
		if(result > 0){
			return false;
		}

	}
	// Wird das array ein mal komplett durchlaufen ohne ein false wiederzugeben, ist das array sortiert, also wird ein true wiedergegeben:
	return true;
}

// (d,e) TODO: implement random_sort function
int random_sort(Car* a, int length){
	int swap = 0;
	while(!sorted(a, length)){
		int rand_1 = i_rnd(length);
		int rand_2 = i_rnd(length);

		if(rand_1 == rand_2){
			continue;
		}

		Car copy = a[rand_1];
		a[rand_1] = a[rand_2];
		a[rand_2] = copy;
		swap++;
	}
	printf("times swapped: %d\n", swap);
	return swap;
}

/*
e)
Die Variable swaps zählt, wie oft in random_sort zwei Elemente vertauscht wurden.
Nach jedem Tausch wird die Funktion sorted() erneut aufgerufen, welche im Worst Case
(length - 1) Aufrufe der compare()-Funktion durchführt.

Damit hängt die Anzahl der compare()-Aufrufe direkt von der Anzahl der swaps ab.
Im Worst Case gilt:

    compare_calls ≈ swaps * (length - 1)

Je größer die Anzahl der swaps ist, desto häufiger wird compare() aufgerufen und
desto ineffizienter ist der Algorithmus.
*/


int main(void) {
	
	// (b) TODO: test compare function
	compare_test();
	
	
	//some output
	int number_of_random_cars = 10;
	Car* car_park = create_car_park(number_of_random_cars);
	print_car_array(car_park, number_of_random_cars);
	
	printf("Sorting...\n");
	
	//TODO: sort the car_park array.
	random_sort(car_park, number_of_random_cars);
	
	
	print_car_array(car_park, number_of_random_cars);
	
	delete_car_park(car_park);

    return 0;
}
